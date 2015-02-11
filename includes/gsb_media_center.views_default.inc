<?php

/**
 * Implementation of hook_views_default_views().
 */
function gsb_media_center_views_default_views() {

  $view = new view();
  $view->name = 'gsb_media_browser';
  $view->description = 'Default view for the media browser library tab.';
  $view->tag = 'media, default';
  $view->base_table = 'file_managed';
  $view->human_name = 'GSB Media Browser';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view files';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_tags'] = array(
    0 => 'media_browser',
  );
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
    ),
    'sort' => array(
      'bef_format' => 'default',
      'advanced' => array(
        'collapsible' => 0,
        'collapsible_label' => 'Sort options',
        'combine' => 0,
        'combine_rewrite' => '',
        'reset' => 0,
        'reset_label' => '',
        'is_secondary' => 0,
      ),
    ),
    'filename' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_sections_tid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
  );
  $handler->display->display_options['exposed_form']['options']['input_required'] = 0;
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'gsb_wysiwyg_text';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'media_browser';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['content'] = 'No files available.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: File: Name */
  $handler->display->display_options['fields']['filename']['id'] = 'filename';
  $handler->display->display_options['fields']['filename']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filename']['field'] = 'filename';
  $handler->display->display_options['fields']['filename']['label'] = '';
  $handler->display->display_options['fields']['filename']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['filename']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: File: Upload date */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'file_managed';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
  $handler->display->display_options['sorts']['timestamp']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['timestamp']['expose']['label'] = 'Upload date';
  /* Sort criterion: SUM(File Usage: Use count) */
  $handler->display->display_options['sorts']['count']['id'] = 'count';
  $handler->display->display_options['sorts']['count']['table'] = 'file_usage';
  $handler->display->display_options['sorts']['count']['field'] = 'count';
  $handler->display->display_options['sorts']['count']['group_type'] = 'sum';
  $handler->display->display_options['sorts']['count']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['count']['expose']['label'] = 'Use count';
  /* Filter criterion: File: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'file_managed';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: File: Name */
  $handler->display->display_options['filters']['filename']['id'] = 'filename';
  $handler->display->display_options['filters']['filename']['table'] = 'file_managed';
  $handler->display->display_options['filters']['filename']['field'] = 'filename';
  $handler->display->display_options['filters']['filename']['operator'] = 'contains';
  $handler->display->display_options['filters']['filename']['group'] = 1;
  $handler->display->display_options['filters']['filename']['exposed'] = TRUE;
  $handler->display->display_options['filters']['filename']['expose']['operator_id'] = 'filename_op';
  $handler->display->display_options['filters']['filename']['expose']['label'] = 'File name';
  $handler->display->display_options['filters']['filename']['expose']['operator'] = 'filename_op';
  $handler->display->display_options['filters']['filename']['expose']['identifier'] = 'filename';
  /* Filter criterion: File: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'file_managed';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'image' => 'image',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 1;
  /* Filter criterion: File: Sections (field_sections) */
  $handler->display->display_options['filters']['field_sections_tid']['id'] = 'field_sections_tid';
  $handler->display->display_options['filters']['field_sections_tid']['table'] = 'field_data_field_sections';
  $handler->display->display_options['filters']['field_sections_tid']['field'] = 'field_sections_tid';
  $handler->display->display_options['filters']['field_sections_tid']['value'] = array(
    12256 => '12256',
    13071 => '13071',
    13186 => '13186',
    26671 => '26671',
    12461 => '12461',
    13021 => '13021',
    13046 => '13046',
    13056 => '13056',
    27251 => '27251',
    27256 => '27256',
    12946 => '12946',
    13051 => '13051',
    12396 => '12396',
    12401 => '12401',
    12406 => '12406',
    12456 => '12456',
    28606 => '28606',
    12481 => '12481',
    13191 => '13191',
    13146 => '13146',
    12956 => '12956',
    12261 => '12261',
    13001 => '13001',
    13011 => '13011',
    12421 => '12421',
    13016 => '13016',
    12416 => '12416',
  );
  $handler->display->display_options['filters']['field_sections_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_sections_tid']['expose']['operator_id'] = 'field_sections_tid_op';
  $handler->display->display_options['filters']['field_sections_tid']['expose']['label'] = 'Sections';
  $handler->display->display_options['filters']['field_sections_tid']['expose']['operator'] = 'field_sections_tid_op';
  $handler->display->display_options['filters']['field_sections_tid']['expose']['identifier'] = 'field_sections_tid';
  $handler->display->display_options['filters']['field_sections_tid']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['field_sections_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_sections_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    11 => 0,
    151 => 0,
    16 => 0,
    21 => 0,
    71 => 0,
    61 => 0,
    171 => 0,
    56 => 0,
    66 => 0,
    31 => 0,
    36 => 0,
    201 => 0,
    41 => 0,
    91 => 0,
    146 => 0,
    136 => 0,
    26 => 0,
    46 => 0,
    51 => 0,
    81 => 0,
    86 => 0,
    96 => 0,
    101 => 0,
    106 => 0,
    116 => 0,
    121 => 0,
    126 => 0,
    131 => 0,
    141 => 0,
    156 => 0,
    161 => 0,
    166 => 0,
    176 => 0,
    181 => 0,
    186 => 0,
    191 => 0,
  );
  $handler->display->display_options['filters']['field_sections_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_sections_tid']['vocabulary'] = 'workbench_sections';

  /* Display: Images */
  $handler = $view->new_display('media_browser', 'Images', 'images');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Images';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;

  /* Display: Files and Documents */
  $handler = $view->new_display('media_browser', 'Files and Documents', 'files_and_docs');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Files and Documents';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: File: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'file_managed';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: File: Name */
  $handler->display->display_options['filters']['filename']['id'] = 'filename';
  $handler->display->display_options['filters']['filename']['table'] = 'file_managed';
  $handler->display->display_options['filters']['filename']['field'] = 'filename';
  $handler->display->display_options['filters']['filename']['operator'] = 'contains';
  $handler->display->display_options['filters']['filename']['group'] = 1;
  $handler->display->display_options['filters']['filename']['exposed'] = TRUE;
  $handler->display->display_options['filters']['filename']['expose']['operator_id'] = 'filename_op';
  $handler->display->display_options['filters']['filename']['expose']['label'] = 'File name';
  $handler->display->display_options['filters']['filename']['expose']['operator'] = 'filename_op';
  $handler->display->display_options['filters']['filename']['expose']['identifier'] = 'filename';
  /* Filter criterion: File: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'file_managed';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'audio' => 'audio',
    'document' => 'document',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 1;
  /* Filter criterion: File: Sections (field_sections) */
  $handler->display->display_options['filters']['field_sections_tid']['id'] = 'field_sections_tid';
  $handler->display->display_options['filters']['field_sections_tid']['table'] = 'field_data_field_sections';
  $handler->display->display_options['filters']['field_sections_tid']['field'] = 'field_sections_tid';
  $handler->display->display_options['filters']['field_sections_tid']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_sections_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_sections_tid']['expose']['operator_id'] = 'field_sections_tid_op';
  $handler->display->display_options['filters']['field_sections_tid']['expose']['label'] = 'Sections';
  $handler->display->display_options['filters']['field_sections_tid']['expose']['operator'] = 'field_sections_tid_op';
  $handler->display->display_options['filters']['field_sections_tid']['expose']['identifier'] = 'field_sections_tid';
  $handler->display->display_options['filters']['field_sections_tid']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['field_sections_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_sections_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_sections_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_sections_tid']['vocabulary'] = 'workbench_sections';

  /* Display: Videos */
  $handler = $view->new_display('media_browser', 'Videos', 'videos');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Videos';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: File: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'file_managed';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: File: Name */
  $handler->display->display_options['filters']['filename']['id'] = 'filename';
  $handler->display->display_options['filters']['filename']['table'] = 'file_managed';
  $handler->display->display_options['filters']['filename']['field'] = 'filename';
  $handler->display->display_options['filters']['filename']['operator'] = 'contains';
  $handler->display->display_options['filters']['filename']['group'] = 1;
  $handler->display->display_options['filters']['filename']['exposed'] = TRUE;
  $handler->display->display_options['filters']['filename']['expose']['operator_id'] = 'filename_op';
  $handler->display->display_options['filters']['filename']['expose']['label'] = 'File name';
  $handler->display->display_options['filters']['filename']['expose']['operator'] = 'filename_op';
  $handler->display->display_options['filters']['filename']['expose']['identifier'] = 'filename';
  /* Filter criterion: File: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'file_managed';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'video' => 'video',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 1;
  /* Filter criterion: File: Sections (field_sections) */
  $handler->display->display_options['filters']['field_sections_tid']['id'] = 'field_sections_tid';
  $handler->display->display_options['filters']['field_sections_tid']['table'] = 'field_data_field_sections';
  $handler->display->display_options['filters']['field_sections_tid']['field'] = 'field_sections_tid';
  $handler->display->display_options['filters']['field_sections_tid']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_sections_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_sections_tid']['expose']['operator_id'] = 'field_sections_tid_op';
  $handler->display->display_options['filters']['field_sections_tid']['expose']['label'] = 'Sections';
  $handler->display->display_options['filters']['field_sections_tid']['expose']['operator'] = 'field_sections_tid_op';
  $handler->display->display_options['filters']['field_sections_tid']['expose']['identifier'] = 'field_sections_tid';
  $handler->display->display_options['filters']['field_sections_tid']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['field_sections_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_sections_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_sections_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_sections_tid']['vocabulary'] = 'workbench_sections';

  $views[$view->name] = $view;
  return $views;
}
