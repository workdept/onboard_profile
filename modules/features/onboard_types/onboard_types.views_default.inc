<?php
/**
 * @file
 * onboard_types.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function onboard_types_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'board_terms';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Board terms';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Active board members';
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['use_more_text'] = 'search past and future members';
  $handler->display->display_options['link_display'] = 'page_all';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    5 => '5',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_member' => 'field_member',
    'field_term_dates' => 'field_term_dates',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_member' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_term_dates' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No active board terms';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: Content: Board */
  $handler->display->display_options['fields']['field_board']['id'] = 'field_board';
  $handler->display->display_options['fields']['field_board']['table'] = 'field_data_field_board';
  $handler->display->display_options['fields']['field_board']['field'] = 'field_board';
  $handler->display->display_options['fields']['field_board']['label'] = 'Board nid';
  $handler->display->display_options['fields']['field_board']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_board']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_board']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'board term nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Member */
  $handler->display->display_options['fields']['field_member']['id'] = 'field_member';
  $handler->display->display_options['fields']['field_member']['table'] = 'field_data_field_member';
  $handler->display->display_options['fields']['field_member']['field'] = 'field_member';
  $handler->display->display_options['fields']['field_member']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_member']['alter']['text'] = '[field_member] <a href="/node/[field_member-target_id]/edit?destination=node/[field_board]" title="Edit member\'s contact information">edit</a>';
  $handler->display->display_options['fields']['field_member']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Position */
  $handler->display->display_options['fields']['field_position']['id'] = 'field_position';
  $handler->display->display_options['fields']['field_position']['table'] = 'field_data_field_position';
  $handler->display->display_options['fields']['field_position']['field'] = 'field_position';
  /* Field: Content: Term Dates */
  $handler->display->display_options['fields']['field_term_dates']['id'] = 'field_term_dates';
  $handler->display->display_options['fields']['field_term_dates']['table'] = 'field_data_field_term_dates';
  $handler->display->display_options['fields']['field_term_dates']['field'] = 'field_term_dates';
  $handler->display->display_options['fields']['field_term_dates']['label'] = 'Term';
  $handler->display->display_options['fields']['field_term_dates']['settings'] = array(
    'format_type' => 'onboard_date_type_human_short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href="/node/[nid]/edit?destination=node/[field_board]">edit</a>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Term Dates */
  $handler->display->display_options['fields']['field_term_dates_1']['id'] = 'field_term_dates_1';
  $handler->display->display_options['fields']['field_term_dates_1']['table'] = 'field_data_field_term_dates';
  $handler->display->display_options['fields']['field_term_dates_1']['field'] = 'field_term_dates';
  $handler->display->display_options['fields']['field_term_dates_1']['label'] = 'start date';
  $handler->display->display_options['fields']['field_term_dates_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_term_dates_1']['type'] = 'date_plain';
  $handler->display->display_options['fields']['field_term_dates_1']['settings'] = array(
    'format_type' => 'onboard_date_type_human_short',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Term Dates */
  $handler->display->display_options['fields']['field_term_dates_2']['id'] = 'field_term_dates_2';
  $handler->display->display_options['fields']['field_term_dates_2']['table'] = 'field_data_field_term_dates';
  $handler->display->display_options['fields']['field_term_dates_2']['field'] = 'field_term_dates';
  $handler->display->display_options['fields']['field_term_dates_2']['label'] = 'end date';
  $handler->display->display_options['fields']['field_term_dates_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_term_dates_2']['type'] = 'date_plain';
  $handler->display->display_options['fields']['field_term_dates_2']['settings'] = array(
    'format_type' => 'onboard_date_type_human_short',
    'fromto' => 'value2',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Sort criterion: Content: Term Dates -  start date (field_term_dates) */
  $handler->display->display_options['sorts']['field_term_dates_value']['id'] = 'field_term_dates_value';
  $handler->display->display_options['sorts']['field_term_dates_value']['table'] = 'field_data_field_term_dates';
  $handler->display->display_options['sorts']['field_term_dates_value']['field'] = 'field_term_dates_value';
  /* Contextual filter: Content: Board (field_board) */
  $handler->display->display_options['arguments']['field_board_target_id']['id'] = 'field_board_target_id';
  $handler->display->display_options['arguments']['field_board_target_id']['table'] = 'field_data_field_board';
  $handler->display->display_options['arguments']['field_board_target_id']['field'] = 'field_board_target_id';
  $handler->display->display_options['arguments']['field_board_target_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_board_target_id']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_board_target_id']['default_argument_options']['index'] = '0';
  $handler->display->display_options['arguments']['field_board_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_board_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_board_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_board_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_board_target_id']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['field_board_target_id']['validate_options']['types'] = array(
    'board' => 'board',
  );
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
    3 => 'OR',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'board_term' => 'board_term',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Term Dates -  start date (field_term_dates) */
  $handler->display->display_options['filters']['field_term_dates_value']['id'] = 'field_term_dates_value';
  $handler->display->display_options['filters']['field_term_dates_value']['table'] = 'field_data_field_term_dates';
  $handler->display->display_options['filters']['field_term_dates_value']['field'] = 'field_term_dates_value';
  $handler->display->display_options['filters']['field_term_dates_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_term_dates_value']['group'] = 2;
  $handler->display->display_options['filters']['field_term_dates_value']['expose']['operator_id'] = 'field_term_dates_value_op';
  $handler->display->display_options['filters']['field_term_dates_value']['expose']['label'] = 'Term Dates -  start date (field_term_dates)';
  $handler->display->display_options['filters']['field_term_dates_value']['expose']['operator'] = 'field_term_dates_value_op';
  $handler->display->display_options['filters']['field_term_dates_value']['expose']['identifier'] = 'field_term_dates_value';
  $handler->display->display_options['filters']['field_term_dates_value']['default_date'] = 'now';
  /* Filter criterion: Content: Term Dates - end date (field_term_dates:value2) */
  $handler->display->display_options['filters']['field_term_dates_value2']['id'] = 'field_term_dates_value2';
  $handler->display->display_options['filters']['field_term_dates_value2']['table'] = 'field_data_field_term_dates';
  $handler->display->display_options['filters']['field_term_dates_value2']['field'] = 'field_term_dates_value2';
  $handler->display->display_options['filters']['field_term_dates_value2']['operator'] = '>=';
  $handler->display->display_options['filters']['field_term_dates_value2']['group'] = 3;
  $handler->display->display_options['filters']['field_term_dates_value2']['default_date'] = 'now';
  /* Filter criterion: Global: Fields comparison */
  $handler->display->display_options['filters']['fields_compare']['id'] = 'fields_compare';
  $handler->display->display_options['filters']['fields_compare']['table'] = 'views';
  $handler->display->display_options['filters']['fields_compare']['field'] = 'fields_compare';
  $handler->display->display_options['filters']['fields_compare']['group'] = 3;
  $handler->display->display_options['filters']['fields_compare']['right_field'] = 'field_term_dates_1';
  $handler->display->display_options['filters']['fields_compare']['left_field'] = 'field_term_dates_2';

  /* Display: Active page */
  $handler = $view->new_display('page', 'Active page', 'page');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Board (field_board) */
  $handler->display->display_options['arguments']['field_board_target_id']['id'] = 'field_board_target_id';
  $handler->display->display_options['arguments']['field_board_target_id']['table'] = 'field_data_field_board';
  $handler->display->display_options['arguments']['field_board_target_id']['field'] = 'field_board_target_id';
  $handler->display->display_options['arguments']['field_board_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_board_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_board_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_board_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_board_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_board_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_board_target_id']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['field_board_target_id']['validate_options']['types'] = array(
    'board' => 'board',
  );
  $handler->display->display_options['path'] = 'city/%/board/%/terms';

  /* Display: Active block */
  $handler = $view->new_display('block', 'Active block', 'block_1');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Board (field_board) */
  $handler->display->display_options['arguments']['field_board_target_id']['id'] = 'field_board_target_id';
  $handler->display->display_options['arguments']['field_board_target_id']['table'] = 'field_data_field_board';
  $handler->display->display_options['arguments']['field_board_target_id']['field'] = 'field_board_target_id';
  $handler->display->display_options['arguments']['field_board_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_board_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_board_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_board_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_board_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_board_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_board_target_id']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['field_board_target_id']['validate_options']['types'] = array(
    'board' => 'board',
  );

  /* Display: All page */
  $handler = $view->new_display('page', 'All page', 'page_all');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'All board members';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'search past and future members';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_member' => 'field_member',
    'field_term_dates' => 'field_term_dates',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = 'field_term_dates';
  $handler->display->display_options['style_options']['info'] = array(
    'field_member' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_term_dates' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Board (field_board) */
  $handler->display->display_options['arguments']['field_board_target_id_1']['id'] = 'field_board_target_id_1';
  $handler->display->display_options['arguments']['field_board_target_id_1']['table'] = 'field_data_field_board';
  $handler->display->display_options['arguments']['field_board_target_id_1']['field'] = 'field_board_target_id';
  $handler->display->display_options['arguments']['field_board_target_id_1']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_board_target_id_1']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_board_target_id_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_board_target_id_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_board_target_id_1']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_board_target_id_1']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_board_target_id_1']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['field_board_target_id_1']['validate_options']['types'] = array(
    'board' => 'board',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'board_term' => 'board_term',
  );
  /* Filter criterion: Content: Term Dates -  start date (field_term_dates) */
  $handler->display->display_options['filters']['field_term_dates_value']['id'] = 'field_term_dates_value';
  $handler->display->display_options['filters']['field_term_dates_value']['table'] = 'field_data_field_term_dates';
  $handler->display->display_options['filters']['field_term_dates_value']['field'] = 'field_term_dates_value';
  $handler->display->display_options['filters']['field_term_dates_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_term_dates_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_term_dates_value']['expose']['operator_id'] = 'field_term_dates_value_op';
  $handler->display->display_options['filters']['field_term_dates_value']['expose']['label'] = 'Start date before';
  $handler->display->display_options['filters']['field_term_dates_value']['expose']['operator'] = 'field_term_dates_value_op';
  $handler->display->display_options['filters']['field_term_dates_value']['expose']['identifier'] = 'field_term_dates_value';
  $handler->display->display_options['filters']['field_term_dates_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_term_dates_value']['default_date'] = 'now +1 year';
  /* Filter criterion: Content: Term Dates - end date (field_term_dates:value2) */
  $handler->display->display_options['filters']['field_term_dates_value2']['id'] = 'field_term_dates_value2';
  $handler->display->display_options['filters']['field_term_dates_value2']['table'] = 'field_data_field_term_dates';
  $handler->display->display_options['filters']['field_term_dates_value2']['field'] = 'field_term_dates_value2';
  $handler->display->display_options['filters']['field_term_dates_value2']['operator'] = '>=';
  $handler->display->display_options['filters']['field_term_dates_value2']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_term_dates_value2']['expose']['operator_id'] = 'field_term_dates_value2_op';
  $handler->display->display_options['filters']['field_term_dates_value2']['expose']['label'] = 'End date after';
  $handler->display->display_options['filters']['field_term_dates_value2']['expose']['operator'] = 'field_term_dates_value2_op';
  $handler->display->display_options['filters']['field_term_dates_value2']['expose']['identifier'] = 'field_term_dates_value2';
  $handler->display->display_options['filters']['field_term_dates_value2']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_term_dates_value2']['group_info']['label'] = 'Term Dates - end date (field_term_dates:value2)';
  $handler->display->display_options['filters']['field_term_dates_value2']['group_info']['identifier'] = 'field_term_dates_value2';
  $handler->display->display_options['filters']['field_term_dates_value2']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_term_dates_value2']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  $handler->display->display_options['filters']['field_term_dates_value2']['default_date'] = 'now -1 year';
  $handler->display->display_options['path'] = 'node/%/board_terms';

  /* Display: public active block */
  $handler = $view->new_display('block', 'public active block', 'block_2');
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'search past and future members';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Member */
  $handler->display->display_options['fields']['field_member']['id'] = 'field_member';
  $handler->display->display_options['fields']['field_member']['table'] = 'field_data_field_member';
  $handler->display->display_options['fields']['field_member']['field'] = 'field_member';
  $handler->display->display_options['fields']['field_member']['alter']['text'] = '[field_member] <a href="/node/[field_member-target_id]/edit?destination=node/[field_board]" title="Edit member\'s contact information">edit</a>';
  $handler->display->display_options['fields']['field_member']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Position */
  $handler->display->display_options['fields']['field_position']['id'] = 'field_position';
  $handler->display->display_options['fields']['field_position']['table'] = 'field_data_field_position';
  $handler->display->display_options['fields']['field_position']['field'] = 'field_position';
  /* Field: Content: Term Dates */
  $handler->display->display_options['fields']['field_term_dates']['id'] = 'field_term_dates';
  $handler->display->display_options['fields']['field_term_dates']['table'] = 'field_data_field_term_dates';
  $handler->display->display_options['fields']['field_term_dates']['field'] = 'field_term_dates';
  $handler->display->display_options['fields']['field_term_dates']['label'] = 'Term';
  $handler->display->display_options['fields']['field_term_dates']['settings'] = array(
    'format_type' => 'onboard_date_type_human_short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Term Dates */
  $handler->display->display_options['fields']['field_term_dates_1']['id'] = 'field_term_dates_1';
  $handler->display->display_options['fields']['field_term_dates_1']['table'] = 'field_data_field_term_dates';
  $handler->display->display_options['fields']['field_term_dates_1']['field'] = 'field_term_dates';
  $handler->display->display_options['fields']['field_term_dates_1']['label'] = 'start date';
  $handler->display->display_options['fields']['field_term_dates_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_term_dates_1']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Term Dates */
  $handler->display->display_options['fields']['field_term_dates_2']['id'] = 'field_term_dates_2';
  $handler->display->display_options['fields']['field_term_dates_2']['table'] = 'field_data_field_term_dates';
  $handler->display->display_options['fields']['field_term_dates_2']['field'] = 'field_term_dates';
  $handler->display->display_options['fields']['field_term_dates_2']['label'] = 'end date';
  $handler->display->display_options['fields']['field_term_dates_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_term_dates_2']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'value2',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Board (field_board) */
  $handler->display->display_options['arguments']['field_board_target_id']['id'] = 'field_board_target_id';
  $handler->display->display_options['arguments']['field_board_target_id']['table'] = 'field_data_field_board';
  $handler->display->display_options['arguments']['field_board_target_id']['field'] = 'field_board_target_id';
  $handler->display->display_options['arguments']['field_board_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_board_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_board_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_board_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_board_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_board_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_board_target_id']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['field_board_target_id']['validate_options']['types'] = array(
    'board' => 'board',
  );

  /* Display: Export all */
  $handler = $view->new_display('views_data_export', 'Export all', 'views_data_export_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Export all board members';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%view_%1-title_%timestamp-full.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Board */
  $handler->display->display_options['fields']['field_board']['id'] = 'field_board';
  $handler->display->display_options['fields']['field_board']['table'] = 'field_data_field_board';
  $handler->display->display_options['fields']['field_board']['field'] = 'field_board';
  $handler->display->display_options['fields']['field_board']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Member */
  $handler->display->display_options['fields']['field_member']['id'] = 'field_member';
  $handler->display->display_options['fields']['field_member']['table'] = 'field_data_field_member';
  $handler->display->display_options['fields']['field_member']['field'] = 'field_member';
  $handler->display->display_options['fields']['field_member']['alter']['text'] = '[field_member] <a href="/node/[field_member-target_id]/edit?destination=node/[field_board]" title="Edit member\'s contact information">edit</a>';
  $handler->display->display_options['fields']['field_member']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Position */
  $handler->display->display_options['fields']['field_position']['id'] = 'field_position';
  $handler->display->display_options['fields']['field_position']['table'] = 'field_data_field_position';
  $handler->display->display_options['fields']['field_position']['field'] = 'field_position';
  /* Field: Content: Term Dates */
  $handler->display->display_options['fields']['field_term_dates']['id'] = 'field_term_dates';
  $handler->display->display_options['fields']['field_term_dates']['table'] = 'field_data_field_term_dates';
  $handler->display->display_options['fields']['field_term_dates']['field'] = 'field_term_dates';
  $handler->display->display_options['fields']['field_term_dates']['settings'] = array(
    'format_type' => 'onboard_date_type_human_short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'board_term' => 'board_term',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['path'] = 'node/%/board_terms/csv';
  $handler->display->display_options['displays'] = array(
    'page_all' => 'page_all',
    'default' => 0,
    'page' => 0,
    'block_1' => 0,
    'block_2' => 0,
  );
  $handler->display->display_options['sitename_title'] = 0;

  /* Display: Export active */
  $handler = $view->new_display('views_data_export', 'Export active', 'views_data_export_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Export active board members';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%view_%1-title_%timestamp-full.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Board */
  $handler->display->display_options['fields']['field_board']['id'] = 'field_board';
  $handler->display->display_options['fields']['field_board']['table'] = 'field_data_field_board';
  $handler->display->display_options['fields']['field_board']['field'] = 'field_board';
  $handler->display->display_options['fields']['field_board']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Member */
  $handler->display->display_options['fields']['field_member']['id'] = 'field_member';
  $handler->display->display_options['fields']['field_member']['table'] = 'field_data_field_member';
  $handler->display->display_options['fields']['field_member']['field'] = 'field_member';
  $handler->display->display_options['fields']['field_member']['alter']['text'] = '[field_member] <a href="/node/[field_member-target_id]/edit?destination=node/[field_board]" title="Edit member\'s contact information">edit</a>';
  $handler->display->display_options['fields']['field_member']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Position */
  $handler->display->display_options['fields']['field_position']['id'] = 'field_position';
  $handler->display->display_options['fields']['field_position']['table'] = 'field_data_field_position';
  $handler->display->display_options['fields']['field_position']['field'] = 'field_position';
  /* Field: Content: Term Dates */
  $handler->display->display_options['fields']['field_term_dates']['id'] = 'field_term_dates';
  $handler->display->display_options['fields']['field_term_dates']['table'] = 'field_data_field_term_dates';
  $handler->display->display_options['fields']['field_term_dates']['field'] = 'field_term_dates';
  $handler->display->display_options['fields']['field_term_dates']['settings'] = array(
    'format_type' => 'onboard_date_type_human_short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['path'] = 'node/%/board_terms/csv/active_only';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'block_1' => 'block_1',
    'default' => 0,
    'page_all' => 0,
    'block_2' => 0,
  );
  $handler->display->display_options['sitename_title'] = 0;
  $export['board_terms'] = $view;

  $view = new view();
  $view->name = 'my_boards';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'My Boards';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'My Boards';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Relationship: OG membership: OG membership from Node */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  /* Relationship: OG membership: Group Taxonomy term from OG membership */
  $handler->display->display_options['relationships']['og_membership_related_taxonomy_term_group']['id'] = 'og_membership_related_taxonomy_term_group';
  $handler->display->display_options['relationships']['og_membership_related_taxonomy_term_group']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['og_membership_related_taxonomy_term_group']['field'] = 'og_membership_related_taxonomy_term_group';
  $handler->display->display_options['relationships']['og_membership_related_taxonomy_term_group']['relationship'] = 'og_membership_rel';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Contextual filter: OG membership: Group ID */
  $handler->display->display_options['arguments']['gid']['id'] = 'gid';
  $handler->display->display_options['arguments']['gid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['gid']['field'] = 'gid';
  $handler->display->display_options['arguments']['gid']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['arguments']['gid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['gid']['default_argument_type'] = 'og_user_groups';
  $handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'board' => 'board',
  );
  /* Filter criterion: OG membership: State */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'og_membership';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['filters']['state']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: OG membership: Group_type */
  $handler->display->display_options['filters']['group_type']['id'] = 'group_type';
  $handler->display->display_options['filters']['group_type']['table'] = 'og_membership';
  $handler->display->display_options['filters']['group_type']['field'] = 'group_type';
  $handler->display->display_options['filters']['group_type']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['filters']['group_type']['value'] = array(
    'taxonomy_term' => 'taxonomy_term',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'user/boards';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'My boards';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-manage-my-city';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
    'og_group_ref' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: City */
  $handler->display->display_options['fields']['og_group_ref']['id'] = 'og_group_ref';
  $handler->display->display_options['fields']['og_group_ref']['table'] = 'og_membership';
  $handler->display->display_options['fields']['og_group_ref']['field'] = 'og_group_ref';
  $handler->display->display_options['fields']['og_group_ref']['label'] = '';
  $handler->display->display_options['fields']['og_group_ref']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['og_group_ref']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;

  /* Display: Entity Reference (admin) */
  $handler = $view->new_display('entityreference', 'Entity Reference (admin)', 'entityreference_admin');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
    'og_group_ref' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: City */
  $handler->display->display_options['fields']['og_group_ref']['id'] = 'og_group_ref';
  $handler->display->display_options['fields']['og_group_ref']['table'] = 'og_membership';
  $handler->display->display_options['fields']['og_group_ref']['field'] = 'og_group_ref';
  $handler->display->display_options['fields']['og_group_ref']['label'] = '';
  $handler->display->display_options['fields']['og_group_ref']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['og_group_ref']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $export['my_boards'] = $view;

  $view = new view();
  $view->name = 'my_members';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'My Members';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'My Members';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Relationship: OG membership: OG membership from Node */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  /* Relationship: OG membership: Group Taxonomy term from OG membership */
  $handler->display->display_options['relationships']['og_membership_related_taxonomy_term_group']['id'] = 'og_membership_related_taxonomy_term_group';
  $handler->display->display_options['relationships']['og_membership_related_taxonomy_term_group']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['og_membership_related_taxonomy_term_group']['field'] = 'og_membership_related_taxonomy_term_group';
  $handler->display->display_options['relationships']['og_membership_related_taxonomy_term_group']['relationship'] = 'og_membership_rel';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: OG membership: Group ID */
  $handler->display->display_options['arguments']['gid']['id'] = 'gid';
  $handler->display->display_options['arguments']['gid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['gid']['field'] = 'gid';
  $handler->display->display_options['arguments']['gid']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['arguments']['gid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['gid']['default_argument_type'] = 'og_user_groups';
  $handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'member' => 'member',
  );
  /* Filter criterion: OG membership: State */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'og_membership';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['filters']['state']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: OG membership: Group_type */
  $handler->display->display_options['filters']['group_type']['id'] = 'group_type';
  $handler->display->display_options['filters']['group_type']['table'] = 'og_membership';
  $handler->display->display_options['filters']['group_type']['field'] = 'group_type';
  $handler->display->display_options['filters']['group_type']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['filters']['group_type']['value'] = array(
    'taxonomy_term' => 'taxonomy_term',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'My Members';
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['path'] = 'user/members';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'My members';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-manage-my-city';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
    'og_group_ref' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: City */
  $handler->display->display_options['fields']['og_group_ref']['id'] = 'og_group_ref';
  $handler->display->display_options['fields']['og_group_ref']['table'] = 'og_membership';
  $handler->display->display_options['fields']['og_group_ref']['field'] = 'og_group_ref';
  $handler->display->display_options['fields']['og_group_ref']['label'] = '';
  $handler->display->display_options['fields']['og_group_ref']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['og_group_ref']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;

  /* Display: Entity Reference (admin) */
  $handler = $view->new_display('entityreference', 'Entity Reference (admin)', 'entityreference_admin');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
    'og_group_ref' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: City */
  $handler->display->display_options['fields']['og_group_ref']['id'] = 'og_group_ref';
  $handler->display->display_options['fields']['og_group_ref']['table'] = 'og_membership';
  $handler->display->display_options['fields']['og_group_ref']['field'] = 'og_group_ref';
  $handler->display->display_options['fields']['og_group_ref']['label'] = '';
  $handler->display->display_options['fields']['og_group_ref']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['og_group_ref']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'member' => 'member',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $export['my_members'] = $view;

  $view = new view();
  $view->name = 'public_all_boards';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Public: all boards';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Boards';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'board' => 'board',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'boards';
  $export['public_all_boards'] = $view;

  $view = new view();
  $view->name = 'public_cities';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Public: cities';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Cities';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'city/[name]/boards';
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path_case'] = 'lower';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'city' => 'city',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'cities';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Cities';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Front Page Block */
  $handler = $view->new_display('block', 'Front Page Block', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['display_description'] = 'Block displayed on the front page';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['text'] = '<span class="field-content"><span class="centering-wrapper">[name]</span></span>';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'city/[name]/boards';
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path_case'] = 'lower';
  $handler->display->display_options['fields']['name']['alter']['link_class'] = 'views-field-name';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_type'] = '0';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_wrapper_type'] = '0';
  $export['public_cities'] = $view;

  $view = new view();
  $view->name = 'public_city_boards';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Public: city boards';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Boards for city';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['tid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['tid']['title'] = 'Boards in %1';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['tid']['validate_options']['vocabularies'] = array(
    'city' => 'city',
  );
  $handler->display->display_options['arguments']['tid']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['tid']['validate_options']['transform'] = TRUE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'board' => 'board',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'city/%/boards';
  $handler->display->display_options['menu']['title'] = 'My boards';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-manage-my-city';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: catch taxonomy term urls page */
  $handler = $view->new_display('page', 'catch taxonomy term urls page', 'page_1');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['tid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['tid']['title'] = 'Boards in %1';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['tid']['validate_options']['vocabularies'] = array(
    'city' => 'city',
  );
  $handler->display->display_options['arguments']['tid']['validate_options']['transform'] = TRUE;
  $handler->display->display_options['path'] = 'taxonomy/term/%';
  $export['public_city_boards'] = $view;

  $view = new view();
  $view->name = 'recent_updates';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Recent updates';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Recent updates';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = '';
  $handler->display->display_options['fields']['changed']['exclude'] = TRUE;
  $handler->display->display_options['fields']['changed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['changed']['date_format'] = 'time ago';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[name] edited [title] [changed]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'recent-updates';
  $export['recent_updates'] = $view;

  return $export;
}
