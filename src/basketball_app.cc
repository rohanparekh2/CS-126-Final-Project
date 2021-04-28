#include "basketball_app.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"

namespace basketball {

BasketballApp::BasketballApp() : game_(player_two_, player_one_) {
  offense_ = Offense();
  ci::app::setWindowSize((int)kWindowSize, (int)kWindowSize);
}
void BasketballApp::draw() {
  // https://libcinder.org/docs/guides/opengl/part4.html
  background = ci::gl::Texture2d::create(loadImage(loadAsset("/court.jpeg")));
  ci::gl::draw(background, getWindowBounds());

  game_.Update();
}
void BasketballApp::keyDown(ci::app::KeyEvent event) {
  switch (event.getCode()) {
  case ci::app::KeyEvent::KEY_l:
    shot_ = Offense::Layup;
    game_.SetShot(shot_);
    offense_.SelectShot(shot_);
    break;
  case ci::app::KeyEvent::KEY_m:
    shot_ = Offense::Midrange;
    game_.SetShot(shot_);
    offense_.SelectShot(shot_);
    break;
  case ci::app::KeyEvent::KEY_t:
    shot_ = Offense::ThreePointer;
    game_.SetShot(shot_);
    offense_.SelectShot(shot_);
    break;
  case ci::app::KeyEvent::KEY_h:
    shot_ = Offense::HalfCourt;
    game_.SetShot(shot_);
    offense_.SelectShot(shot_);
    break;
  case ci::app::KeyEvent::KEY_RETURN:
    game_.SetNextPlayer(true);
    break;
  case ci::app::KeyEvent::KEY_SPACE:
    size_t power = game_.CalculatePower();
    game_.SetPower(power);
    offense_.CalculateShotPercentage(power);
    bool result = offense_.DetermineShotResult(player_two_, shot_);
    game_.SetResult(result);
    break;
  }
}

} // namespace basketball
