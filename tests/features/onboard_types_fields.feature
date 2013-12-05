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
  Scenario: An administrator can manually set the City field of a Person
    Given cities:
      | name      |
      | Ferndale  |
    And I am logged in as a user with the "administrator" role
    When I go to add a person
    And I fill in "Name" with "Test Person"
    And I fill in "Email" with "test@email.com"
    And I select "Ferndale" from the "Other groups" autocomplete field
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

  @javascript
  Scenario: Board field is limited to boards in a clerk's city when adding a Board Term
    Given cities:
      | name      |
      | Ferndale  |
      | Ypsilanti |
    And users:
      | name  | status |
      | nancy | 1      |
      | ada   | 1      |
      | allen | 1      |
    And clerks:
      | user  | city      |
      | nancy | Ferndale  |
      | allen | Ferndale  |
      | ada   | Ypsilanti |
    And boards:
      | title                 | author | city      |
      | Beautification Board  | nancy  | Ferndale  |
      | Parks Board           | ada    | Ypsilanti |
      | School Board          | allen  | Ferndale  |
    And people:
      | name        | author |
      | Test Person | nancy  |
    And I am logged in as "nancy"
    When I go to add a board term
    And I fill in "field_term_dates[und][0][value][date]" with "12/24/1983"
    And I fill in "field_term_dates[und][0][value2][date]" with "1/1/1985"
    And I fill in "boa" for "Board"
    And I wait 1 second
    Then I should see "Beautification Board"
    And I should see "School Board"
    And I should not see "Parks Board"

  @javascript
  Scenario: Person field is limited to people in a clerk's city when adding a Board Term
    Given cities:
      | name      |
      | Ferndale  |
      | Ypsilanti |
    And users:
      | name  | status |
      | nancy | 1      |
      | ada   | 1      |
      | allen | 1      |
    And clerks:
      | user  | city      |
      | nancy | Ferndale  |
      | allen | Ferndale  |
      | ada   | Ypsilanti |
    And boards:
      | title                 | author | city      |
      | Beautification Board  | nancy  | Ferndale  |
    And people:
      | name          | author |
      | Test Person   | nancy  |
      | Test Person 2 | allen  |
      | Test Person 3 | ada    |
    And I am logged in as "nancy"
    When I go to add a board term
    And I fill in "field_term_dates[und][0][value][date]" with "12/24/1983"
    And I fill in "field_term_dates[und][0][value2][date]" with "1/1/1985"
    And I fill in "Test" for "Person"
    And I wait 1 second
    Then I should see "Test Person"
    And I should see "Test Person 2"
    And I should not see "Test Person 3"

  @javascript
  Scenario: An administrator can see all boards when adding a Board Term
    Given cities:
      | name      |
      | Ferndale  |
      | Ypsilanti |
    And users:
      | name  | status |
      | nancy | 1      |
      | ada   | 1      |
      | allen | 1      |
    And clerks:
      | user  | city      |
      | nancy | Ferndale  |
      | allen | Ferndale  |
      | ada   | Ypsilanti |
    And boards:
      | title                 | author | city      |
      | Beautification Board  | nancy  | Ferndale  |
      | Parks Board           | ada    | Ypsilanti |
      | School Board          | allen  | Ferndale  |
    And people:
      | name        | author |
      | Test Person | nancy  |
    And I am logged in as a user with the "administrator" role
    When I go to add a board term
    And I fill in "field_term_dates[und][0][value][date]" with "12/24/1983"
    And I fill in "field_term_dates[und][0][value2][date]" with "1/1/1985"
    And I fill in "boa" for "Board"
    And I wait 1 second
    Then I should see "Beautification Board"
    And I should see "School Board"
    And I should see "Parks Board"

  @javascript
  Scenario: An administrator can see all available people when adding a Board Term
    Given cities:
      | name      |
      | Ferndale  |
      | Ypsilanti |
    And users:
      | name  | status |
      | nancy | 1      |
      | ada   | 1      |
      | allen | 1      |
    And clerks:
      | user  | city      |
      | nancy | Ferndale  |
      | allen | Ferndale  |
      | ada   | Ypsilanti |
    And boards:
      | title                 | author | city      |
      | Beautification Board  | nancy  | Ferndale  |
    And people:
      | name          | author |
      | Test Person   | nancy  |
      | Test Person 2 | allen  |
      | Test Person 3 | ada    |
    And I am logged in as a user with the "administrator" role
    When I go to add a board term
    And I fill in "field_term_dates[und][0][value][date]" with "12/24/1983"
    And I fill in "field_term_dates[und][0][value2][date]" with "1/1/1985"
    And I fill in "Test" for "Person"
    And I wait 1 second
    Then I should see "Test Person"
    And I should see "Test Person 2"
    And I should see "Test Person 3"
