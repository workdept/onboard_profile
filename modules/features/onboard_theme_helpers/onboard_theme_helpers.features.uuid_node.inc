<?php
/**
 * @file
 * onboard_theme_helpers.features.uuid_node.inc
 */

/**
 * Implements hook_uuid_features_default_content().
 */
function onboard_theme_helpers_uuid_features_default_content() {
  $nodes = array();

  $nodes[] = array(
  'uid' => 1,
  'title' => 'Page Not Found',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'vuuid' => '178b1ad1-26c5-4da0-bb3c-2b15ea4e4de4',
  'type' => 'page',
  'language' => 'und',
  'created' => 1388762893,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '4c252070-8b71-42eb-9fca-d21364c33927',
  'revision_uid' => 0,
  'body' => array(
    'und' => array(
      0 => array(
        'value' => 'Oops! Sorry, the page you\'re looking for can\'t be found.

<a href="/">Visit our home page</a>. ',
        'summary' => '',
        'format' => 'filtered_html',
        'safe_value' => '<p>Oops! Sorry, the page you\'re looking for can\'t be found.</p>
<p><a href="/">Visit our home page</a>.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
  'name' => 'admin',
  'picture' => 0,
  'data' => 'b:0;',
  'date' => '2014-01-03 10:28:13 -0500',
);
  $nodes[] = array(
  'uid' => 1,
  'title' => 'Access Denied',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'vuuid' => 'c69190f9-e463-4dc1-bcb8-8cc09fb13a39',
  'type' => 'page',
  'language' => 'und',
  'created' => 1388762978,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => 'dbc85b7e-0109-4f7b-82e4-d5f9463ad7eb',
  'revision_uid' => 0,
  'body' => array(
    'und' => array(
      0 => array(
        'value' => 'Oops! Sorry, you need to log in to view this page.

<a href="/user">Log in here</a>.',
        'summary' => '',
        'format' => 'filtered_html',
        'safe_value' => '<p>Oops! Sorry, you need to log in to view this page.</p>
<p><a href="/user">Log in here</a>.</p>
',
        'safe_summary' => '',
      ),
    ),
  ),
  'name' => 'admin',
  'picture' => 0,
  'data' => 'b:0;',
  'date' => '2014-01-03 10:29:38 -0500',
);
  return $nodes;
}
