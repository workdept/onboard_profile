@api
Feature: Automatic field values for custom content types 
  In order to manage boards, board terms and members with minimum data entry
  As a clerk 
  I need to be able to have some field values automatically assigned

  Scenario: City field of Board is hidden for clerks 
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
    When I go to add a board 
    Then I should not see the city field

  Scenario: City field of Board is visible for administrators
    Given cities:
      | name      |
      | Ferndale  |
    And users:
      | name  | status | 
      | nancy | 1      |     
    And clerks:
      | user  | city     |
      | nancy | Ferndale |
    And I am logged in as a user with the "administrator" role
    When I go to add a board
    Then I should see the city field

  Scenario: City field of Board is automatically populated
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
    When I go to add a board 
    And I fill in "Name" with "Beautification Board"
    And I press "Save"
    Then I should see "Board Beautification Board has been created"
    And I should see "Ferndale"

  Scenario: City field of Member is not visible for clerks
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
    When I go to add a member
    Then I should not see the city field

  Scenario: City field of Member is visible for administrators 
    Given cities:
      | name      |
      | Ferndale  |
    And users:
      | name  | status | 
      | nancy | 1      |     
    And clerks:
      | user  | city     |
      | nancy | Ferndale |
    And I am logged in as a user with the "administrator" role
    When I go to add a member
    Then I should see the city field

  Scenario: City field of Member is automatically populated
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
    When I go to add a member
    And I fill in "Name" with "Test Member"
    And I fill in "Email" with "test@email.com"
    And I press "Save"
    Then I should see "Member Test Member has been created"
    And I should see "Ferndale"

  @javascript
  Scenario: An administrator can manually set the City field of a Member
    Given cities:
      | name      |
      | Ferndale  |
    And I am logged in as a user with the "administrator" role
    When I go to add a member
    And I fill in "Name" with "Test Member"
    And I fill in "Email" with "test@email.com"
    And I select "Ferndale" from the "Other groups" autocomplete field
    And I press "Save"
    Then I should see "Member Test Member has been created"
    And I should see "Ferndale"

  Scenario: City field of Board Term is hidden from clerks 
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
    And members:
      | name        | author |
      | Test Member | nancy  |
    And I am logged in as "nancy"
    When I go to add a board term
    Then I should not see the city field

  Scenario: City field of Board Term is visible for administrators
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
    And members:
      | name        | author |
      | Test Member | nancy  |
    And I am logged in as a user with the "administrator" role
    When I go to add a board term
    Then I should see the city field

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
    And members:
      | name        | author |
      | Test Member | nancy  |
    And I am logged in as "nancy"
    When I go to add a board term
    And I fill in "field_term_dates[und][0][value][date]" with "12/24/1983"
    And I fill in "field_term_dates[und][0][value2][date]" with "1/1/1985"
    And I select "Beautification Board" from the "Board" autocomplete field
    And I select "Test Member" from the "Member" autocomplete field
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
    And members:
      | name        | author |
      | Test Member | nancy  |
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
  Scenario: Member field is limited to members in a clerk's city when adding a Board Term
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
    And members:
      | name          | author |
      | Test Member   | nancy  |
      | Test Member 2 | allen  |
      | Test Member 3 | ada    |
    And I am logged in as "nancy"
    When I go to add a board term
    And I fill in "field_term_dates[und][0][value][date]" with "12/24/1983"
    And I fill in "field_term_dates[und][0][value2][date]" with "1/1/1985"
    And I fill in "Test" for "Member"
    And I wait 1 second
    Then I should see "Test Member"
    And I should see "Test Member 2"
    And I should not see "Test Member 3"

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
    And members:
      | name        | author |
      | Test Member | nancy  |
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
  Scenario: An administrator can see all available members when adding a Board Term
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
    And members:
      | name          | author |
      | Test Member   | nancy  |
      | Test Member 2 | allen  |
      | Test Member 3 | ada    |
    And I am logged in as a user with the "administrator" role
    When I go to add a board term
    And I fill in "field_term_dates[und][0][value][date]" with "12/24/1983"
    And I fill in "field_term_dates[und][0][value2][date]" with "1/1/1985"
    And I fill in "Test" for "Member"
    And I wait 1 second
    Then I should see "Test Member"
    And I should see "Test Member 2"
    And I should see "Test Member 3"
