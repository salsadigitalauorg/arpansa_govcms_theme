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
      1 => 'landing_page',
      2 => 'news_article',
      3 => 'page',
      4 => 'webform',
    ),
    'pages' => 'whats-new
have-your-say',
    'roles' => array(),
    'themes' => array(
      'arpansa_theme' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'arpansa_theme',
        'weight' => -33,
      ),
    ),
    'title' => 'In this section',
    'visibility' => 0,
  );

  $export['views-careers-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'careers-block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'about-us/careers',
    'roles' => array(),
    'themes' => array(
      'arpansa_theme' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'arpansa_theme',
        'weight' => -30,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['views-fact_sheets_filterable-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'fact_sheets_filterable-block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'understanding-radiation/radiation-sources/more-radiation-sources',
    'roles' => array(),
    'themes' => array(
      'arpansa_theme' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'arpansa_theme',
        'weight' => -28,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['views-latest_news-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'latest_news-block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'arpansa_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'arpansa_theme',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-latest_news-block_1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'latest_news-block_1',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'arpansa_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'arpansa_theme',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-literature_surveys-lit_survey'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'literature_surveys-lit_survey',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'research/surveys/electromagnetic-radiation-literature-survey',
    'roles' => array(),
    'themes' => array(
      'arpansa_theme' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'arpansa_theme',
        'weight' => -29,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['views-submissions-block_1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'submissions-block_1',
    'module' => 'views',
    'node_types' => array(
      0 => 'consultation',
    ),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'arpansa_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'arpansa_theme',
        'weight' => -24,
      ),
    ),
    'title' => 'The following formal submissions have been made public.',
    'visibility' => 0,
  );

  $export['views-what_s_new-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'what_s_new-block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'whats-new',
    'roles' => array(),
    'themes' => array(
      'arpansa_theme' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'arpansa_theme',
        'weight' => -26,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['views-what_s_new_search_api-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'what_s_new_search_api-block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'whats-new',
    'roles' => array(),
    'themes' => array(
      'arpansa_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'arpansa_theme',
        'weight' => -28,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  return $export;
}