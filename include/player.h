#pragma once

#include <string>
namespace basketball {

class Player {
public:
  Player();

  void AdjustScore(std::string& shot_type);

private:
  size_t score_;
  std::string name_;

};

} // namespace basketball

