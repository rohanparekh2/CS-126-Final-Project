#pragma once

#include <cstddef>
namespace basketball {
class Defense {
public:
  enum DefenseType {
    Default,
    Block,
    Steal,
    Contest,
  };

  Defense();

  void SelectDefense(DefenseType &user_input);

  size_t GetTurnoverPercentage() const;

  size_t GetAdjustedShotPercentage() const;

private:
  size_t turnover_percentage_;
  size_t adjusted_shot_percentage;

};
} // namespace basketball
