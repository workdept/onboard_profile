<?php
/**
 * @file
 * onboard_types.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function onboard_types_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'taxonomy_term:city:add user'
  $permissions['taxonomy_term:city:add user'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'taxonomy_term:city:administer group'
  $permissions['taxonomy_term:city:administer group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'taxonomy_term:city:approve and deny subscription'
  $permissions['taxonomy_term:city:approve and deny subscription'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'taxonomy_term:city:create board content'
  $permissions['taxonomy_term:city:create board content'] = array(
    'roles' => array(
      'clerk' => 'clerk',
    ),
  );

  // Exported og permission: 'taxonomy_term:city:delete any board content'
  $permissions['taxonomy_term:city:delete any board content'] = array(
    'roles' => array(
      'clerk' => 'clerk',
    ),
  );

  // Exported og permission: 'taxonomy_term:city:delete own board content'
  $permissions['taxonomy_term:city:delete own board content'] = array(
    'roles' => array(
      'clerk' => 'clerk',
    ),
  );

  // Exported og permission: 'taxonomy_term:city:manage members'
  $permissions['taxonomy_term:city:manage members'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'taxonomy_term:city:manage permissions'
  $permissions['taxonomy_term:city:manage permissions'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'taxonomy_term:city:manage roles'
  $permissions['taxonomy_term:city:manage roles'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'taxonomy_term:city:subscribe'
  $permissions['taxonomy_term:city:subscribe'] = array(
    'roles' => array(
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'taxonomy_term:city:subscribe without approval'
  $permissions['taxonomy_term:city:subscribe without approval'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'taxonomy_term:city:unsubscribe'
  $permissions['taxonomy_term:city:unsubscribe'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'taxonomy_term:city:update any board content'
  $permissions['taxonomy_term:city:update any board content'] = array(
    'roles' => array(
      'clerk' => 'clerk',
    ),
  );

  // Exported og permission: 'taxonomy_term:city:update body field'
  $permissions['taxonomy_term:city:update body field'] = array(
    'roles' => array(
      'clerk' => 'clerk',
    ),
  );

  // Exported og permission: 'taxonomy_term:city:update group'
  $permissions['taxonomy_term:city:update group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'taxonomy_term:city:update group_group field'
  $permissions['taxonomy_term:city:update group_group field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'taxonomy_term:city:update og_group_ref field'
  $permissions['taxonomy_term:city:update og_group_ref field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'clerk' => 'clerk',
    ),
  );

  // Exported og permission: 'taxonomy_term:city:update og_user_taxonomy_term field'
  $permissions['taxonomy_term:city:update og_user_taxonomy_term field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'taxonomy_term:city:update own board content'
  $permissions['taxonomy_term:city:update own board content'] = array(
    'roles' => array(
      'clerk' => 'clerk',
    ),
  );

  // Exported og permission: 'taxonomy_term:city:view body field'
  $permissions['taxonomy_term:city:view body field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'taxonomy_term:city:view group_group field'
  $permissions['taxonomy_term:city:view group_group field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'taxonomy_term:city:view og_group_ref field'
  $permissions['taxonomy_term:city:view og_group_ref field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'clerk' => 'clerk',
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'taxonomy_term:city:view og_user_taxonomy_term field'
  $permissions['taxonomy_term:city:view og_user_taxonomy_term field'] = array(
    'roles' => array(),
  );

  return $permissions;
}
