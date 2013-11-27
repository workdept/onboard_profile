@api
Feature: DrupalContext
  In order to prove the Drupal context is working properly
  As a developer
  I need to use the step definitions of this context

  # These scenarios assume a "standard" install of Drupal 7.

  @drush
  Scenario: Create and log in as a user
    Given I am logged in as a user with the "authenticated user" role
    When I click "My account"
    Then I should see the heading "History"

  @drush
  Scenario: Target links within table rows
    Given I am logged in as a user with the "administrator" role
    When I am at "admin/structure/types"
    And I click "manage fields" in the "Basic page" row
    Then I should be on "admin/structure/types/manage/page/fields"
    And I should see text matching "Add new field"

  @drush
  Scenario: Find a heading in a region
    Given I am not logged in
    When I am on the homepage
    Then I should see the heading "User login" in the "First sidebar" region

  @drush
  Scenario: Clear cache
    Given the cache has been cleared
    When I am on the homepage
    Then I should get a "200" HTTP response

  @drush
  Scenario: Run cron
    Given I am logged in as a user with the "administrator" role
    When I run cron
    And am on "admin/reports/dblog"
    Then I should see the link "Cron run completed"

  Scenario: Create a node
    Given I am logged in as a user with the "administrator" role
    When I am viewing a "page" node with the title "My page"
    Then I should see the heading "My page"

  Scenario: Create many nodes
    Given "page" nodes:
    | title    |
    | Page one |
    | Page two |
    And "Board" nodes:
    | title              |
    | Board of Education |
    | Board of Testing   |
    And I am logged in as a user with the "administrator" role
    When I go to "admin/content"
    Then I should see "Page one"
    And I should see "Page two"
    And I should see "Board of Education"
    And I should see "Board of Testing"

  Scenario: Create nodes with fields
    Given "page" nodes:
    | title                  | promote | body             |
    | First page with fields |       1 | PLACEHOLDER BODY |
    When I am on the homepage
    And follow "First page with fields"
    Then I should see the text "PLACEHOLDER BODY"

  Scenario: Create and view a node with fields
    Given I am viewing a "Page" node:
    | title | My page with fields! |
    | body  | A placeholder        |
    Then I should see the heading "My page with fields!"
    And I should see the text "A placeholder"

  Scenario: Create users
    Given users:
    | name     | mail            | status |
    | Joe User | joe@example.com | 1      |
    And I am logged in as a user with the "administrator" role
    When I visit "admin/people"
    Then I should see the link "Joe User"

  Scenario: Login as a user created during this scenario
    Given users:
    | name      | status |
    | Test user |      1 |
    When I am logged in as "Test user"
    Then I should see the link "Log out"

  Scenario: Create a term
    Given I am logged in as a user with the "administrator" role
    When I am viewing a "city" term with the name "Melvindale"
    Then I should see the heading "Melvindale"

  Scenario: Create many terms
    Given "city" terms:
    | name        |
    | Ecorse      |
    | River Rouge |
    And I am logged in as a user with the "administrator" role
    When I go to "admin/structure/taxonomy/city"
    Then I should see "Ecorse"
    And I should see "River Rouge"

  Scenario: Create terms using vocabulary title rather than machine name.
    Given "City" terms:
    | name        |
    | Ecorse      |
    | River Rouge |
    And I am logged in as a user with the "administrator" role
    When I go to "admin/structure/taxonomy/city"
    Then I should see "Ecorse"
    And I should see "River Rouge"

  Scenario: Create nodes with specific authorship
    Given users:
    | name     | mail            | status |
    | Joe User | joe@example.com | 1      |
    And "page" nodes:
    | title       | author   | body             | promote |
    | Page by Joe | Joe User | PLACEHOLDER BODY | 1       |
    When I am logged in as a user with the "administrator" role
    And I am on the homepage
    And I follow "Page by Joe"
    Then I should see the link "Joe User"

  Scenario: Create a board with city reference
    Given "city" terms:
    | name       |
    | Commerce   |
    | Southfield |
    And "board" nodes:
    | title         | body             | promote | og_group_ref |
    | Board by Joe  | PLACEHOLDER BODY |       1 | Commerce     |
    | Board by Mike | PLACEHOLDER BODY |       1 | Southfield   |
    When I am on the homepage
    Then I should see the link "Commerce"
    And I should see the link "Southfield"

  Scenario: Readable created dates
    Given "article" nodes:
    | title        | body             | created            | status | promote |
    | Test article | PLACEHOLDER BODY | 07/27/2014 12:03am |      1 |       1 |
    When I am on the homepage
    Then I should see the text "Sun, 07/27/2014 - 00:03"

  Scenario: Node hooks are functioning
    Given "article" nodes:
    | title        | body        | published on       | status | promote |
    | Test article | PLACEHOLDER | 04/27/2013 11:11am |      1 |       1 |
    When I am on the homepage
    Then I should see the text "Sat, 04/27/2013 - 11:11"

  Scenario: Node edit access by administrator
    Given I am logged in as a user with the "administrator" role
    Then I should be able to edit an "Article" node

  Scenario: User hooks are functioning
    Given users:
    | First name | Last name | E-mail               |
    | Joe        | User      | joe.user@example.com |
    And I am logged in as a user with the "administrator" role
    When I visit "admin/people"
    Then I should see the link "Joe User"

  Scenario: Term hooks are functioning
    Given "tags" terms:
    | Label     |
    | Tag one   |
    | Tag two   |
    And I am logged in as a user with the "administrator" role
    When I go to "admin/structure/taxonomy/tags"
    Then I should see "Tag one"
    And I should see "Tag two"

  Scenario: Log in as a user with specific permissions
    Given I am logged in as a user with the "Administer content types" permission
    When I go to "admin/structure/types"
    Then I should see the link "Add content type"
