<?php
/**
 * @file
 * onboard_types.features.uuid_node.inc
 */

/**
 * Implements hook_uuid_features_default_content().
 */
function onboard_types_uuid_features_default_content() {
  $nodes = array();

  $nodes[] = array(
  'uid' => 1,
  'title' => 'About local government',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'vuuid' => '8a1041f4-cae0-420e-bbde-6d8054afe3b2',
  'type' => 'page',
  'language' => 'und',
  'created' => 1386452459,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '18aeee0d-abfc-4463-bbeb-f1762c6ff923',
  'revision_uid' => 1,
  'body' => array(),
  'name' => 'admin',
  'picture' => 0,
  'data' => 'b:0;',
  'date' => '2013-12-07 16:40:59 -0500',
);
  $nodes[] = array(
  'uid' => 1,
  'title' => 'About us',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'vuuid' => '10982589-2c74-4a79-9781-c44aeb8933c3',
  'type' => 'page',
  'language' => 'und',
  'created' => 1386452439,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => 'db6dd32f-330c-40b2-98fb-c15be223dc56',
  'revision_uid' => 1,
  'body' => array(),
  'name' => 'admin',
  'picture' => 0,
  'data' => 'b:0;',
  'date' => '2013-12-07 16:40:39 -0500',
);
  return $nodes;
}
