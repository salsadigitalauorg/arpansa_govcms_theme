<?php
/**
 * @file
 * arpansa_blocks.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function arpansa_blocks_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'ARPANSA Copyright Footer';
  $fe_block_boxes->format = 'iframe';
  $fe_block_boxes->machine_name = 'arpansa_copyright_footer';
  $fe_block_boxes->body = '<p><strong>ARPANSA</strong>&nbsp;</p><p>&copy; Commonwealth of Australia</p>';

  $export['arpansa_copyright_footer'] = $fe_block_boxes;

  return $export;
}
