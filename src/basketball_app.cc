#include "basketball_app.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"

namespace basketball {

BasketballApp::BasketballApp()
    : game_(player_two_, player_one_) {
  ci::app::setWindowSize((int)kWindowSize, (int)kWindowSize);
}
void BasketballApp::draw() {
  //https://libcinder.org/docs/guides/opengl/part4.html
  background = ci::gl::Texture2d::create(loadImage(
      loadAsset("/court.jpeg")));
  ci::gl::draw(background, getWindowBounds());

  // draw out the court and add hoop/ball
  //ci::gl::drawStrokedRect(ci::Rectf(glm::vec2(100,100),
                      //  glm::vec2(200,200)));
  //game_.Update();
}
void BasketballApp::keyDown(ci::app::KeyEvent event) {
  switch (event.getChar()) {
    case 'l':
      game_.SetShot(Offense::Layup);
      break;
    case 'm':
      game_.SetShot(Offense::Midrange);
      break;
    case 't':
      game_.SetShot(Offense::ThreePointer);
      break;
    case 'h':
      game_.SetShot(Offense::HalfCourt);
      break;
  }
}

void BasketballApp::mouseDown(ci::app::MouseEvent event) {
  size_t power = game_.CalculatePower();
  game_.SetPower(power);
}

} // namespace basketball
