#pragma once

#include "basketball_app.h"
#include <string>
namespace basketball {

class GameDisplay {
public:
 GameDisplay();

 GameDisplay(Player& player_one, Player& player_two);

 void Update();
private:
  Player player_one_;
  Player player_two_;
};

} // namespace basketball
