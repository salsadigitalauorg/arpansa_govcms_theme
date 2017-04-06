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
   * Stub count.
   *
   * @var int
   */
  protected $stubCount = 0;

  /**
   * Imported Node Ids.
   *
   * @var array
   */
  protected $importedNids = [];

  /**
   * Remap content flag.
   *
   * @var bool
   */
  protected $remapContentWhenScraping = FALSE;

  /**
   * {@inheritdoc}
   */
  public function __construct(array $arguments = array()) {
    parent::__construct($arguments);

    $this->sourceCSV = $this->getEnvOption('source-csv');

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
      ['redirect', 'Redirect'],
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
    $this->addFieldMapping('field_tags', 'tags');
    $this->addFieldMapping('field_tags:create_term')->defaultValue(TRUE);
    $this->addFieldMapping('field_tags:ignore_case')->defaultValue(TRUE);
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

    $this->sanitizeIdList();

    parent::preImport();
  }

  /**
   * {@inheritdoc}
   */
  protected function preRollback() {
    $this->sanitizeIdList();
    parent::preRollback();
  }

  /**
   * {@inheritdoc}
   */
  public function prepareKey($source_key, $row) {
    if (!empty($row->source)) {
      $row->origin = $row->source;
      if (strpos($row->source, 'index.cfm') !== FALSE) {
        $row->is_index = TRUE;
        $row->source = str_replace('index.cfm', '/', $row->source);
      }
      $row->source = rtrim($row->source, '/');
      $row->source = preg_replace('/\/+/', '/', $row->source);
    }
    $key = parent::prepareKey($source_key, $row);

    return $key;
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

    return TRUE;
  }

  /**
   * {@inheritdoc}
   */
  public function prepareRow($row) {
    $url = ArpansaMigrationHelper::sanitizeArpansaSourceUri($row->source);
    $row->source_url = 'http://www.arpansa.gov.au/' . $url;

    $row->alias = ArpansaMigrationHelper::sanitizeArpansaSourceUri($row->alias);

    // AC7.1 Items marked with "delete" in column G should not be migrated.
    if ($row->type == 'delete' || $url == 'delete' || $row->alias == 'delete') {
      return FALSE;
    }

    // Map content type.
    switch ($row->type) {
      case 'news':
        $row->type = 'news_article';
        break;

      case 'page':
      case 'landing_page':
      case 'consultation':
        break;

      default:
        $row->type = 'page';
        break;
    }

    // Scrape content.
    if (!$this->scrapeArpansaContent($row)) {
      return FALSE;
    }

    foreach ([1, 2, 3, 4] as $index) {
      if (!empty($row->{'tag' . $index})) {
        $row->tags[] = ucfirst($row->{'tag' . $index});
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
    else {
      $node->path['alias'] = $row->alias;
    }

    if ($node->type == 'consultation') {
      $node->field_consultation_summary = $node->body;
    }
  }

  /**
   * {@inheritdoc}
   */
  public function complete($node, $row) {
    $this->lastPage = $node;
    $this->importedNids[$node->nid] = $node->nid;

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

    // Create another redirect if the page is index.cfm.
    if (!empty($row->is_index)) {
      try {
        // Skips if the legacy path is already in use.
        if ($row->origin != drupal_get_normal_path($row->origin)) {
          $this->saveMessage(t('Skip creating redirect for !path', ['!path' => $row->origin]), self::MESSAGE_INFORMATIONAL);
          return;
        }
        $path = trim($row->origin, '/');
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
      catch (PDOException $e) {
        $this->displayMessage('Could not create ' . $row->origin . ' redirect for file ' . $node->nid);
      }
    }
  }

  /**
   * {@inheritdoc}
   */
  protected function postImport() {
    if (count($this->importedNids)) {
      foreach ($this->importedNids as $nid) {
        $mapping = $this->map->getRowByDestination([$nid]);
        if ($mapping) {
          $row = (object) ['source' => $mapping['sourceid1']];
          $this->currentFauxSourceKey = ['source' => $mapping['sourceid1']];
          if ($node = node_load($nid)) {
            $field_name = 'body';
            if ($node->type == 'consultation') {
              $field_name = 'field_consultation_summary';
            }
            if (!empty($node->{$field_name}[LANGUAGE_NONE][0]['value'])) {
              $text = $node->{$field_name}[LANGUAGE_NONE][0]['value'];
              $text = $this->remapContent($text, $row);
              $node->{$field_name}[LANGUAGE_NONE][0]['value'] = $text;
              $node->revision = FALSE;
              node_save($node);
            }
          }
        }
      }
    }

    if ($this->stubCount) {
      $this->remapContentWhenScraping = TRUE;
      for ($try = 0; $try < 10; $try++) {
        $mappingRows = $this->map->getRowsNeedingUpdate($this->stubCount);
        if (!$mappingRows || !count($mappingRows)) {
          break;
        }
        foreach ($mappingRows as $mappingRow) {
          if (empty($mappingRow->destid1)) {
            continue;
          }
          $this->currentFauxSourceKey = ['source' => $mappingRow->sourceid1];
          // Wipe all messages of the current row.
          $this->map->delete($this->currentSourceKey(), TRUE);
          // Prepare a faux row.
          $row = new stdClass();
          $row->source = $mappingRow->sourceid1;
          $row->alias = '';
          $this->prepareKey([
            'source' => [
              'type' => 'varchar',
              'length' => 255,
            ],
          ], $row);
          $node = node_load($mappingRow->destid1);
          $row->type = $node->type;
          // Stimulate import process.
          if (!$this->prepareRow($row)) {
            // Cannot scrape this page, ignore it.
            $this->map->saveIDMapping((object) ['source' => $mappingRow->sourceid1], [$mappingRow->destid1], MigrateMap::STATUS_IGNORED);
            continue;
          }
          $node->title = $row->title;
          $node->body[LANGUAGE_NONE][0]['value'] = ArpansaMigrationHelper::sanitizeText($row->body);
          $node->body[LANGUAGE_NONE][0]['format'] = 'rich_text';
          $this->prepare($node, $row);
          $node->revision = FALSE;
          node_save($node);
          $this->complete($node, $row);
          // Update this mapping as IMPORTED.
          $this->map->saveIDMapping((object) ['source' => $mappingRow->sourceid1], [$mappingRow->destid1], MigrateMap::STATUS_IMPORTED);
          unset($this->currentFauxSourceKey);
        }
      }
    }
  }

  /**
   * Implements createStub().
   */
  protected function createStub($migration, $source_key = NULL) {
    migrate_instrument_start('ArpansaMigrationPage::createStub');
    $source = reset($source_key);

    $ignoredSources = [
      '/uvindex',
      '/archive',
      '/news/mediareleases/archive',
    ];
    foreach ($ignoredSources as $ignoredSource) {
      if (strpos($source, $ignoredSource) === 0) {
        return FALSE;
      }
    }

    $node = new stdClass();
    $node->title = $source;
    $node->type = pathinfo($source, PATHINFO_EXTENSION) ? 'page' : 'landing_page';
    $node->language = LANGUAGE_NONE;
    node_object_prepare($node);
    $node->uid = 1;
    $node->status = NODE_PUBLISHED;
    $node->revision = FALSE;
    $node->body[LANGUAGE_NONE][0] = ['value' => '', 'format' => 'rich_text'];
    $node->path = [
      'pathauto' => FALSE,
      'alias' => NULL,
    ];
    node_save($node);
    migrate_instrument_stop('ArpansaMigrationPage::createStub');
    if (isset($node->nid)) {
      $this->stubCount++;
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
    $result = drupal_http_request($row->source_url);
    if (empty($result->error) && in_array($result->code, [200, 304])) {
      $html = $result->data;
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
        if ($row->title == '404 Error') {
          $this->queueMessage(t('Error 404 returned for page @url', ['@url' => $row->source_url]));
          return FALSE;
        }

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
        if ($this->remapContentWhenScraping) {
          $this->remapImages($row, $content, $xpath);
          $this->remapLinks($row, $content, $xpath);
        }
        $this->sanitizeContent($row, $content, $xpath);

        // Scrape remaining children into body.
        $row->body = '';
        foreach ($content->childNodes as $child) {
          if (!($child instanceof DOMComment)) {
            $row->body .= $content->ownerDocument->saveHTML($child);
          }
        }

        // Prevent malformed media token.
        $row->body = str_replace(
          ['[[[{', '}]]]'],
          ['&#91;[[{', '}]]&#93;'],
          $row->body
        );

        return TRUE;
      }
      else {
        $this->queueMessage(t('No content extracted from @url', ['@url' => $row->source_url]));
      }
    }
    else {
      $error = '';
      if (!empty($result->error)) {
        $error = 'HTTP Error: ' . $result->error;
      }
      $this->queueMessage(t('Could not scrape content from @url. @error', [
        '@url' => $row->source_url,
        '@error' => $error,
      ]));
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
      $src = ArpansaMigrationHelper::sanitizeArpansaSourceUri($src);
      $src = ArpansaMigrationHelper::remapRelativeUri($src, $row->source);

      // Search for migrated file.
      /** @var ArpansaMigrationFile $fileMigration */
      $fileMigration = Migration::getInstance('File');
      if ($destids = $fileMigration->getMap()->lookupDestinationID(['sourceid1' => $src])) {
        if (!empty($destids['destid1'])) {
          $fid = $destids['destid1'];

          // Build a media token to replace this image.
          $attributes = [];
          foreach ([
            'id', 'title', 'alt', 'class', 'width', 'height',
            'hspace', 'vspace', 'align', 'border',
          ] as $attribute_name) {
            if ($attribute = $image->getAttribute($attribute_name)) {
              $attributes[$attribute_name] = ArpansaMigrationHelper::sanitizeText($attribute);
            }
          }
          if (!empty($attributes['title']) && empty($attributes['alt'])) {
            $attributes['alt'] = $attributes['title'];
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
      $href = ArpansaMigrationHelper::sanitizeArpansaSourceUri($href);
      $url = parse_url($href);
      if (!empty($url['scheme'])) {
        continue;
      }
      if (empty($url['path'])) {
        $url['path'] = '/';
      }

      $path = ArpansaMigrationHelper::sanitizeArpansaSourceUri($url['path']);

      // Attempts to fix malformed external URL.
      if (strpos($url['path'], 'www.') === 0) {
        $anchor->setAttribute('href', 'http://' . $url['path']);
        continue;
      }

      $href = ArpansaMigrationHelper::remapRelativeUri($path, $row->source);
      if (empty($href)) {
        $anchor->setAttribute('href', '/');
        continue;
      }

      $extension = pathinfo($href, PATHINFO_EXTENSION);
      // Search for migrated page.
      if (empty($extension)
        || in_array(strtolower($extension), ['cfm', 'htm', 'html'])
      ) {
        if (strpos($href, 'index.cfm') !== FALSE) {
          $href = str_replace('index.cfm', '/', $href);
        }
        if (strpos($href, 'index.html') !== FALSE) {
          $href = str_replace('index.html', '/', $href);
        }
        if (strpos($href, 'index.htm') !== FALSE) {
          $href = str_replace('index.htm', '/', $href);
        }
        $href = rtrim(strtolower($href), '/');

        // Follow redirect.
        $redirect = ArpansaMigrationHelper::followRedirect($href);
        if ($redirect != $href) {
          // @code
          // $this->map->saveMessage([$row->source],'Use redirect ' . $redirect . ' for ' . $href, self::MESSAGE_INFORMATIONAL);
          // @endcode
          $anchor->setAttribute('href', $redirect);
          continue;
        }

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

        $this->map->saveMessage([$row->source], 'No migrated page found for ' . $href, self::MESSAGE_INFORMATIONAL);
      }
      // Search for migrated file.
      else {
        /** @var ArpansaMigrationFile $fileMigration */
        $fileMigration = Migration::getInstance('File');
        if ($destids = $fileMigration->getMap()->lookupDestinationID(['sourceid1' => $href])) {
          if (!empty($destids['destid1'])) {
            $fid = $destids['destid1'];

            // Do not convert image link to media token.
            if ($file = file_load($fid)) {
              if (!empty($file->type) && $file->type == 'image') {
                $image_url = parse_url(file_create_url($file->uri), PHP_URL_PATH);
                $anchor->setAttribute('href', $image_url);
                continue;
              }
            }

            $link_text = $anchor->nodeValue;
            // Check for nested media token.
            if (preg_match("/\[\[\{(.*)\}\]\]/siU", $link_text)) {
              $new_href = '/file/' . $fid;
              if (!empty($url['query'])) {
                $new_href .= '?' . $url['query'];
              }
              if (!empty($url['fragment'])) {
                $new_href .= '#' . $url['fragment'];
              }
              $anchor->setAttribute('href', $new_href);
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
   * Sanitize content.
   *
   * @param object $row
   *   Current row.
   * @param \DOMElement $content
   *   Body Content.
   * @param \DOMXPath $xpath
   *   XPath.
   */
  protected function sanitizeContent($row, DOMElement $content, DOMXPath $xpath) {
    // Strip out <script> tags.
    $scripts = $xpath->query('//script', $content);
    /** @var DOMElement $script */
    foreach ($scripts as $script) {
      $script->parentNode->removeChild($script);
    }

    // Strip out unwanted attributes.
    $unwantedAttributes = [
      'style',
      'onblur', 'onchange', 'onfocus', 'oninput', 'onselect',
      'onreset', 'onsubmit',
      'onkeydown', 'onkeyup', 'onkeypress',
      'onclick', 'ondbclick',
      'onmousedown', 'onmousemove', 'onmouseout', 'onmouseover', 'onmouseup',
    ];
    foreach ($unwantedAttributes as $attribute) {
      $elements = $xpath->query('//*[@' . $attribute . ']', $content);
      /** @var DOMElement $element */
      foreach ($elements as $element) {
        $element->removeAttribute($attribute);
      }
    }

    // Remove href: javascript from anchors.
    $anchors = $xpath->query('//a', $content);
    /** @var DOMElement $anchor */
    foreach ($anchors as $anchor) {
      $href = $anchor->getAttribute('href');
      if (strpos($href, 'javascript:') !== FALSE) {
        $anchor->setAttribute('href', '');
      }
    }
  }

  /**
   * Sanitise idList.
   */
  protected function sanitizeIdList() {
    $idlist = $this->getOption('idlist');
    if ($idlist) {
      $idlist = explode(',', $idlist);
      foreach ($idlist as &$id) {
        if (strpos($id, 'index.cfm') !== FALSE) {
          $id = str_replace('index.cfm', '/', $id);
        }
        $id = rtrim($id, '/');
      }
      $idlist = implode(',', $idlist);
      $this->options['idlist'] = $idlist;
    }
  }

  /**
   * Remap images and link in content.
   *
   * @param string $text
   *   Text to process.
   * @param object $row
   *   Row object.
   *
   * @return string
   *   Processed text.
   */
  protected function remapContent($text, $row) {
    $dom = new DOMDocument();
    $dom->preserveWhiteSpace = FALSE;
    $html = '<html><body>' . $text . '</body></html>';
    @$dom->loadHTML(mb_convert_encoding($html, 'HTML-ENTITIES', 'UTF-8'),
      LIBXML_NOERROR | LIBXML_NOWARNING | LIBXML_HTML_NOIMPLIED | LIBXML_HTML_NODEFDTD | LIBXML_NOXMLDECL);

    $xpath = new DOMXPath($dom);

    $content = $xpath->query("/html/body")->item(0);
    $this->remapImages($row, $content, $xpath);
    $this->remapLinks($row, $content, $xpath);

    $text = '';
    foreach ($content->childNodes as $child) {
      if (!($child instanceof DOMComment)) {
        $text .= $content->ownerDocument->saveHTML($child);
      }
    }

    // Prevent malformed media token.
    $text = str_replace(
      ['[[[{', '}]]]'],
      ['&#91;[[{', '}]]&#93;'],
      $text
    );

    return $text;
  }

}
