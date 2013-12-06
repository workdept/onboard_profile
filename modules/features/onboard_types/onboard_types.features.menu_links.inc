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

  // Exported menu link: menu-manage-my-city_add-board-term:node/add/board-term
  $menu_links['menu-manage-my-city_add-board-term:node/add/board-term'] = array(
    'menu_name' => 'menu-manage-my-city',
    'link_path' => 'node/add/board-term',
    'router_path' => 'node/add/board-term',
    'link_title' => 'Add board term',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-manage-my-city_add-board-term:node/add/board-term',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: menu-manage-my-city_add-board:node/add/board
  $menu_links['menu-manage-my-city_add-board:node/add/board'] = array(
    'menu_name' => 'menu-manage-my-city',
    'link_path' => 'node/add/board',
    'router_path' => 'node/add/board',
    'link_title' => 'Add board',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-manage-my-city_add-board:node/add/board',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: menu-manage-my-city_add-member:node/add/member
  $menu_links['menu-manage-my-city_add-member:node/add/member'] = array(
    'menu_name' => 'menu-manage-my-city',
    'link_path' => 'node/add/member',
    'router_path' => 'node/add',
    'link_title' => 'Add member',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-manage-my-city_add-member:node/add/member',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: menu-manage-my-city_get-help:<front>
  $menu_links['menu-manage-my-city_get-help:<front>'] = array(
    'menu_name' => 'menu-manage-my-city',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Get help',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-manage-my-city_get-help:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
  );
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
    'hidden' => 0,
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
    'link_title' => 'My boards',
    'options' => array(
      'identifier' => 'menu-manage-my-city_my-boards:user/boards',
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
  t('Add board');
  t('Add board term');
  t('Add member');
  t('Get help');
  t('Log out');
  t('My boards');


  return $menu_links;
}
