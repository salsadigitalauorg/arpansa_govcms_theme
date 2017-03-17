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

  $export['facetapi-TT4kRhy7ZZSdHZ05fmUoffihxyvKPxlT'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'TT4kRhy7ZZSdHZ05fmUoffihxyvKPxlT',
    'module' => 'facetapi',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'arpansa_theme' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'arpansa_theme',
        'weight' => 0,
      ),
    ),
    'title' => 'Document type',
    'visibility' => 0,
  );

  $export['facetapi-e1vziaDdlbhFZQEviU3C14vhjRBDGLsB'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'e1vziaDdlbhFZQEviU3C14vhjRBDGLsB',
    'module' => 'facetapi',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'arpansa_theme' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'arpansa_theme',
        'weight' => 0,
      ),
    ),
    'title' => 'Date published',
    'visibility' => 0,
  );

  $export['facetapi-scWlDoEFH97LuLJzfVAXs3b1iBv5zxfi'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'scWlDoEFH97LuLJzfVAXs3b1iBv5zxfi',
    'module' => 'facetapi',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'arpansa_theme' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'arpansa_theme',
        'weight' => -32,
      ),
    ),
    'title' => 'Tags',
    'visibility' => 0,
  );

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
