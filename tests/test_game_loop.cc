#include <catch2/catch.hpp>
#include <game_loop.h>
TEST_CASE("Test Determine Winner") {
  basketball::GameLoop g = basketball::GameLoop();
  basketball::Player p1 = basketball::Player();
  p1.SetScore(5);
  basketball::Player p2 = basketball::Player();
  p1.SetScore(4);
  REQUIRE(g.DetermineWinner(p1, p2) == p1);
}
TEST_CASE("Test Calculate Power") {
  basketball::GameLoop g = basketball::GameLoop();
  g.SetCurrentBarHeight(430);
  REQUIRE(g.CalculatePower() == 10);
}

TEST_CASE("Test Choose Shot Type") {
  basketball::Offense offense = basketball::Offense();
  basketball::GameLoop g = basketball::GameLoop();
  basketball::Offense::ShotType s = basketball::Offense::Layup;
  g.ChooseShotType(s);
  REQUIRE(offense.GetMakePercentage() == 85);
}

TEST_CASE("Test Choose Defense Type") {
  basketball::Defense defense = basketball::Defense();
  basketball::GameLoop g = basketball::GameLoop();
  basketball::Defense::DefenseType d = basketball::Defense::Block;

  g.ChooseDefenseType(d);
  REQUIRE(defense.GetTurnoverPercentage() == 25);
  REQUIRE(defense.GetAdjustedShotPercentage() == 5);
}