#include <catch2/catch.hpp>
#include <game_display.h>
TEST_CASE("Test Determine Winner") {
  basketball::GameDisplay g = basketball::GameDisplay();
  basketball::Player p1 = basketball::Player();
  p1.SetScore(5);
  basketball::Player p2 = basketball::Player();
  p1.SetScore(4);
  REQUIRE(g.DetermineWinner(p1, p2) == p1);
}
TEST_CASE("Test Calculate Power") {
  basketball::GameDisplay g = basketball::GameDisplay();
  g.SetCurrentBarHeight(430);
  REQUIRE(g.CalculatePower() == 70);
}
