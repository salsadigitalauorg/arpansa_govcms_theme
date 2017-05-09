<?php
/**
 * @file
 * govcms_consultation.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function govcms_consultation_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|consultation|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'consultation';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'arpansa_public_submissions' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'formal_submission_form' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'progress_bar' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'show_title' => 0,
        'title_wrapper' => '',
        'ctools' => 'a:3:{s:4:"conf";a:10:{s:5:"label";s:6:"hidden";s:9:"formatter";s:12:"date_default";s:11:"delta_limit";i:0;s:12:"delta_offset";s:1:"0";s:14:"delta_reversed";b:0;s:18:"formatter_settings";a:5:{s:11:"format_type";s:4:"long";s:15:"multiple_number";s:0:"";s:13:"multiple_from";s:0:"";s:11:"multiple_to";s:0:"";s:6:"fromto";s:4:"both";}s:7:"context";s:25:"argument_entity_id:node_1";s:14:"override_title";i:0;s:19:"override_title_text";s:0:"";s:22:"override_title_heading";s:2:"h2";}s:4:"type";s:12:"entity_field";s:7:"subtype";s:28:"node:field_consultation_date";}',
        'load_terms' => 0,
      ),
    ),
    'comments' => array(
      'weight' => '9',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|consultation|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|consultation|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'consultation';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
      ),
    ),
  );
  $export['node|consultation|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function govcms_consultation_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|consultation|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'consultation';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_consultation_summary',
        1 => 'field_page_type',
        2 => 'group_consultation_htabs',
        3 => 'group_formal_submissions',
        4 => 'field_consultation_date',
        5 => 'progress_bar',
        6 => 'arpansa_public_submissions',
        7 => 'field_consultation_issue_text',
        8 => 'field_formal_submission_cta_1',
        9 => 'field_issue_documentation',
        10 => 'formal_submission_form',
        11 => 'field_updates',
        12 => 'field_twitter_discussion',
        13 => 'field_discussion_forum_heading',
        14 => 'field_formal_submission_cta_2',
        15 => 'field_discussion_forum_intro',
        16 => 'group_issue',
        17 => 'comments',
        18 => 'group_updates',
        19 => 'field_show_related_content',
        20 => 'group_outcomes',
        21 => 'field_social_links',
        22 => 'field_outcomes_text',
      ),
    ),
    'fields' => array(
      'field_consultation_summary' => 'ds_content',
      'field_page_type' => 'ds_content',
      'group_consultation_htabs' => 'ds_content',
      'group_formal_submissions' => 'ds_content',
      'field_consultation_date' => 'ds_content',
      'progress_bar' => 'ds_content',
      'arpansa_public_submissions' => 'ds_content',
      'field_consultation_issue_text' => 'ds_content',
      'field_formal_submission_cta_1' => 'ds_content',
      'field_issue_documentation' => 'ds_content',
      'formal_submission_form' => 'ds_content',
      'field_updates' => 'ds_content',
      'field_twitter_discussion' => 'ds_content',
      'field_discussion_forum_heading' => 'ds_content',
      'field_formal_submission_cta_2' => 'ds_content',
      'field_discussion_forum_intro' => 'ds_content',
      'group_issue' => 'ds_content',
      'comments' => 'ds_content',
      'group_updates' => 'ds_content',
      'field_show_related_content' => 'ds_content',
      'group_outcomes' => 'ds_content',
      'field_social_links' => 'ds_content',
      'field_outcomes_text' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|consultation|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'taxonomy_term|update_type|default';
  $ds_layout->entity_type = 'taxonomy_term';
  $ds_layout->bundle = 'update_type';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_pbundle_image',
      ),
    ),
    'fields' => array(
      'field_pbundle_image' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
  );
  $export['taxonomy_term|update_type|default'] = $ds_layout;

  return $export;
}
