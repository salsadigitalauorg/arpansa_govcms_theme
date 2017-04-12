<?php
/**
 * @file
 * govcms_menu.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function govcms_menu_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-quick-links_smartraveller:http://www.smartraveller.gov.au/.
  $menu_links['menu-quick-links_smartraveller:http://www.smartraveller.gov.au/'] = array(
    'menu_name' => 'menu-quick-links',
    'link_path' => 'http://www.smartraveller.gov.au/',
    'router_path' => '',
    'link_title' => 'Smartraveller',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-quick-links_smartraveller:http://www.smartraveller.gov.au/',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Exported menu link: user-menu_site-map-and-feeds:sitemap.
  $menu_links['user-menu_site-map-and-feeds:sitemap'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'sitemap',
    'router_path' => 'sitemap',
    'link_title' => 'Site map and Feeds',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'user-menu_site-map-and-feeds:sitemap',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 0,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Site map and Feeds');
  t('Smartraveller');

  return $menu_links;
}
