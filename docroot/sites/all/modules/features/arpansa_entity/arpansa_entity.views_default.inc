<?php
/**
 * @file
 * arpansa_entity.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function arpansa_entity_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'careers';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Careers';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Careers';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'career' => 'career',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['careers'] = $view;

  $view = new view();
  $view->name = 'homepage_what_s_new';
  $view->description = 'Returns 3 items from standard page, news page, consultations page with \'Promoted to front page\' selected.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Homepage What\'s New';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'What\'s New';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<div class="more-link">
  <a href="#">View more</a>
</div>';
  $handler->display->display_options['footer']['area']['format'] = 'rich_text';
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Content: Date of Publication (field_news_date) */
  $handler->display->display_options['sorts']['field_news_date_value']['id'] = 'field_news_date_value';
  $handler->display->display_options['sorts']['field_news_date_value']['table'] = 'field_data_field_news_date';
  $handler->display->display_options['sorts']['field_news_date_value']['field'] = 'field_news_date_value';
  $handler->display->display_options['sorts']['field_news_date_value']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'consultation' => 'consultation',
    'news_article' => 'news_article',
    'page' => 'page',
  );
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['display_description'] = 'Homepage What\'s New';
  $export['homepage_what_s_new'] = $view;

  $view = new view();
  $view->name = 'literature_surveys';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Literature Surveys';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Literature Surveys';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'compact';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no results for this search.';
  $handler->display->display_options['empty']['area']['format'] = 'rich_text';
  /* Relationship: Content: Literature Survey Date (field_literature_survey_date) */
  $handler->display->display_options['relationships']['field_literature_survey_date_tid']['id'] = 'field_literature_survey_date_tid';
  $handler->display->display_options['relationships']['field_literature_survey_date_tid']['table'] = 'field_data_field_literature_survey_date';
  $handler->display->display_options['relationships']['field_literature_survey_date_tid']['field'] = 'field_literature_survey_date_tid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Authored By */
  $handler->display->display_options['fields']['field_authored_by']['id'] = 'field_authored_by';
  $handler->display->display_options['fields']['field_authored_by']['table'] = 'field_data_field_authored_by';
  $handler->display->display_options['fields']['field_authored_by']['field'] = 'field_authored_by';
  /* Field: Content: Published In */
  $handler->display->display_options['fields']['field_published_in']['id'] = 'field_published_in';
  $handler->display->display_options['fields']['field_published_in']['table'] = 'field_data_field_published_in';
  $handler->display->display_options['fields']['field_published_in']['field'] = 'field_published_in';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Summary';
  /* Field: Field: Link to */
  $handler->display->display_options['fields']['field_link_to']['id'] = 'field_link_to';
  $handler->display->display_options['fields']['field_link_to']['table'] = 'field_data_field_link_to';
  $handler->display->display_options['fields']['field_link_to']['field'] = 'field_link_to';
  $handler->display->display_options['fields']['field_link_to']['label'] = 'Link';
  $handler->display->display_options['fields']['field_link_to']['click_sort_column'] = 'url';
  /* Field: Content: Commentary by ARPANSA */
  $handler->display->display_options['fields']['field_commentary']['id'] = 'field_commentary';
  $handler->display->display_options['fields']['field_commentary']['table'] = 'field_data_field_commentary';
  $handler->display->display_options['fields']['field_commentary']['field'] = 'field_commentary';
  /* Field: Content: Commentary by ARPANSA */
  $handler->display->display_options['fields']['field_commentary_1']['id'] = 'field_commentary_1';
  $handler->display->display_options['fields']['field_commentary_1']['table'] = 'field_data_field_commentary';
  $handler->display->display_options['fields']['field_commentary_1']['field'] = 'field_commentary';
  $handler->display->display_options['fields']['field_commentary_1']['label'] = '';
  $handler->display->display_options['fields']['field_commentary_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_commentary_1']['alter']['text'] = '1';
  $handler->display->display_options['fields']['field_commentary_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_commentary_1']['empty'] = '0';
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['relationship'] = 'field_literature_survey_date_tid';
  $handler->display->display_options['sorts']['weight']['order'] = 'DESC';
  /* Sort criterion: Content: Commentary by ARPANSA (field_commentary:format) */
  $handler->display->display_options['sorts']['field_commentary_format']['id'] = 'field_commentary_format';
  $handler->display->display_options['sorts']['field_commentary_format']['table'] = 'field_data_field_commentary';
  $handler->display->display_options['sorts']['field_commentary_format']['field'] = 'field_commentary_format';
  $handler->display->display_options['sorts']['field_commentary_format']['order'] = 'DESC';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'literature_survey' => 'literature_survey',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    16 => 0,
    21 => 0,
    26 => 0,
    31 => 0,
    11 => 0,
  );
  /* Filter criterion: Content: Literature Survey Date (field_literature_survey_date) */
  $handler->display->display_options['filters']['field_literature_survey_date_tid']['id'] = 'field_literature_survey_date_tid';
  $handler->display->display_options['filters']['field_literature_survey_date_tid']['table'] = 'field_data_field_literature_survey_date';
  $handler->display->display_options['filters']['field_literature_survey_date_tid']['field'] = 'field_literature_survey_date_tid';
  $handler->display->display_options['filters']['field_literature_survey_date_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_literature_survey_date_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_literature_survey_date_tid']['expose']['operator_id'] = 'field_literature_survey_date_tid_op';
  $handler->display->display_options['filters']['field_literature_survey_date_tid']['expose']['label'] = 'Literature Survey Date';
  $handler->display->display_options['filters']['field_literature_survey_date_tid']['expose']['operator'] = 'field_literature_survey_date_tid_op';
  $handler->display->display_options['filters']['field_literature_survey_date_tid']['expose']['identifier'] = 'field_literature_survey_date_tid';
  $handler->display->display_options['filters']['field_literature_survey_date_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    16 => 0,
    21 => 0,
    26 => 0,
    31 => 0,
    11 => 0,
  );
  $handler->display->display_options['filters']['field_literature_survey_date_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_literature_survey_date_tid']['vocabulary'] = 'literature_survey_date';
  /* Filter criterion: Content: Tags (field_tags) */
  $handler->display->display_options['filters']['field_tags_tid']['id'] = 'field_tags_tid';
  $handler->display->display_options['filters']['field_tags_tid']['table'] = 'field_data_field_tags';
  $handler->display->display_options['filters']['field_tags_tid']['field'] = 'field_tags_tid';
  $handler->display->display_options['filters']['field_tags_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_tags_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_tags_tid']['expose']['operator_id'] = 'field_tags_tid_op';
  $handler->display->display_options['filters']['field_tags_tid']['expose']['label'] = 'Tags';
  $handler->display->display_options['filters']['field_tags_tid']['expose']['operator'] = 'field_tags_tid_op';
  $handler->display->display_options['filters']['field_tags_tid']['expose']['identifier'] = 'field_tags_tid';
  $handler->display->display_options['filters']['field_tags_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_tags_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    16 => 0,
    21 => 0,
    26 => 0,
    31 => 0,
    11 => 0,
  );
  $handler->display->display_options['filters']['field_tags_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_tags_tid']['vocabulary'] = 'tags';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'lit_survey');
  $handler->display->display_options['block_description'] = 'View: Literature Surveys';
  $export['literature_surveys'] = $view;

  $view = new view();
  $view->name = 'what_s_new_search_api';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_what_s_new_index';
  $view->human_name = 'What\'s New Search API';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'What\'s New';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  /* Field: Indexed Content: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_what_s_new_index';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Sort criterion: Indexed Content: Date of Publication */
  $handler->display->display_options['sorts']['field_news_date']['id'] = 'field_news_date';
  $handler->display->display_options['sorts']['field_news_date']['table'] = 'search_api_index_what_s_new_index';
  $handler->display->display_options['sorts']['field_news_date']['field'] = 'field_news_date';
  $handler->display->display_options['sorts']['field_news_date']['order'] = 'DESC';
  /* Filter criterion: Indexed Content: Date of Publication */
  $handler->display->display_options['filters']['field_news_date']['id'] = 'field_news_date';
  $handler->display->display_options['filters']['field_news_date']['table'] = 'search_api_index_what_s_new_index';
  $handler->display->display_options['filters']['field_news_date']['field'] = 'field_news_date';
  $handler->display->display_options['filters']['field_news_date']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_news_date']['expose']['operator_id'] = 'field_news_date_op';
  $handler->display->display_options['filters']['field_news_date']['expose']['label'] = 'Date of Publication';
  $handler->display->display_options['filters']['field_news_date']['expose']['operator'] = 'field_news_date_op';
  $handler->display->display_options['filters']['field_news_date']['expose']['identifier'] = 'field_news_date';
  $handler->display->display_options['filters']['field_news_date']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    16 => 0,
    11 => 0,
    21 => 0,
    26 => 0,
    31 => 0,
    36 => 0,
  );
  $handler->display->display_options['filters']['field_news_date']['widget_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_news_date']['date_popup_format'] = 'd/m/Y';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['what_s_new_search_api'] = $view;

  return $export;
}
