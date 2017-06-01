<?php

/**
 * @file
 * Contain Drush utility commands.
 */

/**
 * Implements hook_drush_command().
 */
function arpansa_migration_drush_command() {
  $items['arpansa-update-link-text'] = array(
    'description' => dt('Invoke a hook update.'),
    'aliases' => array('ault'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_SITE,
  );

  return $items;
}

/**
 * Update link text in migrated media tokens.
 */
function drush_arpansa_migration_arpansa_update_link_text() {
  /** @var \ArpansaMigrationPage $pageMigration */
  $pageMigration = Migration::getInstance('Page');
  /** @var \MigrateSQLMap $map */
  $map = $pageMigration->getMap();

  $importedCount = $map->importedCount();
  if (!$importedCount) {
    drush_log(dt('No pages were migrated.'), 'error');
    return;
  }

  drush_log(dt('Processing @count nodes.', ['@count' => $importedCount]), 'ok');
  $updatedCount = 0;
  foreach ($map as $mapping) {
    /** @var \MigrateSQLMap $mapping */
    if (!empty($mapping->destid1)) {
      if ($node = node_load($mapping->destid1)) {
        $dataChanged = FALSE;
        $field_name = 'body';
        if ($node->type == 'consultation') {
          $field_name = 'field_consultation_summary';
        }
        if (!empty($node->{$field_name}[LANGUAGE_NONE][0]['value'])) {
          $text = $node->{$field_name}[LANGUAGE_NONE][0]['value'];
          $replacement = _arpansa_migration_process_text($text);
          if ($text != $replacement) {
            $node->{$field_name}[LANGUAGE_NONE][0]['value'] = $replacement;
            $dataChanged = TRUE;
          }
        }
        if ($dataChanged) {
          $node->revision = FALSE;
          node_save($node);
          $updatedCount++;
        }
      }
      else {
        drush_log(dt('Failed to load node #@nid.', ['@nid' => $mapping->destid1]), 'error');
      }
    }
  }
  drush_log(dt('Updated @count nodes.', ['@count' => $updatedCount]), 'ok');
}

/**
 * Process text.
 *
 * @param string $text
 *   Text to process.
 *
 * @return string
 *   Processed text.
 */
function _arpansa_migration_process_text($text) {
  $mediaRegex = '#\[\[(.*?\"type":"media".*?)\]\]#';
  preg_match_all($mediaRegex, $text, $matches);
  if (!empty($matches[1])) {
    foreach ($matches[1] as $idx => $match) {
      $mediaItem = json_decode($match, TRUE);

      if (empty($mediaItem)) {
        continue;
      }

      $fid = $mediaItem['fid'];

      $file = file_load($fid);
      if (!$file) {
        continue;
      }

      if (empty($file->field_document_title[LANGUAGE_NONE][0]['value'])) {
        continue;
      }

      $documentTitle = $file->field_document_title[LANGUAGE_NONE][0]['value'];
      $mediaItem['link_text'] = $documentTitle;

      $replace = '[[' . json_encode($mediaItem) . ']]';

      $text = str_replace($matches[0][$idx], $replace, $text);
    }
  }

  return $text;
}
