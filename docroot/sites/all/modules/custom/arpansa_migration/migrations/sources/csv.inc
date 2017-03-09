<?php

/**
 * @file
 * csv.inc
 */

/**
 * Class ArpansaMigrationCSV.
 */
class ArpansaMigrationCSV extends MigrateSourceCSV {

  /**
   * {@inheritdoc}
   */
  public function __construct($path, array $csvcolumns = array(), array $options = array(), array $fields = array()) {
    $this->file = '';
    if (!empty($path) && file_exists($path)) {
      parent::__construct($path, $csvcolumns, $options, $fields);
    }
  }

  /**
   * {@inheritdoc}
   */
  public function getNextRow() {
    do {
      $row = parent::getNextRow();

      // Give the active migration a chance to validate a CSV row.
      if (method_exists($this->activeMigration, 'validateRow')) {
        if ($this->activeMigration->validateRow($row)) {
          return $row;
        }
        // If a row is invalid, it is skipped entirely without a mapping.
        $row = NULL;
      }

      return $row;
    }
    while (!$row);
  }

  /**
   * {@inheritdoc}
   */
  public function computeCount() {
    if (empty($this->file) || !file_exists($this->file)) {
      return t('N/A');
    }

    return parent::computeCount();
  }

}
