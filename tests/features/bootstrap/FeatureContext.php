<?php

use Drupal\DrupalExtension\Context\DrupalContext;
use Behat\Behat\Exception\PendingException;
use Behat\Gherkin\Node\TableNode;

class FeatureContext extends DrupalContext
{
  /**
   * @Given /^cities:$/
   */
  public function cities(TableNode $table) {
    // Abstract away the implementation of city as a taxonomy term
    parent::createTerms("city", $table);
  }

  public function getCity($city_name) {
    $city_terms = taxonomy_get_term_by_name($city_name);
    $city_term = reset($city_terms); 
    return $city_term;
  }

  public function assignClerk($user, $city_name) {
    $city = $this->getCity($city_name);
    $roles = og_roles('taxonomy_term', 'city', $city->tid);
    $rid = array_search('clerk', $roles);
    og_group('taxonomy_term', $city->tid, array(
      'entity_type' => 'user',
      'entity' => $user,
    ));
    og_role_grant('taxonomy_term', $city->tid, $user->uid, $rid);
  }

  /**
   * @Given /^clerks:$/
   */
  public function clerks(TableNode $table) {
    foreach ($table->getHash() as $clerk_map) {
      $user = user_load_by_name($clerk_map['user']);
      $this->getDriver()->userAddRole($user, 'clerk');  
      $this->assignClerk($user, $clerk_map['city']);
    } 
  }

  /**
   * @Given /^boards:$/
   */
  public function boards(TableNode $table) {
    // Get the table rows.  We're going to change them
    $rows = $table->getRows();
    $city_idx = array_search('city', $rows[0]);
    // Convert the 'city' column of the table to be
    // 'og_group_ref', the actual field name
    $rows[0][$city_idx] = 'og_group_ref';
    for ($i = 1; $i < count($rows); $i++) {
      // Convert the city name to a group id (in our case
      // a taxonomy id)
      $city = $this->getCity($rows[$i][$city_idx]);
      $rows[$i][$city_idx] = $city->tid;
    }
    // Update the rows in the table
    $table->setRows($rows);
    // Call upstream to actually create the nodes
    parent::createNodes('board', $table);
  }


  public function getBoard($board_name, $city_name) {
    $city = $this->getCity($city_name);
    $query = new EntityFieldQuery();
    $entities = $query->entityCondition('entity_type', 'node')
      ->propertyCondition('type', 'board')
      ->propertyCondition('title', $board_name)
      ->fieldCondition('og_group_ref', 'target_id', $city->tid, '=')
      ->range(0, 1)
      ->execute();

    if (empty($entities['node'])) {
      return FALSE;
    }

    $node = node_load(array_keys($entities['node'])[0]);
    return $node;
  }

  /**
   * @When /^I go to view the board "([^"]*)" for "([^"]*)"$/
   */
  public function goToViewBoard($board_name, $city_name) {
    $board = $this->getBoard($board_name, $city_name);
    parent::visit(sprintf("node/%d", $board->nid));
  }

  /**
   * @When /^I go to edit the board "([^"]*)" for "([^"]*)"$/
   */
  public function goToEditBoard($board_name, $city_name) {
    $board = $this->getBoard($board_name, $city_name);
    parent::visit(sprintf("node/%d/edit", $board->nid));
  }

  /**
   * @When /^I go to delete the board "([^"]*)" for "([^"]*)"$/
   */
  public function goToDeleteBoard($board_name, $city_name) {
    $board = $this->getBoard($board_name, $city_name);
    parent::visit(sprintf("node/%d/delete", $board->nid));
  }

}
