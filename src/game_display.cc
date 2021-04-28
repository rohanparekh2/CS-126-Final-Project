#include "game_display.h"
#include<unistd.h>
using ci::Color;
using ci::Rectf;
using ci::gl::color;
using ci::gl::drawSolidRect;
using ci::gl::drawStrokedRect;
using glm::vec2;

namespace basketball {

GameDisplay::GameDisplay() {}

GameDisplay::GameDisplay(Player &player_one, Player &player_two) {
  player_one_ = player_one;
  player_two_ = player_two;
  offense_ = Offense();
  shot_ = Offense::Default;
  power_ = 0;
  current_bar_height_ = kStartingHeight - 1;
  change_in_power_ = -5;
  result_ = false;
  next_player = false;
}

void basketball::GameDisplay::Draw() {
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
  if (shot_ != Offense::Default && power_ != 0) {
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
    if (next_player) {
      // reset variables if it is the next player's turn and swap players
      shot_ = Offense::Default;
      power_ = 0;
      next_player = false;
      std::swap(player_one_, player_two_);
    }
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
  // While the KeyDown has not been executed, display this message
  if (shot_ == Offense::Default) {
    ci::gl::drawStringCentered(
        player_two_.GetName() +
            " pick which shot you want to take. Press L to take a layup, M to "
            "take a midrange, T to take a three pointer, and H to take a Half "
            "Court shot.",
        glm::vec2(400, 400), ci::Color("white"));
  }
}

void GameDisplay::CreatePowerMeter() {
  // Let power bar increase unless it reaches the top
  if (current_bar_height_ <= kEndingHeight || current_bar_height_
                                                  >= kStartingHeight) {
    change_in_power_ *= -1;
  }
  current_bar_height_ += change_in_power_;

  // Print the outline and the moving power bar
  if (power_ == 0 && shot_ != Offense::Default) {
    color(Color("white"));

    drawStrokedRect(Rectf(vec2(kStartingWidth, kEndingHeight),
                          vec2(kEndingWidth, kStartingHeight)));

    color(Color("blue"));

    drawSolidRect(Rectf(vec2(kStartingWidth, current_bar_height_),
                        vec2(kEndingWidth, kStartingHeight)));
  }
}
void GameDisplay::SetCurrentBarHeight(size_t currentBarHeight) {
  current_bar_height_ = currentBarHeight;
}

size_t GameDisplay::CalculatePower() const {
  return kStartingHeight - current_bar_height_;
}

void GameDisplay::ConvertKeyToShot(Offense::ShotType shot_type) {
  shot_ = shot_type;
  offense_.SelectShot(shot_);
}

void GameDisplay::CheckShotResult(){
  power_ = CalculatePower();
  offense_.CalculateShotPercentage(power_);
  result_ = offense_.DetermineShotResult(player_two_, shot_);
}

void GameDisplay::SetNextPlayer(bool next) {
  next_player = next;
}

} // namespace basketball