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

      $xpath = new DomXPath($dom);

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
        $top_anchor = $xpath->query("./a[@class='linkTop']", $content)->item(0);
        $content->removeChild($top_anchor);
      }
      // It's a landing page.
      elseif ($content = $xpath->query("//div[@class='center-box']")->item(0)) {
        // Scrape the #content #visual h2 as title.
        if ($title_node = $xpath->query("//div[@id='visual']//h2")->item(0)) {
          $row->title = $title_node->nodeValue;
        }
      }

      if ($content) {
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
   * {@inheritdoc}
   */
  public function prepareRow($row) {
    $url = ArpansaMigrationHelper::sanitizeArpansaSourceUri($row->source);
    $row->source_url = 'http://www.arpansa.gov.au/' . $url;

    $row->alias = ArpansaMigrationHelper::sanitizeArpansaSourceUri($row->alias);

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
   * {@inheritdoc}
   */
  public function complete($node, $row) {
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

}
