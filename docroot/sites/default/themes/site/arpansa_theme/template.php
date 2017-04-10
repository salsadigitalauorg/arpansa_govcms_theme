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
      'content' => 'width=device-width, initial-scale=1',
    ),
  );
  // IE Latest Browser.
  $head_elements['ie_view'] = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'http-equiv' => 'x-ua-compatible',
      'content' => 'ie=edge',
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
    'scope' => 'header',
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
    $path = 'node/' . $variables['element']['#object']->field_reference[LANGUAGE_NONE][0]['target_id'];
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
    // Remove "Hide Social Links" field if checked,
    // or replace with rendered block content.
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

  if ($form_id === 'views_exposed_form') {
    /** @var \view $view */
    $view = $form_state['view'];
    switch ($view->name) {
      // Only show terms tagged in Fact Sheet pages [ARPANSA-78].
      case 'fact_sheets_filterable':
        $tags = _arpansa_theme_get_page_type_tags('Fact Sheet');
        if (count($tags)) {
          $form['field_tags_tid']['#options'] = array('All' => '- Any -') + $tags;
        }
        break;

      // Only show terms tagged in Literature Surveys [ARPANSA-114].
      case 'literature_surveys':
        $tags = _arpansa_theme_get_page_type_tags('', 'literature_survey');
        if (count($tags)) {
          $form['field_tags_tid']['#options'] = array('All' => '- Any -') + $tags;
        }
        break;
    }

  }
}

/**
 * Retrieve a subset of terms tagged in nodes with a particular Page Type.
 *
 * @param string $page_type
 *   Page Type.
 * @param string $node_type
 *   Node Type, always take precedent on page type.
 *
 * @return array
 *   Tags.
 */
function _arpansa_theme_get_page_type_tags($page_type, $node_type = NULL) {
  if ($page_type || $node_type) {
    $type = $node_type ?: $page_type;
    $cid = 'arpansa_theme:tags:' . drupal_html_id($type);
    if ($cache = cache_get($cid)) {
      return $cache->data;
    }

    $tags = [];
    $vocabulary_tags = taxonomy_vocabulary_machine_name_load('tags');
    if ($vocabulary_tags) {
      if (!$node_type) {
        if ($vocabulary_page_type = taxonomy_vocabulary_machine_name_load('page_type')) {
          $entityQuery = new EntityFieldQuery();
          $page_type_terms = $entityQuery->entityCondition('entity_type', 'taxonomy_term')
            ->propertyCondition('vid', $vocabulary_page_type->vid)
            ->propertyCondition('name', $page_type)
            ->range(0, 1)
            ->execute();
          if (!empty($page_type_terms['taxonomy_term']) && count($page_type_terms['taxonomy_term'])) {
            $page_type_term = reset($page_type_terms['taxonomy_term']);
          }
        }
      }
      if ($node_type || !empty($page_type_term)) {
        /** @var \SelectQuery $query */
        $query = db_select('taxonomy_term_data', 'term')
          ->distinct()
          ->fields('term', array('tid', 'name'));
        $query->join('taxonomy_index', 'term_index', 'term_index.tid = term.tid');
        $query->join('node', 'n', 'n.nid = term_index.nid');
        if ($node_type) {
          $query->condition('n.type', $node_type);
        }
        elseif (!empty($page_type_term)) {
          $query->join('field_data_field_page_type', 'page_type', 'page_type.entity_id = n.nid AND page_type.revision_id = n.vid');
          $query->condition('page_type.field_page_type_tid', $page_type_term->tid);
        }
        $query->condition('term.vid', $vocabulary_tags->vid);
        $query->orderBy('term.name', 'ASC');
        $results = $query->execute();
        if ($results->rowCount()) {
          foreach ($results as $result) {
            $tags[$result->tid] = $result->name;
          }

          cache_set($cid, $tags, 'cache', REQUEST_TIME + 1800);
          return $tags;
        }
      }
    }
  }

  return [];
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

  $accessible_vars = array(
    'text' => $variables['text'],
    'active' => FALSE,
  );
  $accessible_markup = theme('facetapi_accessible_markup', $accessible_vars);

  // Sanitizes the link text if necessary.
  $sanitize = empty($variables['options']['html']);
  $variables['text'] = ($sanitize) ? check_plain($variables['text']) : $variables['text'];

  // Adds count to link if one was passed.
  if (isset($variables['count'])) {
    $variables['text'] .= ' ' . theme('facetapi_count', $variables);
  }

  // Resets link text, sets to options to HTML since we already sanitized the
  // link text and are providing additional markup for accessibility.
  $variables['text'] .= $accessible_markup;
  $variables['options']['html'] = TRUE;
  return theme('link', $variables);
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

  // Sanitizes the link text if necessary.
  $sanitize = empty($variables['options']['html']);
  $link_text = ($sanitize) ? check_plain($variables['text']) : $variables['text'];

  // Theme function variables fro accessible markup.
  // @see http://drupal.org/node/1316580
  $accessible_vars = array(
    'text' => $variables['text'],
    'active' => TRUE,
  );

  // Builds link, passes through t() which gives us the ability to change the
  // position of the widget on a per-language basis.
  $replacements = array(
    '!facetapi_deactivate_widget' => theme('facetapi_deactivate_widget', $variables),
    '!facetapi_accessible_markup' => theme('facetapi_accessible_markup', $accessible_vars),
  );
  $variables['text'] = t('!facetapi_deactivate_widget !facetapi_accessible_markup', $replacements);
  $variables['options']['html'] = TRUE;
  return theme('link', $variables) . $link_text;
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

/**
 * Implements template_preprocess_page().
 */
function arpansa_theme_preprocess_page(&$variables) {
  $variables['current_abs_url'] = url(current_path(), array('absolute' => TRUE, 'query' => drupal_get_query_parameters()));
}

/**
 * Implements hook_search_api_query_alter().
 *
 * @see hook_search_api_query_alter()
 */
function arpansa_theme_search_api_query_alter(SearchApiQueryInterface $query) {
  if ($query->getIndex()->machine_name == 'site_search_index') {
    // Exclude unpublished nodes from search results [ARPANSA-109].
    $file_filter = $query->createFilter('AND');
    $file_filter->condition('item_type', 'file');

    $node_filter = $query->createFilter('AND');
    $node_filter->condition('item_type', 'node');
    $node_filter->condition('node:status', TRUE);

    $filter = $query->createFilter('OR');
    $filter->filter($file_filter);
    $filter->filter($node_filter);

    $query->filter($filter);
  }
}
