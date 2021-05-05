#pragma once

#include "offense.h"
#include "player.h"
#include <string>
namespace basketball {

class GameLoop {
public:
  /**
   * Creates new Game Display Object
   */
  GameLoop();

  /**
   * Creates new Game Display Object that takes in players
   * @param player_one The first player that gets to take a shot
   * @param player_two The second player that gets to take a shot
   */
  GameLoop(Player &player_one, Player &player_two);

  /**
   * Draws the text and power meter on the screen
   */
  void Draw();

  /**
   * When the game is over, this checks who has won the game
   * @param player_one The first player
   * @param player_two The second player
   * @return Player with the highest score
   */
  Player DetermineWinner(Player &player_one, Player &player_two) const;

  /**
   * Checks to see if the player has taken a shot yet
   */
  void CheckShotSelection();

  /**
   * Checks to see if the player has chosen a power yet
   */
  void CreatePowerMeter();

  /**
   * Calculates power based on the position of the meter
   * @return The power of the current shot
   */
  size_t CalculatePower() const;

  /**
   * Determines the shot taken based on the button that is pushed
   * @param shot_type Type of shot taken by player
   */
  void ChooseShotType(Offense::ShotType shot_type);

  /**
   * Chooses the power based on keys and finds the shot result
   */
  void CheckShotResult();

  /**
   * Changes boolean that checks if it is the next player's turn
   * @param next Boolean that checks whose turn it is
   */
  void SetNextPlayer(bool next);

  /**
   * Changes bar height of the power bar
   * @param currentBarHeight height of the power bar
   */
  void SetCurrentBarHeight(size_t currentBarHeight);

  /**
   * Changes position of ball animation
   */
  void ChangeBallPosition();

  /**
   * Resets variables for the next turn
   */
  void Clear();

  /**
   * Draws Scoreboard on Screen
   */
  void DrawScoreboard();

  /**
   * Quits Game if button is pressed
   */
  void QuitGame();

  /**
   * Determines the defense type taken based on the button that is pushed
   * @param shot_type Type of defense chosen by player
   */
  void ChooseDefenseType(Defense::DefenseType defense_type);

  /**
   * Checks to see if the player has chosen their defense type
   */
  void CheckDefenseSelection();

  /**
   * Gets the type of shot that the player chose
   * @return Shot Type
   */
  Offense::ShotType GetShot() const;

  /**
   * Gets the current length coordinates of the basketball image
   * @return Vec2 of length
   */
  glm::vec2 GetCurrentLength() const;

  /**
   *  Gets the current width coordinates of the basketball image
   * @return Vec2 of width
   */
  glm::vec2 GetCurrentWidth() const;
  /**
   *  Chnages the value of the quit variable
   * @param vairable that represents if the player quit the game or not
   */
  void SetQuit(bool quit);


private:
  Player player_one_;
  Player player_two_;
  Offense::ShotType shot_;
  Offense offense_;
  Defense::DefenseType defense_type_;
  Defense defense_;
  size_t power_;
  size_t kStartingWidth = 500;
  size_t kEndingWidth = 550;
  size_t kStartingHeight = 450;
  size_t kEndingHeight = 250;
  size_t current_bar_height_;
  int change_in_power_;
  bool result_;
  bool next_player_;
  glm::vec2 top_left_;
  glm::vec2 bottom_right_;
  bool animation_finished_;
  ci::Color kTextColor = "white";
  ci::Color kButtonColor = "blue";
  size_t font_size_;
  size_t end_font_size_;
  size_t change_in_pos_;
  size_t kMaxYPos = 60;
  size_t kEndYPosTop = 375;
  bool part_one_;
  size_t player_one_score_;
  size_t player_two_score_;
  bool quit_;
};

} // namespace basketball
