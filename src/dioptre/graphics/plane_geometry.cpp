#include "dioptre/graphics/plane_geometry.h"

#include "dioptre/debug.h"

namespace dioptre {
namespace graphics {

PlaneGeometry::PlaneGeometry(glm::float32 width, glm::float32 depth)
    : width_(width), depth_(depth) {
  auto halfWidth = width / 2.0f;
  auto halfDepth = depth_ / 2.0f;

  // Vertices
  vertices_.push_back(glm::vec3(halfWidth, 0.0, halfDepth));
  vertices_.push_back(glm::vec3(halfWidth, 0.0, -halfDepth));
  vertices_.push_back(glm::vec3(-halfWidth, 0.0, -halfDepth));
  vertices_.push_back(glm::vec3(-halfWidth, 0.0, halfDepth));

  // Normals
  for (unsigned int i = 0; i < 4; i++) {
    normals_.push_back(glm::vec3(0, 1, 0));
  }

  // Faces
  faces_.push_back(glm::uvec3(0, 1, 2));
  faces_.push_back(glm::uvec3(0, 2, 3));

  // UV coordinates
  uvs_.push_back(glm::vec2(1, 0));
  uvs_.push_back(glm::vec2(1, 1));
  uvs_.push_back(glm::vec2(0, 1));
  uvs_.push_back(glm::vec2(0, 0));
}

glm::float32 PlaneGeometry::getWidth() { return width_; }

glm::float32 PlaneGeometry::getDepth() { return depth_; }

} // graphics
} // dioptre
