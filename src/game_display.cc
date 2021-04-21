
#include "game_display.h"
#include <basketball_app.h>

namespace basketball {

basketball::GameDisplay::GameDisplay() {}
void basketball::GameDisplay::Update() {
  //Let users choose names
  player_one_name_ = "Player One";
  player_one_name_ = "Player Two";
  Player player_one = Player(player_one_name_);
  Player player_two = Player(player_two_name_);

  Offense offense = Offense();

  while ()
  ci::gl::drawStringCentered(
      player_one_name_.,
      glm::vec2(400, 400),
      ci::Color("black"));
  // Do Key Down

}
} // namespace basketball