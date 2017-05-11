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
  if ($module == "file_entity" && $api == "file_default_displays") {
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
 * Implements hook_fe_date_custom_date_formats().
 */
function arpansa_entity_fe_date_custom_date_formats() {
  $custom_date_formats = array();
  $custom_date_formats['l j F Y - H:i'] = 'l j F Y - H:i';
  return $custom_date_formats;
}

/**
 * Implements hook_date_format_types().
 */
function arpansa_entity_date_format_types() {
  $format_types = array();
  // Exported date format type: consultation_date
  $format_types['consultation_date'] = 'Consultation Date';
  // Exported date format type: progress_bar
  $format_types['progress_bar'] = 'Progress Bar';
  return $format_types;
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
          'width' => 550,
          'height' => 410,
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
    'career' => array(
      'name' => t('Career'),
      'base' => 'node_content',
      'description' => t('Use <em>Careers</em> to present careers details professionally to site visitors per the theme.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
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
    'submissions' => array(
      'name' => t('Submissions'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
