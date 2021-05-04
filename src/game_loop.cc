#include "game_loop.h"
#include<unistd.h>
using ci::Color;
using ci::Rectf;
using ci::gl::color;
using ci::gl::drawSolidRect;
using ci::gl::drawStrokedRect;
using glm::vec2;

namespace basketball {

GameLoop::GameLoop() {}

GameLoop::GameLoop(Player &player_one, Player &player_two) {
  player_one_ = player_one;
  player_two_ = player_two;
  offense_ = Offense();
  shot_ = Offense::Default;
  power_ = -1;
  current_bar_height_ = kStartingHeight - 1;
  change_in_power_ = -10;
  result_ = false;
  next_player_ = false;
  animation_finished_ = false;
}

void basketball::GameLoop::Draw() {
  // Let users choose names

  if (player_one_.GetScore() >= 10 || player_two_.GetScore() >= 10) {
    // Check if a player has won the game and display winner if so
    Player winner = DetermineWinner(player_one_, player_two_);
    ci::gl::drawStringCentered(winner.GetName() + " has won the game",
                               glm::vec2(200, 200),
                               ci::Color("black"));
    return;
  }
  // Determine if player made shot by using variables determined by KeyDown
  CheckShotSelection();
  CreatePowerMeter();
  //ChangeBallPosition(current_position_, result_);
  //Change Ball position
  if (shot_ != Offense::Default && power_ != -1) { // && animation_finished_)
    // Display if the player made the shot or not
    if (result_) {
      ci::gl::drawStringCentered(player_two_.GetName() + " made the shot",
                                 glm::vec2(200, 200),
                                 ci::Color("white"));
    } else {
      ci::gl::drawStringCentered(player_two_.GetName() + " missed the shot",
                                 glm::vec2(200, 200),
                                 ci::Color("white"));
    }
    if (next_player_) {
      // reset variables if it is the next player's turn and swap players
      shot_ = Offense::Default;
      power_ = -1;
      next_player_ = false;
      std::swap(player_one_, player_two_);
    }
  }
}

Player GameLoop::DetermineWinner(Player &player_one,
                                    Player &player_two) const {
  if (player_one.GetScore() > player_two.GetScore()) {
    return player_one;
  }
  return player_two;
}

void GameLoop::CheckShotSelection() {
  // While the KeyDown has not been executed, display this message
  if (shot_ == Offense::Default) {
    cinder::Font font = cinder::Font("Arial", 20);
    ci::gl::drawStringCentered(
        player_two_.GetName() +
            ", pick which shot you want to take.",
        glm::vec2(290, 180), kTextColor, font);
    color(kButtonColor);
    drawSolidRect(Rectf(vec2(80,240), vec2(230,280)));
    drawSolidRect(Rectf(vec2(400,240), vec2(550,280)));
    drawSolidRect(Rectf(vec2(80,360), vec2(230,400)));
    drawSolidRect(Rectf(vec2(400,360), vec2(550,400)));
    color(kTextColor);
    ci::gl::drawStringCentered(
        "Layup",
        glm::vec2(155, 253), kTextColor, font);
    ci::gl::drawStringCentered(
        "Midrange",
        glm::vec2(475, 253), kTextColor, font);
    ci::gl::drawStringCentered(
        "Three-Pointer",
        glm::vec2(155, 375), kTextColor, font);
    ci::gl::drawStringCentered(
        "Half Court",
        glm::vec2(475, 375), kTextColor, font);
  }
}

void GameLoop::CreatePowerMeter() {
  // Let power bar increase unless it reaches the top
  if (current_bar_height_ <= kEndingHeight || current_bar_height_
                                                  >= kStartingHeight) {
    change_in_power_ *= -1;
  }
  current_bar_height_ += change_in_power_;

  // Print the outline and the moving power bar
  if (power_ == -1 && shot_ != Offense::Default) {

    drawStrokedRect(Rectf(vec2(kStartingWidth, kEndingHeight),
                          vec2(kEndingWidth, kStartingHeight)));

    color(kButtonColor);

    drawSolidRect(Rectf(vec2(kStartingWidth, current_bar_height_),
                        vec2(kEndingWidth, kStartingHeight)));

    color(kTextColor);
  }
}
void GameLoop::SetCurrentBarHeight(size_t currentBarHeight) {
  current_bar_height_ = currentBarHeight;
}

size_t GameLoop::CalculatePower() const {
  return (kStartingHeight - current_bar_height_) / 2;
}

void GameLoop::ChooseShotType(Offense::ShotType shot_type) {
  if (shot_ == Offense::Default) {
    shot_ = shot_type;
    offense_.SelectShot(shot_);
  }
}

void GameLoop::CheckShotResult() {
  if (shot_ != Offense::Default && power_ == -1) {
    power_ = CalculatePower();
    offense_.CalculateShotPercentage(power_);
    result_ = offense_.DetermineShotResult(player_two_, shot_);
  }
}

void GameLoop::SetNextPlayer(bool next) {
  if (shot_ != Offense::Default && power_ != -1) {
    next_player_ = next;
  }
}

void GameLoop::ChangeBallPosition(Rectf current_position,
                                       bool shot_result) {
}

Offense::ShotType GameLoop::GetShot() const { return shot_; }

size_t GameLoop::GetPower() const { return power_; }


} // namespace basketball