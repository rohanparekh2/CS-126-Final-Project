#include "player.h"
#include <offense.h>
#include <string>

namespace basketball {

Player::Player() {}

Player::Player(std::string &name) {
  score_ = 0;
  name_ = name;
}

void Player::AdjustScore(ShotType &shot){
  if (shot == ShotType::Layup || shot == ShotType::Midrange) {
    score_ += 2;
  } else {
    score_ += 3;
  }
}
const std::string &Player::GetName() const { return name_; }
size_t Player::GetScore() const { return score_; }

bool operator==(const Player& player_one, const Player& player_two) {
  return player_one.GetName() == player_two.GetName();
}

}// namespace basketball