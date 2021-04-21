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
