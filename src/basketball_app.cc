
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
  // shot_type
  switch (event.getChar()) {
  case 'l':
    shot_type = "layup";
  case 'm':
    shot_type = "midrange";
  case 't':
    shot_type = "three-pointer";
  case 'h':
    shot_type = "half court";
  }
}

} // namespace basketball
