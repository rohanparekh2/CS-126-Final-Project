#pragma once

#include "cinder/gl/gl.h"
#include "defense.h"
#include <player.h>
#include <string>

namespace basketball {

class Offense {
public:
  /**
   * Enum values represent all the shot options the player could take
   */
  enum ShotType {
    Default,
    Layup,
    Midrange,
    ThreePointer,
    HalfCourt,
  };

  /**
   * Creates an Offense Object.
   */
  Offense();

  /**
   * Selects shot and calculates initial percentage
   * @param user_input Input decided by user through keys
   */
  void SelectShot(ShotType &user_input);
  /**
   * Calculates Probability of a Certain Shot Being Made when power is taken
   * into account
   * @param power Power of the shot determined by the power meter
   * @param defense Defense object that contains defense type
   */
  void CalculateShotPercentage(size_t power, Defense &defense);
  /**
   * Uses randomization to check if the player made the shot or not
   * @param current_player The player taking the shot
   * @param user_input Type of shot being taken
   * @param defense Defense object that contains defense type
   * @return bool that represents if the shot was made or not
   */
  bool DetermineShotResult(Player &current_player, ShotType &user_input,
                           Defense &defense) const;

  /**
   * Adjusts the score of the player depending on the shot that is made
   * @param current_player Current player
   * @param shot_type Type of shot taken
   */
  void AdjustScore(Player &current_player, ShotType &shot) const;

  /**
   * Gets the percentage that a shot is made
   *  @return double that represents the chance that the shot is made
   */
  double GetMakePercentage() const;

private:
  double make_percentage_;
  size_t kMinPower = 10;
  size_t kMaxPower = 90;
  size_t kPowerBonus = 10;
  size_t kOptimalPercentage = 100;
  size_t kMinimumPercentage = 0;
};

} // namespace basketball
