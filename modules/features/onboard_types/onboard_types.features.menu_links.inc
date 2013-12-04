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

  // Exported menu link: shortcuts-onboard_add-city:admin/structure/taxonomy/city/add
  $menu_links['shortcuts-onboard_add-city:admin/structure/taxonomy/city/add'] = array(
    'menu_name' => 'shortcuts-onboard',
    'link_path' => 'admin/structure/taxonomy/city/add',
    'router_path' => 'admin/structure/taxonomy/%/add',
    'link_title' => 'Add city',
    'options' => array(
      'identifier' => 'shortcuts-onboard_add-city:admin/structure/taxonomy/city/add',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 0,
  );
  // Exported menu link: shortcuts-onboard_add-people-boards-or-board-terms:node/add
  $menu_links['shortcuts-onboard_add-people-boards-or-board-terms:node/add'] = array(
    'menu_name' => 'shortcuts-onboard',
    'link_path' => 'node/add',
    'router_path' => 'node/add',
    'link_title' => 'Add people, boards, or board terms',
    'options' => array(
      'identifier' => 'shortcuts-onboard_add-people-boards-or-board-terms:node/add',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 0,
  );
  // Exported menu link: shortcuts-onboard_find-people-boards-or-board-terms:admin/content
  $menu_links['shortcuts-onboard_find-people-boards-or-board-terms:admin/content'] = array(
    'menu_name' => 'shortcuts-onboard',
    'link_path' => 'admin/content',
    'router_path' => 'admin/content',
    'link_title' => 'Find people, boards, or board terms',
    'options' => array(
      'identifier' => 'shortcuts-onboard_find-people-boards-or-board-terms:admin/content',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 0,
  );
  // Exported menu link: shortcuts-onboard_manage-cities:admin/structure/taxonomy/city
  $menu_links['shortcuts-onboard_manage-cities:admin/structure/taxonomy/city'] = array(
    'menu_name' => 'shortcuts-onboard',
    'link_path' => 'admin/structure/taxonomy/city',
    'router_path' => 'admin/structure/taxonomy/%',
    'link_title' => 'Manage cities',
    'options' => array(
      'identifier' => 'shortcuts-onboard_manage-cities:admin/structure/taxonomy/city',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Add city');
  t('Add people, boards, or board terms');
  t('Find people, boards, or board terms');
  t('Manage cities');


  return $menu_links;
}
