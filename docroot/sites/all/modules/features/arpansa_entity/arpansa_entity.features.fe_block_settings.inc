<?php
/**
 * @file
 * arpansa_entity.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function arpansa_entity_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['menu_block-left_nav'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'left_nav',
    'module' => 'menu_block',
    'node_types' => array(
      0 => 'event',
      1 => 'news_article',
      2 => 'page',
      3 => 'webform',
    ),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'arpansa_theme' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'arpansa_theme',
        'weight' => -33,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['views-literature_surveys-lit_survey'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'literature_surveys-lit_survey',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'arpansa-radiation-protection/arpansa-emr-literature-survey',
    'roles' => array(),
    'themes' => array(
      'arpansa_theme' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'arpansa_theme',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  return $export;
}
