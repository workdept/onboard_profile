<?php
/**
 * @file
 * onboard_types.features.shortcut_set.inc
 */

/**
 * Implements hook_shortcut_default_shortcut_set().
 */
function onboard_types_shortcut_default_shortcut_set() {
  $shortcut_sets = array();
  $shortcut_sets['shortcuts-onboard'] = array(
    'set_name' => 'shortcuts-onboard',
    'title' => 'On Board shortcuts',
  );
  return $shortcut_sets;
}
