#include "offense.h"
#include <cinder/Rand.h>

namespace basketball {

Offense::Offense() { make_percentage_ = 0; }
void Offense::SelectShot(std::string &user_input){
  if (user_input == "layup") {
    make_percentage_ = 85;
  } else if (user_input == "midrange") {
    make_percentage_ = 55;
  } else if (user_input == "three-pointer") {
    make_percentage_ = 35;
  } else {
    make_percentage_ = 10;
  }
}

void Offense::CalculateShotPercentage(double power){
  if (power < kMinPower || power > kMaxPower) {
    make_percentage_ = 0;
  } else {
    make_percentage_ =
        (make_percentage_ * ((power + make_percentage_) / kOptimalPercentage)) +
        kPowerBonus;
  }
}

bool Offense::DetermineShotResult(Player &current_player,
                                  std::string &user_input) const{
  float random_percentage = ci::randFloat(kMinimumPercentage, kOptimalPercentage);
  if (random_percentage > make_percentage_) {
    return false;
  } else {
    current_player.AdjustScore(user_input);
    return true;
  }
}

} // namespace basketball