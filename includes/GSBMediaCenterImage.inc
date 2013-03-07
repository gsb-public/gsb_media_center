<?php

/**
 * @file
 * Definition of GSBMediaCenterImage.
 */

/**
 * Media browser plugin for Media Images.
 */
class GSBMediaCenterImage extends MediaBrowserPlugin {
  /**
   * Implements MediaBrowserPlugin::view().
   */
  public function view() {
    module_load_include('inc', 'file_entity', 'file_entity.pages');

    $build = array();
    $params = $this->params;
    $params['file_extensions'] = 'jpg jpeg gif png';

    $build['form']['image_upload'] = drupal_get_form('gsb_media_center_add_image_upload', $params);

    // We need the current step put on the form portion of the array.
    $build['form']['#step'] = $build['form']['image_upload']['#step'];
    if ($build['form']['image_upload']['#step'] == 1) {
      $build['form']['image_upload']['upload']['#weight'] = -3;
      $build['form']['image_upload']['private_upload']['#weight'] = -2;
      $build['form']['image_upload']['actions']['#weight'] = -1;

      $build['form']['image_upload']['upload']['upload_button']['#access'] = FALSE;

      $info['view_name'] = 'gsb_media_browser';
      $info['view_display_id'] = 'images';

      $view = new GSBMediaCenterView($info, $params);

      $build['form']['image_browser']['view'] = $view->view();

      $fake_buttons = '<div class="form-actions form-wrapper">';
      $fake_buttons .= l(t('Submit'), '', array('attributes' => array('class' => array('button', 'button-yes', 'fake-submit', $info['view_name'] . '--' . $info['view_display_id']))));
      $fake_buttons .= l(t('Cancel'), '', array('attributes' => array('class' => array('button', 'button-no', 'fake-cancel', $info['view_name'] . '--' . $info['view_display_id']))));
      $fake_buttons .= '</div>';

      $build['form']['image_browser']['fake_buttons']['#markup'] = $fake_buttons;
    }
    return $build;
  }
}
