#include <gtest/gtest.h>

#include "test_component.h"

TEST(ComponentInterface, Initialization) {
  TestComponent component;

  EXPECT_FALSE(component.getIsInitialized());

  component.initialize();

  EXPECT_TRUE(component.getIsInitialized());
}
