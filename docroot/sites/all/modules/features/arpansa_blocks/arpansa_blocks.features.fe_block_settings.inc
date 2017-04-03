<?php
/**
 * @file
 * arpansa_blocks.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function arpansa_blocks_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['block-arpansa_copyright_footer'] = array(
    'cache' => -1,
    'custom' => 0,
    'machine_name' => 'arpansa_copyright_footer',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'arpansa_theme' => array(
        'region' => 'bottom',
        'status' => 1,
        'theme' => 'arpansa_theme',
        'weight' => -33,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['crumbs-breadcrumb'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'breadcrumb',
    'module' => 'crumbs',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'arpansa_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'arpansa_theme',
        'weight' => -30,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['govcms_social_links-services'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'services',
    'module' => 'govcms_social_links',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'arpansa_theme' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'arpansa_theme',
        'weight' => -28,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['govcms_text_resize-text_resize'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'text_resize',
    'module' => 'govcms_text_resize',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'arpansa_theme' => array(
        'region' => 'header',
        'status' => 1,
        'theme' => 'arpansa_theme',
        'weight' => -31,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['menu-menu-footer-menu'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-footer-menu',
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'arpansa_theme' => array(
        'region' => 'footer',
        'status' => 1,
        'theme' => 'arpansa_theme',
        'weight' => -31,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['menu-menu-footer-sub-menu'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-footer-sub-menu',
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'arpansa_theme' => array(
        'region' => 'bottom',
        'status' => 1,
        'theme' => 'arpansa_theme',
        'weight' => -34,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['menu-menu-quick-links'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-quick-links',
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'arpansa_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'arpansa_theme',
        'weight' => -29,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['menu-menu-top-header-menu'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-top-header-menu',
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'arpansa_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'arpansa_theme',
        'weight' => -4,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['menu_block-govcms_menu_block-footer'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'govcms_menu_block-footer',
    'module' => 'menu_block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'arpansa_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'arpansa_theme',
        'weight' => -30,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['menu_block-govcms_menu_block-main-menu'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'govcms_menu_block-main-menu',
    'module' => 'menu_block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'arpansa_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'arpansa_theme',
        'weight' => -23,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['menu_block-govcms_menu_block-sidebar'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'govcms_menu_block-sidebar',
    'module' => 'menu_block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'arpansa_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'arpansa_theme',
        'weight' => -21,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['menu_block-landing_page_children_listing'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'landing_page_children_listing',
    'module' => 'menu_block',
    'node_types' => array(
      0 => 'landing_page',
    ),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'arpansa_theme' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'arpansa_theme',
        'weight' => -31,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['search-form'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'form',
    'module' => 'search',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'arpansa_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'arpansa_theme',
        'weight' => -15,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['service_links-service_links'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'service_links',
    'module' => 'service_links',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'arpansa_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'arpansa_theme',
        'weight' => -14,
      ),
    ),
    'title' => 'Share this:',
    'visibility' => 0,
  );

  $export['superfish-1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 1,
    'module' => 'superfish',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'arpansa_theme' => array(
        'region' => 'navigation',
        'status' => 1,
        'theme' => 'arpansa_theme',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['system-help'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'help',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'arpansa_theme' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'arpansa_theme',
        'weight' => -34,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-main'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'main',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'arpansa_theme' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'arpansa_theme',
        'weight' => -32,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-main-menu'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'main-menu',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'arpansa_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'arpansa_theme',
        'weight' => -22,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['twitter_block-1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 1,
    'module' => 'twitter_block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'arpansa_theme' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'arpansa_theme',
        'weight' => -29,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['user-login'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'login',
    'module' => 'user',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'arpansa_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'arpansa_theme',
        'weight' => -3,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-footer_teaser-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'footer_teaser-block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'arpansa_theme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'arpansa_theme',
        'weight' => 1,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['views-related_content-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'related_content-block',
    'module' => 'views',
    'node_types' => array(
      0 => 'consultation',
      1 => 'news_article',
      2 => 'page',
    ),
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
    'title' => 'Not what you\'re looking for?',
    'visibility' => 0,
  );

  $export['workbench-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'block',
    'module' => 'workbench',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'arpansa_theme' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'arpansa_theme',
        'weight' => -33,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
