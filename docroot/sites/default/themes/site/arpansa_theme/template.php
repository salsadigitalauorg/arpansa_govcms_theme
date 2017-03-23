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
  $javascript['misc/jquery.js']['data'] = drupal_get_path('theme', 'arpansa_theme') . '/vendor/jquery/jquery-3.1.1.min.js';
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
  // Rewrite the Promotions links to include the query string for Lit Surveys
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
  if ($variables['view_mode'] === 'teaser' || $variables['view_mode'] === 'compact') {
    // Apply thumbnail class to node teaser view if image exists.
    $has_thumb = !empty($variables['content']['field_thumbnail']);
    $has_image = !empty($variables['content']['field_image']);
    $has_featured_image = !empty($variables['content']['field_feature_image']);
    if ($has_thumb || $has_image || $has_featured_image) {
      $variables['classes_array'][] = 'has-thumbnail';
    }

    if ($variables['type'] === 'career') {
      $variables['title'] = null;
      $variables['content']['field_position_number'][0]['#markup'] = '<a href="' . $variables['node_url'] . '">' . $variables['content']['field_position_number'][0]['#markup'] . '</a>';
    }
  }

  if ($variables['type'] === 'webform') {
    // Hide submitted date on webforms.
    $variables['display_submitted'] = FALSE;
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
