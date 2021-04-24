
#include "basketball_app.h"

namespace basketball {
basketball::BasketballApp::BasketballApp() {
  // create window and edit size
}
void BasketballApp::draw() {
  // draw out the court and add hoop/ball
}
void BasketballApp::keyDown(ci::app::KeyEvent event) {
  // Should call a function inside game_display instead of being set to
  // shot_type variable
  switch (event.getChar()) {
  case 'l':
    shot = ShotType::Layup;
  case 'm':
    shot = ShotType::Midrange;
  case 't':
    shot = ShotType::ThreePointer;
  case 'h':
    shot = ShotType::HalfCourt;
  }
}

} // namespace basketball
