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
   * {@inheritdoc}
   */
  public function __construct(array $arguments = array()) {
    parent::__construct($arguments);
    module_load_include('inc', 'arpansa_migration', 'includes/helper');
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
    $value = variable_get('arpansa_migration_' . str_replace('-', '_', $option), $default);
    if (drupal_is_cli() && function_exists('drush_get_option')) {
      $value = drush_get_option($option, $value);
    }
    return $value;
  }

}
