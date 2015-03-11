#include <unittest++/UnitTest++.h>
#include "dioptre/application.h"

TEST(application_running) {
  dioptre::Application *application = new dioptre::Application();
  CHECK(!application->isRunning());
}
