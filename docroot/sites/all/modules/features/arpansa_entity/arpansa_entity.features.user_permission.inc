<?php
/**
 * @file
 * arpansa_entity.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function arpansa_entity_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access administration pages'.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access all views'.
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: 'access all webform results'.
  $permissions['access all webform results'] = array(
    'name' => 'access all webform results',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'access bean overview'.
  $permissions['access bean overview'] = array(
    'name' => 'access bean overview',
    'roles' => array(
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'access broken links report'.
  $permissions['access broken links report'] = array(
    'name' => 'access broken links report',
    'roles' => array(
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'linkchecker',
  );

  // Exported permission: 'access comments'.
  $permissions['access comments'] = array(
    'name' => 'access comments',
    'roles' => array(
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access content overview'.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access contextual links'.
  $permissions['access contextual links'] = array(
    'name' => 'access contextual links',
    'roles' => array(
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'contextual',
  );

  // Exported permission: 'access draggableviews'.
  $permissions['access draggableviews'] = array(
    'name' => 'access draggableviews',
    'roles' => array(
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'draggableviews',
  );

  // Exported permission: 'access event log'.
  $permissions['access event log'] = array(
    'name' => 'access event log',
    'roles' => array(
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'event_log',
  );

  // Exported permission: 'access google analytics reports'.
  $permissions['access google analytics reports'] = array(
    'name' => 'access google analytics reports',
    'roles' => array(
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'google_analytics_reports',
  );

  // Exported permission: 'access media browser'.
  $permissions['access media browser'] = array(
    'name' => 'access media browser',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Preview user' => 'Preview user',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'media',
  );

  // Exported permission: 'access own broken links report'.
  $permissions['access own broken links report'] = array(
    'name' => 'access own broken links report',
    'roles' => array(
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'linkchecker',
  );

  // Exported permission: 'access own webform results'.
  $permissions['access own webform results'] = array(
    'name' => 'access own webform results',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'access own webform submissions'.
  $permissions['access own webform submissions'] = array(
    'name' => 'access own webform submissions',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'access rules debug'.
  $permissions['access rules debug'] = array(
    'name' => 'access rules debug',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'access search_api_page'.
  $permissions['access search_api_page'] = array(
    'name' => 'access search_api_page',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'search_api_page',
  );

  // Exported permission: 'access site in maintenance mode'.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access site map'.
  $permissions['access site map'] = array(
    'name' => 'access site map',
    'roles' => array(
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'site_map',
  );

  // Exported permission: 'access site reports'.
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access site-wide contact form'.
  $permissions['access site-wide contact form'] = array(
    'name' => 'access site-wide contact form',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'contact',
  );

  // Exported permission: 'access user contact forms'.
  $permissions['access user contact forms'] = array(
    'name' => 'access user contact forms',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'contact',
  );

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'access workbench'.
  $permissions['access workbench'] = array(
    'name' => 'access workbench',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench',
  );

  // Exported permission: 'add JS snippets for google analytics'.
  $permissions['add JS snippets for google analytics'] = array(
    'name' => 'add JS snippets for google analytics',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'googleanalytics',
  );

  // Exported permission: 'add media from remote sources'.
  $permissions['add media from remote sources'] = array(
    'name' => 'add media from remote sources',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'media_internet',
  );

  // Exported permission: 'admin_display_suite'.
  $permissions['admin_display_suite'] = array(
    'name' => 'admin_display_suite',
    'roles' => array(
      'Site builder' => 'Site builder',
      'administrator' => 'administrator',
    ),
    'module' => 'ds',
  );

  // Exported permission: 'administer actions'.
  $permissions['administer actions'] = array(
    'name' => 'administer actions',
    'roles' => array(
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer advanced pane settings'.
  $permissions['administer advanced pane settings'] = array(
    'name' => 'administer advanced pane settings',
    'roles' => array(
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer bean settings'.
  $permissions['administer bean settings'] = array(
    'name' => 'administer bean settings',
    'roles' => array(
      'Site builder' => 'Site builder',
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'administer bean types'.
  $permissions['administer bean types'] = array(
    'name' => 'administer bean types',
    'roles' => array(
      'Site builder' => 'Site builder',
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'administer beans'.
  $permissions['administer beans'] = array(
    'name' => 'administer beans',
    'roles' => array(
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'administer blocks'.
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'block',
  );

  // Exported permission: 'administer comments'.
  $permissions['administer comments'] = array(
    'name' => 'administer comments',
    'roles' => array(
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'administer contact forms'.
  $permissions['administer contact forms'] = array(
    'name' => 'administer contact forms',
    'roles' => array(
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'contact',
  );

  // Exported permission: 'administer content types'.
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(
      'Site builder' => 'Site builder',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer crumbs'.
  $permissions['administer crumbs'] = array(
    'name' => 'administer crumbs',
    'roles' => array(
      'Site builder' => 'Site builder',
      'administrator' => 'administrator',
    ),
    'module' => 'crumbs',
  );

  // Exported permission: 'administer default config'.
  $permissions['administer default config'] = array(
    'name' => 'administer default config',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'defaultconfig',
  );

  // Exported permission: 'administer features'.
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'administer fields'.
  $permissions['administer fields'] = array(
    'name' => 'administer fields',
    'roles' => array(
      'Site builder' => 'Site builder',
      'administrator' => 'administrator',
    ),
    'module' => 'field',
  );

  // Exported permission: 'administer file types'.
  $permissions['administer file types'] = array(
    'name' => 'administer file types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'administer files'.
  $permissions['administer files'] = array(
    'name' => 'administer files',
    'roles' => array(
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'administer filters'.
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'administer google analytics'.
  $permissions['administer google analytics'] = array(
    'name' => 'administer google analytics',
    'roles' => array(
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'googleanalytics',
  );

  // Exported permission: 'administer google analytics reports api'.
  $permissions['administer google analytics reports api'] = array(
    'name' => 'administer google analytics reports api',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'google_analytics_reports_api',
  );

  // Exported permission: 'administer honeypot'.
  $permissions['administer honeypot'] = array(
    'name' => 'administer honeypot',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'honeypot',
  );

  // Exported permission: 'administer image styles'.
  $permissions['administer image styles'] = array(
    'name' => 'administer image styles',
    'roles' => array(
      'Site builder' => 'Site builder',
      'administrator' => 'administrator',
    ),
    'module' => 'image',
  );

  // Exported permission: 'administer linkchecker'.
  $permissions['administer linkchecker'] = array(
    'name' => 'administer linkchecker',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'linkchecker',
  );

  // Exported permission: 'administer linkit'.
  $permissions['administer linkit'] = array(
    'name' => 'administer linkit',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'linkit',
  );

  // Exported permission: 'administer maintenance mode'.
  $permissions['administer maintenance mode'] = array(
    'name' => 'administer maintenance mode',
    'roles' => array(
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'maintenance_mode_permissions',
  );

  // Exported permission: 'administer managed modules'.
  $permissions['administer managed modules'] = array(
    'name' => 'administer managed modules',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'module_permissions',
  );

  // Exported permission: 'administer managed modules permissions'.
  $permissions['administer managed modules permissions'] = array(
    'name' => 'administer managed modules permissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'module_permissions',
  );

  // Exported permission: 'administer media browser'.
  $permissions['administer media browser'] = array(
    'name' => 'administer media browser',
    'roles' => array(
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'media',
  );

  // Exported permission: 'administer menu'.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'menu',
  );

  // Exported permission: 'administer meta tags'.
  $permissions['administer meta tags'] = array(
    'name' => 'administer meta tags',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'administer module filter'.
  $permissions['administer module filter'] = array(
    'name' => 'administer module filter',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'module_filter',
  );

  // Exported permission: 'administer module permissions'.
  $permissions['administer module permissions'] = array(
    'name' => 'administer module permissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'module_permissions',
  );

  // Exported permission: 'administer modules'.
  $permissions['administer modules'] = array(
    'name' => 'administer modules',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer nodes'.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer page manager'.
  $permissions['administer page manager'] = array(
    'name' => 'administer page manager',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'page_manager',
  );

  // Exported permission: 'administer pane access'.
  $permissions['administer pane access'] = array(
    'name' => 'administer pane access',
    'roles' => array(
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer panels layouts'.
  $permissions['administer panels layouts'] = array(
    'name' => 'administer panels layouts',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer panels styles'.
  $permissions['administer panels styles'] = array(
    'name' => 'administer panels styles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer pathauto'.
  $permissions['administer pathauto'] = array(
    'name' => 'administer pathauto',
    'roles' => array(
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: 'administer permissions'.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer quicktabs'.
  $permissions['administer quicktabs'] = array(
    'name' => 'administer quicktabs',
    'roles' => array(
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'quicktabs',
  );

  // Exported permission: 'administer redirects'.
  $permissions['administer redirects'] = array(
    'name' => 'administer redirects',
    'roles' => array(
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'redirect',
  );

  // Exported permission: 'administer robots.txt'.
  $permissions['administer robots.txt'] = array(
    'name' => 'administer robots.txt',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'robotstxt',
  );

  // Exported permission: 'administer rules'.
  $permissions['administer rules'] = array(
    'name' => 'administer rules',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'administer scheduler'.
  $permissions['administer scheduler'] = array(
    'name' => 'administer scheduler',
    'roles' => array(
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'scheduler',
  );

  // Exported permission: 'administer search'.
  $permissions['administer search'] = array(
    'name' => 'administer search',
    'roles' => array(
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'search',
  );

  // Exported permission: 'administer search_api'.
  $permissions['administer search_api'] = array(
    'name' => 'administer search_api',
    'roles' => array(
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'search_api',
  );

  // Exported permission: 'administer seckit'.
  $permissions['administer seckit'] = array(
    'name' => 'administer seckit',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'seckit',
  );

  // Exported permission: 'administer shield'.
  $permissions['administer shield'] = array(
    'name' => 'administer shield',
    'roles' => array(
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'shield',
  );

  // Exported permission: 'administer shortcuts'.
  $permissions['administer shortcuts'] = array(
    'name' => 'administer shortcuts',
    'roles' => array(
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: 'administer site configuration'.
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer software updates'.
  $permissions['administer software updates'] = array(
    'name' => 'administer software updates',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer superfish'.
  $permissions['administer superfish'] = array(
    'name' => 'administer superfish',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'superfish',
  );

  // Exported permission: 'administer taxonomy'.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'administer theme settings'.
  $permissions['administer theme settings'] = array(
    'name' => 'administer theme settings',
    'roles' => array(
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'govcms_appearance',
  );

  // Exported permission: 'administer themes'.
  $permissions['administer themes'] = array(
    'name' => 'administer themes',
    'roles' => array(
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer twitter block'.
  $permissions['administer twitter block'] = array(
    'name' => 'administer twitter block',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'twitter_block',
  );

  // Exported permission: 'administer url aliases'.
  $permissions['administer url aliases'] = array(
    'name' => 'administer url aliases',
    'roles' => array(
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'path',
  );

  // Exported permission: 'administer userprotect'.
  $permissions['administer userprotect'] = array(
    'name' => 'administer userprotect',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'userprotect',
  );

  // Exported permission: 'administer users'.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer uuid'.
  $permissions['administer uuid'] = array(
    'name' => 'administer uuid',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'uuid',
  );

  // Exported permission: 'administer views'.
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: 'administer workbench'.
  $permissions['administer workbench'] = array(
    'name' => 'administer workbench',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'workbench',
  );

  // Exported permission: 'administer workbench moderation'.
  $permissions['administer workbench moderation'] = array(
    'name' => 'administer workbench moderation',
    'roles' => array(
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'administer xmlsitemap'.
  $permissions['administer xmlsitemap'] = array(
    'name' => 'administer xmlsitemap',
    'roles' => array(
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'xmlsitemap',
  );

  // Exported permission: 'administer_file_lock'.
  $permissions['administer_file_lock'] = array(
    'name' => 'administer_file_lock',
    'roles' => array(
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'file_lock',
  );

  // Exported permission: 'assign Content approver role'.
  $permissions['assign Content approver role'] = array(
    'name' => 'assign Content approver role',
    'roles' => array(
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign Content editor role'.
  $permissions['assign Content editor role'] = array(
    'name' => 'assign Content editor role',
    'roles' => array(
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign Site builder role'.
  $permissions['assign Site builder role'] = array(
    'name' => 'assign Site builder role',
    'roles' => array(
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign Site editor role'.
  $permissions['assign Site editor role'] = array(
    'name' => 'assign Site editor role',
    'roles' => array(
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign all roles'.
  $permissions['assign all roles'] = array(
    'name' => 'assign all roles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'block IP addresses'.
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'bypass access in place editing'.
  $permissions['bypass access in place editing'] = array(
    'name' => 'bypass access in place editing',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'bypass file access'.
  $permissions['bypass file access'] = array(
    'name' => 'bypass file access',
    'roles' => array(
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'bypass honeypot protection'.
  $permissions['bypass honeypot protection'] = array(
    'name' => 'bypass honeypot protection',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'honeypot',
  );

  // Exported permission: 'bypass node access'.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'bypass redirection'.
  $permissions['bypass redirection'] = array(
    'name' => 'bypass redirection',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'field_redirection',
  );

  // Exported permission: 'bypass rules access'.
  $permissions['bypass rules access'] = array(
    'name' => 'bypass rules access',
    'roles' => array(),
    'module' => 'rules',
  );

  // Exported permission: 'bypass workbench moderation'.
  $permissions['bypass workbench moderation'] = array(
    'name' => 'bypass workbench moderation',
    'roles' => array(
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'cancel account'.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'change layouts in place editing'.
  $permissions['change layouts in place editing'] = array(
    'name' => 'change layouts in place editing',
    'roles' => array(
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'change own e-mail'.
  $permissions['change own e-mail'] = array(
    'name' => 'change own e-mail',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'userprotect',
  );

  // Exported permission: 'change own openid'.
  $permissions['change own openid'] = array(
    'name' => 'change own openid',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'userprotect',
  );

  // Exported permission: 'change own password'.
  $permissions['change own password'] = array(
    'name' => 'change own password',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'userprotect',
  );

  // Exported permission: 'change own username'.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'create any basic_content bean'.
  $permissions['create any basic_content bean'] = array(
    'name' => 'create any basic_content bean',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'create any image_and_text bean'.
  $permissions['create any image_and_text bean'] = array(
    'name' => 'create any image_and_text bean',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'create blog_article content'.
  $permissions['create blog_article content'] = array(
    'name' => 'create blog_article content',
    'roles' => array(
      'Site builder' => 'Site builder',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create career content'.
  $permissions['create career content'] = array(
    'name' => 'create career content',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create consultation content'.
  $permissions['create consultation content'] = array(
    'name' => 'create consultation content',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create event content'.
  $permissions['create event content'] = array(
    'name' => 'create event content',
    'roles' => array(
      'Site builder' => 'Site builder',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create files'.
  $permissions['create files'] = array(
    'name' => 'create files',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'create footer_teaser content'.
  $permissions['create footer_teaser content'] = array(
    'name' => 'create footer_teaser content',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create landing_page content'.
  $permissions['create landing_page content'] = array(
    'name' => 'create landing_page content',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create literature_survey content'.
  $permissions['create literature_survey content'] = array(
    'name' => 'create literature_survey content',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create media_release content'.
  $permissions['create media_release content'] = array(
    'name' => 'create media_release content',
    'roles' => array(
      'Site builder' => 'Site builder',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create news_article content'.
  $permissions['create news_article content'] = array(
    'name' => 'create news_article content',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create page content'.
  $permissions['create page content'] = array(
    'name' => 'create page content',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create publication content'.
  $permissions['create publication content'] = array(
    'name' => 'create publication content',
    'roles' => array(
      'Site builder' => 'Site builder',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create slide content'.
  $permissions['create slide content'] = array(
    'name' => 'create slide content',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create url aliases'.
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'path',
  );

  // Exported permission: 'create webform content'.
  $permissions['create webform content'] = array(
    'name' => 'create webform content',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'customize shortcut links'.
  $permissions['customize shortcut links'] = array(
    'name' => 'customize shortcut links',
    'roles' => array(
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: 'delete all webform submissions'.
  $permissions['delete all webform submissions'] = array(
    'name' => 'delete all webform submissions',
    'roles' => array(
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'delete any audio files'.
  $permissions['delete any audio files'] = array(
    'name' => 'delete any audio files',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any basic_content bean'.
  $permissions['delete any basic_content bean'] = array(
    'name' => 'delete any basic_content bean',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'delete any blog_article content'.
  $permissions['delete any blog_article content'] = array(
    'name' => 'delete any blog_article content',
    'roles' => array(
      'Site builder' => 'Site builder',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any career content'.
  $permissions['delete any career content'] = array(
    'name' => 'delete any career content',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any consultation content'.
  $permissions['delete any consultation content'] = array(
    'name' => 'delete any consultation content',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any document files'.
  $permissions['delete any document files'] = array(
    'name' => 'delete any document files',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any event content'.
  $permissions['delete any event content'] = array(
    'name' => 'delete any event content',
    'roles' => array(
      'Site builder' => 'Site builder',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any footer_teaser content'.
  $permissions['delete any footer_teaser content'] = array(
    'name' => 'delete any footer_teaser content',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any image files'.
  $permissions['delete any image files'] = array(
    'name' => 'delete any image files',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any image_and_text bean'.
  $permissions['delete any image_and_text bean'] = array(
    'name' => 'delete any image_and_text bean',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'delete any landing_page content'.
  $permissions['delete any landing_page content'] = array(
    'name' => 'delete any landing_page content',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any literature_survey content'.
  $permissions['delete any literature_survey content'] = array(
    'name' => 'delete any literature_survey content',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any media_release content'.
  $permissions['delete any media_release content'] = array(
    'name' => 'delete any media_release content',
    'roles' => array(
      'Site builder' => 'Site builder',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any news_article content'.
  $permissions['delete any news_article content'] = array(
    'name' => 'delete any news_article content',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any page content'.
  $permissions['delete any page content'] = array(
    'name' => 'delete any page content',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any publication content'.
  $permissions['delete any publication content'] = array(
    'name' => 'delete any publication content',
    'roles' => array(
      'Site builder' => 'Site builder',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any slide content'.
  $permissions['delete any slide content'] = array(
    'name' => 'delete any slide content',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any video files'.
  $permissions['delete any video files'] = array(
    'name' => 'delete any video files',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any webform content'.
  $permissions['delete any webform content'] = array(
    'name' => 'delete any webform content',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own audio files'.
  $permissions['delete own audio files'] = array(
    'name' => 'delete own audio files',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own blog_article content'.
  $permissions['delete own blog_article content'] = array(
    'name' => 'delete own blog_article content',
    'roles' => array(
      'Site builder' => 'Site builder',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own career content'.
  $permissions['delete own career content'] = array(
    'name' => 'delete own career content',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own consultation content'.
  $permissions['delete own consultation content'] = array(
    'name' => 'delete own consultation content',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own document files'.
  $permissions['delete own document files'] = array(
    'name' => 'delete own document files',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own event content'.
  $permissions['delete own event content'] = array(
    'name' => 'delete own event content',
    'roles' => array(
      'Site builder' => 'Site builder',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own footer_teaser content'.
  $permissions['delete own footer_teaser content'] = array(
    'name' => 'delete own footer_teaser content',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own image files'.
  $permissions['delete own image files'] = array(
    'name' => 'delete own image files',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own landing_page content'.
  $permissions['delete own landing_page content'] = array(
    'name' => 'delete own landing_page content',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own literature_survey content'.
  $permissions['delete own literature_survey content'] = array(
    'name' => 'delete own literature_survey content',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own media_release content'.
  $permissions['delete own media_release content'] = array(
    'name' => 'delete own media_release content',
    'roles' => array(
      'Site builder' => 'Site builder',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own news_article content'.
  $permissions['delete own news_article content'] = array(
    'name' => 'delete own news_article content',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own page content'.
  $permissions['delete own page content'] = array(
    'name' => 'delete own page content',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own publication content'.
  $permissions['delete own publication content'] = array(
    'name' => 'delete own publication content',
    'roles' => array(
      'Site builder' => 'Site builder',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own slide content'.
  $permissions['delete own slide content'] = array(
    'name' => 'delete own slide content',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own video files'.
  $permissions['delete own video files'] = array(
    'name' => 'delete own video files',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own webform content'.
  $permissions['delete own webform content'] = array(
    'name' => 'delete own webform content',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own webform submissions'.
  $permissions['delete own webform submissions'] = array(
    'name' => 'delete own webform submissions',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'delete revisions'.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in file_tags'.
  $permissions['delete terms in file_tags'] = array(
    'name' => 'delete terms in file_tags',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in tags'.
  $permissions['delete terms in tags'] = array(
    'name' => 'delete terms in tags',
    'roles' => array(
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'download any audio files'.
  $permissions['download any audio files'] = array(
    'name' => 'download any audio files',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any document files'.
  $permissions['download any document files'] = array(
    'name' => 'download any document files',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any image files'.
  $permissions['download any image files'] = array(
    'name' => 'download any image files',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any video files'.
  $permissions['download any video files'] = array(
    'name' => 'download any video files',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own audio files'.
  $permissions['download own audio files'] = array(
    'name' => 'download own audio files',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own document files'.
  $permissions['download own document files'] = array(
    'name' => 'download own document files',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own image files'.
  $permissions['download own image files'] = array(
    'name' => 'download own image files',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own video files'.
  $permissions['download own video files'] = array(
    'name' => 'download own video files',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit all webform submissions'.
  $permissions['edit all webform submissions'] = array(
    'name' => 'edit all webform submissions',
    'roles' => array(
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'edit any audio files'.
  $permissions['edit any audio files'] = array(
    'name' => 'edit any audio files',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any basic_content bean'.
  $permissions['edit any basic_content bean'] = array(
    'name' => 'edit any basic_content bean',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'edit any blog_article content'.
  $permissions['edit any blog_article content'] = array(
    'name' => 'edit any blog_article content',
    'roles' => array(
      'Site builder' => 'Site builder',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any career content'.
  $permissions['edit any career content'] = array(
    'name' => 'edit any career content',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any consultation content'.
  $permissions['edit any consultation content'] = array(
    'name' => 'edit any consultation content',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any document files'.
  $permissions['edit any document files'] = array(
    'name' => 'edit any document files',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any event content'.
  $permissions['edit any event content'] = array(
    'name' => 'edit any event content',
    'roles' => array(
      'Site builder' => 'Site builder',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any footer_teaser content'.
  $permissions['edit any footer_teaser content'] = array(
    'name' => 'edit any footer_teaser content',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any image files'.
  $permissions['edit any image files'] = array(
    'name' => 'edit any image files',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any image_and_text bean'.
  $permissions['edit any image_and_text bean'] = array(
    'name' => 'edit any image_and_text bean',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'edit any landing_page content'.
  $permissions['edit any landing_page content'] = array(
    'name' => 'edit any landing_page content',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any literature_survey content'.
  $permissions['edit any literature_survey content'] = array(
    'name' => 'edit any literature_survey content',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any media_release content'.
  $permissions['edit any media_release content'] = array(
    'name' => 'edit any media_release content',
    'roles' => array(
      'Site builder' => 'Site builder',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any news_article content'.
  $permissions['edit any news_article content'] = array(
    'name' => 'edit any news_article content',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any page content'.
  $permissions['edit any page content'] = array(
    'name' => 'edit any page content',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any publication content'.
  $permissions['edit any publication content'] = array(
    'name' => 'edit any publication content',
    'roles' => array(
      'Site builder' => 'Site builder',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any slide content'.
  $permissions['edit any slide content'] = array(
    'name' => 'edit any slide content',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any video files'.
  $permissions['edit any video files'] = array(
    'name' => 'edit any video files',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any webform content'.
  $permissions['edit any webform content'] = array(
    'name' => 'edit any webform content',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit bean view mode'.
  $permissions['edit bean view mode'] = array(
    'name' => 'edit bean view mode',
    'roles' => array(
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'edit link settings'.
  $permissions['edit link settings'] = array(
    'name' => 'edit link settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'linkchecker',
  );

  // Exported permission: 'edit meta tags'.
  $permissions['edit meta tags'] = array(
    'name' => 'edit meta tags',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit node machine name'.
  $permissions['edit node machine name'] = array(
    'name' => 'edit node machine name',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'defaultcontent',
  );

  // Exported permission: 'edit own account'.
  $permissions['edit own account'] = array(
    'name' => 'edit own account',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'userprotect',
  );

  // Exported permission: 'edit own audio files'.
  $permissions['edit own audio files'] = array(
    'name' => 'edit own audio files',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own blog_article content'.
  $permissions['edit own blog_article content'] = array(
    'name' => 'edit own blog_article content',
    'roles' => array(
      'Site builder' => 'Site builder',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own career content'.
  $permissions['edit own career content'] = array(
    'name' => 'edit own career content',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own comments'.
  $permissions['edit own comments'] = array(
    'name' => 'edit own comments',
    'roles' => array(
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'edit own consultation content'.
  $permissions['edit own consultation content'] = array(
    'name' => 'edit own consultation content',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own document files'.
  $permissions['edit own document files'] = array(
    'name' => 'edit own document files',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own event content'.
  $permissions['edit own event content'] = array(
    'name' => 'edit own event content',
    'roles' => array(
      'Site builder' => 'Site builder',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own footer_teaser content'.
  $permissions['edit own footer_teaser content'] = array(
    'name' => 'edit own footer_teaser content',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own image files'.
  $permissions['edit own image files'] = array(
    'name' => 'edit own image files',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own landing_page content'.
  $permissions['edit own landing_page content'] = array(
    'name' => 'edit own landing_page content',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own literature_survey content'.
  $permissions['edit own literature_survey content'] = array(
    'name' => 'edit own literature_survey content',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own media_release content'.
  $permissions['edit own media_release content'] = array(
    'name' => 'edit own media_release content',
    'roles' => array(
      'Site builder' => 'Site builder',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own news_article content'.
  $permissions['edit own news_article content'] = array(
    'name' => 'edit own news_article content',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own page content'.
  $permissions['edit own page content'] = array(
    'name' => 'edit own page content',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own publication content'.
  $permissions['edit own publication content'] = array(
    'name' => 'edit own publication content',
    'roles' => array(
      'Site builder' => 'Site builder',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own slide content'.
  $permissions['edit own slide content'] = array(
    'name' => 'edit own slide content',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own video files'.
  $permissions['edit own video files'] = array(
    'name' => 'edit own video files',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own webform content'.
  $permissions['edit own webform content'] = array(
    'name' => 'edit own webform content',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own webform submissions'.
  $permissions['edit own webform submissions'] = array(
    'name' => 'edit own webform submissions',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'edit terms in file_tags'.
  $permissions['edit terms in file_tags'] = array(
    'name' => 'edit terms in file_tags',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in tags'.
  $permissions['edit terms in tags'] = array(
    'name' => 'edit terms in tags',
    'roles' => array(
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit webform components'.
  $permissions['edit webform components'] = array(
    'name' => 'edit webform components',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'generate features'.
  $permissions['generate features'] = array(
    'name' => 'generate features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'manage features'.
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'moderate content from archived to draft'.
  $permissions['moderate content from archived to draft'] = array(
    'name' => 'moderate content from archived to draft',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate content from draft to needs_review'.
  $permissions['moderate content from draft to needs_review'] = array(
    'name' => 'moderate content from draft to needs_review',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate content from needs_review to draft'.
  $permissions['moderate content from needs_review to draft'] = array(
    'name' => 'moderate content from needs_review to draft',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate content from needs_review to published'.
  $permissions['moderate content from needs_review to published'] = array(
    'name' => 'moderate content from needs_review to published',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate content from published to archived'.
  $permissions['moderate content from published to archived'] = array(
    'name' => 'moderate content from published to archived',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'notify of path changes'.
  $permissions['notify of path changes'] = array(
    'name' => 'notify of path changes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: 'opt-in or out of tracking'.
  $permissions['opt-in or out of tracking'] = array(
    'name' => 'opt-in or out of tracking',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'googleanalytics',
  );

  // Exported permission: 'override default scheduler time'.
  $permissions['override default scheduler time'] = array(
    'name' => 'override default scheduler time',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'scheduler_workbench',
  );

  // Exported permission: 'post comments'.
  $permissions['post comments'] = array(
    'name' => 'post comments',
    'roles' => array(
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'rename features'.
  $permissions['rename features'] = array(
    'name' => 'rename features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'revert revisions'.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'schedule (un)publishing of nodes'.
  $permissions['schedule (un)publishing of nodes'] = array(
    'name' => 'schedule (un)publishing of nodes',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'scheduler',
  );

  // Exported permission: 'search content'.
  $permissions['search content'] = array(
    'name' => 'search content',
    'roles' => array(
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'search',
  );

  // Exported permission: 'select account cancellation method'.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'set webform_clear times'.
  $permissions['set webform_clear times'] = array(
    'name' => 'set webform_clear times',
    'roles' => array(
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'webform_clear',
  );

  // Exported permission: 'skip comment approval'.
  $permissions['skip comment approval'] = array(
    'name' => 'skip comment approval',
    'roles' => array(
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'switch shortcut sets'.
  $permissions['switch shortcut sets'] = array(
    'name' => 'switch shortcut sets',
    'roles' => array(
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: 'use PHP for tracking visibility'.
  $permissions['use PHP for tracking visibility'] = array(
    'name' => 'use PHP for tracking visibility',
    'roles' => array(),
    'module' => 'googleanalytics',
  );

  // Exported permission: 'use advanced search'.
  $permissions['use advanced search'] = array(
    'name' => 'use advanced search',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'search',
  );

  // Exported permission: 'use ccl'.
  $permissions['use ccl'] = array(
    'name' => 'use ccl',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ccl',
  );

  // Exported permission: 'use ctools import'.
  $permissions['use ctools import'] = array(
    'name' => 'use ctools import',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ctools',
  );

  // Exported permission: 'use ipe with page manager'.
  $permissions['use ipe with page manager'] = array(
    'name' => 'use ipe with page manager',
    'roles' => array(
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use media wysiwyg'.
  $permissions['use media wysiwyg'] = array(
    'name' => 'use media wysiwyg',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'media_wysiwyg',
  );

  // Exported permission: 'use page manager'.
  $permissions['use page manager'] = array(
    'name' => 'use page manager',
    'roles' => array(
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'page_manager',
  );

  // Exported permission: 'use panels caching features'.
  $permissions['use panels caching features'] = array(
    'name' => 'use panels caching features',
    'roles' => array(
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use panels dashboard'.
  $permissions['use panels dashboard'] = array(
    'name' => 'use panels dashboard',
    'roles' => array(
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use panels in place editing'.
  $permissions['use panels in place editing'] = array(
    'name' => 'use panels in place editing',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use panels locks'.
  $permissions['use panels locks'] = array(
    'name' => 'use panels locks',
    'roles' => array(
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use text format rich_text'.
  $permissions['use text format rich_text'] = array(
    'name' => 'use text format rich_text',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use workbench_moderation my drafts tab'.
  $permissions['use workbench_moderation my drafts tab'] = array(
    'name' => 'use workbench_moderation my drafts tab',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'use workbench_moderation needs review tab'.
  $permissions['use workbench_moderation needs review tab'] = array(
    'name' => 'use workbench_moderation needs review tab',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'view all unpublished content'.
  $permissions['view all unpublished content'] = array(
    'name' => 'view all unpublished content',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Preview user' => 'Preview user',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'view any basic_content bean'.
  $permissions['view any basic_content bean'] = array(
    'name' => 'view any basic_content bean',
    'roles' => array(
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any image_and_text bean'.
  $permissions['view any image_and_text bean'] = array(
    'name' => 'view any image_and_text bean',
    'roles' => array(
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any unpublished blog_article content'.
  $permissions['view any unpublished blog_article content'] = array(
    'name' => 'view any unpublished blog_article content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished career content'.
  $permissions['view any unpublished career content'] = array(
    'name' => 'view any unpublished career content',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Preview user' => 'Preview user',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished consultation content'.
  $permissions['view any unpublished consultation content'] = array(
    'name' => 'view any unpublished consultation content',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Preview user' => 'Preview user',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished content'.
  $permissions['view any unpublished content'] = array(
    'name' => 'view any unpublished content',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Preview user' => 'Preview user',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished event content'.
  $permissions['view any unpublished event content'] = array(
    'name' => 'view any unpublished event content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished footer_teaser content'.
  $permissions['view any unpublished footer_teaser content'] = array(
    'name' => 'view any unpublished footer_teaser content',
    'roles' => array(
      'Preview user' => 'Preview user',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished landing_page content'.
  $permissions['view any unpublished landing_page content'] = array(
    'name' => 'view any unpublished landing_page content',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Preview user' => 'Preview user',
      'Site builder' => 'Site builder',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished literature_survey content'.
  $permissions['view any unpublished literature_survey content'] = array(
    'name' => 'view any unpublished literature_survey content',
    'roles' => array(
      'Preview user' => 'Preview user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished media_release content'.
  $permissions['view any unpublished media_release content'] = array(
    'name' => 'view any unpublished media_release content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished news_article content'.
  $permissions['view any unpublished news_article content'] = array(
    'name' => 'view any unpublished news_article content',
    'roles' => array(
      'Preview user' => 'Preview user',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished page content'.
  $permissions['view any unpublished page content'] = array(
    'name' => 'view any unpublished page content',
    'roles' => array(
      'Preview user' => 'Preview user',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished publication content'.
  $permissions['view any unpublished publication content'] = array(
    'name' => 'view any unpublished publication content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished slide content'.
  $permissions['view any unpublished slide content'] = array(
    'name' => 'view any unpublished slide content',
    'roles' => array(
      'Preview user' => 'Preview user',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished webform content'.
  $permissions['view any unpublished webform content'] = array(
    'name' => 'view any unpublished webform content',
    'roles' => array(
      'Preview user' => 'Preview user',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view bean page'.
  $permissions['view bean page'] = array(
    'name' => 'view bean page',
    'roles' => array(
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view bean revisions'.
  $permissions['view bean revisions'] = array(
    'name' => 'view bean revisions',
    'roles' => array(
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view files'.
  $permissions['view files'] = array(
    'name' => 'view files',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view moderation history'.
  $permissions['view moderation history'] = array(
    'name' => 'view moderation history',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'view moderation messages'.
  $permissions['view moderation messages'] = array(
    'name' => 'view moderation messages',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'view own files'.
  $permissions['view own files'] = array(
    'name' => 'view own files',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view own private files'.
  $permissions['view own private files'] = array(
    'name' => 'view own private files',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view own unpublished content'.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Preview user' => 'Preview user',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view pane admin links'.
  $permissions['view pane admin links'] = array(
    'name' => 'view pane admin links',
    'roles' => array(
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'view private files'.
  $permissions['view private files'] = array(
    'name' => 'view private files',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view revisions'.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Preview user' => 'Preview user',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view scheduled content'.
  $permissions['view scheduled content'] = array(
    'name' => 'view scheduled content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'scheduler',
  );

  // Exported permission: 'view the administration theme'.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'view user actions'.
  $permissions['view user actions'] = array(
    'name' => 'view user actions',
    'roles' => array(
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'user_action_report',
  );

  return $permissions;
}
