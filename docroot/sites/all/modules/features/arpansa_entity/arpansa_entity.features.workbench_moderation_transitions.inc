<?php
/**
 * @file
 * arpansa_entity.features.workbench_moderation_transitions.inc
 */

/**
 * Implements hook_workbench_moderation_export_transitions().
 */
function arpansa_entity_workbench_moderation_export_transitions() {
  $items = array(
    'archived:draft' => array(
      'from_name' => 'archived',
      'to_name' => 'draft',
      'name' => 'Unarchive',
    ),
    'draft:needs_review' => array(
      'from_name' => 'draft',
      'to_name' => 'needs_review',
      'name' => 'Submit for Review',
    ),
    'needs_review:draft' => array(
      'from_name' => 'needs_review',
      'to_name' => 'draft',
      'name' => 'Reject',
    ),
    'needs_review:published' => array(
      'from_name' => 'needs_review',
      'to_name' => 'published',
      'name' => 'Publish',
    ),
    'published:archived' => array(
      'from_name' => 'published',
      'to_name' => 'archived',
      'name' => 'Archive',
    ),
  );
  return $items;
}
