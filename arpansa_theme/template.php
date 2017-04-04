<?php

/**
 * @file
 * template.php
 */

/**
 * Implements hook_html_head_alter().
 */
function arpansa_theme_html_head_alter(&$head_elements) {
  // Mobile Viewport.
  $head_elements['viewport'] = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'name' => 'viewport',
      'content' => 'width=device-width, initial-scale=1'
    ),
  );
  // IE Latest Browser.
  $head_elements['ie_view'] = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'http-equiv' => 'x-ua-compatible',
      'content' => 'ie=edge'
    ),
  );
}

/**
 * Implements hook_js_alter().
 */
function arpansa_theme_js_alter(&$javascript) {
  $javascript['misc/jquery.js']['data'] = drupal_get_path('theme', 'arpansa_theme') . '/vendor/jquery/jquery-2.2.4.min.js';
}

/**
 * Implements hook_preprocess_html().
 */
function arpansa_theme_preprocess_html(&$variables) {
  drupal_add_js("(function(h) {h.className = h.className.replace('no-js', '') })(document.documentElement);", array(
    'type' => 'inline',
    'scope' => 'header'
  ));
  drupal_add_js('jQuery.extend(Drupal.settings, { "pathToTheme": "' . path_to_theme() . '" });', 'inline');
  // Drupal forms.js does not support new jQuery. Migrate library needed.
  drupal_add_js(drupal_get_path('theme', 'arpansa_theme') . '/vendor/jquery/jquery-migrate-1.2.1.min.js');
}

/**
 * Implements hook_preprocess_field().
 */
function arpansa_theme_preprocess_field(&$variables) {
  // Bean 'Image and Text' field 'Link To' to show 'Read [title]' text.
  if ($variables['element']['#field_name'] === 'field_link_to' && $variables['element']['#bundle'] === 'image_and_text') {
    if (!empty($variables['items'][0]) && !empty($variables['element']['#object']->title)) {
      // This only applies if field has a non-configurable title.
      if ($variables['items'][0]['#field']['settings']['title'] === 'none') {
        $variables['items'][0]['#element']['title'] = t('Read !title', array('!title' => $variables['element']['#object']->title));
      }
    }
  }
  // Rewrite the Promotions links to include the query string for Lit Surveys.
  if ($variables['element']['#bundle'] === 'footer_teaser' && $variables['element']['#view_mode'] == 'teaser') {
    $path = 'node/' . $variables['element']['#object']->field_reference['und'][0]['target_id'];
    if (isset($variables['element']['#object']->field_literature_survey_date[LANGUAGE_NONE])) {
      $query = array(
        'field_literature_survey_date_tid' => $variables['element']['#object']->field_literature_survey_date[LANGUAGE_NONE][0]['tid'],
      );
    }
    if ($variables['element']['#field_name'] === 'field_image') {
      $variables['items'][0]['#path']['path'] = $path;
      if (isset($variables['items'][0]['#path']) && !empty($query)) {
        $variables['items'][0]['#path']['options']['query'] = $query;
      }
    }
    elseif ($variables['element']['#field_name'] === 'title') {
      $pattern = "/(?<=href=(\"|'))[^\"']+(?=(\"|'))/";
      if (!empty($query)) {
        $path = url($path, array('query' => $query));
      }
      else {
        $path = url($path);
      }
      $markup = preg_replace($pattern, $path, $variables['items'][0]['#markup']);

      $variables['items'][0]['#markup'] = $markup;
    }
  }
}

/**
 * Implements hook_preprocess_node().
 */
function arpansa_theme_preprocess_node(&$variables) {
  $whats_new_content_types = array('consultation', 'news_article', 'page');
  if ($variables['view_mode'] === 'teaser' || $variables['view_mode'] === 'compact') {
    // Apply thumbnail class to node teaser view if image exists.
    $has_thumb = !empty($variables['content']['field_thumbnail']);
    $has_image = !empty($variables['content']['field_image']);
    $has_featured_image = !empty($variables['content']['field_feature_image']);
    if ($has_thumb || $has_image || $has_featured_image) {
      $variables['classes_array'][] = 'has-thumbnail';
    }

    if ($variables['type'] === 'career') {
      $variables['title'] = NULL;
      $variables['content']['field_position_number'][0]['#markup'] = '<a href="' . $variables['node_url'] . '">' . $variables['content']['field_position_number'][0]['#markup'] . '</a>';
    }
  }

  if ($variables['view_mode'] === 'full') {
    // Remove "Hide Social Links" field if checked, or replace with rendered block content.
    $hide_social_links = !empty($variables['node']->field_social_links[LANGUAGE_NONE][0]['value']) ? (int) $variables['node']->field_social_links[LANGUAGE_NONE][0]['value'] : 0;
    if ($hide_social_links === 1 || !in_array($variables['type'], $whats_new_content_types)) {
      $variables['content']['field_social_links'] = NULL;
    }
    else {
      $block = block_load('service_links', 'service_links');
      $block_content = _block_get_renderable_array(_block_render_blocks(array($block)));
      $output = drupal_render($block_content);
      $variables['content']['field_social_links'][0]['#markup'] = $output;
    }

    $show_related_content = !empty($variables['field_show_related_content'][0]['value']) ? (int) $variables['field_show_related_content'][0]['value'] : 0;
    if ($show_related_content === 1) {
      $block = block_load('views', 'related_content-block');
      $block_content = _block_get_renderable_array(_block_render_blocks(array($block)));
      $output = drupal_render($block_content);
      $variables['content']['field_show_related_content'][0]['#markup'] = $output;
    }
    else {
      $variables['content']['field_show_related_content'] = NULL;
    }
  }

  if ($variables['type'] === 'webform') {
    // Hide submitted date on webforms.
    $variables['display_submitted'] = FALSE;
  }

  if (($variables['view_mode'] === 'teaser') && ($variables['type'] === 'footer_teaser')) {
    $variables['footer_teaser_path'] = url('node/' . $variables['content']['field_image']['#object']->field_reference[LANGUAGE_NONE]['0']['target_id']);
  }
  if ($variables['view_mode'] === 'teaser') {
    if ($variables['type'] == 'news_article' || $variables['type'] == 'consultation' || $variables['type'] == 'page') {
      $variables['date'] = date('d F Y', $variables['created']);
      $variables['content']['links']['node']['#links']['node-readmore']['attributes']['class'][] = 'button';
    }
    $variables['theme_hook_suggestions'][] = $variables['theme_hook_suggestions'][0] . '__teaser';
  }
  elseif ($variables['view_mode'] === 'full') {
    if ($variables['type'] == 'slide') {
      $variables['content']['field_read_more'][0]['#element']['attributes']['class'] = 'button';
    }
  }
}

/**
 * Implements theme_breadcrumb().
 */
function arpansa_theme_breadcrumb($variables) {
  $breadcrumb = $variables['breadcrumb'];
  $output = '';

  if (!empty($breadcrumb)) {
    // Build the breadcrumb trail.
    $output = '<nav class="breadcrumbs--inverted" role="navigation" aria-label="breadcrumb">';
    $output .= '<ul><li>' . implode('</li><li>', $breadcrumb) . '</li></ul>';
    $output .= '</nav>';
  }

  return $output;
}

/**
 * Implements hook_form_alter().
 */
function arpansa_theme_form_alter(&$form, &$form_state, $form_id) {
  if ($form_id === 'search_api_page_search_form_default_search') {
    // Global header form.
    $form['keys_1']['#attributes']['placeholder'] = t('Type search term here');
    $form['keys_1']['#title'] = t('Search field');
  }
  elseif ($form_id === 'search_api_page_search_form') {
    // Search page (above results) form.
    $form['form']['keys_1']['#title'] = t('Type search term here');
  }
  if ($form_id === 'search_form') {
    // Search form on page not found (404 page).
    $form['basic']['keys']['#title'] = t('Type search term here');
  }
  // ARPANSA-78: Only show tags already assigned Fact Sheets on the Fact Sheets view.
  if ($form_id === 'views_exposed_form' && strpos($form['#id'], 'fact-sheets') !== FALSE) {
    // Use "Raw SQL Query" mode because it's faster than the Drupal dynamic query.
    $fact_sheet_tags = get_fact_sheet_assigned_tags();

    if (count($fact_sheet_tags)) {
      $form['field_tags_tid']['#options'] = array('All' => '- Any -') + $fact_sheet_tags;
    }
  }
}

/**
 * Helper function to extract distinct set of tags already assigned to Fact Sheet content items.
 *
 * @param bool $raw_query
 *   Boolean to indicate which query method to use.
 *
 * @return array
 *   An array of tag IDs => tag Names.
 */
function get_fact_sheet_assigned_tags($raw_query = FALSE) {
  $tags = array();

  // Obtain vocabulary ID (vid) via its machine name.
  $vocabulary = taxonomy_vocabulary_machine_name_load('tags');

  if (!empty($vocabulary->vid)) {
    // "Raw" db_query(...) mode seems faster than dynamic Drupal query builder.
    if ($raw_query === TRUE) {
      $fact_sheet_tags = db_query("
        SELECT DISTINCT ttd.tid, ttd.name
        FROM taxonomy_term_data ttd
        JOIN taxonomy_index ti ON ti.tid = ttd.tid
        JOIN node n ON n.nid = ti.nid AND n.type = 'page' AND n.`status` = 1
        JOIN field_data_field_page_type pt ON pt.entity_id = n.nid AND pt.revision_id = n.vid
        JOIN taxonomy_term_data ttd_2 ON ttd_2.tid = pt.field_page_type_tid AND ttd_2.name = 'Fact Sheet'
        WHERE ttd.vid = " . (int) $vocabulary->vid . "
        ORDER BY ttd.`name`
      ");
    }
    else {
      $query = db_select('taxonomy_term_data', 'ttd')
        ->distinct()
        ->fields('ttd', array('tid', 'name'))
        ->condition('ttd.vid', (int) $vocabulary->vid, '=')
        ->orderBy('ttd.`name`');
      $query->join('taxonomy_index', 'ti', 'ti.tid = ttd.tid');
      $query->join('node', 'n', "n.nid = ti.nid AND n.type = 'page' AND n.`status` = 1");
      $query->join('field_data_field_page_type', 'pt', 'pt.entity_id = n.nid AND pt.revision_id = n.vid');
      $query->join('taxonomy_term_data', 'ttd_2', "ttd_2.tid = pt.field_page_type_tid AND ttd_2.name = 'Fact Sheet'");

      $fact_sheet_tags = $query->execute();
    }

    if (count($fact_sheet_tags)) {
      foreach ($fact_sheet_tags as $tag) {
        $tags[$tag->tid] = $tag->name;
      }
    }
  }

  return $tags;
}

/**
 * Implements theme_preprocess_search_api_page_result().
 */
function arpansa_theme_preprocess_search_api_page_result(&$variables) {
  // Strip out HTML tags from search results.
  $variables['snippet'] = strip_tags($variables['snippet']);
  // Remove the author / date from the result display.
  $variables['info'] = '';
}

/**
 * Implements theme_preprocess_search_result().
 */
function arpansa_theme_preprocess_search_result(&$variables) {
  // Strip out HTML tags from search results (404 page).
  $variables['snippet'] = strip_tags($variables['snippet']);
  // Remove the author / date from the result display (404 page).
  $variables['info'] = '';
}

/**
 * Implements template_preprocess_block().
 */
function arpansa_theme_preprocess_block(&$variables) {
  if ($variables['block_html_id'] == 'block-menu-block-landing-page-children-listing') {
    $child_content = array();
    foreach ($variables['elements']['#content'] as $key => $content) {
      if (is_numeric($key)) {
        if ($node = node_load(str_replace('node/', '', $content['#href']))) {
          $child_content[] = node_view($node, 'teaser');
        }
      }
    }
    $variables['children_contents'] = $child_content;
  }
}

/**
 * Implements theme_facetapi_link_inactive().
 *
 * @see theme_facetapi_link_inactive()
 */
function arpansa_theme_facetapi_link_inactive($variables) {
  $text = &$variables['text'];
  if (strpos($text, '/') !== FALSE) {
    $text = _arpansa_theme_get_file_type($text);
  }

  return theme_facetapi_link_inactive($variables);
}

/**
 * Implements theme_facetapi_link_active().
 *
 * @see theme_facetapi_link_active()
 */
function arpansa_theme_facetapi_link_active($variables) {
  $text = &$variables['text'];
  if (strpos($text, '/') !== FALSE) {
    $text = _arpansa_theme_get_file_type($text);
  }

  return theme_facetapi_link_active($variables);
}

/**
 * Get file extension from MIME type.
 *
 * @param string $mime_type
 *   File MIME type.
 *
 * @return string
 *   Extension.
 */
function _arpansa_theme_get_file_type($mime_type) {
  include_once DRUPAL_ROOT . '/includes/file.mimetypes.inc';
  $mapping = file_mimetype_mapping();
  if ($index = array_search($mime_type, $mapping['mimetypes'])) {
    if ($extension = array_search($index, $mapping['extensions'])) {
      return strtoupper($extension);
    }

    $text = explode('/', $mime_type);
    if (count($text) > 1) {
      array_shift($text);
      return implode('/', $text);
    }
  }

  return $mime_type;
}

/**
 * Implements template_preprocess_views_view_row_rss().
 *
 * @see template_preprocess_views_view_row_rss()
 */
function arpansa_theme_preprocess_views_view_row_rss(&$variables) {
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
 * Implements template_preprocess_region().
 */
function arpansa_theme_preprocess_region(&$variables) {
  if ($variables['region'] == 'content') {
    $variables['page_title'] = drupal_get_title();
  }
}
