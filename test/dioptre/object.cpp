#include <gtest/gtest.h>

#include "test_object.h"
#include "test_component.h"

#include "glm/glm.hpp"

TEST(Object, Initialization) {
  TestComponent *component1 = new TestComponent();
  TestComponent *component2 = new TestComponent();

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

TEST(Object, TransformChangeCascade) {
  TestComponent *component1 = new TestComponent();

  TestObject object;
  object.addComponent(component1);

  object.getTransform()->attach(component1);

  glm::vec3 expected(1.2, 3.45, 67.8);
  object.getTransform()->setPosition(expected.x, expected.y, expected.z);

  EXPECT_EQ(component1->getPosition(), expected);
}
