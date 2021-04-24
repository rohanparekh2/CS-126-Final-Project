
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
  if (player_one.GetScore() >= 10 || player_two.GetScore() >= 10) {
    if (player_two.GetScore() >=) {
      ci::gl::drawStringCentered(
          player_two.GetName() +
          " has won the game",
          glm::vec2(200, 200), ci::Color("black"));
    }
  }
    std::swap(player_one, player_two);
    ci::gl::drawStringCentered(
        player_two.GetName() +
            " pick which shot you want to take. Press L to take a layup, M to "
            "take a midrange, T to take a three pointer, and H to take a Half "
            "Court shot.",
        glm::vec2(400, 400), ci::Color("black"));
    // Do Key Down
    // offense.SelectShot("user input");
    // Use power meter to get power
    // offense.CalculateShotPercentage("get power from power meter");
    ShotType shot = ShotType::Midrange;
    bool result = offense.DetermineShotResult(
        player_two, shot);
    if (result) {
      ci::gl::drawStringCentered(player_two.GetName() +
                                     " made the (user input)",
                                 glm::vec2(200, 200),
                                 ci::Color("black"));
    }
}
} // namespace basketball