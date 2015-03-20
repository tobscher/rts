#include <gtest/gtest.h>
#include "dioptre/application.h"

TEST(Application, IsRunning) {
  char empty[1] = {0};
  char *argv[] = {empty, 0};
  int argc = 1;

  dioptre::Application *application = new dioptre::Application(argc, argv);
  EXPECT_FALSE(application->isRunning());
}
