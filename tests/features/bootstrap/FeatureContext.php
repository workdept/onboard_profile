<?php

use Drupal\DrupalExtension\Context\DrupalContext;
use Behat\Behat\Exception\PendingException;
use Behat\Gherkin\Node\TableNode;

class FeatureContext extends DrupalContext
{
  public function goToViewNode($node) {
    parent::visit(sprintf("node/%d", $node->nid));
  }

  public function goToEditNode($node) {
    parent::visit(sprintf("node/%d/edit", $node->nid));
  }

  public function goToDeleteNode($node) {
    parent::visit(sprintf("node/%d/delete", $node->nid));
  }

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

    return node_load(array_keys($entities['node'])[0]);
  }

  /**
   * @When /^I go to add a board$/
   */
  public function goToAddBoard() {
    parent::visit("node/add/board");
  }

  /**
   * @When /^I go to view the board "([^"]*)" for "([^"]*)"$/
   */
  public function goToViewBoard($board_name, $city_name) {
    $board = $this->getBoard($board_name, $city_name);
    $this->goToViewNode($board);
  }

  /**
   * @When /^I go to edit the board "([^"]*)" for "([^"]*)"$/
   */
  public function goToEditBoard($board_name, $city_name) {
    $board = $this->getBoard($board_name, $city_name);
    $this->goToEditNode($board);
  }

  /**
   * @When /^I go to delete the board "([^"]*)" for "([^"]*)"$/
   */
  public function goToDeleteBoard($board_name, $city_name) {
    $board = $this->getBoard($board_name, $city_name);
    $this->goToDeleteNode($board);
  }

  /**
   * @When /^I go to add a person$/
   */
  public function goToAddPerson() {
    parent::visit("node/add/person");
  }

  /**
   * @Given /^people:$/
   */
  public function people(TableNode $table) {
    // Get the table rows.  We're going to change them
    $rows = $table->getRows();
    $name_idx = array_search('name', $rows[0]);
    // Convert the 'name' column of the table to be
    // 'title', the actual field name
    $rows[0][$name_idx] = 'title';

    // Update the rows in the table
    $table->setRows($rows);
    parent::createNodes('person', $table);
  }

  public function getPerson($person_name) {
    $query = new EntityFieldQuery();
    $entities = $query->entityCondition('entity_type', 'node')
      ->propertyCondition('type', 'person')
      ->propertyCondition('title', $person_name)
      ->range(0, 1)
      ->execute();

    if (empty($entities['node'])) {
      return FALSE;
    }

    return node_load(array_keys($entities['node'])[0]);
  }

  /**
   * @When /^I go to edit the person "([^"]*)"$/
   */
  public function goToEditPerson($name) {
    $person = $this->getPerson($name);
    $this->goToEditNode($person);
  }

  /**
   * @When /^I go to delete the person "([^"]*)"$/
   */
  public function goToDeletePerson($name) {
    $person = $this->getPerson($name);
    $this->goToDeleteNode($person);
  }

  public function getBoardTerm($city_name, $board_name, $person_name) {
    $board = $this->getBoard($board_name, $city_name);
    $person = $this->getPerson($person_name);
    $query = new EntityFieldQuery();
    $entities = $query->entityCondition('entity_type', 'node')
      ->propertyCondition('type', 'board_term')
      ->fieldCondition('field_board', 'target_id', $board->nid, '=')
      ->fieldCondition('field_person', 'target_id', $person->nid, '=')
      ->range(0, 1)
      ->execute();

    if (empty($entities['node'])) {
      return FALSE;
    }

    $node = node_load(array_keys($entities['node'])[0]);
    return $node;
  }

  /**
   * @Given /^board terms:$/
   */
  public function boardTerms(TableNode $table) {
    $rows = $table->getRows();

    $city_idx = array_search('city', $rows[0]);
    $board_idx = array_search('board', $rows[0]);
    $person_idx = array_search('person', $rows[0]);
    $start_idx = array_search('start', $rows[0]);
    $end_idx = array_search('end', $rows[0]);

    $rows[0][$board_idx] = 'field_board';
    $rows[0][$person_idx] = 'field_person';
    array_splice($rows[0], $city_idx, $city_idx + 1);

    for ($i = 1; $i < count($rows); $i++) {
      $city_name = $rows[$i][$city_idx];
      $board_name = $rows[$i][$board_idx];
      $board = $this->getBoard($board_name, $city_name);
      $person = $this->getPerson($rows[$i][$person_idx]);

      $rows[$i][$board_idx] = $board->nid;
      $rows[$i][$person_idx] = $person->nid;
      array_splice($rows[$i], $city_idx, $city_idx + 1);
    }
    $table->setRows($rows);

    parent::createNodes('board_term', $table);
  }

  /**
   * @When /^I go to edit the board term for the city of "([^"]*)" board "([^"]*)" for "([^"]*)"$/
   */
  public function goToEditBoardTerm($city_name, $board_name, $person_name) {
    $term = $this->getBoardTerm($city_name, $board_name, $person_name);
    $this->goToEditNode($term);
  }

  /**
   * @When /^I go to add a board term$/
   */
  public function goToAddBoardTerm() {
    parent::visit("node/add/board-term");
  }

  /**
   * @When /^I go to delete the board term for the city of "([^"]*)" board "([^"]*)" for "([^"]*)"$/
   */
  public function goToDeleteBoardTerm($city_name, $board_name, $person_name) {
    $term = $this->getBoardTerm($city_name, $board_name, $person_name);
    $this->goToDeleteNode($term);
  }

  /**
   * @Given /^I wait (\d+) seconds?$/
   */
  public function iWait($seconds) {
    sleep($seconds);
  }

  /**
   * @Given /^I select "([^"]*)" from the "([^"]*)" autocomplete field$/
   */
  public function iSelectFromTheAutocompleteField($value, $field) {
    $this->getSession()->getPage()->fillField($field, $value);
    $this->iWait(1);
    // Down arrow
    parent::pressKey(40, $field);
    parent::pressKey("enter", $field);
  }
}
