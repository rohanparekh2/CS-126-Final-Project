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
void Player::SetScore(size_t score) { score_ = score; }

}// namespace basketball