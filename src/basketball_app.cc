#include "basketball_app.h"

namespace basketball {

BasketballApp::BasketballApp()
    : game_(player_two_, player_one_) {
  ci::app::setWindowSize((int)kWindowSize, (int)kWindowSize);
}
void BasketballApp::draw() {
  // draw out the court and add hoop/ball
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
