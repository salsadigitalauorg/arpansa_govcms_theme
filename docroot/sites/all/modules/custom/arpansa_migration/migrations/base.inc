<?php

/**
 * @file
 * base.inc
 */

/**
 * Class ArpansaMigrationBase.
 */
abstract class ArpansaMigrationBase extends Migration {
  /**
   * Helper.
   *
   * @var ArpansaMigrationHelper
   */
  protected $helper;

  /**
   * {@inheritdoc}
   */
  public function __construct(array $arguments = array()) {
    parent::__construct($arguments);
    module_load_include('inc', 'arpansa_migration', 'includes/helper');
    $this->helper = new ArpansaMigrationHelper();
  }

}
