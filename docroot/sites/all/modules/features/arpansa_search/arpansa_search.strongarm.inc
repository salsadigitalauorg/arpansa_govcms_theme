<?php
/**
 * @file
 * arpansa_search.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function arpansa_search_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'facetapi:block_cache:search_api@site_search_index';
  $strongarm->value = -1;
  $export['facetapi:block_cache:search_api@site_search_index'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search_api_facets_search_ids';
  $strongarm->value = array(
    'site_search_index' => array(
      'search_api_page:search' => 'search_api_page:search',
    ),
  );
  $export['search_api_facets_search_ids'] = $strongarm;

  return $export;
}
