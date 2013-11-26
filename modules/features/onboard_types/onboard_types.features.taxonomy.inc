<?php
/**
 * @file
 * onboard_types.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function onboard_types_taxonomy_default_vocabularies() {
  return array(
    'city' => array(
      'name' => 'City',
      'machine_name' => 'city',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
