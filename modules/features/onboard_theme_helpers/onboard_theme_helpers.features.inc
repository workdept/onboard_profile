<?php
/**
 * @file
 * onboard_theme_helpers.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function onboard_theme_helpers_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
