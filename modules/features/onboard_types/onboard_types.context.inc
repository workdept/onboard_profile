<?php
/**
 * @file
 * onboard_types.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function onboard_types_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'board';
  $context->description = 'clerk boards view';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'board' => 'board',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'user' => array(
      'values' => array(
        'administrator' => 'administrator',
        'clerk' => 'clerk',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-board_terms-block_1' => array(
          'module' => 'views',
          'delta' => 'board_terms-block_1',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('clerk boards view');
  $export['board'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'clerks';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
    'user' => array(
      'values' => array(
        'clerk' => 'clerk',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-menu-manage-my-city' => array(
          'module' => 'menu',
          'delta' => 'menu-manage-my-city',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;
  $export['clerks'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'public_board';
  $context->description = 'public board view';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'board' => 'board',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'user' => array(
      'values' => array(
        'anonymous user' => 'anonymous user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-board_terms-block_2' => array(
          'module' => 'views',
          'delta' => 'board_terms-block_2',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('public board view');
  $export['public_board'] = $context;

  return $export;
}
