<?php

/**
 * @file
 * Definition of GSBMediaCenterDocument.
 */

/**
 * Media browser plugin for Media Documents.
 */
class GSBMediaCenterDocument extends MediaBrowserPlugin {
  /**
   * Implements MediaBrowserPlugin::view().
   */
  public function view() {
    module_load_include('inc', 'file_entity', 'file_entity.pages');

    $build = array();
    $params = $this->params;
    $params['file_extensions'] = 'txt doc docx xls xlsx pdf ppt pptx pps odt ods odp zip';

    $build['form']['document_upload'] = drupal_get_form('gsb_media_center_add_files_and_docs_upload', $params);
    $build['form']['document_upload']['upload']['#weight'] = -3;
    $build['form']['document_upload']['private_upload']['#weight'] = -2;
    $build['form']['document_upload']['actions']['#weight'] = -1;

    $build['form']['document_upload']['upload']['upload_button']['#access'] = FALSE;

    if ($build['form']['document_upload']['#step'] == 1) {
      $info['view_name'] = 'gsb_media_browser';
      $info['view_display_id'] = 'files_and_docs';

      $view = new GSBMediaCenterView($info, $params);

      $build['form']['document_browser']['view'] = $view->view();

      $fake_buttons = '<div class="form-actions form-wrapper">';
      $fake_buttons .= l(t('Submit'), '', array('attributes' => array('class' => array('button', 'button-yes', 'fake-submit', $info['view_name'] . '--' . $info['view_display_id']))));
      $fake_buttons .= l(t('Cancel'), '', array('attributes' => array('class' => array('button', 'button-no', 'fake-cancel', $info['view_name'] . '--' . $info['view_display_id']))));
      $fake_buttons .= '</div>';

      $build['form']['document_browser']['fake_buttons']['#markup'] = $fake_buttons;
    }

    return $build;

  }
}
