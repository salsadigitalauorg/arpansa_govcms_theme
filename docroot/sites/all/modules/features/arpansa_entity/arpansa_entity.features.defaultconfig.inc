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
    'title' => array(
      'value' => '[current-page:title] | [current-page:pager][site:name]',
    ),
    'generator' => array(
      'value' => 'Drupal 7 (http://drupal.org) + govCMS (http://govcms.gov.au)',
    ),
    'canonical' => array(
      'value' => '[current-page:url:absolute]',
    ),
    'shortlink' => array(
      'value' => '[current-page:url:unaliased]',
    ),
    'dcterms.title' => array(
      'item' => array(
        'value' => '[current-page:title]',
      ),
    ),
    'dcterms.identifier' => array(
      'item' => array(
        'value' => '[current-page:url:absolute]',
      ),
    ),
    'dcterms.type' => array(
      'item' => array(
        'value' => 'other',
      ),
    ),
    'dcterms.format' => array(
      'item' => array(
        'value' => 'text/html',
      ),
    ),
    'og:site_name' => array(
      'value' => '[site:name]',
    ),
    'og:title' => array(
      'value' => '[current-page:title]',
    ),
    'og:type' => array(
      'value' => 'article',
    ),
    'og:url' => array(
      'value' => '[current-page:url:absolute]',
    ),
    'dcterms.creator' => array(
      'item' => array(
        'value' => '[site:name]',
      ),
    ),
    'dcterms.date' => array(
      'item' => array(
        'value' => '[current-date:custom:Y-m-d\\TH:iP]',
      ),
    ),
    'dcterms.description' => array(
      'item' => array(
        'value' => '[site:slogan]',
      ),
    ),
    'dcterms.language' => array(
      'item' => array(
        'value' => 'en',
      ),
    ),
    'dcterms.publisher' => array(
      'item' => array(
        'value' => '[site:name]',
      ),
    ),
    'dcterms.subject' => array(
      'item' => array(
        'value' => '[site:slogan]',
      ),
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
    'og:image' => array(
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
