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

    $build['form'] = drupal_get_form('gsb_media_center_add_image_upload', $params);
    $build['form']['upload']['#weight'] = -3;
    $build['form']['private_upload']['#weight'] = -2;
    $build['form']['actions']['#weight'] = -1;

    $build['form']['upload']['upload_button']['#access'] = FALSE;

    if ($build['form']['#step'] == 1) {
      $info['view_name'] = 'gsb_media_browser';
      $info['view_display_id'] = 'images';

      $view = new GSBMediaCenterView($info, $params);

      $build['form']['upload_images']['view'] = $view->view();

      $fake_buttons = '<div class="form-actions form-wrapper">';
      $fake_buttons .= l(t('Submit'), '', array('attributes' => array('class' => array('button', 'button-yes', 'fake-submit', $info['view_name'] . '--' . $info['view_display_id']))));
      $fake_buttons .= l(t('Cancel'), '', array('attributes' => array('class' => array('button', 'button-no', 'fake-cancel', $info['view_name'] . '--' . $info['view_display_id']))));
      $fake_buttons .= '</div>';

      $build['form']['upload_images']['fake_buttons']['#markup'] = $fake_buttons;
    }

    return $build;
  }
}
