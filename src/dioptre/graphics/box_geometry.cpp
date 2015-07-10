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

  // Normals
  for (int i = 0; i < 6; i++) {
    normals_.push_back(glm::vec3(0,-1,0));
  }

  // Side 1
  addPlane(
      glm::vec3(halfWidth, -halfHeight, -halfDepth),
      glm::vec3(-halfWidth, -halfHeight, -halfDepth),
      glm::vec3(halfWidth, halfHeight, -halfDepth),
      glm::vec3(-halfWidth, halfHeight, -halfDepth)
  );

  // Normals
  for (int i = 0; i < 6; i++) {
    normals_.push_back(glm::vec3(0,0,-1));
  }

  // Side 2
  addPlane(
      glm::vec3(-halfWidth, -halfHeight, -halfDepth),
      glm::vec3(-halfWidth, -halfHeight, halfDepth),
      glm::vec3(-halfWidth, halfHeight, -halfDepth),
      glm::vec3(-halfWidth, halfHeight, halfDepth)
  );

  // Normals
  for (int i = 0; i < 6; i++) {
    normals_.push_back(glm::vec3(-1,0,0));
  }

  // Side 3
  addPlane(
      glm::vec3(halfWidth, -halfHeight, halfDepth),
      glm::vec3(halfWidth, -halfHeight, -halfDepth),
      glm::vec3(halfWidth, halfHeight, halfDepth),
      glm::vec3(halfWidth, halfHeight, -halfDepth)
  );

  // Normals
  for (int i = 0; i < 6; i++) {
    normals_.push_back(glm::vec3(1,0,0));
  }

  // Side 4
  addPlane(
      glm::vec3(-halfWidth, -halfHeight, halfDepth),
      glm::vec3(halfWidth, -halfHeight, halfDepth),
      glm::vec3(-halfWidth, halfHeight, halfDepth),
      glm::vec3(halfWidth, halfHeight, halfDepth)
  );

  // Normals
  for (int i = 0; i < 6; i++) {
    normals_.push_back(glm::vec3(0,0,1));
  }

  // Top
  addPlane(
      glm::vec3(-halfWidth, halfHeight, halfDepth),
      glm::vec3(halfWidth, halfHeight, halfDepth),
      glm::vec3(-halfWidth, halfHeight, -halfDepth),
      glm::vec3(halfWidth, halfHeight, -halfDepth)
  );

  // Normals
  for (int i = 0; i < 6; i++) {
    normals_.push_back(glm::vec3(0,1,0));
  }

  for (int i = 0; i < 6; i++) {
    uvs_.push_back(glm::vec2(1,1));
    uvs_.push_back(glm::vec2(0,0));
    uvs_.push_back(glm::vec2(1,0));

    uvs_.push_back(glm::vec2(1,1));
    uvs_.push_back(glm::vec2(0,1));
    uvs_.push_back(glm::vec2(0,0));
  }
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
