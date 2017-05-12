<?php
/**
 * @file
 * govcms_editing.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function govcms_editing_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'use text format iframe'.
  $permissions['use text format iframe'] = array(
    'name' => 'use text format iframe',
    'roles' => array(
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  return $permissions;
}
