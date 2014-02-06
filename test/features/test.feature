Feature: Site installation

  Scenario: Installation succeeded
    Given I am on "/"
    Then I should see "Welcome to Minimal CI"

  @javascript
  Scenario: Installation succeeded with js enabled
    Given I am on "/"
    Then I should see "Welcome to Minimal CI"
