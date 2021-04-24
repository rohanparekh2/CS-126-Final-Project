
#include "game_display.h"
#include <basketball_app.h>

namespace basketball {

GameDisplay::GameDisplay() {}

GameDisplay::GameDisplay(Player &player_one, Player &player_two) {
  player_one_ = player_one;
  player_two_ = player_two;
}
void basketball::GameDisplay::Update() {
  // Let users choose names

  Offense offense = Offense();
  if (player_one_.GetScore() >= 10 || player_two_.GetScore() >= 10) {
    Player winner = DetermineWinner(player_one_, player_two_);
    ci::gl::drawStringCentered(winner.GetName() + " has won the game",
                               glm::vec2(200, 200),
                               ci::Color("black"));
    return;
  }
  std::swap(player_one_, player_two_);
  ci::gl::drawStringCentered(
      player_two_.GetName() +
          " pick which shot you want to take. Press L to take a layup, M to "
          "take a midrange, T to take a three pointer, and H to take a Half "
          "Court shot.",
      glm::vec2(400, 400), ci::Color("black"));
  // Do Key Down
  // offense.SelectShot("user input");
  // Use power meter to get power
  // offense.CalculateShotPercentage("get power from power meter");
  ShotType shot = ShotType::Midrange;
  bool result = offense.DetermineShotResult(player_two_, shot);
  if (result) {
    ci::gl::drawStringCentered(player_two_.GetName() + " made the (user input)",
                               glm::vec2(200, 200), ci::Color("black"));
  }
}

Player GameDisplay::DetermineWinner(Player &player_one,
                                    Player &player_two) const {
  if (player_one.GetScore() > player_two.GetScore()) {
    return player_one;
  }
  return player_two;
}
} // namespace basketball