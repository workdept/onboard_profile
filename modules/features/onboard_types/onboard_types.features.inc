<?php
/**
 * @file
 * onboard_types.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function onboard_types_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function onboard_types_node_info() {
  $items = array(
    'board' => array(
      'name' => t('Board'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
    'board_term' => array(
      'name' => t('Board term'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('don\'t need a title, TODO REMOVE THIS'),
      'help' => '',
    ),
    'person' => array(
      'name' => t('Person'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  return $items;
}
