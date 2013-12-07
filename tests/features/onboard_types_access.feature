@api
Feature: Access controls for Onboard content types
  In order to manage boards, board terms and members
  As a clerk 
  I need to be able to edit and unpublish items I'm responsible for and prevent others from having unauthorized access

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

  @javascript
  Scenario: Admin creates a board for a city that they're not a member of
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
    And I fill in "Name" with "Beautification Board"
    # Admin users see two form elements for the City field, and other
    # organic groups fields.  A select element labeled "Your groups" and
    # an autocompleting text input labeled "Other groups".  Use
    # "Other groups" here since the admin user isn't a member of any groups
    And I select "Ferndale" from the "Other groups" autocomplete field
    And I press "Save"
    Then I should see "Board Beautification Board has been created"
    And I should see "Ferndale"

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

  Scenario: Clerk cannot delete their own board
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
    Then the response status code should be 403

  Scenario: Clerk can unpublish their own board
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
    When I unpublish the board "Beautification Board" of "Ferndale"
    Then the board "Beautification Board" of "Ferndale" is unpublished

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

  Scenario: Admin can delete a board
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
    And I am logged in as a user with the "administrator" role
    When I go to delete the board "Beautification Board" for "Ferndale"
    And I press "Delete"
    Then I should see "has been deleted"

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

  Scenario: Clerk cannot delete another clerk's board for her city
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
    Then the response status code should be 403

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

  Scenario: User who is not a clerk cannot create a Member 
    Given cities:
      | name      |
      | Ferndale  |
      | Ypsilanti |
    And users:
      | name  | status |
      | allen | 1      |
    And I am logged in as "allen"
    When I go to add a member 
    Then the response status code should be 403

  Scenario: Clerk can create a Member
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
    When I go to add a member
    And I fill in "Name" with "Test Member"
    And I fill in "Email" with "test@email.com"
    And I press "Save"
    Then I should see "Member Test Member has been created"

  Scenario: Clerk can unpublish a Member
    Given cities:
      | name      |
      | Ferndale  |
    And users:
      | name  | status |
      | nancy | 1      |
    And clerks:
      | user  | city      |
      | nancy | Ferndale  |
    And members:
      | name        | author |
      | Test Member | nancy  |
    And I am logged in as "nancy"
    When I unpublish the member "Test Member"
    Then the member "Test Member" is unpublished

  @javascript
  Scenario: Admin creates a member for a city that they're not a member of
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

  Scenario: Clerk can edit a member she created
    Given cities:
      | name      |
      | Ferndale  |
    And users:
      | name  | status |
      | nancy | 1      |
    And clerks:
      | user  | city      |
      | nancy | Ferndale  |
    And members:
      | name        | author |
      | Test Member | nancy  |
    And I am logged in as "nancy"
    When I go to edit the member "Test Member"
    And I fill in "Email" with "test@email.com"
    And I press "Save"
    Then I should see "Member Test Member has been updated"
    And I should see "test@email.com"

  Scenario: Clerk cannot delete a member she created
    Given cities:
      | name      |
      | Ferndale  |
    And users:
      | name  | status |
      | nancy | 1      |
    And clerks:
      | user  | city      |
      | nancy | Ferndale  |
    And members:
      | name        | author |
      | Test Member | nancy  |
    And I am logged in as "nancy"
    When I go to delete the member "Test Member"
    Then the response status code should be 403

  Scenario: Clerk cannot edit a member from another city
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
    And members:
      | name          | author |
      | Test Member   | nancy  |
      | Test Member 2 | ada    |
    And I am logged in as "nancy"
    When I go to edit the member "Test Member 2"
    Then the response status code should be 403

  Scenario: Clerk cannot delete a member from another city
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
    And members:
      | name          | author |
      | Test Member   | nancy  |
      | Test Member 2 | ada    |
    And I am logged in as "nancy"
    When I go to delete the member "Test Member 2"
    Then the response status code should be 403

  Scenario: Clerk can edit a member from her city
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
    And members:
      | name          | author |
      | Test Member   | nancy  |
      | Test Member 2 | allen    |
    And I am logged in as "nancy"
    When I go to edit the member "Test Member 2"
    And I fill in "Email" with "test2@email.com"
    And I press "Save"
    Then I should see "Member Test Member 2 has been updated"
    And I should see "test2@email.com"

  Scenario: Clerk cannot delete a member from her city
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
    And members:
      | name          | author |
      | Test Member   | nancy  |
      | Test Member 2 | allen  |
    And I am logged in as "nancy"
    When I go to delete the member "Test Member 2"
    Then the response status code should be 403

  Scenario: Admin can delete a member created by another user
    Given cities:
      | name      |
      | Ferndale  |
    And users:
      | name  | status |
      | nancy | 1      |
    And clerks:
      | user  | city      |
      | nancy | Ferndale  |
    And members:
      | name        | author |
      | Test Member | nancy  |
    And I am logged in as a user with the "administrator" role
    When I go to delete the member "Test Member"
    And I press "Delete"
    Then I should see "has been deleted"

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
    And members:
      | name        | author |
      | Test Member | nancy  |
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
      | title                | author | city     |
      | Beautification Board | nancy  | Ferndale |
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

  @javascript
  Scenario: An admin creates a board term for a city that they're not a member of
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
      | title                | author | city     |
      | Beautification Board | nancy  | Ferndale |
    And members:
      | name        | author |
      | Test Member | nancy  |
    And I am logged in as a user with the "administrator" role
    When I go to add a board term
    And I fill in "field_term_dates[und][0][value][date]" with "12/24/1983"
    And I fill in "field_term_dates[und][0][value2][date]" with "1/1/1985"
    And I select "Beautification Board" from the "Board" autocomplete field
    And I select "Test Member" from the "Member" autocomplete field
    And I press "Save"
    Then I should see "has been created" 
    And I should see "Test Member"
    And I should see "Beautification Board"

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
    And members:
      | name        | author |
      | Test Member | nancy  |
    And board terms:
      | city     | board                | member      | field_term_dates     | author |
      | Ferndale | Beautification Board | Test Member | 3/15/2012, 4/15/2013 | nancy  |
    And I am logged in as "nancy"
    When I go to edit the board term for the city of "Ferndale" board "Beautification Board" for "Test Member"
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
    And members:
      | name          | author |
      | Test Member   | nancy  |
      | Test Member 2 | allen  |
    And board terms:
      | city     | board                | member        | field_term_dates     | author |
      | Ferndale | Beautification Board | Test Member   | 3/15/2012, 4/15/2013 | nancy  |
      | Ferndale | Parks Board          | Test Member 2 | 2/15/2010, 1/31/2011 | allen  |
    And I am logged in as "nancy"
    When I go to edit the board term for the city of "Ferndale" board "Parks Board" for "Test Member 2"
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
    And members:
      | name          | author |
      | Test Member   | nancy  |
      | Test Member 2 | ada    |
    And board terms:
      | city     | board                 | member        | field_term_dates     | author |
      | Ferndale  | Beautification Board | Test Member   | 3/15/2012, 4/15/2013 | nancy  |
      | Ypsilanti | Parks Board          | Test Member 2 | 2/15/2010, 1/31/2011 | ada    |
    And I am logged in as "nancy"
    When I go to edit the board term for the city of "Ypsilanti" board "Parks Board" for "Test Member 2"
    Then the response status code should be 403

  Scenario: A clerk cannot delete a board term for a board for her city
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
    And board terms:
      | city     | board                | member      | field_term_dates     | author |
      | Ferndale | Beautification Board | Test Member | 3/15/2012, 4/15/2013 | nancy  |
    And I am logged in as "nancy"
    When I go to delete the board term for the city of "Ferndale" board "Beautification Board" for "Test Member"
    Then the response status code should be 403

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
    And members:
      | name          | author |
      | Test Member   | nancy  |
      | Test Member 2 | ada    |
    And board terms:
      | city     | board                 | member        | field_term_dates     | author |
      | Ferndale  | Beautification Board | Test Member   | 3/15/2012, 4/15/2013 | nancy  |
      | Ypsilanti | Parks Board          | Test Member 2 | 2/15/2010, 1/31/2011 | ada    |
    And I am logged in as "nancy"
    When I go to delete the board term for the city of "Ypsilanti" board "Parks Board" for "Test Member 2"
    Then the response status code should be 403

  Scenario: A clerk can unpublish a board term for a board for her city
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
    And board terms:
      | city     | board                | member      | field_term_dates     | author |
      | Ferndale | Beautification Board | Test Member | 3/15/2012, 4/15/2013 | nancy  |
    And I am logged in as "nancy"
    When I unpublish the board term for the city of "Ferndale" board "Beautification Board" for "Test Member"
    Then the board term for the city of "Ferndale" board "Beautification Board" for "Test Member" is unpublished

  Scenario: A clerk cannot delete a board term for a board for her city created by another clerk
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
    And members:
      | name          | author |
      | Test Member   | nancy  |
      | Test Member 2 | allen  |
    And board terms:
      | city     | board                | member        | field_term_dates     | author |
      | Ferndale | Beautification Board | Test Member   | 3/15/2012, 4/15/2013 | nancy  |
      | Ferndale | Parks Board          | Test Member 2 | 2/15/2010, 1/31/2011 | allen  |
    And I am logged in as "nancy"
    When I go to delete the board term for the city of "Ferndale" board "Parks Board" for "Test Member 2"
    Then the response status code should be 403

  Scenario: An admin can delete a board term created by another user
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
    And board terms:
      | city     | board                | member      | field_term_dates     | author |
      | Ferndale | Beautification Board | Test Member | 3/15/2012, 4/15/2013 | nancy  |
    And I am logged in as a user with the "administrator" role
    When I go to delete the board term for the city of "Ferndale" board "Beautification Board" for "Test Member"
    And I press "Delete"
    Then I should see "has been deleted"
