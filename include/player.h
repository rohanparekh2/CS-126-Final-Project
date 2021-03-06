#pragma once
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
   * Overlaods == operator
   * @param player_one The first player
   * @param player_two the second player
   * @return bool that represents if the players are the same
   */
  friend bool operator==(const Player &player_one, const Player &player_two);

  /**
   * Adds two points if player made 2-pointer
   */
  void TwoPointer();

  /**
   * Adds two points if player made 3-pointer
   */
  void ThreePointer();

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

  /**
 * Sets the score of the player
 * @param s The player's score
 */
  void SetScore(size_t s);

private:
  size_t score_;
  std::string name_;
};

} // namespace basketball
