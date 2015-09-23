#include <gtest/gtest.h>

#include "test_box_geometry.h"

TEST(BoxGeometry, BoundingBox) {
  TestBoxGeometry box(5, 10, 15);

  auto boundingBox = box.getBoundingBox();
  EXPECT_EQ(boundingBox->getMin(), glm::vec3(-2.5, -5, -7.5));
  EXPECT_EQ(boundingBox->getMax(), glm::vec3(2.5, 5, 7.5));
}
