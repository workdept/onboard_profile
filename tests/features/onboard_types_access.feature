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
      | user  | city     |
      | nancy | Ferndale |
      | allen | Ferndale |
    And people:
      | name          | author |
      | Test Person   | nancy  |
      | Test Person 2 | allen  |
    And I am logged in as "nancy"
    When I go to delete the person "Test Person 2"
    And I press "Delete"
    Then I should see "Person Test Person 2 has been deleted"

  Scenario: A user who is not a clerk cannot create a board term
    Given cities:
      | name      |
      | Ferndale  |
      | Ypsilanti |
    And users:
      | name  | status |
      | nancy | 1      |
      | allen | 1      |
    And clerks:
      | user  | city      |
      | nancy | Ferndale  |
    And boards:
      | title                 | author           | city         |
      | Beautification Board  | nancy            | Ferndale     |
    And people:
      | name        | author |
      | Test Person | nancy  |
    And I am logged in as "allen"
    When I go to add a board term
    Then the response status code should be 403

  @javascript
  Scenario: A clerk can create a board term for a board in her city
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
    Given I fill in "Board" with "Beautification Board"
    And I press the "enter" key in the "Board" field
    And I fill in "Person" with "Test Person"
    And I press the "enter" key in the "Board" field
    And I fill in "field_term_dates[und][0][value][date]" with "12/24/1983"
    And I fill in "field_term_dates[und][0][value2][date]" with "1/1/1985"
    And I press "Save"
    Then I should see "has been created" 

  Scenario: A clerk can edit a board term for a board for her city
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
    And board terms:
      | city     | board                | person      | start     | end       | author |
      | Ferndale | Beautification Board | Test Person | 3/15/2012 | 4/15/2013 | nancy |
    And I am logged in as "nancy"
    When I go to edit the board term for the city of "Ferndale" board "Beautification Board" for "Test Person"
    And I fill in "field_term_dates[und][0][value][date]" with "3/1/2013"
    And I fill in "field_term_dates[und][0][value2][date]" with "4/16/2013"
    And I press "Save"
    Then I should see "has been updated"

  Scenario: A clerk can edit a board term for a board for her city created by another clerk
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
      | allen | Ferndale  |
    And boards:
      | title                 | author           | city         |
      | Beautification Board  | nancy            | Ferndale     |
      | Parks Board           | allen            | Ferndale     |
    And people:
      | name          | author |
      | Test Person   | nancy  |
      | Test Person 2 | allen  |
    And board terms:
      | city     | board                | person      | start     | end       | author |
      | Ferndale | Beautification Board | Test Person | 3/15/2012 | 4/15/2013 | nancy |
      | Ferndale | Parks Board          | Test Person 2 | 2/15/2010 | 1/31/2011 | allen |
    And I am logged in as "nancy"
    When I go to edit the board term for the city of "Ferndale" board "Parks Board" for "Test Person 2"
    And I fill in "field_term_dates[und][0][value][date]" with "3/1/2013"
    And I fill in "field_term_dates[und][0][value2][date]" with "4/16/2013"
    And I press "Save"
    Then I should see "has been updated"

  Scenario: A clerk cannot edit a board term for a board for another city
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
    And people:
      | name          | author |
      | Test Person   | nancy  |
      | Test Person 2 | ada    |
    And board terms:
      | city     | board                 | person        | start     | end       | author |
      | Ferndale  | Beautification Board | Test Person   | 3/15/2012 | 4/15/2013 | nancy |
      | Ypsilanti | Parks Board          | Test Person 2 | 2/15/2010 | 1/31/2011 | ada   |
    And I am logged in as "nancy"
    When I go to edit the board term for the city of "Ypsilanti" board "Parks Board" for "Test Person 2"
    Then the response status code should be 403

  Scenario: A clerk can delete a board term for a board for her city
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
    And board terms:
      | city     | board                | person      | start     | end       | author |
      | Ferndale | Beautification Board | Test Person | 3/15/2012 | 4/15/2013 | nancy |
    And I am logged in as "nancy"
    When I go to delete the board term for the city of "Ferndale" board "Beautification Board" for "Test Person"
    And I press "Delete"
    Then I should see "has been deleted"

  Scenario: A clerk cannot delete a board term for a board for another city
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
    And people:
      | name          | author |
      | Test Person   | nancy  |
      | Test Person 2 | ada    |
    And board terms:
      | city     | board                 | person        | start     | end       | author |
      | Ferndale  | Beautification Board | Test Person   | 3/15/2012 | 4/15/2013 | nancy |
      | Ypsilanti | Parks Board          | Test Person 2 | 2/15/2010 | 1/31/2011 | ada   |
    And I am logged in as "nancy"
    When I go to delete the board term for the city of "Ypsilanti" board "Parks Board" for "Test Person 2"
    Then the response status code should be 403

  Scenario: A clerk can delete a board term for a board for her city created by another clerk
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
      | allen | Ferndale  |
    And boards:
      | title                 | author           | city         |
      | Beautification Board  | nancy            | Ferndale     |
      | Parks Board           | allen            | Ferndale     |
    And people:
      | name          | author |
      | Test Person   | nancy  |
      | Test Person 2 | allen  |
    And board terms:
      | city     | board                | person      | start     | end       | author |
      | Ferndale | Beautification Board | Test Person | 3/15/2012 | 4/15/2013 | nancy |
      | Ferndale | Parks Board          | Test Person 2 | 2/15/2010 | 1/31/2011 | allen |
    And I am logged in as "nancy"
    When I go to edit the board term for the city of "Ferndale" board "Parks Board" for "Test Person 2"
    And I press "Delete"
    Then I should see "has been deleted"