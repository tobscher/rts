#include <gtest/gtest.h>

#include "dioptre/ai/recast/navigation_mesh.h"
#include "test_box_geometry.h"

TEST(NavigationMesh, Build) {
  auto width = 128.0;
  auto height = 128.0;

  auto geometry = new TestBoxGeometry(width, 1.0f, height);

  auto navMesh = new dioptre::ai::recast::NavigationMesh(geometry);
  navMesh->build();
}
