#include <catch2/catch.hpp>
#include <offense.h>


TEST_CASE("Test Select Shot") {
  SECTION("Layup") {
    basketball::Offense offense = basketball::Offense();
    std::string input = "layup";
    offense.SelectShot(input);
    REQUIRE(offense.GetMakePercentage() == 85);
  }

  SECTION("Midrange") {
    basketball::Offense offense = basketball::Offense();
    std::string input = "midrange";
    offense.SelectShot(input);
    REQUIRE(offense.GetMakePercentage() == 55);
  }

  SECTION("Three pointer") {
    basketball::Offense offense = basketball::Offense();
    std::string input = "three-pointer";
    offense.SelectShot(input);
    REQUIRE(offense.GetMakePercentage() == 35);
  }

  SECTION("Half Court") {
    basketball::Offense offense = basketball::Offense();
    std::string input = "half court";
    offense.SelectShot(input);
    REQUIRE(offense.GetMakePercentage() == 10);
  }
}

TEST_CASE("Test Calculate Shot Result") {
  SECTION("Layup") {
    basketball::Offense offense = basketball::Offense();
    std::string input = "layup";
    offense.SelectShot(input);
    double power = 10;
    offense.CalculateShotPercentage(power);
    REQUIRE(offense.GetMakePercentage() == 90.75);
  }

  SECTION("Midrange") {
    basketball::Offense offense = basketball::Offense();
    std::string input = "midrange";
    offense.SelectShot(input);
    double power = 60;
    offense.CalculateShotPercentage(power);
    REQUIRE(offense.GetMakePercentage() == 56.75);
  }

  SECTION("Three pointer") {
    basketball::Offense offense = basketball::Offense();
    std::string input = "three-pointer";
    offense.SelectShot(input);
    double power = 70;
    offense.CalculateShotPercentage(power);
    REQUIRE(offense.GetMakePercentage() == 43.25);
  }

  SECTION("Half Court") {
    basketball::Offense offense = basketball::Offense();
    std::string input = "half court";
    offense.SelectShot(input);
    double power = 90;
    offense.CalculateShotPercentage(power);
    REQUIRE(offense.GetMakePercentage() == 20);
  }

  SECTION("Power Too Low") {
    basketball::Offense offense = basketball::Offense();
    std::string input = "half court";
    offense.SelectShot(input);
    double power = 0;
    offense.CalculateShotPercentage(power);
    REQUIRE(offense.GetMakePercentage() == 0);
  }

  SECTION("Power Too High") {
    basketball::Offense offense = basketball::Offense();
    std::string input = "half court";
    offense.SelectShot(input);
    double power = 100;
    offense.CalculateShotPercentage(power);
    REQUIRE(offense.GetMakePercentage() == 0);
  }
}

