#include "offense.h"
#include <cinder/Rand.h>
#include <defense.h>

namespace basketball {

Offense::Offense() { make_percentage_ = 0; }

void Offense::SelectShot(ShotType &user_input) {
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

void Offense::CalculateShotPercentage(size_t power, Defense &defense) {
  double new_percentage;
  // If the power is too high or low, the shot cannot be made
  if (power < kMinPower || power > kMaxPower) {
    make_percentage_ = 0;
  } else {

    // equation that takes power into account
    new_percentage =
        power + make_percentage_ + defense.GetAdjustedShotPercentage();
    if (new_percentage > kOptimalPercentage) {
      new_percentage =
          kOptimalPercentage - (new_percentage - kOptimalPercentage);
    }
    make_percentage_ =
        (make_percentage_ * (new_percentage / kOptimalPercentage)) +
        kPowerBonus;
  }
}

bool Offense::DetermineShotResult(Player &current_player, ShotType &user_input,
                                  Defense &defense) const {
  // randomizes shot to see if it is made
  float random_percentage =
      ci::randFloat(kMinimumPercentage, kOptimalPercentage);
  if (random_percentage > make_percentage_ ||
      random_percentage <= defense.GetTurnoverPercentage()) {
    return false;
  } else {
    AdjustScore(current_player, user_input);
    return true;
  }
}

void Offense::AdjustScore(Player &current_player, ShotType &shot) const {
  if (shot == Offense::ShotType::Layup || shot == Offense::ShotType::Midrange) {
    current_player.TwoPointer();
  } else {
    current_player.ThreePointer();
  }
}
double Offense::GetMakePercentage() const { return make_percentage_; }

} // namespace basketball