#pragma once

#include <cstddef>
namespace basketball {
class Defense {
public:
  /**
   * Enum values represent all the defene options the player could take
   */
  enum DefenseType {
    Default,
    Block,
    Steal,
    Contest,
  };
  /**
   * Creates Defense Object
   */
  Defense();

  /**
   * Creates Defense Object
   * @param d Type of defense
   */
  Defense(DefenseType d);

  /**
   * Selects defense and calculates turnover percentage and adjusted percentage
   * @param user_input Type of defense chosen
   */
  void SelectDefense(DefenseType &user_input);

  /**
   * Getter for adjusted shot_percentage used in offense class
   * @return int that represents adjusted shot percentage
   */
  int GetAdjustedShotPercentage() const;

  /**
   * Getter for adjusted turnover_percentage used in offense class
   * @return int that represents turnover percentage
   */
  size_t GetTurnoverPercentage() const;

private:
  size_t turnover_percentage_;
  int adjusted_shot_percentage;
};
} // namespace basketball
