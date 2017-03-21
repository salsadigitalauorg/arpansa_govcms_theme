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
      'metatag_config_default' => 'metatag_config_default',
    ),
  );
}

/**
 * Implements hook_defaultconfig_metatag_config_default().
 */
function arpansa_entity_defaultconfig_metatag_config_default() {
  $export = array();

  $config = new stdClass();
  $config->disabled = FALSE; /* Edit this to true to make a default config disabled initially */
  $config->api_version = 1;
  $config->instance = 'global';
  $config->config = array(
    'AGLSTERMS.act' => array(
      'item' => array(
        'value' => '',
        'scheme' => '',
        'lang' => '',
        'dir' => '0',
      ),
    ),
    'AGLSTERMS.aggregationLevel' => array(
      'item' => array(
        'value' => '',
        'scheme' => '',
        'lang' => '',
        'dir' => '0',
      ),
    ),
    'AGLSTERMS.availability' => array(
      'item' => array(
        'value' => '',
        'scheme' => '',
        'lang' => '',
        'dir' => '0',
      ),
    ),
    'AGLSTERMS.case' => array(
      'item' => array(
        'value' => '',
        'scheme' => '',
        'lang' => '',
        'dir' => '0',
      ),
    ),
    'AGLSTERMS.category' => array(
      'item' => array(
        'value' => '',
        'scheme' => '',
        'lang' => '',
        'dir' => '0',
      ),
    ),
    'AGLSTERMS.dateLicenced' => array(
      'item' => array(
        'value' => '',
        'scheme' => '',
        'lang' => '',
        'dir' => '0',
      ),
    ),
    'AGLSTERMS.documentType' => array(
      'item' => array(
        'value' => '',
        'scheme' => '',
        'lang' => '',
        'dir' => '0',
      ),
    ),
    'AGLSTERMS.function' => array(
      'item' => array(
        'value' => '',
        'scheme' => '',
        'lang' => '',
        'dir' => '0',
      ),
    ),
    'AGLSTERMS.isBasisFor' => array(
      'item' => array(
        'value' => '',
        'scheme' => '',
        'lang' => '',
        'dir' => '0',
      ),
    ),
    'AGLSTERMS.isBasedOn' => array(
      'item' => array(
        'value' => '',
        'scheme' => '',
        'lang' => '',
        'dir' => '0',
      ),
    ),
    'AGLSTERMS.jurisdiction' => array(
      'item' => array(
        'value' => '',
        'scheme' => '',
        'lang' => '',
        'dir' => '0',
      ),
    ),
    'AGLSTERMS.mandate' => array(
      'item' => array(
        'value' => '',
        'scheme' => '',
        'lang' => '',
        'dir' => '0',
      ),
    ),
    'AGLSTERMS.protectiveMarking' => array(
      'item' => array(
        'value' => '',
        'scheme' => '',
        'lang' => '',
        'dir' => '0',
      ),
    ),
    'AGLSTERMS.regulation' => array(
      'item' => array(
        'value' => '',
        'scheme' => '',
        'lang' => '',
        'dir' => '0',
      ),
    ),
    'AGLSTERMS.serviceType' => array(
      'item' => array(
        'value' => '',
        'scheme' => '',
        'lang' => '',
        'dir' => '0',
      ),
    ),
    'title' => array(
      'value' => '[current-page:title] | [current-page:pager][site:name]',
    ),
    'description' => array(
      'value' => '',
    ),
    'abstract' => array(
      'value' => '',
    ),
    'keywords' => array(
      'value' => '',
    ),
    'robots' => array(
      'value' => array(
        'index' => 0,
        'follow' => 0,
        'noindex' => 0,
        'nofollow' => 0,
        'noarchive' => 0,
        'nosnippet' => 0,
        'noodp' => 0,
        'noydir' => 0,
        'noimageindex' => 0,
        'notranslate' => 0,
      ),
    ),
    'news_keywords' => array(
      'value' => '',
    ),
    'standout' => array(
      'value' => '',
    ),
    'rating' => array(
      'value' => '',
    ),
    'referrer' => array(
      'value' => '',
    ),
    'generator' => array(
      'value' => 'Drupal 7 (http://drupal.org) + govCMS (http://govcms.gov.au)',
    ),
    'rights' => array(
      'value' => '',
    ),
    'image_src' => array(
      'value' => '',
    ),
    'canonical' => array(
      'value' => '[current-page:url:absolute]',
    ),
    'shortlink' => array(
      'value' => '[current-page:url:unaliased]',
    ),
    'publisher' => array(
      'value' => '',
    ),
    'author' => array(
      'value' => '',
    ),
    'original-source' => array(
      'value' => '',
    ),
    'prev' => array(
      'value' => '',
    ),
    'next' => array(
      'value' => '',
    ),
    'content-language' => array(
      'value' => '',
    ),
    'geo.position' => array(
      'value' => '',
    ),
    'geo.placename' => array(
      'value' => '',
    ),
    'geo.region' => array(
      'value' => '',
    ),
    'icbm' => array(
      'value' => '',
    ),
    'refresh' => array(
      'value' => '',
    ),
    'revisit-after' => array(
      'value' => '',
      'period' => '',
    ),
    'pragma' => array(
      'value' => '',
    ),
    'cache-control' => array(
      'value' => '',
    ),
    'expires' => array(
      'value' => '',
    ),
    'dcterms.title' => array(
      'item' => array(
        'value' => '[current-page:title]',
        'scheme' => '',
        'lang' => '',
        'dir' => '0',
      ),
    ),
    'dcterms.creator' => array(
      'item' => array(
        'value' => '[site:name]',
        'scheme' => '',
        'lang' => '',
        'dir' => '0',
      ),
    ),
    'dcterms.subject' => array(
      'item' => array(
        'value' => '[site:slogan]',
        'scheme' => '',
        'lang' => '',
        'dir' => '0',
      ),
    ),
    'dcterms.description' => array(
      'item' => array(
        'value' => '[site:slogan]',
        'scheme' => '',
        'lang' => '',
        'dir' => '0',
      ),
    ),
    'dcterms.publisher' => array(
      'item' => array(
        'value' => '[site:name]',
        'scheme' => '',
        'lang' => '',
        'dir' => '0',
      ),
    ),
    'dcterms.contributor' => array(
      'item' => array(
        'value' => '',
        'scheme' => '',
        'lang' => '',
        'dir' => '0',
      ),
    ),
    'dcterms.date' => array(
      'item' => array(
        'value' => '[current-date:custom:Y-m-d\\TH:iP]',
        'scheme' => '',
        'lang' => '',
        'dir' => '0',
      ),
    ),
    'dcterms.type' => array(
      'item' => array(
        'value' => 'other',
        'scheme' => '',
        'lang' => '',
        'dir' => '0',
      ),
    ),
    'dcterms.format' => array(
      'item' => array(
        'value' => 'text/html',
        'scheme' => '',
        'lang' => '',
        'dir' => '0',
      ),
    ),
    'dcterms.identifier' => array(
      'item' => array(
        'value' => '[current-page:url:absolute]',
        'scheme' => '',
        'lang' => '',
        'dir' => '0',
      ),
    ),
    'dcterms.source' => array(
      'item' => array(
        'value' => '',
        'scheme' => '',
        'lang' => '',
        'dir' => '0',
      ),
    ),
    'dcterms.language' => array(
      'item' => array(
        'value' => 'en',
        'scheme' => '',
        'lang' => '',
        'dir' => '0',
      ),
    ),
    'dcterms.relation' => array(
      'item' => array(
        'value' => '',
        'scheme' => '',
        'lang' => '',
        'dir' => '0',
      ),
    ),
    'dcterms.coverage' => array(
      'item' => array(
        'value' => '',
        'scheme' => '',
        'lang' => '',
        'dir' => '0',
      ),
    ),
    'dcterms.rights' => array(
      'item' => array(
        'value' => '',
        'scheme' => '',
        'lang' => '',
        'dir' => '0',
      ),
    ),
    'og:site_name' => array(
      'value' => '[site:name]',
    ),
    'og:type' => array(
      'value' => 'article',
    ),
    'og:url' => array(
      'value' => '[current-page:url:absolute]',
    ),
    'og:title' => array(
      'value' => '[current-page:title]',
    ),
    'og:determiner' => array(
      'value' => '',
    ),
    'og:description' => array(
      'value' => '',
    ),
    'og:updated_time' => array(
      'value' => '',
    ),
    'og:see_also' => array(
      'value' => '',
    ),
    'og:image' => array(
      'value' => '',
    ),
    'og:image:url' => array(
      'value' => '',
    ),
    'og:image:secure_url' => array(
      'value' => '',
    ),
    'og:image:type' => array(
      'value' => '',
    ),
    'og:image:width' => array(
      'value' => '',
    ),
    'og:image:height' => array(
      'value' => '',
    ),
    'og:latitude' => array(
      'value' => '',
    ),
    'og:longitude' => array(
      'value' => '',
    ),
    'og:street_address' => array(
      'value' => '',
    ),
    'og:locality' => array(
      'value' => '',
    ),
    'og:region' => array(
      'value' => '',
    ),
    'og:postal_code' => array(
      'value' => '',
    ),
    'og:country_name' => array(
      'value' => '',
    ),
    'og:email' => array(
      'value' => '',
    ),
    'og:phone_number' => array(
      'value' => '',
    ),
    'og:fax_number' => array(
      'value' => '',
    ),
    'og:locale' => array(
      'value' => '',
    ),
    'og:locale:alternate' => array(
      'value' => '',
    ),
    'article:author' => array(
      'value' => '',
    ),
    'article:publisher' => array(
      'value' => '',
    ),
    'article:section' => array(
      'value' => '',
    ),
    'article:tag' => array(
      'value' => '',
    ),
    'article:published_time' => array(
      'value' => '',
    ),
    'article:modified_time' => array(
      'value' => '',
    ),
    'article:expiration_time' => array(
      'value' => '',
    ),
    'profile:first_name' => array(
      'value' => '',
    ),
    'profile:last_name' => array(
      'value' => '',
    ),
    'profile:username' => array(
      'value' => '',
    ),
    'profile:gender' => array(
      'value' => '',
    ),
    'og:audio' => array(
      'value' => '',
    ),
    'og:audio:secure_url' => array(
      'value' => '',
    ),
    'og:audio:type' => array(
      'value' => '',
    ),
    'book:author' => array(
      'value' => '',
    ),
    'book:isbn' => array(
      'value' => '',
    ),
    'book:release_date' => array(
      'value' => '',
    ),
    'book:tag' => array(
      'value' => '',
    ),
    'og:video:url' => array(
      'value' => '',
    ),
    'og:video:secure_url' => array(
      'value' => '',
    ),
    'og:video:width' => array(
      'value' => '',
    ),
    'og:video:height' => array(
      'value' => '',
    ),
    'og:video:type' => array(
      'value' => '',
    ),
    'video:actor' => array(
      'value' => '',
    ),
    'video:actor:role' => array(
      'value' => '',
    ),
    'video:director' => array(
      'value' => '',
    ),
    'video:writer' => array(
      'value' => '',
    ),
    'video:duration' => array(
      'value' => '',
    ),
    'video:release_date' => array(
      'value' => '',
    ),
    'video:tag' => array(
      'value' => '',
    ),
    'video:series' => array(
      'value' => '',
    ),
  );
  $export['global'] = $config;

  $config = new stdClass();
  $config->disabled = FALSE; /* Edit this to true to make a default config disabled initially */
  $config->api_version = 1;
  $config->instance = 'node';
  $config->config = array(
    'AGLSTERMS.act' => array(
      'item' => array(
        'value' => '',
        'scheme' => '',
        'lang' => '',
        'dir' => '0',
      ),
    ),
    'AGLSTERMS.aggregationLevel' => array(
      'item' => array(
        'value' => '',
        'scheme' => '',
        'lang' => '',
        'dir' => '0',
      ),
    ),
    'AGLSTERMS.availability' => array(
      'item' => array(
        'value' => '',
        'scheme' => '',
        'lang' => '',
        'dir' => '0',
      ),
    ),
    'AGLSTERMS.case' => array(
      'item' => array(
        'value' => '',
        'scheme' => '',
        'lang' => '',
        'dir' => '0',
      ),
    ),
    'AGLSTERMS.category' => array(
      'item' => array(
        'value' => '',
        'scheme' => '',
        'lang' => '',
        'dir' => '0',
      ),
    ),
    'AGLSTERMS.dateLicenced' => array(
      'item' => array(
        'value' => '',
        'scheme' => '',
        'lang' => '',
        'dir' => '0',
      ),
    ),
    'AGLSTERMS.documentType' => array(
      'item' => array(
        'value' => '',
        'scheme' => '',
        'lang' => '',
        'dir' => '0',
      ),
    ),
    'AGLSTERMS.function' => array(
      'item' => array(
        'value' => '',
        'scheme' => '',
        'lang' => '',
        'dir' => '0',
      ),
    ),
    'AGLSTERMS.isBasisFor' => array(
      'item' => array(
        'value' => '',
        'scheme' => '',
        'lang' => '',
        'dir' => '0',
      ),
    ),
    'AGLSTERMS.isBasedOn' => array(
      'item' => array(
        'value' => '',
        'scheme' => '',
        'lang' => '',
        'dir' => '0',
      ),
    ),
    'AGLSTERMS.jurisdiction' => array(
      'item' => array(
        'value' => '',
        'scheme' => '',
        'lang' => '',
        'dir' => '0',
      ),
    ),
    'AGLSTERMS.mandate' => array(
      'item' => array(
        'value' => '',
        'scheme' => '',
        'lang' => '',
        'dir' => '0',
      ),
    ),
    'AGLSTERMS.protectiveMarking' => array(
      'item' => array(
        'value' => '',
        'scheme' => '',
        'lang' => '',
        'dir' => '0',
      ),
    ),
    'AGLSTERMS.regulation' => array(
      'item' => array(
        'value' => '',
        'scheme' => '',
        'lang' => '',
        'dir' => '0',
      ),
    ),
    'AGLSTERMS.serviceType' => array(
      'item' => array(
        'value' => '',
        'scheme' => '',
        'lang' => '',
        'dir' => '0',
      ),
    ),
    'title' => array(
      'value' => '[node:title] | [current-page:pager][site:name]',
    ),
    'description' => array(
      'value' => '[node:summary]',
    ),
    'robots' => array(
      'value' => array(
        'index' => 0,
        'follow' => 0,
        'noindex' => 0,
        'nofollow' => 0,
        'noarchive' => 0,
        'nosnippet' => 0,
        'noodp' => 0,
        'noydir' => 0,
        'noimageindex' => 0,
        'notranslate' => 0,
      ),
    ),
    'dcterms.title' => array(
      'item' => array(
        'value' => '[node:title]',
        'scheme' => '',
        'lang' => '',
        'dir' => '0',
      ),
    ),
    'dcterms.creator' => array(
      'item' => array(
        'value' => '[node:author]',
        'scheme' => '',
        'lang' => '',
        'dir' => '0',
      ),
    ),
    'dcterms.subject' => array(
      'item' => array(
        'scheme' => '',
        'lang' => '',
        'dir' => '0',
      ),
    ),
    'dcterms.description' => array(
      'item' => array(
        'value' => '[node:summary]',
        'scheme' => '',
        'lang' => '',
        'dir' => '0',
      ),
    ),
    'dcterms.publisher' => array(
      'item' => array(
        'scheme' => '',
        'lang' => '',
        'dir' => '0',
      ),
    ),
    'dcterms.contributor' => array(
      'item' => array(
        'value' => '',
        'scheme' => '',
        'lang' => '',
        'dir' => '0',
      ),
    ),
    'dcterms.date' => array(
      'item' => array(
        'value' => '[node:created:custom:Y-m-d\\TH:iP]',
        'scheme' => '',
        'lang' => '',
        'dir' => '0',
      ),
    ),
    'dcterms.type' => array(
      'item' => array(
        'value' => 'Text',
        'scheme' => '',
        'lang' => '',
        'dir' => '0',
      ),
    ),
    'dcterms.format' => array(
      'item' => array(
        'scheme' => '',
        'lang' => '',
        'dir' => '0',
      ),
    ),
    'dcterms.identifier' => array(
      'item' => array(
        'scheme' => '',
        'lang' => '',
        'dir' => '0',
      ),
    ),
    'dcterms.source' => array(
      'item' => array(
        'value' => '',
        'scheme' => '',
        'lang' => '',
        'dir' => '0',
      ),
    ),
    'dcterms.language' => array(
      'item' => array(
        'scheme' => '',
        'lang' => '',
        'dir' => '0',
      ),
    ),
    'dcterms.relation' => array(
      'item' => array(
        'value' => '',
        'scheme' => '',
        'lang' => '',
        'dir' => '0',
      ),
    ),
    'dcterms.coverage' => array(
      'item' => array(
        'value' => '',
        'scheme' => '',
        'lang' => '',
        'dir' => '0',
      ),
    ),
    'dcterms.rights' => array(
      'item' => array(
        'value' => '',
        'scheme' => '',
        'lang' => '',
        'dir' => '0',
      ),
    ),
    'og:title' => array(
      'value' => '[node:title]',
    ),
    'og:description' => array(
      'value' => '[node:summary]',
    ),
    'og:updated_time' => array(
      'value' => '[node:changed:custom:c]',
    ),
    'og:image:url' => array(
      'value' => '[node:field_image]',
    ),
    'article:published_time' => array(
      'value' => '[node:created:custom:c]',
    ),
    'article:modified_time' => array(
      'value' => '[node:changed:custom:c]',
    ),
  );
  $export['node'] = $config;

  return $export;
}
