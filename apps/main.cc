#include <basketball_app.h>

using basketball::BasketballApp;

void prepareSettings(BasketballApp::Settings* settings) {
  settings->setResizable(false);
}

// This line is a macro that expands into an "int main()" function.
CINDER_APP(BasketballApp, ci::app::RendererGl, prepareSettings);

