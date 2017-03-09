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
      ['a', 'a'],
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

}
