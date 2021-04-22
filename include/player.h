#pragma once

#include <string>
namespace basketball {

class Player {
public:
  Player();

  Player(std::string& name);

  void AdjustScore(std::string& shot_type);

  friend bool operator==(const Player &player_one, const Player& player_two);

  size_t GetScore() const;

  const std::string &GetName() const;

private:
  size_t score_;


  std::string name_;
};

} // namespace basketball

