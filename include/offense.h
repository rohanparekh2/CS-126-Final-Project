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
  size_t kMinPower = 10;
  size_t kMaxPower = 90;
  size_t kPowerBonus = 10;
  size_t kOptimalPercentage = 100;


};

}// namespace basketball
