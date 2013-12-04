@api
Feature: Automatic field values for custom content types 
  In order to manage boards, board terms and people with minimum data entry
  As a clerk 
  I need to be able to have some field values automatically assigned

  Scenario: City field of Person is automatically populated
    Given cities:
      | name      |
      | Ferndale  |
    And users:
      | name  | status | 
      | nancy | 1      |     
    And clerks:
      | user  | city     |
      | nancy | Ferndale |
    And I am logged in as "nancy"
    When I go to add a person
    And I fill in "Name" with "Test Person"
    And I fill in "Email" with "test@email.com"
    And I press "Save"
    Then I should see "Person Test Person has been created"
    And I should see "Ferndale"

  @javascript
  Scenario: City field of Board Term is automatically populated
    Given cities:
      | name      |
      | Ferndale  |
    And users:
      | name  | status |
      | nancy | 1      |
    And clerks:
      | user  | city      |
      | nancy | Ferndale  |
    And boards:
      | title                 | author           | city         |
      | Beautification Board  | nancy            | Ferndale     |
    And people:
      | name        | author |
      | Test Person | nancy  |
    And I am logged in as "nancy"
    When I go to add a board term
    And I fill in "field_term_dates[und][0][value][date]" with "12/24/1983"
    And I fill in "field_term_dates[und][0][value2][date]" with "1/1/1985"
    And I select "Beautification Board" from the "Board" autocomplete field
    And I select "Test Person" from the "Person" autocomplete field
    And I press "Save"
    Then I should see "has been created" 
    And I should see "Ferndale"
