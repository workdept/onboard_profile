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
    When I go to "node/add/board"
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
    When I go to "node/add/board"
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
    When I go to "node/add/board"
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
    When I edit the board "Beautification Board" for "Ferndale"
    And I fill in "City Hall" for "Meeting Location"
    And I press "Save"
    Then I should see "Board Beautification Board has been updated"
    And I should see "City Hall"

  #Scenario: Clerk can delete their own board

  #Scenario: Clerk cannot edit a board for another city

  #Scenario: Clerk cannot delete a board for another city

    # And print last response
