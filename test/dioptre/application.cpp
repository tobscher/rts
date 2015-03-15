#include <unittest++/UnitTest++.h>
#include "dioptre/application.h"

TEST(application_running) {
  char empty[1] = {0};
  char *argv[] = {empty, 0};
  int argc = 1;

  dioptre::Application *application = new dioptre::Application(argc, argv);
  CHECK(!application->isRunning());
}
