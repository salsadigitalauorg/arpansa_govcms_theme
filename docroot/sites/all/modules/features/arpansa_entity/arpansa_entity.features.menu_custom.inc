<?php
/**
 * @file
 * arpansa_entity.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function arpansa_entity_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-footer-menu.
  $menus['menu-footer-menu'] = array(
    'menu_name' => 'menu-footer-menu',
    'title' => 'Footer Menu',
    'description' => 'The 2 Level menu appearing above the Footer Sub Menu in the site footer.',
  );
  // Exported menu: menu-top-header-menu.
  $menus['menu-top-header-menu'] = array(
    'menu_name' => 'menu-top-header-menu',
    'title' => 'Top Header Menu',
    'description' => 'The menu sitting at the top right of the page, above Search.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Footer Menu');
  t('The 2 Level menu appearing above the Footer Sub Menu in the site footer.');
  t('The menu sitting at the top right of the page, above Search.');
  t('Top Header Menu');

  return $menus;
}
