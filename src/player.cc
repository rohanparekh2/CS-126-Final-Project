#include "player.h"
#include <string>

namespace basketball {

Player::Player() {}

Player::Player(std::string &name) {
  score_ = 0;
  name_ = name;
}

const std::string &Player::GetName() const { return name_; }
size_t Player::GetScore() const { return score_; }

bool operator==(const Player& player_one, const Player& player_two) {
  return player_one.GetName() == player_two.GetName();
}

void Player::TwoPointer() {
  score_+= 2;
}

void Player::ThreePointer() {
  score_+= 3;
}
void Player::SetScore(size_t s) {
  score_ = s;
}

}// namespace basketball