<?php

/**
 * @file
 * file.inc
 */

/**
 * Class ArpansaMigrationFile.
 */
class ArpansaMigrationFile extends ArpansaMigrationBase {
  /**
   * Source directory.
   *
   * @var string
   */
  protected $sourceDir;

  /**
   * {@inheritdoc}
   */
  public function __construct(array $arguments = array()) {
    parent::__construct($arguments);

    $this->sourceDir = self::getEnvOption('source-dir');

    module_load_include('inc', 'arpansa_migration', '/migrations/file.source');
    $this->source = new MigrateSourceList(
      new MigrateListFiles([$this->sourceDir], $this->sourceDir, '/(.*\.*$)/i', [], NULL, FALSE),
      new ArpansaMigrationFileItem($this->sourceDir, FALSE)
    );

    module_load_include('inc', 'arpansa_migration', '/migrations/file.destination');
    $this->destination = new ArpansaMigrationFileDestination('file', 'MigrateFileUri');

    $this->map = new MigrateSQLMap($this->machineName, [
      'path' => [
        'type' => 'varchar',
        'length' => 255,
      ],
    ], ArpansaMigrationFileDestination::getKeySchema());

    $this->addFieldMapping('uid')->defaultValue(1);
    $this->addFieldMapping('source_dir')->defaultValue($this->sourceDir);
    $this->addFieldMapping('value', 'path');
    $this->addFieldMapping('status')->defaultValue(FILE_STATUS_PERMANENT);
    $this->addFieldMapping('type', 'type');
    $this->addFieldMapping('destination_file', 'destination_file');
    $this->addFieldMapping('file_replace')->defaultValue(MigrateFile::FILE_EXISTS_REUSE);
  }

  /**
   * {@inheritdoc}
   */
  protected function preImport() {
    if (empty($this->sourceDir)) {
      throw new MigrateException(t('The source directory must be provided.'));
    }
    if (!file_exists($this->sourceDir)) {
      throw new MigrateException(t('The source directory !source_dir does not exist.', ['!source_dir' => $this->sourceDir]));
    }

    parent::preImport();
  }

  /**
   * {@inheritdoc}
   */
  public function prepareRow($row) {
    $row->destination_file = 'legacy' . $row->path;

    return TRUE;
  }

  /**
   * {@inheritdoc}
   */
  public function complete($file, $row) {
    // Create redirect from legacy path.
    try {
      if (!empty($row->path)) {
        // Skips if the legacy path is already in use.
        if ($row->path != drupal_get_normal_path($row->path)) {
          $this->saveMessage(t('Skip creating redirect for !path', ['!path' => $row->path]), self::MESSAGE_INFORMATIONAL);
          return;
        }
        $path = ltrim($row->path, '/');
        $url = parse_url(file_create_url($file->uri));
        if ($redirect = redirect_load_by_source($path)) {
          $redirect->redirect = $url['path'];
          redirect_save($redirect);
        }
        else {
          $redirect = new stdClass();
          redirect_object_prepare($redirect);
          $redirect->status_code = 301;
          $redirect->source = $path;
          $redirect->redirect = $url['path'];
          redirect_save($redirect);
        }
      }
    }
    catch (PDOException $e) {
      $this->displayMessage('Could not create ' . $row->path . ' redirect for file ' . $file->fid);
    }
  }

}
