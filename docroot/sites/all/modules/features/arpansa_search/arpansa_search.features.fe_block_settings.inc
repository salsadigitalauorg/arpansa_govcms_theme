<?php
/**
 * @file
 * arpansa_search.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function arpansa_search_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['search_api_page-content_search'] = array(
    'cache' => 5,
    'custom' => 0,
    'delta' => 'content_search',
    'module' => 'search_api_page',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'arpansa_theme' => array(
        'region' => 'header',
        'status' => 1,
        'theme' => 'arpansa_theme',
        'weight' => -30,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  return $export;
}
