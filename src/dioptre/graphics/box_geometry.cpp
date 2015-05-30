#include "dioptre/graphics/box_geometry.h"

#include "dioptre/debug.h"

namespace dioptre {
namespace graphics {

BoxGeometry::BoxGeometry(glm::float32 width, glm::float32 height, glm::float32 depth) {
  auto halfWidth = width / 2.0f;
  auto halfHeight = height / 2.0f;
  auto halfDepth = depth / 2.0f;

  // Bottom
  addPlane(
      glm::vec3(halfWidth, -halfHeight, halfDepth),
      glm::vec3(-halfWidth, -halfHeight, halfDepth),
      glm::vec3(halfWidth, -halfHeight, -halfDepth),
      glm::vec3(-halfWidth, -halfHeight, -halfDepth)
  );

  // Side 1
  addPlane(
      glm::vec3(halfWidth, -halfHeight, -halfDepth),
      glm::vec3(-halfWidth, -halfHeight, -halfDepth),
      glm::vec3(halfWidth, halfHeight, -halfDepth),
      glm::vec3(-halfWidth, halfHeight, -halfDepth)
  );

  // Side 2
  addPlane(
      glm::vec3(-halfWidth, -halfHeight, -halfDepth),
      glm::vec3(-halfWidth, -halfHeight, halfDepth),
      glm::vec3(-halfWidth, halfHeight, -halfDepth),
      glm::vec3(-halfWidth, halfHeight, halfDepth)
  );

  // Side 3
  addPlane(
      glm::vec3(halfWidth, -halfHeight, halfDepth),
      glm::vec3(halfWidth, -halfHeight, -halfDepth),
      glm::vec3(halfWidth, halfHeight, halfDepth),
      glm::vec3(halfWidth, halfHeight, -halfDepth)
  );

  // Side 4
  addPlane(
      glm::vec3(-halfWidth, -halfHeight, halfDepth),
      glm::vec3(halfWidth, -halfHeight, halfDepth),
      glm::vec3(-halfWidth, halfHeight, halfDepth),
      glm::vec3(halfWidth, halfHeight, halfDepth)
  );

  // Top
  addPlane(
      glm::vec3(-halfWidth, halfHeight, halfDepth),
      glm::vec3(halfWidth, halfHeight, halfDepth),
      glm::vec3(-halfWidth, halfHeight, -halfDepth),
      glm::vec3(halfWidth, halfHeight, -halfDepth)
  );
}

void BoxGeometry::addPlane(glm::vec3 a, glm::vec3 b, glm::vec3 c, glm::vec3 d) {
  vertices_.push_back(a);
  vertices_.push_back(d);
  vertices_.push_back(c);

  vertices_.push_back(a);
  vertices_.push_back(b);
  vertices_.push_back(d);
}

} // graphics
} // dioptre
