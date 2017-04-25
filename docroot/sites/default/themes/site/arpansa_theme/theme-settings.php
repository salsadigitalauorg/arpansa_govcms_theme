<?php

/**
 * @file
 * Theme settings for govCMS UI Kit theme.
 */

/**
 * Implements hook_system_theme_settings_alter().
 */
function arpansa_theme_form_system_theme_settings_alter(&$form, $form_state) {
  // I want to place the Secondary Logo enable checkbox underneath the Logo enable checkbox as it makes sense.
  $new_theme_settings = array();

  foreach ($form['theme_settings'] as $key => $setting) {
    $new_theme_settings[$key] = $setting;
    if ($key == 'toggle_logo') {
      $new_theme_settings['toggle_secondary_logo'] = array(
        '#type' => 'checkbox',
        '#title' => 'Secondary Logo',
        '#default_value' => theme_get_setting('toggle_secondary_logo'),
      );
    }
  }

  $form['theme_settings'] = $new_theme_settings;

  $form['secondary_logo'] = array(
    '#type' => 'fieldset',
    '#title' => t('Secondary Logo'),
    '#weight' => 2,
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );

  $form['secondary_logo']['secondary_logo_path'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Path to secondary logo'),
    '#description'   => t("The path to the file you would like to use as your secondary logo file."),
    '#default_value' => theme_get_setting('secondary_logo_path'),
  );

  $form['secondary_logo']['secondary_logo_upload'] = array(
    '#type'          => 'managed_file',
    '#title'         => t('Upload secondary logo image'),
    '#description'   => t("If you don't have direct file access to the server, use this field to upload your secondary logo."),
    '#upload_location' => file_default_scheme() . '://theme/',
    '#default_value' => theme_get_setting('secondary_logo_upload'),
    '#upload_validators' => array(
      'file_validate_extensions' => array('gif png jpg jpeg')
    ),
  );

  $form['secondary_logo']['secondary_logo_alt'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Secondary logo alternative text'),
    '#description'   => t("Alternative text to assign to the secondary logo in the top header."),
    '#default_value' => theme_get_setting('secondary_logo_alt'),
  );

  $form['govcms_ui_kit_options'] = array(
    '#type' => 'fieldset',
    '#title' => t('govCMS UI Kit settings'),
    '#weight' => 5,
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );

  $form['govcms_ui_kit_options']['govcms_ui_kit_header_title'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Header title'),
    '#default_value' => theme_get_setting('govcms_ui_kit_header_title'),
    '#description'   => t("Text to display beside the site logo in the top header."),
  );

  $form['govcms_ui_kit_options']['govcms_ui_kit_header_logo_alt'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Header logo alternative text'),
    '#default_value' => theme_get_setting('govcms_ui_kit_header_logo_alt'),
    '#description'   => t("Alternative text to assign to the logo in the top header."),
  );

  $form['govcms_ui_kit_options']['govcms_ui_kit_footer_copyright'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Footer copyright'),
    '#default_value' => theme_get_setting('govcms_ui_kit_footer_copyright'),
    '#description'   => t("Text to display beside the sub menu links. Defaults to <em>&copy; [current year]. [Site Name]. All rights reserved.</em>"),
  );
}
