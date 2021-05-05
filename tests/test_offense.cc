#include <catch2/catch.hpp>
#include <offense.h>

TEST_CASE("Test Select Shot") {
  SECTION("Layup") {
    basketball::Offense offense = basketball::Offense();
    basketball::Offense::ShotType input = basketball::Offense::Layup;
    offense.SelectShot(input);
    REQUIRE(offense.GetMakePercentage() == 85);
  }

  SECTION("Midrange") {
    basketball::Offense offense = basketball::Offense();
    basketball::Offense::ShotType input = basketball::Offense::Midrange;
    offense.SelectShot(input);
    REQUIRE(offense.GetMakePercentage() == 55);
  }

  SECTION("Three pointer") {
    basketball::Offense offense = basketball::Offense();
    basketball::Offense::ShotType input = basketball::Offense::ThreePointer;
    offense.SelectShot(input);
    REQUIRE(offense.GetMakePercentage() == 35);
  }

  SECTION("Half Court") {
    basketball::Offense offense = basketball::Offense();
    basketball::Offense::ShotType input = basketball::Offense::HalfCourt;
    offense.SelectShot(input);
    REQUIRE(offense.GetMakePercentage() == 10);
  }
}

TEST_CASE("Test Calculate Shot Result") {
  SECTION("Layup") {
    basketball::Defense defense =
        basketball::Defense(basketball::Defense::Steal);
    basketball::Offense offense = basketball::Offense();
    basketball::Offense::ShotType input = basketball::Offense::Layup;
    offense.SelectShot(input);
    double power = 10;
    offense.CalculateShotPercentage(power, defense);
    REQUIRE(offense.GetMakePercentage() == 94.15);
  }

  SECTION("Midrange") {
    basketball::Defense defense =
        basketball::Defense(basketball::Defense::Contest);
    basketball::Offense offense = basketball::Offense();
    basketball::Offense::ShotType input = basketball::Offense::Midrange;
    offense.SelectShot(input);
    double power = 60;
    offense.CalculateShotPercentage(power, defense);
    REQUIRE(offense.GetMakePercentage() == Approx(61.15));
  }

  SECTION("Three pointer") {
    basketball::Defense defense =
        basketball::Defense(basketball::Defense::Contest);
    basketball::Offense offense = basketball::Offense();
    basketball::Offense::ShotType input = basketball::Offense::ThreePointer;
    offense.SelectShot(input);
    double power = 70;
    offense.CalculateShotPercentage(power, defense);
    REQUIRE(offense.GetMakePercentage() == Approx(43.95));
  }

  SECTION("Half Court") {
    basketball::Defense defense =
        basketball::Defense(basketball::Defense::Steal);
    basketball::Offense offense = basketball::Offense();
    basketball::Offense::ShotType input = basketball::Offense::HalfCourt;
    offense.SelectShot(input);
    double power = 90;
    offense.CalculateShotPercentage(power, defense);
    REQUIRE(offense.GetMakePercentage() == 19.6);
  }

  SECTION("Power Too Low") {
    basketball::Defense defense =
        basketball::Defense(basketball::Defense::Block);
    basketball::Offense offense = basketball::Offense();
    basketball::Offense::ShotType input = basketball::Offense::HalfCourt;
    offense.SelectShot(input);
    double power = 0;
    offense.CalculateShotPercentage(power, defense);
    REQUIRE(offense.GetMakePercentage() == 0);
  }

  SECTION("Power Too High") {
    basketball::Defense defense =
        basketball::Defense(basketball::Defense::Block);
    basketball::Offense offense = basketball::Offense();
    basketball::Offense::ShotType input = basketball::Offense::HalfCourt;
    offense.SelectShot(input);
    double power = 100;
    offense.CalculateShotPercentage(power, defense);
    REQUIRE(offense.GetMakePercentage() == 0);
  }
}

TEST_CASE("Test Adjust Score") {
  SECTION("Layup") {
    basketball::Player p1 = basketball::Player();
    p1.SetScore(5);
    basketball::Offense offense = basketball::Offense();
    basketball::Offense::ShotType shot = basketball::Offense::Layup;
    offense.AdjustScore(p1, shot);
    REQUIRE(p1.GetScore() == 7);
  }

  SECTION("Midrange") {
    basketball::Player p1 = basketball::Player();
    p1.SetScore(9);
    basketball::Offense offense = basketball::Offense();
    basketball::Offense::ShotType shot = basketball::Offense::Midrange;
    offense.AdjustScore(p1, shot);
    REQUIRE(p1.GetScore() == 11);
  }

  SECTION("Three pointer") {
    basketball::Player p1 = basketball::Player();
    p1.SetScore(2);
    basketball::Offense offense = basketball::Offense();
    basketball::Offense::ShotType shot = basketball::Offense::ThreePointer;
    offense.AdjustScore(p1, shot);
    REQUIRE(p1.GetScore() == 5);
  }

  SECTION("Half Court") {
    basketball::Player p1 = basketball::Player();
    p1.SetScore(3);
    basketball::Offense offense = basketball::Offense();
    basketball::Offense::ShotType shot = basketball::Offense::HalfCourt;
    offense.AdjustScore(p1, shot);
    REQUIRE(p1.GetScore() == 6);
  }
}
