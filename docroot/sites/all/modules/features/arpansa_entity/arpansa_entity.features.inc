<?php
/**
 * @file
 * arpansa_entity.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function arpansa_entity_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function arpansa_entity_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function arpansa_entity_image_default_styles() {
  $styles = array();

  // Exported image style: govcms_ui_kit_banner.
  $styles['govcms_ui_kit_banner'] = array(
    'label' => 'govCMS UI Kit Banner',
    'effects' => array(
      2 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 1650,
          'height' => 440,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: govcms_ui_kit_thumbnail.
  $styles['govcms_ui_kit_thumbnail'] = array(
    'label' => 'govCMS UI Kit Thumbnail',
    'effects' => array(
      3 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 370,
          'height' => 275,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function arpansa_entity_node_info() {
  $items = array(
    'landing_page' => array(
      'name' => t('Landing Page'),
      'base' => 'node_content',
      'description' => t('Use landing pages for site sections such that grouped subsections present professionally to site visitors.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'literature_survey' => array(
      'name' => t('Literature Survey'),
      'base' => 'node_content',
      'description' => t('Published literature includes articles in peer-reviewed journals, scientific-body reports, fact sheets, conference proceedings etc.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
