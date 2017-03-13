<?php

/**
 * @file
 * page.inc
 */

/**
 * Class ArpansaMigrationPage.
 */
class ArpansaMigrationPage extends ArpansaMigrationBase {

  /**
   * Source CSV file.
   *
   * @var string
   */
  protected $sourceCSV;

  /**
   * Last migrated page.
   *
   * @var object
   */
  protected $lastPage;

  /**
   * Last migrate menu item.
   *
   * @var object
   */
  protected $lastMenuItem;

  /**
   * {@inheritdoc}
   */
  public function __construct(array $arguments = array()) {
    parent::__construct($arguments);

    $this->sourceCSV = $this->getEnvOption('csv');

    $csvColumns = [
      ['a', 'Reference ID'],
      ['ia_title1', 'IA Title L1'],
      ['ia_title2', 'IA Title L2'],
      ['ia_title3', 'IA Title L3'],
      ['ia_title4', 'IA Title L4'],
      ['source', 'Current location'],
      ['alias', 'New location'],
      ['type', 'Content Type'],
      ['tag1', 'Tag 1'],
      ['tag2', 'Tag 2'],
      ['tag3', 'Tag 3'],
      ['tag4', 'Tag 4'],
      ['tag5', 'Tag 5'],
    ];

    module_load_include('inc', 'arpansa_migration', '/migrations/sources/csv');
    $this->source = new ArpansaMigrationCSV($this->sourceCSV, $csvColumns, ['header_rows' => 2]);
    $this->destination = new MigrateDestinationNode('page', MigrateDestinationNode::options(LANGUAGE_NONE, 'rich_text'));
    $this->map = new MigrateSQLMap($this->machineName, [
      'source' => [
        'type' => 'varchar',
        'length' => 255,
      ],
    ], MigrateDestinationNode::getKeySchema());

    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('body', 'body')
      ->callbacks('ArpansaMigrationHelper::sanitizeText');
    $this->addFieldMapping('uid')->defaultValue(1);
    $this->addFieldMapping('type', 'type');
    $this->addFieldMapping('path', 'alias');
    $this->addFieldMapping('status')->defaultValue(NODE_PUBLISHED);
    $this->addFieldMapping('sticky')->defaultValue(0);
    $this->addFieldMapping('revision')->defaultValue(FALSE);
    $this->addFieldMapping('pathauto')->defaultValue(FALSE);
  }

  /**
   * {@inheritdoc}
   */
  protected function preImport() {
    if (empty($this->sourceCSV)) {
      throw new MigrateException(t('The source CSV file must be provided.'));
    }
    if (!file_exists($this->sourceCSV)) {
      throw new MigrateException(t('The source CSV file !source_csv does not exist.', ['!source_csv' => $this->sourceCSV]));
    }

    parent::preImport();
  }

  /**
   * Implements validateRow().
   */
  public function validateRow($row) {
    if (empty($row->source)) {
      return FALSE;
    }

    // Skips homepage.
    $url = ArpansaMigrationHelper::sanitizeArpansaSourceUri($row->source);
    if (empty($url)) {
      return FALSE;
    }

    // AC7.1 Items marked with "delete" in column G should not be migrated.
    if ($row->type == 'delete' || $url == 'delete' || $row->alias == 'delete') {
      return FALSE;
    }

    return TRUE;
  }

  /**
   * {@inheritdoc}
   */
  public function prepareRow($row) {
    $url = ArpansaMigrationHelper::sanitizeArpansaSourceUri($row->source);
    $row->source_url = 'http://www.arpansa.gov.au/' . $url;

    $row->alias = ArpansaMigrationHelper::sanitizeArpansaSourceUri($row->alias);

    // Map content type.
    switch ($row->type) {
      case 'news':
        $row->type = 'news_article';
        break;
      case 'consultation':
        $row->type = 'news_article';
        break;
    }

    // Scrape content.
    if (!$this->scrapeArpansaContent($row)) {
      return FALSE;
    }

    // Detect IA Title.
    $row->ia_title = $row->title;
    foreach ([1, 2, 3, 4] as $ia_title_level) {
      $ia_title = $row->{'ia_title' . $ia_title_level};
      if (!empty($ia_title)) {
        $ia_title_parts = explode(' - ', $ia_title);
        // Remove "ARPANSA" from IA title.
        array_shift($ia_title_parts);
        for ($i = 1; $i < $ia_title_level; $i++) {
          if ($ia_title_parts && count($ia_title_parts)) {
            array_shift($ia_title_parts);
          }
        }
        if ($ia_title_parts && count($ia_title_parts)) {
          $ia_title = implode(' - ', $ia_title_parts);
        }

        if ($ia_title) {
          $row->ia_title = $ia_title;
        }

        break;
      }
    }

    return TRUE;
  }

  /**
   * Implements prepare().
   */
  public function prepare($node, $row) {
    if (empty($row->alias)) {
      $node->path['pathauto'] = TRUE;
    }
  }

  /**
   * {@inheritdoc}
   */
  public function complete($node, $row) {
    $this->lastPage = $node;

    $this->remapIA($node, $row);

    // Create redirect from legacy path.
    try {
      if (!empty($row->source)) {
        // Skips if the legacy path is already in use.
        if ($row->source != drupal_get_normal_path($row->source)) {
          $this->saveMessage(t('Skip creating redirect for !path', ['!path' => $row->source]), self::MESSAGE_INFORMATIONAL);
          return;
        }
        $path = trim($row->source, '/');
        if ($redirect = redirect_load_by_source($path)) {
          $redirect->redirect = 'node/' . $node->nid;
          redirect_save($redirect);
        }
        else {
          $redirect = new stdClass();
          redirect_object_prepare($redirect);
          $redirect->status_code = 301;
          $redirect->source = $path;
          $redirect->redirect = 'node/' . $node->nid;
          redirect_save($redirect);
        }
      }
    }
    catch (PDOException $e) {
      $this->displayMessage('Could not create ' . $row->source . ' redirect for file ' . $node->nid);
    }
  }

  /**
   * {@inheritdoc}
   */
  public function postImport() {
    parent::postImport();
    menu_rebuild();
  }

  /**
   * Implements createStub().
   */
  protected function createStub($migration, $source_key = NULL) {
    migrate_instrument_start('ArpansaMigrationPage::createStub');
    $source = reset($source_key);
    $node = new stdClass();
    $node->title = $source;
    $node->type = $this->destination->getBundle();
    $node->language = LANGUAGE_NONE;
    node_object_prepare($node);
    $node->uid = 1;
    $node->status = NODE_NOT_PUBLISHED;
    $node->revision = FALSE;
    node_save($node);
    migrate_instrument_stop('ArpansaMigrationPage::createStub');
    if (isset($node->nid)) {
      return array($node->nid);
    }

    return FALSE;
  }

  /**
   * Scrape ARPANSA content.
   *
   * @param object $row
   *   Row data.
   *
   * @return bool
   *   FALSE upon failure.
   */
  protected function scrapeArpansaContent($row) {
    if ($html = file_get_contents($row->source_url)) {
      $dom = new DOMDocument();
      $dom->preserveWhiteSpace = FALSE;
      @$dom->loadHTML(mb_convert_encoding($html, 'HTML-ENTITIES', 'UTF-8'),
        LIBXML_NOERROR | LIBXML_NOWARNING | LIBXML_HTML_NOIMPLIED | LIBXML_HTML_NODEFDTD | LIBXML_NOXMLDECL);

      $xpath = new DOMXPath($dom);

      /** @var DOMElement $content */
      if ($content = $xpath->query("//div[@id='genericContent']")->item(0)) {
        // Content Title wrapper.
        $content_title = $xpath->query("./div[@class='contentTitle']", $content)
          ->item(0);
        // Extract title from the first H3.
        $title_node = $xpath->query("./h3", $content_title)->item(0);
        $row->title = $title_node->nodeValue;
        // Remove title from body.
        $content->removeChild($content_title);

        // Remove Top of Page anchor.
        foreach ($xpath->query("./a[@class='linkTop']", $content) as $top_anchor) {
          $content->removeChild($top_anchor);
        }
      }
      // It's a landing page.
      elseif ($content = $xpath->query("//div[@class='center-box']")->item(0)) {
        // Scrape the #content #visual h2 as title.
        if ($title_node = $xpath->query("//div[@id='visual']//h2")->item(0)) {
          $row->title = $title_node->nodeValue;
        }
      }

      if ($content) {
        $this->remapImages($row, $content, $xpath);
        $this->remapLinks($row, $content, $xpath);

        // Scrape remaining children into body.
        $row->body = '';
        foreach ($content->childNodes as $child) {
          if (!($child instanceof DOMComment)) {
            $row->body .= $content->ownerDocument->saveHTML($child);
          }
        }

        return TRUE;
      }
    }

    return FALSE;
  }

  /**
   * Remap ARPANSA images.
   *
   * @param object $row
   *   Current row.
   * @param \DOMElement $content
   *   Body Content.
   * @param \DOMXPath $xpath
   *   XPath.
   */
  protected function remapImages($row, DOMElement $content, DOMXPath $xpath) {
    $images = $xpath->query('//img', $content);
    /** @var DOMElement $image */
    foreach ($images as $image) {
      $src = $image->getAttribute('src');
      $src = ArpansaMigrationHelper::remapRelativeUri($src, $row->source);

      // Search for migrated file.
      /** @var ArpansaMigrationFile $fileMigration */
      $fileMigration = Migration::getInstance('File');
      if ($destids = $fileMigration->getMap()->lookupDestinationID(['sourceid1' => $src])) {
        if (!empty($destids['destid1'])) {
          $fid = $destids['destid1'];

          // Build a media token to replace this image.
          $attributes = [];
          foreach (['id', 'alt', 'title', 'class', 'width', 'height', 'hspace', 'vspace', 'align', 'border'] as $attribute_name) {
            if ($attribute = $image->getAttribute($attribute_name)) {
              $attributes[$attribute_name] = ArpansaMigrationHelper::sanitizeText($attribute);
            }
            elseif ($attribute_name == 'title' && empty($attributes['alt'])) {
              $attributes['alt'] = $attributes[$attribute_name];
            }
          }

          $media_token = ArpansaMigrationHelper::buildMediaJson($fid, $attributes, NULL, 'full');
          $media_token_node = $content->ownerDocument->createTextNode($media_token);
          $image->parentNode->replaceChild($media_token_node, $image);
          continue;
        }
      }

      // No migrated files found.
      $image->setAttribute('src', $src);
    }
  }

  /**
   * Remap ARPANSA links.
   *
   * @param object $row
   *   Current row.
   * @param \DOMElement $content
   *   Body Content.
   * @param \DOMXPath $xpath
   *   XPath.
   */
  protected function remapLinks($row, DOMElement $content, DOMXPath $xpath) {
    $anchors = $xpath->query('//a', $content);
    /** @var DOMElement $anchor */
    foreach ($anchors as $anchor) {
      $href = $anchor->getAttribute('href');
      $url = parse_url($href);
      if (!empty($url['scheme'])) {
        continue;
      }
      $href = ArpansaMigrationHelper::remapRelativeUri($url['path'], $row->source);

      $extension = pathinfo($href, PATHINFO_EXTENSION);
      // Search for migrated page.
      if (empty($extension) || in_array(strtolower($extension), ['cfm', 'htm', 'html'])) {
        $href = strtolower($href);
        if ($destination = $this->handleSourceMigration(['Page'], [$href])) {
          $nid = is_array($destination) ? reset($destination) : $destination;
          $href = '/node/' . $nid;
          if (!empty($url['query'])) {
            $href .= '?' . $url['query'];
          }
          if (!empty($url['fragment'])) {
            $href .= '#' . $url['fragment'];
          }
          $anchor->setAttribute('href', $href);
          continue;
        }
      }
      // Search for migrated file.
      else {
        /** @var ArpansaMigrationFile $fileMigration */
        $fileMigration = Migration::getInstance('File');
        if ($destids = $fileMigration->getMap()->lookupDestinationID(['sourceid1' => $href])) {
          if (!empty($destids['destid1'])) {
            $fid = $destids['destid1'];

            $link_text = $anchor->nodeValue;
            // Check for nested media token.
            if (preg_match("/\[\[\{(.*)\}\]\]/siU", $link_text)) {
              $href = '/file/' . $fid;
              if (!empty($url['query'])) {
                $href .= '?' . $url['query'];
              }
              if (!empty($url['fragment'])) {
                $href .= '#' . $url['fragment'];
              }
              $anchor->setAttribute('href', $href);
              continue;
            }

            // No nested, so we can build a media token to replace this link.
            $attributes = [];
            foreach (['id', 'title', 'class', 'target'] as $attribute_name) {
              if ($attribute = $anchor->getAttribute($attribute_name)) {
                $attributes[$attribute_name] = ArpansaMigrationHelper::sanitizeText($attribute);
              }
            }

            $media_token = ArpansaMigrationHelper::buildMediaJson($fid, $attributes, $link_text, 'default');
            $media_token_node = $content->ownerDocument->createTextNode($media_token);
            $anchor->parentNode->replaceChild($media_token_node, $anchor);
            continue;
          }
        }
      }

      // No migrated files/pages found.
      $anchor->setAttribute('href', $href);
    }
  }

  /**
   * Assign the migrated page to main menu.
   *
   * @param object $node
   *   Node object.
   * @param object $row
   *   Row object.
   */
  protected function remapIA($node, $row) {
    if ($menu = menu_link_get_preferred('node/' . $node->nid, 'main-menu')) {
      $menu['link_title'] = $row->ia_title;
      $menu['description'] = $node->title;
    }
    else {
      $menu = [
        'enabled' => TRUE,
        'link_title' => $row->ia_title,
        'link_path' => 'node/' . $node->nid,
        'description' => $node->title,
        'plid' => 0,
        'menu_name' => 'main-menu',
        'expanded' => 1,
      ];
    }

    if (empty($row->alias)) {
      if (!empty($this->lastMenuItem)) {
        $menu['plid'] = $this->lastMenuItem['plid'];
      }
    }
    else {
      // Try to find a parent menu item.
      $parent_path = dirname($row->source);
      if (!empty($parent_path) && $parent_path != '/') {
        if ($destination = $this->handleSourceMigration('Page', [$parent_path])) {
          $parent_nid = is_array($destination) ? reset($destination) : $destination;
          if ($parent_menu = menu_link_get_preferred('node/' . $parent_nid, 'main-menu')) {
            $menu['plid'] = $parent_menu['mlid'];
          }
          else {
            // Create one for its parent.
            $parent_menu = [
              'enabled' => TRUE,
              'link_title' => $parent_path,
              'link_path' => 'node/' . $parent_nid,
              'plid' => 0,
              'menu_name' => 'main-menu',
              'expanded' => 1,
            ];
            if ($plid = menu_link_save($parent_menu)) {
              $menu['plid'] = $plid;
            }
          }
        }
      }
    }

    if ($mlid = menu_link_save($menu)) {
      $this->lastMenuItem = $menu;
    }
  }
}
