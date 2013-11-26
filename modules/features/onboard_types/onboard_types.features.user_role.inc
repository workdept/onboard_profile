<?php
/**
 * @file
 * onboard_types.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function onboard_types_user_default_roles() {
  $roles = array();

  // Exported role: clerk.
  $roles['clerk'] = array(
    'name' => 'clerk',
    'weight' => 4,
  );

  return $roles;
}
