#include "game_display.h"
using ci::gl::color;
using ci::Color;
using glm::vec2;
using ci::gl::drawStrokedRect;
using ci::gl::drawSolidRect;
using ci::Rectf;

namespace basketball {

GameDisplay::GameDisplay() {}

GameDisplay::GameDisplay(Player &player_one, Player &player_two) {
  player_one_ = player_one;
  player_two_ = player_two;
  shot_ = Offense::Default;
  power_ = 0;
  current_bar_height_ = kStartingHeight;
}
void basketball::GameDisplay::Update() {
  // Let users choose names

  if (player_one_.GetScore() >= 10 || player_two_.GetScore() >= 10) {
    Player winner = DetermineWinner(player_one_, player_two_);
    ci::gl::drawStringCentered(winner.GetName() + " has won the game",
                               glm::vec2(200, 200),
                               ci::Color("black"));
    return;
  }
  std::swap(player_one_, player_two_);
  CheckShotSelection();
  // Use power meter to get power
  bool result = offense_.DetermineShotResult(player_two_, shot_);
  if (result) {
    ci::gl::drawStringCentered(player_two_.GetName() + " made the (user input)",
                               glm::vec2(200, 200), ci::Color("black"));
  }
}

Player GameDisplay::DetermineWinner(Player &player_one,
                                    Player &player_two) const {
  if (player_one.GetScore() > player_two.GetScore()) {
    return player_one;
  }
  return player_two;
}

void GameDisplay::CheckShotSelection() {
  while (shot_ == Offense::Default) {
    ci::gl::drawStringCentered(
        player_two_.GetName() +
        " pick which shot you want to take. Press L to take a layup, M to "
        "take a midrange, T to take a three pointer, and H to take a Half "
        "Court shot.",
        glm::vec2(400, 400), ci::Color("black"));
  }
  offense_.SelectShot(shot_);
}

void GameDisplay::CreatePowerMeter() {
  if (current_bar_height_ < kEndingHeight) {
    ++current_bar_height_;
  } else {
    --current_bar_height_;
  }
  while (power_ == 0) {
    color(Color("white"));

    drawStrokedRect(Rectf(vec2(kStartingWidth, kStartingHeight),
                          vec2(kEndingWidth,kEndingHeight)));

    color(Color("blue"));

    drawSolidRect(Rectf(vec2(kStartingWidth, kStartingHeight),
                          vec2(kEndingWidth, current_bar_height_)));
  }
  offense_.CalculateShotPercentage(power_);
}

size_t GameDisplay::CalculatePower() const {
  return current_bar_height_ - kStartingHeight;
}

Offense::ShotType GameDisplay::GetShot() const { return shot_; }

void GameDisplay::SetShot(Offense::ShotType s) { shot_ = s; }

size_t GameDisplay::GetPower() const { return power_; }

void GameDisplay::SetPower(size_t p) {
  power_ = p;
}

} // namespace basketball