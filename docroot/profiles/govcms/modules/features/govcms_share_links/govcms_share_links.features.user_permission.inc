<?php
/**
 * @file
 * govcms_share_links.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function govcms_share_links_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access service links'.
  $permissions['access service links'] = array(
    'name' => 'access service links',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Content editor' => 'Content editor',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'service_links',
  );

  // Exported permission: 'use PHP for service visibility'.
  $permissions['use PHP for service visibility'] = array(
    'name' => 'use PHP for service visibility',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'service_links',
  );

  return $permissions;
}
