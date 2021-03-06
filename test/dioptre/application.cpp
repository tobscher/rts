#include <gtest/gtest.h>

#include "dioptre/application.h"
#include "test_object.h"
#include "another_test_object.h"

TEST(Application, IsRunning) {
  char empty[1] = {0};
  char *argv[] = {empty, 0};
  int argc = 1;

  dioptre::Application application(argc, argv);
  EXPECT_FALSE(application.isRunning());
}

TEST(Application, Initialization) {
  char empty[1] = {0};
  char *argv[] = {empty, 0};
  int argc = 1;

  TestObject* object1 = new TestObject();
  TestObject* object2 = new TestObject();

  EXPECT_FALSE(object1->getIsInitialized());
  EXPECT_FALSE(object2->getIsInitialized());

  dioptre::Application application(argc, argv);
  application.addObject(object1);
  application.addObject(object2);

  application.initialize();

  EXPECT_TRUE(application.getIsInitialized());
  EXPECT_TRUE(object1->getIsInitialized());
  EXPECT_TRUE(object2->getIsInitialized());
}

TEST(Application, getObjectByName) {
  char empty[1] = {0};
  char *argv[] = {empty, 0};
  int argc = 1;

  TestObject* object1 = new TestObject();
  AnotherTestObject* object2 = new AnotherTestObject();

  dioptre::Application application(argc, argv);
  application.addObject(object1);
  application.addObject(object2);

  EXPECT_TRUE(application.getObjectByName("test_object") == object1);
  EXPECT_TRUE(application.getObjectByName("another_test_object") == object2);
  EXPECT_TRUE(application.getObjectByName("foo") == nullptr);
}
