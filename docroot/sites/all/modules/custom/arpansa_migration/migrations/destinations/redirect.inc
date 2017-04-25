<?php

/**
 * @file
 * redirect.inc
 */

/**
 * Class ArpansaMigrationDestinationRedirect.
 */
class ArpansaMigrationDestinationRedirect extends MigrateDestinationEntity {

  /**
   * {@inheritdoc}
   */
  static public function getKeySchema() {
    return array(
      'rid' => array(
        'type' => 'int',
        'unsigned' => TRUE,
        'description' => 'ID of destination redirect',
      ),
    );
  }

  /**
   * {@inheritdoc}
   */
  public function __construct() {
    parent::__construct('redirect', 'redirect');
    $this->type = 'redirect';
  }

  /**
   * {@inheritdoc}
   */
  public function fields($migration = NULL) {
    $fields = array();
    $fields['rid'] = t('Redirect ID');
    $fields['uid'] = t('User ID');
    $fields['source'] = t('Source');
    $fields['source_options'] = t('Source options');
    $fields['redirect'] = t('Redirect');
    $fields['redirect_options'] = t('Redirect options');
    $fields['language'] = t('Language');
    $fields['status_code'] = t('Status code');

    return $fields;
  }

  /**
   * {@inheritdoc}
   */
  public function bulkRollback(array $rids) {
    migrate_instrument_start('redirect_delete_multiple');
    $this->prepareRollback($rids);
    redirect_delete_multiple($rids);
    $this->completeRollback($rids);
    migrate_instrument_stop('redirect_delete_multiple');
  }

  /**
   * {@inheritdoc}
   */
  public function rollback(array $key) {
    $rid = reset($key);
    migrate_instrument_start('redirect_delete');
    $this->prepareRollback([$rid]);
    redirect_delete($rid);
    $this->completeRollback([$rid]);
    migrate_instrument_stop('redirect_delete');
  }

  /**
   * {@inheritdoc}
   */
  public function import(stdClass $redirect, stdClass $row) {
    $migration = Migration::currentMigration();

    // Updating previously-migrated redirect?
    if (isset($row->migrate_map_destid1)) {
      if (isset($redirect->rid)) {
        if ($redirect->rid != $row->migrate_map_destid1) {
          throw new MigrateException(t("Incoming rid !rid and map destination rid !destid1 don't match",
            array('!rid' => $redirect->rid, '!destid1' => $row->migrate_map_destid1)));
        }
      }
      else {
        $redirect->rid = $row->migrate_map_destid1;
      }
    }

    if ($migration->getSystemOfRecord() == Migration::DESTINATION) {
      if (!isset($redirect->rid)) {
        throw new MigrateException(t('System-of-record is DESTINATION, but no destination rid provided'));
      }
      $raw_redirect = $redirect;
      redirect_object_prepare($redirect);
      $this->prepare($redirect, $row);
      $old_redirect = redirect_load($redirect->rid);
      if (empty($old_redirect)) {
        throw new MigrateException(t('System-of-record is DESTINATION, but redirect !rid does not exist',
          array('!rid' => $redirect->rid)));
      }
      foreach ($raw_redirect as $field => $value) {
        $old_redirect->$field = $redirect->$field;
      }
      $redirect = $old_redirect;
    }
    else {
      redirect_object_prepare($redirect);
      $this->prepare($redirect, $row);

      if (empty($redirect->source)) {
        throw new MigrateException(t('Redirect source is required.'));
      }

      if (empty($redirect->redirect)) {
        throw new MigrateException(t('Redirect destination is required.'));
      }
    }

    // Trying to update an existing redirect.
    if ($migration->getSystemOfRecord() == Migration::DESTINATION) {
      $existing_redirect = redirect_load($redirect->rid);
      if ($existing_redirect) {
        // Incoming data overrides existing data, only copy non-existent fields.
        foreach ($existing_redirect as $field => $value) {
          if (!isset($redirect->$field)) {
            $redirect->$field = $existing_redirect->$field;
          }
        }
      }
    }

    if (isset($redirect->rid)) {
      $updating = TRUE;
    }
    else {
      $updating = FALSE;
    }

    migrate_instrument_start('redirect_save');
    redirect_save($redirect);
    migrate_instrument_stop('redirect_save');

    $this->complete($redirect, $row);

    if (isset($redirect->rid)) {
      if ($updating) {
        $this->numUpdated++;
      }
      else {
        $this->numCreated++;
      }
      $return = array($redirect->rid);
    }
    else {
      $return = FALSE;
    }

    return $return;
  }

}
