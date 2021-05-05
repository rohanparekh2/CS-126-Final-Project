#include <catch2/catch.hpp>
#include <defense.h>
//#include "test_defense.h"

TEST_CASE("Test Select Defense") {
  SECTION("Block") {
    basketball::Defense defense = basketball::Defense();
    basketball::Defense::DefenseType input = basketball::Defense::Block;
    defense.SelectDefense(input);
    REQUIRE(defense.GetAdjustedShotPercentage() == 5);
    REQUIRE(defense.GetTurnoverPercentage() == 25);
  }

  SECTION("Steal") {
    basketball::Defense defense = basketball::Defense();
    basketball::Defense::DefenseType input = basketball::Defense::Steal;
    defense.SelectDefense(input);
    REQUIRE(defense.GetAdjustedShotPercentage() == 4);
    REQUIRE(defense.GetTurnoverPercentage() == 15);
  }

  SECTION("Contest") {
    basketball::Defense defense = basketball::Defense();
    basketball::Defense::DefenseType input = basketball::Defense::Contest;
    defense.SelectDefense(input);
    REQUIRE(defense.GetAdjustedShotPercentage() == -8);
    REQUIRE(defense.GetTurnoverPercentage() == 0);
  }

}