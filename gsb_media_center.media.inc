<?php

/**
 * @file
 * Media module integration for the Media internet module.
 */

/**
 * Implements hook_media_browser_plugin_info().
 */
function gsb_media_center_media_browser_plugin_info() {
  $info = array();

  $info['gsb_media_center_image'] = array(
    'title' => t('Images'),
    'class' => 'GSBMediaCenterImage',
  );

  $info['gsb_media_center_document'] = array(
    'title' => t('Files'),
    'class' => 'GSBMediaCenterDocument',
  );

  $info['gsb_media_center_video'] = array(
    'title' => t('Videos'),
    'class' => 'GSBMediaCenterVideo',
  );

  return $info;
}

/**
 * Implements hook_media_browser_plugins_alter().
 */
function gsb_media_center_media_browser_plugins_alter(&$plugin_output) {
  $order = array(
    'gsb_media_center_image',
    'gsb_media_center_document',
    'gsb_media_center_video',
  );

  foreach ($order as $index => $plugin) {
    if (isset($plugin_output[$plugin])) {
      $plugin_output[$plugin]['#weight'] = $index;
    }
  }
}
