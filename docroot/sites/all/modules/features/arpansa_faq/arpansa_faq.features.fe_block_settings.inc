<?php
/**
 * @file
 * arpansa_faq.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function arpansa_faq_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-faq-block_faq'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'faq-block_faq',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'understanding-radiation/radiation-sources/frequently-asked-questions',
    'roles' => array(),
    'themes' => array(
      'arpansa_theme' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'arpansa_theme',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  return $export;
}
