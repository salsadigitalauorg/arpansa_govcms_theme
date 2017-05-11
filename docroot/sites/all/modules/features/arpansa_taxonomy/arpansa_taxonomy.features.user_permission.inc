<?php
/**
 * @file
 * arpansa_taxonomy.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function arpansa_taxonomy_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'delete terms in literature_survey_date'.
  $permissions['delete terms in literature_survey_date'] = array(
    'name' => 'delete terms in literature_survey_date',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in page_type'.
  $permissions['delete terms in page_type'] = array(
    'name' => 'delete terms in page_type',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in literature_survey_date'.
  $permissions['edit terms in literature_survey_date'] = array(
    'name' => 'edit terms in literature_survey_date',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in page_type'.
  $permissions['edit terms in page_type'] = array(
    'name' => 'edit terms in page_type',
    'roles' => array(
      'Content approver' => 'Content approver',
      'Site builder' => 'Site builder',
      'Site editor' => 'Site editor',
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  return $permissions;
}