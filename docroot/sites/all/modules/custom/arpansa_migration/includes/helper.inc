<?php

/**
 * @file
 * helper.inc
 */

use \ForceUTF8\Encoding;

/**
 * Class ArpansaMigrationHelper.
 */
class ArpansaMigrationHelper {
  /**
   * List of known file extensions.
   *
   * @var array
   */
  protected static $fileTypes = array(
    'image' => array('GIF', 'IMG', 'JPG', 'JPEG', 'PNG', 'BMP', 'TIFF'),
    'video' => array(
      'FLASH', 'SWF', 'FLV',
      'MPG', 'MPEG',
      'MOV',
      'MP4', 'M4V',
      'AVI', 'WMV',
    ),
    'audio' => array('MIDI', 'WAV', 'MP3', 'AAC', 'OGG'),
    'document' => array(
      'RTF', 'CHM', 'PDF',
      'PPT', 'PPTX',
      'CSV', 'TXT',
      'DOC', 'DOCX',
      'XLS', 'XLSX',
      'ZIP', 'RAR', 'GZ',
    ),
  );

  /**
   * Helper function to sanitize and ensure output in UTF-8.
   *
   * @param string|array $text
   *   Text to be sanitized.
   *
   * @return string|array
   *   Sanitized text.
   */
  public static function sanitizeText($text) {
    $values = is_array($text) ? $text : array($text);
    module_load_include('php', 'arpansa_migration', 'includes/vendor/ForceUTF8/Encoding');
    foreach ($values as &$value) {
      $value = str_replace(array(
        'â€™',
        'â€”',
        '‚Äì',
        '‚Äô',
        '‚Äò',
        'Ê',
        'Õ',
      ), array(
        "'",
        "&#8211;",
        '&#8211;',
        '&#8217;',
        '&#8216;',
        '\'',
        '\'',
      ), $value);
      $value = Encoding::toUTF8($value);
    }
    return is_array($text) ? $values : reset($values);
  }

  /**
   * Get MIME type of a file.
   *
   * @param string $filename
   *   File name.
   *
   * @return string
   *   MIME type.
   */
  public static function getMimeType($filename) {
    include_once DRUPAL_ROOT . '/includes/file.mimetypes.inc';
    $mimeTypes = file_mimetype_mapping();

    $extension = strtolower(pathinfo($filename, PATHINFO_EXTENSION));
    if (!empty($mimeTypes['extensions'][$extension])
      && !empty($mimeTypes['mimetypes'][$mimeTypes['extensions'][$extension]])
    ) {
      return $mimeTypes['mimetypes'][$mimeTypes['extensions'][$extension]];
    }

    return 'application/octet-stream';
  }

  /**
   * Get managed type of a file: image, video, audio, or document.
   *
   * @param string $uri
   *   File URI.
   *
   * @return string
   *   File type.
   */
  public static function getFileType($uri) {
    $extension = strtoupper(pathinfo($uri, PATHINFO_EXTENSION));
    if (in_array($extension, self::$fileTypes['image'])) {
      return 'image';
    }
    elseif (in_array($extension, self::$fileTypes['video'])) {
      return 'video';
    }
    elseif (in_array($extension, self::$fileTypes['audio'])) {
      return 'audio';
    }
    return 'document';
  }

  /**
   * Build Media JSON token for a file entity.
   *
   * @param int $fid
   *   File ID.
   * @param array $attributes
   *   HTML attributes.
   * @param string $link_text
   *   Link text.
   * @param string $view_mode
   *   Machine name of view mode.
   *
   * @return string
   *   Media JSON.
   */
  public static function buildMediaJson($fid, $attributes = array(), $link_text = NULL, $view_mode = 'default') {
    $media_token = new stdClass();
    $media_token->fid = intval($fid);
    $media_token->view_mode = $view_mode ?: 'default';
    $media_token->type = 'media';
    $media_token->link_text = $link_text;
    $media_token->attributes = array();
    if (count($attributes)) {
      $media_token->attributes = (object) $attributes;
    }
    return '[[' . drupal_json_encode($media_token) . ']]';
  }

  /**
   * Sanitize ARPANSA source URI.
   *
   * @param string $source_uri
   *   Source URI.
   * @param bool $urlencode
   *   Indicate if the Source URI is URL-encoded.
   *
   * @return string
   *   Sanitized URI.
   */
  public static function sanitizeArpansaSourceUri($source_uri, $urlencode = FALSE) {
    $source_uri = str_replace(array(
      'http://arpansa.gov.au/',
      'https://arpansa.gov.au/',
      'http://www.arpansa.gov.au/',
      'https://www.arpansa.gov.au/',
    ), '', $source_uri);
    $source_uri = trim($source_uri, '/');
    $source_uri = trim($source_uri);
    $source_uri = preg_replace('/\/+/', '/', $source_uri);
    if ($urlencode) {
      $source_uri = urldecode($source_uri);
    }
    return $source_uri;
  }

  /**
   * Convert relative URI to absolute.
   *
   * @param string $uri
   *   Relative URI, eg. ../../images/abc.jpg
   * @param string $context_uri
   *   Current context, eg. /aboutus/collaboration/
   *
   * @return string
   *   Remapped URI, eg. /images/abc.jpg
   */
  public static function remapRelativeUri($uri, $context_uri) {
    // Absolute URI, return as is.
    if (strpos($uri, '/') === 0 || strpos($uri, '://') !== FALSE) {
      return $uri;
    }

    if (strpos($uri, 'index.cfm') !== FALSE) {
      $uri = str_replace('index.cfm', '/', $uri);
    }
    if (strpos($uri, 'index.htm') !== FALSE) {
      $uri = str_replace('index.htm', '/', $uri);
    }
    $uri = preg_replace('/\/+/i', '/', $uri);

    if (pathinfo($context_uri, PATHINFO_EXTENSION)) {
      $context_dir = dirname($context_uri);
    }
    else {
      $context_dir = $context_uri;
    }
    while (strpos($uri, '../') === 0 || strpos($uri, './') === 0) {
      if (strpos($uri, '../') === 0) {
        $context_dir = dirname($context_dir);
        $uri = substr_replace($uri, '', 0, strlen('../'));
      }
      else {
        $uri = substr_replace($uri, '', 0, strlen('./'));
      }
    }
    if ($context_dir != '/') {
      $uri = $context_dir . '/' . $uri;
    }
    else {
      $uri = $context_dir . $uri;
    }

    return $uri;
  }

  /**
   * Prepare a term.
   *
   * @param string $name
   *   Term name.
   * @param string $vocabulary_machine_name
   *   Vocabulary machine name.
   *
   * @return int|FALSE
   *   Term ID.
   */
  public static function prepareTerm($name, $vocabulary_machine_name) {
    $cache = drupal_static(__FUNCTION__, []);

    if (isset($cache[$vocabulary_machine_name][$name])) {
      return $cache[$vocabulary_machine_name][$name];
    }

    $vocabulary = taxonomy_vocabulary_machine_name_load($vocabulary_machine_name);

    // Attempt to load the existing term.
    $query = new EntityFieldQuery();
    $result = $query->entityCondition('entity_type', 'taxonomy_term')
      ->propertyCondition('vid', $vocabulary->vid)
      ->propertyCondition('name', $name)
      ->range(0, 1)
      ->execute();

    if (!empty($result['taxonomy_term']) && count($result['taxonomy_term'])) {
      $term = reset($result['taxonomy_term']);

      $cache[$vocabulary_machine_name][$name] = $term->tid;

      return $term->tid;
    }

    // No term found, create a new term.
    $term = new stdClass();
    $term->name = $name;
    $term->vid = $vocabulary->vid;
    taxonomy_term_save($term);

    if (!empty($term->tid)) {
      $cache[$vocabulary_machine_name][$name] = $term->tid;
      return $term->tid;
    }

    return FALSE;
  }

}
