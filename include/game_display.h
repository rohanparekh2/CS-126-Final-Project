#pragma once

#include "offense.h"
#include "player.h"
#include <string>
namespace basketball {

class GameDisplay {
public:
  GameDisplay();

  GameDisplay(Player &player_one, Player &player_two);

  void Update();

  Player DetermineWinner(Player &player_one, Player &player_two) const;

  void CheckShotSelection();

  void CreatePowerMeter();

  size_t CalculatePower() const;

  Offense::ShotType GetShot() const;

  void SetShot(Offense::ShotType s);

  size_t GetPower() const;

  void SetPower(size_t p);

  bool GetResult() const;

  void SetResult(bool r);

  void SetNextPlayer(bool next);

  bool GetNextPlayer() const;

private:
  Player player_one_;
  Player player_two_;
  Offense::ShotType shot_;
  size_t power_;
  size_t kStartingWidth = 400;
  size_t kEndingWidth = 425;
  size_t kStartingHeight = 500;
  size_t kEndingHeight = 400;
  size_t current_bar_height_;
  int change_in_power_;
  bool result_;
  bool next_player;
};

} // namespace basketball
