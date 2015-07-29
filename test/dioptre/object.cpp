#include <gtest/gtest.h>

#include "test_object.h"
#include "test_component.h"

TEST(Object, Initialization) {
  TestComponent* component1 = new TestComponent();
  TestComponent* component2 = new TestComponent();

  EXPECT_FALSE(component1->getIsInitialized());
  EXPECT_FALSE(component2->getIsInitialized());

  TestObject object;

  object.addComponent(component1);
  object.addComponent(component2);

  object.initialize();

  EXPECT_TRUE(object.getIsInitialized());
  EXPECT_TRUE(component1->getIsInitialized());
  EXPECT_TRUE(component2->getIsInitialized());
}
