<?php
/**
 * @file
 * arpansa_entity.features.defaultconfig.inc
 */

/**
 * Implements hook_defaultconfig_features().
 */
function arpansa_entity_defaultconfig_features() {
  return array(
    'arpansa_entity' => array(
      'strongarm' => 'strongarm',
    ),
  );
}

/**
 * Implements hook_defaultconfig_strongarm().
 */
function arpansa_entity_defaultconfig_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_progress_bar';
  $strongarm->value = 'j M Y - H:i';
  $export['date_format_progress_bar'] = $strongarm;

  return $export;
}
