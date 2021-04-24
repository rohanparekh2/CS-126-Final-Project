#include "offense.h"
#include <cinder/Rand.h>

namespace basketball {

Offense::Offense() { make_percentage_ = 0; }

void Offense::SelectShot(ShotType& user_input){
  if (user_input == ShotType::Layup) {
    make_percentage_ = 85;
  } else if (user_input == ShotType::Midrange) {
    make_percentage_ = 55;
  } else if (user_input == ShotType::ThreePointer) {
    make_percentage_ = 35;
  } else {
    make_percentage_ = 10;
  }
}

void Offense::CalculateShotPercentage(double power){
  double new_percentage;
  if (power < kMinPower || power > kMaxPower) {
    make_percentage_ = 0;
  } else {
    new_percentage = power + make_percentage_;
    if (new_percentage > kOptimalPercentage) {
      new_percentage = kOptimalPercentage - (new_percentage - kOptimalPercentage);
    }
    make_percentage_ =
        (make_percentage_ * (new_percentage / kOptimalPercentage)) +
        kPowerBonus;
  }
}

bool Offense::DetermineShotResult(Player& current_player,
                                  ShotType &user_input) const{
  float random_percentage = ci::randFloat(kMinimumPercentage, kOptimalPercentage);
  if (random_percentage > make_percentage_) {
    return false;
  } else {
    current_player.AdjustScore(user_input);
    return true;
  }
}
double Offense::GetMakePercentage() const { return make_percentage_; }

} // namespace basketball