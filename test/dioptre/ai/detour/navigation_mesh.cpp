#include <gtest/gtest.h>

#include "dioptre/ai/detour/navigation_mesh.h"
#include "test_box_geometry.h"

TEST(DetourNavigationMesh, Build) {
  auto width = 128.0;
  auto height = 128.0;

  auto geometry = new TestBoxGeometry(width, 1.0f, height);

  auto navMesh = new dioptre::ai::recast::NavigationMesh(geometry);
  navMesh->build();
  auto navMeshQuery = new dioptre::ai::detour::NavigationMesh(navMesh);
  navMeshQuery->build();
  /* navMeshQuery->find(glm::vec3(1, 0, 0), glm::vec3(10, 0, 0)); */
}
