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
