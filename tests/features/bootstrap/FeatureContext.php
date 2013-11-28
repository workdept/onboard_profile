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
}
