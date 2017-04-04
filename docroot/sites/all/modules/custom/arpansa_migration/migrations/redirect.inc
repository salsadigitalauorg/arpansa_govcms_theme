<?php

/**
 * @file
 * redirect.inc
 */

/**
 * Class ArpansaMigrationRedirect.
 */
class ArpansaMigrationRedirect extends ArpansaMigrationPage {

  /**
   * {@inheritdoc}
   */
  public function __construct(array $arguments = array()) {
    parent::__construct($arguments);

    module_load_include('inc', 'arpansa_migration', 'migrations/destinations/redirect');
    $this->destination = new ArpansaMigrationDestinationRedirect();

    $this->map = new MigrateSQLMap($this->machineName, [
      'source' => [
        'type' => 'varchar',
        'length' => 255,
      ],
    ], ArpansaMigrationDestinationRedirect::getKeySchema());

    $this->codedFieldMappings = [];
    $this->addFieldMapping('source', 'source');
    $this->addFieldMapping('redirect', 'redirect');
    $this->addFieldMapping('uid')->defaultValue(1);
    $this->addFieldMapping('status_code')->defaultValue(301);
    $this->addFieldMapping('language')->defaultValue(LANGUAGE_NONE);

    $this->addUnmigratedDestinations([
      'source_options',
      'redirect_options',
    ]);
  }

  /**
   * Implements validateRow().
   */
  public function validateRow($row) {
    if (empty($row->source) || empty($row->redirect)) {
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
    $row->source = trim($row->source, '/');
    if ($redirect = redirect_load_by_source($row->source)) {
      $row->migrate_map_destid1 = $redirect->rid;
    }
  }

  /**
   * Implements prepare().
   */
  public function prepare($redirect, $row) {
    $redirect;
  }

  /**
   * {@inheritdoc}
   */
  public function complete($redirect, $row) {
  }

  /**
   * {@inheritdoc}
   */
  public function postImport() {
  }

  /**
   * Implements createStub().
   */
  protected function createStub($migration, $source_key = NULL) {
    return FALSE;
  }

}
