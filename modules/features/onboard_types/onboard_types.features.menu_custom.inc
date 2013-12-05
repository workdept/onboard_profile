<?php
/**
 * @file
 * onboard_types.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function onboard_types_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-manage-my-city.
  $menus['menu-manage-my-city'] = array(
    'menu_name' => 'menu-manage-my-city',
    'title' => 'Manage my city',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Manage my city');


  return $menus;
}
