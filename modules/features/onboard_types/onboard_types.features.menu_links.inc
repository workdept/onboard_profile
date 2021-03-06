<?php
/**
 * @file
 * onboard_types.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function onboard_types_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-manage-my-city_log-out:user/logout
  $menu_links['menu-manage-my-city_log-out:user/logout'] = array(
    'menu_name' => 'menu-manage-my-city',
    'link_path' => 'user/logout',
    'router_path' => 'user/logout',
    'link_title' => 'Log out',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-manage-my-city_log-out:user/logout',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
  );
  // Exported menu link: menu-manage-my-city_my-boards:user/boards
  $menu_links['menu-manage-my-city_my-boards:user/boards'] = array(
    'menu_name' => 'menu-manage-my-city',
    'link_path' => 'user/boards',
    'router_path' => 'user/boards',
    'link_title' => 'My Boards',
    'options' => array(
      'identifier' => 'menu-manage-my-city_my-boards:user/boards',
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Log out');
  t('My Boards');


  return $menu_links;
}
