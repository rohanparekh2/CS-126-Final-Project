#include "basketball_app.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
using ci::Rectf;
using glm::vec2;

namespace basketball {

BasketballApp::BasketballApp() : game_(player_two_, player_one_) {
  ci::app::setWindowSize((int)kWindowSize, (int)kWindowSize);
}
void BasketballApp::draw() {
  // https://libcinder.org/docs/guides/opengl/part4.html
  background = ci::gl::Texture2d::create(loadImage(
               loadAsset("/court.jpeg")));
  ci::gl::draw(background, getWindowBounds());
  basketball = ci::gl::Texture2d::create(loadImage(
           loadAsset("/basketball.png")));
  ci::gl::draw(basketball,Rectf(game_.GetCurrentLength(),
                                       game_.GetCurrentWidth()));
  game_.Draw();
}
void BasketballApp::keyDown(ci::app::KeyEvent event) {
  switch (event.getCode()) {
  case ci::app::KeyEvent::KEY_RETURN:
    game_.SetNextPlayer(true);
    break;
  case ci::app::KeyEvent::KEY_SPACE:
    game_.CheckShotResult();
    break;
  }
}

void BasketballApp::mouseDown(ci::app::MouseEvent event) {
  //Checks for coordinates or buttons and calls corresponding method
  // if the button is pressed
  if (event.getPos().y >= 240 && event.getPos().y <= 280) {
    if (game_.GetShot() == Offense::Default) {
      if (event.getPos().x >= 80 && event.getPos().x <= 230) {
        game_.ChooseShotType(Offense::Layup);
      }
      if (event.getPos().x >= 400 && event.getPos().x <= 550) {
        game_.ChooseShotType(Offense::Midrange);
      }
    } else {
      if (event.getPos().x >= 80 && event.getPos().x <= 230) {
        game_.ChooseDefenseType(Defense::Block);
      }
      if (event.getPos().x >= 400 && event.getPos().x <= 550) {
        game_.ChooseDefenseType(Defense::Steal);
      }
    }
  }
  if (event.getPos().y >= 360 && event.getPos().y <= 400) {
    if (game_.GetShot() == Offense::Default) {
      if (event.getPos().x >= 80 && event.getPos().x <= 230) {
        game_.ChooseShotType(Offense::ThreePointer);
      }
      if (event.getPos().x >= 440 && event.getPos().x <= 550) {
        game_.ChooseShotType(Offense::HalfCourt);
      }
    } else {
      if (event.getPos().x >= 250 && event.getPos().x <= 400) {
        game_.ChooseDefenseType(Defense::Contest);
      }
    }
  }
  if (event.getPos().y <= 50 && event.getPos().x <= 100) {
    game_.SetQuit(true);
  }
}

} // namespace basketball
