#include "basketball_app.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"

namespace basketball {

BasketballApp::BasketballApp() : game_(player_two_, player_one_) {
  ci::app::setWindowSize((int)kWindowSize, (int)kWindowSize);
}
void BasketballApp::draw() {
  // https://libcinder.org/docs/guides/opengl/part4.html
  background = ci::gl::Texture2d::create(loadImage(loadAsset("/court.jpeg")));
  ci::gl::draw(background, getWindowBounds());
  //ci::gl::draw("basketball", get position from game_loop);

  game_.Draw();
}
void BasketballApp::keyDown(ci::app::KeyEvent event) {
  switch (event.getCode()) {
  case ci::app::KeyEvent::KEY_l:
    game_.ChooseShotType(Offense::Layup);
    break;
  case ci::app::KeyEvent::KEY_m:
    game_.ChooseShotType(Offense::Midrange);
    break;
  case ci::app::KeyEvent::KEY_t:
    game_.ChooseShotType(Offense::ThreePointer);
    break;
  case ci::app::KeyEvent::KEY_h:
    game_.ChooseShotType(Offense::HalfCourt);
    break;
  case ci::app::KeyEvent::KEY_RETURN:
    game_.SetNextPlayer(true);
    break;
  case ci::app::KeyEvent::KEY_SPACE:
    game_.CheckShotResult();
    break;
  }
}

} // namespace basketball
