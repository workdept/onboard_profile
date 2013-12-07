<?php
/**
 * @file
 * onboard_types.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function onboard_types_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create board content'.
  $permissions['create board content'] = array(
    'name' => 'create board content',
    'roles' => array(
      'administrator' => 'administrator',
      'clerk' => 'clerk',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create board_term content'.
  $permissions['create board_term content'] = array(
    'name' => 'create board_term content',
    'roles' => array(
      'administrator' => 'administrator',
      'clerk' => 'clerk',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create member content'.
  $permissions['create member content'] = array(
    'name' => 'create member content',
    'roles' => array(
      'clerk' => 'clerk',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any board content'.
  $permissions['delete any board content'] = array(
    'name' => 'delete any board content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any board_term content'.
  $permissions['delete any board_term content'] = array(
    'name' => 'delete any board_term content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any member content'.
  $permissions['delete any member content'] = array(
    'name' => 'delete any member content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own board content'.
  $permissions['delete own board content'] = array(
    'name' => 'delete own board content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own board_term content'.
  $permissions['delete own board_term content'] = array(
    'name' => 'delete own board_term content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own member content'.
  $permissions['delete own member content'] = array(
    'name' => 'delete own member content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any board content'.
  $permissions['edit any board content'] = array(
    'name' => 'edit any board content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any board_term content'.
  $permissions['edit any board_term content'] = array(
    'name' => 'edit any board_term content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any member content'.
  $permissions['edit any member content'] = array(
    'name' => 'edit any member content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own board content'.
  $permissions['edit own board content'] = array(
    'name' => 'edit own board content',
    'roles' => array(
      'administrator' => 'administrator',
      'clerk' => 'clerk',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own board_term content'.
  $permissions['edit own board_term content'] = array(
    'name' => 'edit own board_term content',
    'roles' => array(
      'administrator' => 'administrator',
      'clerk' => 'clerk',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own member content'.
  $permissions['edit own member content'] = array(
    'name' => 'edit own member content',
    'roles' => array(
      'clerk' => 'clerk',
    ),
    'module' => 'node',
  );

  // Exported permission: 'publish any board content'.
  $permissions['publish any board content'] = array(
    'name' => 'publish any board content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: 'publish any board_term content'.
  $permissions['publish any board_term content'] = array(
    'name' => 'publish any board_term content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: 'publish any member content'.
  $permissions['publish any member content'] = array(
    'name' => 'publish any member content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: 'publish editable board content'.
  $permissions['publish editable board content'] = array(
    'name' => 'publish editable board content',
    'roles' => array(
      'administrator' => 'administrator',
      'clerk' => 'clerk',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: 'publish editable board_term content'.
  $permissions['publish editable board_term content'] = array(
    'name' => 'publish editable board_term content',
    'roles' => array(
      'administrator' => 'administrator',
      'clerk' => 'clerk',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: 'publish editable member content'.
  $permissions['publish editable member content'] = array(
    'name' => 'publish editable member content',
    'roles' => array(
      'administrator' => 'administrator',
      'clerk' => 'clerk',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: 'publish own board content'.
  $permissions['publish own board content'] = array(
    'name' => 'publish own board content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: 'publish own board_term content'.
  $permissions['publish own board_term content'] = array(
    'name' => 'publish own board_term content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: 'publish own member content'.
  $permissions['publish own member content'] = array(
    'name' => 'publish own member content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: 'unpublish any board content'.
  $permissions['unpublish any board content'] = array(
    'name' => 'unpublish any board content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: 'unpublish any board_term content'.
  $permissions['unpublish any board_term content'] = array(
    'name' => 'unpublish any board_term content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: 'unpublish any member content'.
  $permissions['unpublish any member content'] = array(
    'name' => 'unpublish any member content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: 'unpublish editable board content'.
  $permissions['unpublish editable board content'] = array(
    'name' => 'unpublish editable board content',
    'roles' => array(
      'administrator' => 'administrator',
      'clerk' => 'clerk',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: 'unpublish editable board_term content'.
  $permissions['unpublish editable board_term content'] = array(
    'name' => 'unpublish editable board_term content',
    'roles' => array(
      'administrator' => 'administrator',
      'clerk' => 'clerk',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: 'unpublish editable member content'.
  $permissions['unpublish editable member content'] = array(
    'name' => 'unpublish editable member content',
    'roles' => array(
      'administrator' => 'administrator',
      'clerk' => 'clerk',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: 'unpublish own board content'.
  $permissions['unpublish own board content'] = array(
    'name' => 'unpublish own board content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: 'unpublish own board_term content'.
  $permissions['unpublish own board_term content'] = array(
    'name' => 'unpublish own board_term content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: 'unpublish own member content'.
  $permissions['unpublish own member content'] = array(
    'name' => 'unpublish own member content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: 'view own unpublished content'.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      'administrator' => 'administrator',
      'clerk' => 'clerk',
    ),
    'module' => 'node',
  );

  return $permissions;
}
