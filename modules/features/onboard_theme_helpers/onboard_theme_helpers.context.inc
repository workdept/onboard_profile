<?php
/**
 * @file
 * onboard_theme_helpers.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function onboard_theme_helpers_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'front_page';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-public_cities-block_1' => array(
          'module' => 'views',
          'delta' => 'public_cities-block_1',
          'region' => 'below_content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;
  $export['front_page'] = $context;

  return $export;
}
