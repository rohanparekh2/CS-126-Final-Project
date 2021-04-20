#pragma once

#include "player.h"
#include <string>
namespace basketball {

class Offense {
public:
  Offense();

  void SelectShot(std::string& user_input);

  void CalculateShotPercentage(double power);

  bool DetermineShotResult(Player& current_player, std::string& user_input);

private:
  double make_percentage_;
  double shot_power_;

};

}// namespace basketball
