#pragma once
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "offense.h"

namespace basketball {

class BasketballApp : public ci::app::App {
public:
  BasketballApp();

  void draw() override;
  void keyDown(ci::app::KeyEvent event) override;

private:
  ShotType shot;
};

} // namespace basketball
