#include "dioptre/graphics/box_geometry.h"

#include "dioptre/debug.h"

namespace dioptre {
namespace graphics {

BoxGeometry::BoxGeometry(glm::float32 width, glm::float32 height,
                         glm::float32 depth)
    : width_(width), height_(height), depth_(depth) {
  auto halfWidth = width / 2.0f;
  auto halfHeight = height / 2.0f;
  auto halfDepth = depth / 2.0f;

  // Back vertices
  vertices_.push_back(glm::vec3(halfWidth, -halfHeight, halfDepth));
  vertices_.push_back(glm::vec3(halfWidth, halfHeight, halfDepth));
  vertices_.push_back(glm::vec3(-halfWidth, halfHeight, halfDepth));
  vertices_.push_back(glm::vec3(-halfWidth, -halfHeight, halfDepth));

  // Front vertices
  vertices_.push_back(glm::vec3(-halfWidth, -halfHeight, -halfDepth));
  vertices_.push_back(glm::vec3(-halfWidth, halfHeight, -halfDepth));
  vertices_.push_back(glm::vec3(halfWidth, halfHeight, -halfDepth));
  vertices_.push_back(glm::vec3(halfWidth, -halfHeight, -halfDepth));

  // Left vertices
  vertices_.push_back(glm::vec3(-halfWidth, -halfHeight, halfDepth));
  vertices_.push_back(glm::vec3(-halfWidth, halfHeight, halfDepth));
  vertices_.push_back(glm::vec3(-halfWidth, halfHeight, -halfDepth));
  vertices_.push_back(glm::vec3(-halfWidth, -halfHeight, -halfDepth));

  // Right vertices
  vertices_.push_back(glm::vec3(halfWidth, -halfHeight, -halfDepth));
  vertices_.push_back(glm::vec3(halfWidth, halfHeight, -halfDepth));
  vertices_.push_back(glm::vec3(halfWidth, halfHeight, halfDepth));
  vertices_.push_back(glm::vec3(halfWidth, -halfHeight, halfDepth));

  // Top vertices
  vertices_.push_back(glm::vec3(halfWidth, halfHeight, halfDepth));
  vertices_.push_back(glm::vec3(halfWidth, halfHeight, -halfDepth));
  vertices_.push_back(glm::vec3(-halfWidth, halfHeight, -halfDepth));
  vertices_.push_back(glm::vec3(-halfWidth, halfHeight, halfDepth));

  // Bottom vertices
  vertices_.push_back(glm::vec3(halfWidth, -halfHeight, -halfDepth));
  vertices_.push_back(glm::vec3(halfWidth, -halfHeight, halfDepth));
  vertices_.push_back(glm::vec3(-halfWidth, -halfHeight, halfDepth));
  vertices_.push_back(glm::vec3(-halfWidth, -halfHeight, -halfDepth));

  // Back
  for (unsigned int i = 0; i < 4; i++) {
    normals_.push_back(glm::vec3(0, 0, 1));
  }

  // Front
  for (unsigned int i = 0; i < 4; i++) {
    normals_.push_back(glm::vec3(0, 0, -1));
  }

  // Left
  for (unsigned int i = 0; i < 4; i++) {
    normals_.push_back(glm::vec3(-1, 0, 0));
  }

  // Right
  for (unsigned int i = 0; i < 4; i++) {
    normals_.push_back(glm::vec3(1, 0, 0));
  }

  // Top
  for (unsigned int i = 0; i < 4; i++) {
    normals_.push_back(glm::vec3(0, 1, 0));
  }

  // Bottom
  for (unsigned int i = 0; i < 4; i++) {
    normals_.push_back(glm::vec3(0, -1, 0));
  }

  // Back
  faces_.push_back(glm::uvec3(0, 1, 2));
  faces_.push_back(glm::uvec3(0, 2, 3));

  // Front
  faces_.push_back(glm::uvec3(4, 5, 6));
  faces_.push_back(glm::uvec3(4, 6, 7));

  // Left
  faces_.push_back(glm::uvec3(8, 9, 10));
  faces_.push_back(glm::uvec3(8, 10, 11));

  // Right
  faces_.push_back(glm::uvec3(12, 13, 14));
  faces_.push_back(glm::uvec3(12, 14, 15));

  // Top
  faces_.push_back(glm::uvec3(16, 17, 18));
  faces_.push_back(glm::uvec3(16, 18, 19));

  // Bottom
  faces_.push_back(glm::uvec3(20, 21, 22));
  faces_.push_back(glm::uvec3(20, 22, 23));

  // UV coordinates
  for (int i = 0; i < 6; i++) {
    uvs_.push_back(glm::vec2(1, 0));
    uvs_.push_back(glm::vec2(1, 1));
    uvs_.push_back(glm::vec2(0, 1));
    uvs_.push_back(glm::vec2(0, 0));
  }
}

} // graphics
} // dioptre
