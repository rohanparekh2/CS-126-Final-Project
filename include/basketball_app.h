#pragma once
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "game_display.h"
#include "offense.h"

namespace basketball {

class BasketballApp : public ci::app::App {
public:
  BasketballApp();

  void draw() override;
  void keyDown(ci::app::KeyEvent event) override;
  void mouseDown(ci::app::MouseEvent event) override;

private:
  std::string kPlayerOneName = "Player 1";
  std::string kPlayerTwoName = "Player 2";
  Player player_one_ = Player(kPlayerOneName);
  Player player_two_ = Player(kPlayerTwoName);
  GameDisplay game_;
  const double kWindowSize = 600;
  ci::gl::Texture2dRef background;
};

} // namespace basketball
