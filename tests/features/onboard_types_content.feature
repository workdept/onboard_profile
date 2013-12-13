@api
Feature: Content views provided by onboard_types
  In order to efficiently maintain content
  As a clerk
  I need to be able to search for and view my city's boards, members, and terms

  @javascript
  Scenario: Clerk is directed to her dashboard after logging in
    Given I am logged in as a user with the "clerk" role
    Then I should be on "user/boards"
