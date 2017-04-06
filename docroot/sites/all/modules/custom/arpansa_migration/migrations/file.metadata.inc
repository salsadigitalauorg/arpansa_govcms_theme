<?php

/**
 * @file
 * file.metadata.inc
 */

/**
 * Class ArpansaMigrationFileMetadata.
 */
class ArpansaMigrationFileMetadata extends ArpansaMigrationBase {

  /**
   * System of Record.
   *
   * @var int
   */
  protected $systemOfRecord = Migration::DESTINATION;

  /**
   * Source CSV file.
   *
   * @var string
   */
  protected $sourceCSV;

  /**
   * File Migration.
   *
   * @var \ArpansaMigrationFile
   */
  protected $fileMigration;

  /**
   * Vocabulary machine name of File Tags.
   *
   * @var string
   */
  protected $fileTagVocabulary = 'file_tags';

  /**
   * {@inheritdoc}
   */
  public function __construct(array $arguments = array()) {
    parent::__construct($arguments);

    $this->sourceCSV = $this->getEnvOption('source-csv');

    $csvColumns = [
      ['url', 'URL'],
      ['path', 'URL lowercase'],
      ['filename', 'File name'],
      ['title', 'Document title'],
      ['tag1', 'Tag 1'],
      ['tag2', 'Tag 2'],
      ['tag3', 'Tag 3'],
      ['tag4', 'Tag 4'],
      ['tag5', 'Tag 5'],
    ];

    module_load_include('inc', 'arpansa_migration', '/migrations/sources/csv');
    $this->source = new ArpansaMigrationCSV($this->sourceCSV, $csvColumns, ['header_rows' => 1]);

    $this->destination = new MigrateDestinationFile('file', 'MigrateFileFid');

    $this->map = new MigrateSQLMap($this->machineName, [
      'path' => [
        'type' => 'varchar',
        'length' => 255,
      ],
    ], MigrateDestinationFile::getKeySchema());

    $this->addFieldMapping('fid', 'fid');
    $this->addFieldMapping('value', 'fid');

    $this->fileMigration = Migration::getInstance('File');
  }

  /**
   * {@inheritdoc}
   */
  public function prepareRow($row) {
    $row->path = urldecode($row->path);
    if ($destids = $this->fileMigration->map->lookupDestinationID(['sourceid1' => $row->path])) {
      if (!empty($destids['destid1'])) {
        $fid = $destids['destid1'];
        $row->fid = $fid;

        $row->title = drupal_substr($row->title, 0, 255);

        foreach ([1, 2, 3, 4, 5] as $index) {
          if (!empty($row->{'tag' . $index})) {
            $row->tags[] = ucfirst($row->{'tag' . $index});
          }
        }

        return TRUE;
      }
    }

    return FALSE;
  }

  /**
   * {@inheritdoc}
   */
  public function complete($file, $row) {
    try {
      $file_wrapper = entity_metadata_wrapper('file', $file);
      $data_changed = FALSE;

      // Set document title.
      if ($file->type == 'document' && !empty($row->title)) {
        $file_wrapper->field_document_title->set($row->title);
        $data_changed = TRUE;
      }

      // Set tags.
      if (in_array($file->type, ['image', 'document'])
        && !empty($row->tags) && count($row->tags)
      ) {
        $tags = [];
        foreach ($row->tags as $tag) {
          if ($tid = ArpansaMigrationHelper::prepareTerm($tag, $this->fileTagVocabulary)) {
            $tags[] = $tid;
          }
        }
        $file_wrapper->field_file_tags->set($tags);
        $data_changed = TRUE;
      }

      if ($data_changed) {
        $file_wrapper->save();
      }
    }
    catch (Exception $exception) {
      $this->saveMessage($exception->getMessage());
    }
  }

}
