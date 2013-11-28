@api
Feature: Access controls for Onboard content types
  In order to manage boards, board terms and people
  As a clerk 
  I need to be able to edit and delete items I'm responsible for and prevent others from having unauthorized access

  Scenario: Create a Board for your City
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
