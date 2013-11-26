<?php
/**
 * @file
 * onboard_types.features.og_features_role.inc
 */

/**
 * Implements hook_og_features_default_roles().
 */
function onboard_types_og_features_default_roles() {
  $roles = array();

  // Exported OG Role: 'taxonomy_term:city:clerk'.
  $roles['taxonomy_term:city:clerk'] = array(
    'gid' => 0,
    'group_type' => 'taxonomy_term',
    'group_bundle' => 'city',
    'name' => 'clerk',
  );

  return $roles;
}
