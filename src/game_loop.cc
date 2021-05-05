#include "game_loop.h"
#include <unistd.h>
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
  defense_ = Defense();
  defense_type_ = Defense::Default;
  power_ = -1;
  current_bar_height_ = kStartingHeight - 1;
  change_in_power_ = -10;
  result_ = false;
  next_player_ = false;
  animation_finished_ = false;
  font_size_ = 0;
  end_font_size_ = 0;
  top_left_.x = 250;
  top_left_.y = 450;
  bottom_right_.x = 350;
  bottom_right_.y = 550;
  change_in_pos_ = 2;
  part_one_ = false;
  player_one_score_ = 0;
  player_two_score_ = 0;
  quit_ = false;
}

void basketball::GameLoop::Draw() {

  QuitGame();
  if (quit_) {
    return;
  }

  if ((player_one_.GetScore() >= 10 || player_two_.GetScore() >= 10) &&
      next_player_) {
    if (end_font_size_ < 40) {
      end_font_size_ += 3;
    }
    cinder::Font font = cinder::Font("Arial", end_font_size_);
    // Check if a player has won the game and display winner if so
    Player winner = DetermineWinner(player_one_, player_two_);
    ci::gl::drawStringCentered(winner.GetName() + " has won the game!!!",
                               glm::vec2(300, 250),
                               ci::Color("white"), font);
    return;
  }
  DrawScoreboard();
  // Determine if player made shot by using variables determined by MouseDown
  CheckShotSelection();
  CheckDefenseSelection();
  CreatePowerMeter();
  ChangeBallPosition();
  // Change Ball position
  if (shot_ != Offense::Default && defense_type_ != Defense::Default &&
      power_ != -1 && animation_finished_) {
    if (font_size_ < 30) {
      font_size_ += 3;
    }
    cinder::Font font = cinder::Font("Arial", font_size_);
    // Display if the player made the shot or not
    if (result_) {
      ci::gl::drawStringCentered(player_two_.GetName() + " made the shot",
                                 glm::vec2(300, 250),
                                 ci::Color("white"), font);
    } else {
      ci::gl::drawStringCentered(player_two_.GetName() + " missed the shot",
                                 glm::vec2(300, 250),
                                 ci::Color("white"), font);
    }
    // Checks if it is the next player's turn
    if (next_player_) {
      Clear();
    }
  }
}

Player GameLoop::DetermineWinner(Player &player_one, Player &player_two) const {
  if (player_one.GetScore() > player_two.GetScore()) {
    return player_one;
  }
  return player_two;
}

void GameLoop::CheckShotSelection() {
  // While the MouseDown has not been executed, display this message
  if (shot_ == Offense::Default) {
    cinder::Font font = cinder::Font("Arial", 20);
    ci::gl::drawStringCentered(player_two_.GetName() +
                                   ", pick which shot you want to take.",
                               glm::vec2(290, 180),
                               kTextColor, font);
    color(kButtonColor);
    drawSolidRect(Rectf(vec2(80, 240),
                        vec2(230, 280)));
    drawSolidRect(Rectf(vec2(400, 240),
                        vec2(550, 280)));
    drawSolidRect(Rectf(vec2(80, 360),
                        vec2(230, 400)));
    drawSolidRect(Rectf(vec2(400, 360),
                        vec2(550, 400)));
    color(kTextColor);
    ci::gl::drawStringCentered("Layup", glm::vec2(155, 253),
                               kTextColor, font);
    ci::gl::drawStringCentered("Midrange", glm::vec2(475, 253),
                               kTextColor, font);
    ci::gl::drawStringCentered("Three-Pointer",
                               glm::vec2(155, 375),
                               kTextColor, font);
    ci::gl::drawStringCentered("Half Court",
                               glm::vec2(475, 375),
                               kTextColor, font);
  }
}

void GameLoop::CheckDefenseSelection() {
  // While the MouseDown has not been executed, display this message
  if (shot_ != Offense::Default && defense_type_ == Defense::Default) {
    cinder::Font font = cinder::Font("Arial", 20);
    ci::gl::drawStringCentered(player_one_.GetName() +
                                   ", pick a type of defense to play.",
                               glm::vec2(290, 180),
                               kTextColor, font);
    color(kButtonColor);
    drawSolidRect(Rectf(vec2(80, 240),
                        vec2(230, 280)));
    drawSolidRect(Rectf(vec2(400, 240),
                        vec2(550, 280)));
    drawSolidRect(Rectf(vec2(250, 360),
                        vec2(400, 400)));
    color(kTextColor);
    ci::gl::drawStringCentered("Block", glm::vec2(155, 253),
                               kTextColor, font);
    ci::gl::drawStringCentered("Steal", glm::vec2(475, 253),
                               kTextColor, font);
    ci::gl::drawStringCentered("Contest", glm::vec2(325, 373),
                               kTextColor, font);
  }
}

void GameLoop::CreatePowerMeter() {

  // Print the outline and the moving power bar
  if (power_ == -1 && shot_ != Offense::Default &&
      defense_type_ != Defense::Default) {
    cinder::Font font = cinder::Font("Arial", 25);
    ci::gl::drawStringCentered("Click the space bar to choose shot power",
                               glm::vec2(305, 175),
                               kTextColor, font);

    drawStrokedRect(Rectf(vec2(kStartingWidth, kEndingHeight),
                          vec2(kEndingWidth, kStartingHeight)));

    color(kButtonColor);

    drawSolidRect(Rectf(vec2(kStartingWidth, current_bar_height_),
                        vec2(kEndingWidth, kStartingHeight)));

    color(kTextColor);

    current_bar_height_ += change_in_power_;

    // Let power bar increase unless it reaches the top
    if (current_bar_height_ <= kEndingHeight ||
        current_bar_height_ >= kStartingHeight - 10) {
      change_in_power_ *= -1;
    }
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

void GameLoop::ChooseDefenseType(Defense::DefenseType defense_type) {
  if (shot_ != Offense::Default && defense_type_ == Defense::Default) {
    defense_type_ = defense_type;
    defense_.SelectDefense(defense_type_);
  }
}

void GameLoop::CheckShotResult() {
  if (shot_ != Offense::Default && defense_type_ != Defense::Default &&
      power_ == -1) {
    power_ = CalculatePower();
    offense_.CalculateShotPercentage(power_, defense_);
    result_ = offense_.DetermineShotResult(player_two_, shot_,
                                           defense_);
  }
}

void GameLoop::SetNextPlayer(bool next) {
  if (shot_ != Offense::Default && defense_type_ != Defense::Default &&
      power_ != -1 && animation_finished_) {
    next_player_ = next;
  }
}

void GameLoop::ChangeBallPosition() {
  //Changes position of ball depending on if shot was made or not
  if (shot_ != Offense::Default && defense_type_ != Defense::Default &&
      power_ != -1 && !animation_finished_) {
    if (top_left_.y > kMaxYPos && !part_one_) {
      top_left_.y -= 22;
      bottom_right_.y -= 26;
      top_left_.x += change_in_pos_;
      bottom_right_.x -= change_in_pos_;
      if (!result_) {
        top_left_.x -= 2 * change_in_pos_;
        bottom_right_.x -= 2 * change_in_pos_;
      }
    } else if (top_left_.y < kEndYPosTop) {
      part_one_ = true;
      top_left_.y += 40;
      bottom_right_.y += 40;
    } else {
      animation_finished_ = true;
    }
  }
}

void GameLoop::DrawScoreboard() {
  cinder::Font title_font = cinder::Font("Arial", 25);
  cinder::Font score_font = cinder::Font("Arial", 20);
  drawStrokedRect(Rectf(vec2(400, 0), vec2(600, 150)));
  ci::gl::drawStringCentered("Scores", glm::vec2(495, 25),
                             kTextColor, title_font);
  std::string name;
  std::string name_two;
  if (animation_finished_) {
    if (player_two_.GetName() == "Player 1") {
      player_two_score_ = player_one_.GetScore();
      player_one_score_ = player_two_.GetScore();
    } else {
      player_one_score_ = player_one_.GetScore();
      player_two_score_ = player_two_.GetScore();
    }
  }
  if (player_two_.GetName() == "Player 1") {
    name = player_two_.GetName();
    name_two = player_one_.GetName();
  } else {
    name = player_one_.GetName();
    name_two = player_two_.GetName();
  }
  ci::gl::drawStringCentered(name + "        " +
                                 std::to_string(player_one_score_),
                             glm::vec2(475, 65),
                             kTextColor, score_font);
  ci::gl::drawStringCentered(name_two + "        " +
                                 std::to_string(player_two_score_),
                             glm::vec2(475, 105),
                             kTextColor, score_font);
}

void GameLoop::Clear() {
  // reset variables if it is the next player's turn and swap players
  shot_ = Offense::Default;
  defense_type_ = Defense::Default;
  next_player_ = false;
  top_left_.x = 250;
  top_left_.y = 450;
  bottom_right_.x = 350;
  bottom_right_.y = 550;
  part_one_ = false;
  power_ = -1;
  current_bar_height_ = kStartingHeight - 1;
  animation_finished_ = false;
  font_size_ = 0;
  std::swap(player_one_, player_two_);
}

void GameLoop::QuitGame() {
  //Creates quit button and displays message if it is pressed
  color(Color("grey"));

  drawSolidRect(Rectf(vec2(0, 0), vec2(100, 50)));

  color(kTextColor);

  cinder::Font font = cinder::Font("Arial", 25);

  ci::gl::drawStringCentered("Quit", glm::vec2(47, 20),
                             kTextColor, font);

  if (quit_) {
    ci::gl::drawStringCentered("Thanks for Playing",
                               glm::vec2(300, 250),
                               ci::Color("white"), font);
  }
}

Offense::ShotType GameLoop::GetShot() const { return shot_; }

vec2 GameLoop::GetCurrentLength() const { return top_left_; }

vec2 GameLoop::GetCurrentWidth() const { return bottom_right_; }

void GameLoop::SetQuit(bool quit) { quit_ = quit; }

} // namespace basketball