<?php

/**
 * @file
 * Contains the theme's functions to manipulate Drupal's admin default markup.
 */

/**
 * Implements template_preprocess_views_view_row_rss().
 *
 * @see template_preprocess_views_view_row_rss()
 */
function arpansa_admin_preprocess_views_view_row_rss(&$variables) {
  $view = $variables['view'];
  $row = $variables['row'];
  if ($view->name == 'what_s_new' && $view->current_display == 'feed_whats_new') {
    // Use Consultation Summary for RSS row description [ARPANSA-79].
    $current_result = $view->result[$variables['id'] - 1];
    if (!empty($current_result->field_field_consultation_summary[0]['rendered']['#markup'])) {
      $row->description = strip_tags($current_result->field_field_consultation_summary[0]['rendered']['#markup']);
      $variables['description'] = $row->description;
    }
  }
}

/**
 * Implements hook_media_wysiwyg_token_to_markup_alter().
 *
 * @see media_wysiwyg_token_to_markup()
 */
function arpansa_admin_media_wysiwyg_token_to_markup_alter(&$element, $tag_info, $settings) {
  if (!empty($element['content'])) {
    unset($element['content']['#type']);
    unset($element['content']['#attributes']);
    $element['content']['#file']->media_markup = TRUE;
  }
}

/**
 * Implements template_preprocess_file_entity().
 *
 * @see template_preprocess_file_entity()
 */
function arpansa_admin_preprocess_file_entity(&$variables) {
  if (!empty($variables['media_markup'])) {
    $variables['theme_hook_suggestions'][] = 'file_entity__inline_wysiwyg';
    if (!empty($variables['field_document_title'][LANGUAGE_NONE][0]['value'])) {
      $document_title = $variables['field_document_title'][LANGUAGE_NONE][0]['value'];
      $variables['content']['file']['#file']->description = $document_title;
    }
  }
}

/**
 * Implements hook_entity_view_alter().
 */
function arpansa_admin_entity_view_alter(&$build, $type) {
  if ($type == 'file') {
    unset($build['links']);
  }
}
