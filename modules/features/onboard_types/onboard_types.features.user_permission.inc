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
      'clerk' => 'clerk',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own board_term content'.
  $permissions['delete own board_term content'] = array(
    'name' => 'delete own board_term content',
    'roles' => array(
      'administrator' => 'administrator',
      'clerk' => 'clerk',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own member content'.
  $permissions['delete own member content'] = array(
    'name' => 'delete own member content',
    'roles' => array(
      'clerk' => 'clerk',
    ),
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
