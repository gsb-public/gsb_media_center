<?php

/**
 * @file
 * Definition of GSBMediaCenterImage.
 */

/**
 * Media browser plugin for Media Images.
 */
class GSBMediaCenterVideo extends MediaBrowserPlugin {
  /**
   * Implements MediaBrowserPlugin::view().
   */
  public function view() {
    module_load_include('inc', 'file_entity', 'file_entity.pages');

    $build = array();
    $params = $this->params;

    $build['form'] = drupal_get_form('gsb_media_center_add_video_upload', $params['types'], $params['multiselect']);

    $build['form']['embed_code']['#title'] = t('Enter a url to the video.');
    $providers = array();
    foreach ($build['form']['providers']['#items'] as $provider) {
      $providers[] = $provider['data'];
    }

    $provider_list = implode(', ', $providers);
    $build['form']['embed_code']['#description'] = t('Enter the URL to the video. You can use URL\'s from one of these places: @providers', array('@providers' => $provider_list));

    $build['form']['providers']['#access'] = FALSE;

    $build['form']['embed_code']['#weight'] = -2;
    $build['form']['actions']['#weight'] = -1;

    $info['view_name'] = 'gsb_media_browser';
    $info['view_display_id'] = 'videos';

    $view = new GSBMediaCenterView($info, $params);

    $build['form']['upload_images']['view'] = $view->view();

    $fake_buttons = '<div class="form-actions form-wrapper">';
    $fake_buttons .= l(t('Submit'), '', array('attributes' => array('class' => array('button', 'button-yes', 'fake-submit', $info['view_name'] . '--' . $info['view_display_id']))));
    $fake_buttons .= l(t('Cancel'), '', array('attributes' => array('class' => array('button', 'button-no', 'fake-cancel', $info['view_name'] . '--' . $info['view_display_id']))));
    $fake_buttons .= '</div>';

    $build['form']['upload_images']['fake_buttons']['#markup'] = $fake_buttons;

    return $build;
  }
}
