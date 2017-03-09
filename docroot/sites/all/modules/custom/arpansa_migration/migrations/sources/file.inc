<?php

/**
 * @file
 * file.source.inc
 */

/**
 * Class ArpansaMigrationFileItem.
 */
class ArpansaMigrationFileItem extends MigrateItemFile {

  /**
   * {@inheritdoc}
   */
  public function getItem($id) {
    $pieces = explode(MIGRATE_CHUNK_SEPARATOR, $id);
    $item_uri = $this->baseDir . $pieces[0];

    $item = parent::getItem($id);
    if (is_object($item)) {
      $item->source_uri = $item_uri;
      $item->filename = pathinfo($item_uri, PATHINFO_BASENAME);
      $item->type = ArpansaMigrationHelper::getFileType($item_uri);
    }

    return $item;
  }

}
