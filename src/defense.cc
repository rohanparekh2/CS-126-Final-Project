#include "defense.h"

namespace basketball {

Defense::Defense() {
  turnover_percentage_ = 0;
  adjusted_shot_percentage = 0;
}
void Defense::SelectDefense(Defense::DefenseType &user_input) {
  if (user_input == DefenseType::Block) {
    turnover_percentage_ = 25;
    adjusted_shot_percentage = 5;
  } else if (user_input == DefenseType::Steal) {
    turnover_percentage_ = 15;
    adjusted_shot_percentage = 4;
  } else {
    adjusted_shot_percentage = -8;
  }
}
size_t Defense::GetAdjustedShotPercentage() const {
  return adjusted_shot_percentage;
}
size_t Defense::GetTurnoverPercentage() const { return turnover_percentage_; }
}// namespace basketball