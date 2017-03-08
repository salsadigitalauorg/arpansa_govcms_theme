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

  /**
   * Get environment option, either from Drush command or Config variables.
   *
   * @param string $option
   *   Option name.
   * @param mixed $default
   *   Default value.
   *
   * @return mixed
   *   Option value.
   */
  protected static function getEnvOption($option, $default = NULL) {
    if (drupal_is_cli() && function_exists('drush_get_option')) {
      return drush_get_option($option, $default);
    }
    return variable_get('arpansa_migration_' . str_replace('-', '_', $option), $default);
  }

}
