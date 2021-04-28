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
  shot_ = Offense::Default;
  power_ = 0;
  current_bar_height_ = kStartingHeight - 1;
  change_in_power_ = -3;
  result_ = false;
  next_player = false;
}

void basketball::GameDisplay::Update() {
  // Let users choose names

  if (player_one_.GetScore() >= 10 || player_two_.GetScore() >= 10) {
    // Check if a player has won the game and display winner if so
    Player winner = DetermineWinner(player_one_, player_two_);
    ci::gl::drawStringCentered(winner.GetName() + " has won the game",
                               glm::vec2(200, 200), ci::Color("black"));
    return;
  }
  // swaps players every turn
  CheckShotSelection();
  CreatePowerMeter();
  // Determine if player made shot by using variables determined by the KeyDown
  // and mouseDown methods
  if (shot_ != Offense::Default && power_ != 0) {
    // Display if the player made the shot or not
    if (result_) {
      ci::gl::drawStringCentered(player_two_.GetName() + " made the shot",
                                 glm::vec2(200, 200), ci::Color("white"));
    } else {
      ci::gl::drawStringCentered(player_two_.GetName() + " missed the shot",
                                 glm::vec2(200, 200), ci::Color("white"));
    }
    if (next_player) {
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

size_t GameDisplay::CalculatePower() const {
  return kStartingHeight - current_bar_height_;
}

Offense::ShotType GameDisplay::GetShot() const { return shot_; }

void GameDisplay::SetShot(Offense::ShotType s) { shot_ = s; }

size_t GameDisplay::GetPower() const { return power_; }

void GameDisplay::SetPower(size_t p) { power_ = p; }

bool GameDisplay::GetResult() const {
  return result_;
}

void GameDisplay::SetResult(bool r) {
  result_ = r;
}
bool GameDisplay::GetNextPlayer() const {
  return next_player;
}

void GameDisplay::SetNextPlayer(bool next) {
  next_player = next;
}

} // namespace basketball