@api
Feature: Access controls for Onboard content types
  In order to manage boards, board terms and people
  As a clerk 
  I need to be able to edit and delete items I'm responsible for and prevent others from having unauthorized access

  Scenario: Clerk creates a Board for her City
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
    And I select "Ferndale" from "City"
    And I press "Save"
    Then I should see "Board Beautification Board has been created"

  Scenario: Clerk cannot create a board for another city
    Given cities:
      | name      |
      | Ferndale  |
      | Ypsilanti |
    And users:
      | name  | status |
      | nancy | 1      |
      | ada   | 1      |
    And clerks:
      | user  | city      |
      | nancy | Ferndale  |
      | ada   | Ypsilanti |
    And I am logged in as "nancy"
    When I go to add a board
    Then I should see "Create Board"
    And I should not see "Ypsilanti"

  Scenario: User who is not a clerk cannot create a board
    Given cities:
      | name      |
      | Ferndale  |
      | Ypsilanti |
    And users:
      | name  | status |
      | allen | 1      |
    And I am logged in as "allen"
    When I go to add a board 
    Then the response status code should be 403

  Scenario: Clerk can edit their own board
    Given cities:
      | name      |
      | Ferndale  |
    And users:
      | name  | status | 
      | nancy | 1      |     
    And clerks:
      | user  | city     |
      | nancy | Ferndale |
    And boards:
      | title                 | author           | city         |
      | Beautification Board  | nancy            | Ferndale     |
    And I am logged in as "nancy"
    When I go to edit the board "Beautification Board" for "Ferndale"
    And I fill in "City Hall" for "Meeting Location"
    And I press "Save"
    Then I should see "Board Beautification Board has been updated"
    And I should see "City Hall"

  Scenario: Clerk can delete their own board
    Given cities:
      | name      |
      | Ferndale  |
    And users:
      | name  | status | 
      | nancy | 1      |     
    And clerks:
      | user  | city     |
      | nancy | Ferndale |
    And boards:
      | title                 | author           | city         |
      | Beautification Board  | nancy            | Ferndale     |
    And I am logged in as "nancy"
    When I go to delete the board "Beautification Board" for "Ferndale"
    And I press "Delete"
    Then I should see "Board Beautification Board has been deleted"

  Scenario: Clerk cannot edit a board for another city
    Given cities:
      | name      |
      | Ferndale  |
      | Ypsilanti |
    And users:
      | name  | status |
      | nancy | 1      |
      | ada   | 1      |
    And clerks:
      | user  | city      |
      | nancy | Ferndale  |
      | ada   | Ypsilanti |
    And boards:
      | title                 | author           | city         |
      | Beautification Board  | nancy            | Ferndale     |
      | Parks Board           | ada              | Ypsilanti    |
    And I am logged in as "nancy"
    When I go to edit the board "Parks Board" for "Ypsilanti"
    Then the response status code should be 403

  Scenario: Clerk cannot delete a board for another city
    Given cities:
      | name      |
      | Ferndale  |
      | Ypsilanti |
    And users:
      | name  | status |
      | nancy | 1      |
      | ada   | 1      |
    And clerks:
      | user  | city      |
      | nancy | Ferndale  |
      | ada   | Ypsilanti |
    And boards:
      | title                 | author           | city         |
      | Beautification Board  | nancy            | Ferndale     |
      | Parks Board           | ada              | Ypsilanti    |
    And I am logged in as "nancy"
    When I go to delete the board "Parks Board" for "Ypsilanti"
    Then the response status code should be 403

  Scenario: Clerk can edit another clerk's board for her city
    Given cities:
      | name      |
      | Ferndale  |
    And users:
      | name  | status |
      | nancy | 1      |
      | allen | 1      |
    And clerks:
      | user  | city      |
      | nancy | Ferndale  |
      | allen | Ferndale |
    And boards:
      | title                 | author           | city         |
      | Beautification Board  | nancy            | Ferndale     |
      | Parks Board           | allen            | Ferndale     |
    And I am logged in as "nancy"
    When I go to edit the board "Parks Board" for "Ferndale"
    And I fill in "City Hall" for "Meeting Location"
    And I press "Save"
    Then I should see "Board Parks Board has been updated"
    And I should see "City Hall"

  Scenario: Clerk can delete another clerk's board for her city
    Given cities:
      | name      |
      | Ferndale  |
    And users:
      | name  | status |
      | nancy | 1      |
      | allen | 1      |
    And clerks:
      | user  | city      |
      | nancy | Ferndale  |
      | allen | Ferndale |
    And boards:
      | title                 | author           | city         |
      | Beautification Board  | nancy            | Ferndale     |
      | Parks Board           | allen            | Ferndale     |
    And I am logged in as "nancy"
    When I go to delete the board "Parks Board" for "Ferndale"
    And I press "Delete"
    Then I should see "Board Parks Board has been deleted"

  Scenario: An anonymous user can view any board
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
    And I am not logged in
    When I go to view the board "Beautification Board" for "Ferndale"
    Then the response status code should be 200
    And I should see "Beautification Board"
    And I should see "Ferndale"

  Scenario: User who is not a clerk cannot create a Person 
    Given cities:
      | name      |
      | Ferndale  |
      | Ypsilanti |
    And users:
      | name  | status |
      | allen | 1      |
    And I am logged in as "allen"
    When I go to add a person 
    Then the response status code should be 403

  Scenario: Clerk can create a Person
    Given cities:
      | name      |
      | Ferndale  |
    And users:
      | name  | status |
      | nancy | 1      |
    And clerks:
      | user  | city      |
      | nancy | Ferndale  |
    And I am logged in as "nancy"
    When I go to add a person
    And I fill in "Name" with "Test Person"
    And I fill in "Email" with "test@email.com"
    And I press "Save"
    Then I should see "Person Test Person has been created"

  Scenario: Clerk can edit a person she created
    Given cities:
      | name      |
      | Ferndale  |
    And users:
      | name  | status |
      | nancy | 1      |
    And clerks:
      | user  | city      |
      | nancy | Ferndale  |
    And people:
      | name        | author |
      | Test Person | nancy  |
    And I am logged in as "nancy"
    When I go to edit the person "Test Person"
    And I fill in "Email" with "test@email.com"
    And I press "Save"
    Then I should see "Person Test Person has been updated"
    And I should see "test@email.com"

  Scenario: Clerk can delete a person she created
    Given cities:
      | name      |
      | Ferndale  |
    And users:
      | name  | status |
      | nancy | 1      |
    And clerks:
      | user  | city      |
      | nancy | Ferndale  |
    And people:
      | name        | author |
      | Test Person | nancy  |
    And I am logged in as "nancy"
    When I go to delete the person "Test Person"
    And I press "Delete"
    Then I should see "Person Test Person has been deleted"

  Scenario: Clerk cannot edit a person from another city
    Given cities:
      | name      |
      | Ferndale  |
      | Ypsilanti |
    And users:
      | name  | status |
      | nancy | 1      |
      | ada   | 1      |
    And clerks:
      | user  | city      |
      | nancy | Ferndale  |
      | ada   | Ypsilanti |
    And people:
      | name          | author |
      | Test Person   | nancy  |
      | Test Person 2 | ada    |
    And I am logged in as "nancy"
    When I go to edit the person "Test Person 2"
    Then the response status code should be 403

  Scenario: Clerk cannot delete a person from another city
    Given cities:
      | name      |
      | Ferndale  |
      | Ypsilanti |
    And users:
      | name  | status |
      | nancy | 1      |
      | ada   | 1      |
    And clerks:
      | user  | city      |
      | nancy | Ferndale  |
      | ada   | Ypsilanti |
    And people:
      | name          | author |
      | Test Person   | nancy  |
      | Test Person 2 | ada    |
    And I am logged in as "nancy"
    When I go to delete the person "Test Person 2"
    Then the response status code should be 403

  Scenario: Clerk can edit a person from her city
    Given cities:
      | name      |
      | Ferndale  |
    And users:
      | name  | status |
      | nancy | 1      |
      | allen | 1      |
    And clerks:
      | user  | city      |
      | nancy | Ferndale  |
      | allen | Ferndale |
    And people:
      | name          | author |
      | Test Person   | nancy  |
      | Test Person 2 | allen    |
    And I am logged in as "nancy"
    When I go to edit the person "Test Person 2"
    And I fill in "Email" with "test2@email.com"
    And I press "Save"
    Then I should see "Person Test Person 2 has been updated"
    And I should see "test2@email.com"

  Scenario: Clerk can delete a person from her city
    Given cities:
      | name      |
      | Ferndale  |
    And users:
      | name  | status |
      | nancy | 1      |
      | allen | 1      |
    And clerks:
      | user  | city      |
      | nancy | Ferndale  |
      | allen | Ferndale |
    And people:
      | name          | author |
      | Test Person   | nancy  |
      | Test Person 2 | allen    |
    And I am logged in as "nancy"
    When I go to delete the person "Test Person 2"
    And I press "Delete"
    Then I should see "Person Test Person 2 has been deleted"
