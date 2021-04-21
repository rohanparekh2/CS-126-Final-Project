#pragma once

#include <string>
namespace basketball {

class GameDisplay {
public:
 GameDisplay();

 void Update();
private:
  std::string player_one_name_;
  std::string player_two_name_;
};

} // namespace basketball
