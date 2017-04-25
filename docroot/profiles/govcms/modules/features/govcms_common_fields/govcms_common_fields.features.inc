<?php
/**
 * @file
 * govcms_common_fields.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function govcms_common_fields_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
