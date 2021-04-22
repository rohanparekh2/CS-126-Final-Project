
#include "game_display.h"
#include <basketball_app.h>

namespace basketball {

basketball::GameDisplay::GameDisplay() {}
void basketball::GameDisplay::Update() {
  // Let users choose names
  player_one_name_ = "Player One";
  player_one_name_ = "Player Two";
  Player player_one = Player(player_one_name_);
  Player player_two = Player(player_two_name_);

  //Offense offense = Offense();
  Player current_player = player_two;

  while (player_one.GetScore() < 10 && player_two.GetScore() < 10) {
    if (current_player == player_one) {
      current_player = player_two;
    } else {
      current_player = player_one;
    }
    ci::gl::drawStringCentered(
        current_player.GetName() +
            " pick which shot you want to take. Press L to take a layup, M to "
            "take a midrange, T to take a three pointer, and H to take a Half "
            "Court shot.",
        glm::vec2(400, 400), ci::Color("black"));
    // Do Key Down
    //offense.SelectShot("user input");
    //Use power meter to get power
    //offense.CalculateShotPercentage("get power from power meter");
    bool result = offense.DetermineShotResult(current_player, (std::string &)"user input from keys");
    if (result == true) {
      ci::gl::drawStringCentered(
          current_player.GetName() +
          " made the (user input)",
          glm::vec2(400, 400), ci::Color("black"));
    }*/

  }
}
} // namespace basketball