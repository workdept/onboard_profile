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
      'clerk' => 'clerk',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create board_term content'.
  $permissions['create board_term content'] = array(
    'name' => 'create board_term content',
    'roles' => array(
      'clerk' => 'clerk',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create person content'.
  $permissions['create person content'] = array(
    'name' => 'create person content',
    'roles' => array(
      'clerk' => 'clerk',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any board content'.
  $permissions['delete any board content'] = array(
    'name' => 'delete any board content',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any board_term content'.
  $permissions['delete any board_term content'] = array(
    'name' => 'delete any board_term content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any person content'.
  $permissions['delete any person content'] = array(
    'name' => 'delete any person content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own board content'.
  $permissions['delete own board content'] = array(
    'name' => 'delete own board content',
    'roles' => array(
      'clerk' => 'clerk',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own board_term content'.
  $permissions['delete own board_term content'] = array(
    'name' => 'delete own board_term content',
    'roles' => array(
      'clerk' => 'clerk',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own person content'.
  $permissions['delete own person content'] = array(
    'name' => 'delete own person content',
    'roles' => array(
      'clerk' => 'clerk',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any board content'.
  $permissions['edit any board content'] = array(
    'name' => 'edit any board content',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any board_term content'.
  $permissions['edit any board_term content'] = array(
    'name' => 'edit any board_term content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any person content'.
  $permissions['edit any person content'] = array(
    'name' => 'edit any person content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own board content'.
  $permissions['edit own board content'] = array(
    'name' => 'edit own board content',
    'roles' => array(
      'clerk' => 'clerk',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own board_term content'.
  $permissions['edit own board_term content'] = array(
    'name' => 'edit own board_term content',
    'roles' => array(
      'clerk' => 'clerk',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own person content'.
  $permissions['edit own person content'] = array(
    'name' => 'edit own person content',
    'roles' => array(
      'clerk' => 'clerk',
    ),
    'module' => 'node',
  );

  return $permissions;
}
