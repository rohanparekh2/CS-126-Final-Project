#pragma once
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "game_loop.h"
#include "offense.h"

namespace basketball {
/**
 * Creates a new Basketball Game that lets the user use keys to pick their shot
 * and power
 */
class BasketballApp : public ci::app::App {
public:
  /**
   * Creates a new Basketball App.
   */
  BasketballApp();

  void draw() override;
  void keyDown(ci::app::KeyEvent event) override;

private:
  std::string kPlayerOneName = "Player 1";
  std::string kPlayerTwoName = "Player 2";
  Player player_one_ = Player(kPlayerOneName);
  Player player_two_ = Player(kPlayerTwoName);
  GameLoop game_;
  const double kWindowSize = 600;
  ci::gl::Texture2dRef background;
};

} // namespace basketball
