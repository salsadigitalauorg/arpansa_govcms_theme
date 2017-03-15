<?php
/**
 * @file
 * govcms_front.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function govcms_front_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'front_page';
  $page->task = 'page';
  $page->admin_title = 'Front Page';
  $page->admin_description = 'Provides a front page for govCMS.';
  $page->path = 'front';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_front_page_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'front_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'main' => NULL,
      'left' => NULL,
      'right' => NULL,
      'sidebar' => NULL,
      'footer' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Welcome to govCMS';
  $display->uuid = '018af563-e806-4469-95a0-52e841018e36';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_front_page_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-5cbb73df-cce4-4826-9a8e-c9fd0fb2f08d';
  $pane->panel = 'middle';
  $pane->type = 'bean_panels';
  $pane->subtype = 'bean_panels';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'default',
    'bean_delta' => 'about-us',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '5cbb73df-cce4-4826-9a8e-c9fd0fb2f08d';
  $display->content['new-5cbb73df-cce4-4826-9a8e-c9fd0fb2f08d'] = $pane;
  $display->panels['middle'][0] = 'new-5cbb73df-cce4-4826-9a8e-c9fd0fb2f08d';
  $pane = new stdClass();
  $pane->pid = 'new-d796ee66-a849-4c89-bf7a-c8984107266b';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'footer_teaser';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '3',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'block',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'd796ee66-a849-4c89-bf7a-c8984107266b';
  $display->content['new-d796ee66-a849-4c89-bf7a-c8984107266b'] = $pane;
  $display->panels['middle'][1] = 'new-d796ee66-a849-4c89-bf7a-c8984107266b';
  $pane = new stdClass();
  $pane->pid = 'new-0597f166-20f3-4190-a3c4-8a27fa0fff5e';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'latest_news';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '5',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'block_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '0597f166-20f3-4190-a3c4-8a27fa0fff5e';
  $display->content['new-0597f166-20f3-4190-a3c4-8a27fa0fff5e'] = $pane;
  $display->panels['middle'][2] = 'new-0597f166-20f3-4190-a3c4-8a27fa0fff5e';
  $pane = new stdClass();
  $pane->pid = 'new-8cc0befe-9bd0-4b34-b5e2-737fca161c71';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'homepage_what_s_new';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '3',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'block',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '8cc0befe-9bd0-4b34-b5e2-737fca161c71';
  $display->content['new-8cc0befe-9bd0-4b34-b5e2-737fca161c71'] = $pane;
  $display->panels['middle'][3] = 'new-8cc0befe-9bd0-4b34-b5e2-737fca161c71';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['front_page'] = $page;

  return $pages;

}
