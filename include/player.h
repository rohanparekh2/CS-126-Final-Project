#pragma once

#include "offense.h"
#include <string>
namespace basketball {

class Player {
public:
  /**
   * Creates an Player Object.
   */
  Player();
  /**
   * Creates a new Player
   * @param name The name of the player
   */
  Player(std::string &name);

  /**
   * Adjusts the score of the player depending on tha shot that is made
   * @param shot_type Type of shot taken
   */
  void AdjustScore(ShotType &shot);

  Player DetermineWinner(Player& player_one, Player& player_two) const;

  /**
 * Overlaods == operator
 * @param player_one The first player
 * @param player_two the second player
 * @return bool that represents if the players are the same
 */
  friend bool operator==(const Player &player_one, const Player &player_two);
  /**
   * Returns the current score of the player
   * @return The player's score
   */
  size_t GetScore() const;
  /**
   * Returns the name of the player
   * @return The player's name
   */
  const std::string &GetName() const;

private:
  size_t score_;
  std::string name_;
};

} // namespace basketball
