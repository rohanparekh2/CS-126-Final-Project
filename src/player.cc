#include "player.h"
#include <string>

namespace basketball {

Player::Player() {}

Player::Player(std::string &name) {
  score_ = 0;
  name_ = name;
}

void Player::AdjustScore(std::string &shot_type) {
  if (shot_type == "layup" || shot_type == "midrange") {
    score_ += 2;
  } else {
    score_ += 3;
  }
}


}// namespace basketball