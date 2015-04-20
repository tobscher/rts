#ifndef DIOTRE_GRAPHICS_GEOMETRY_H_
#define DIOTRE_GRAPHICS_GEOMETRY_H_

#include <vector>
#include "glm/glm.hpp"

namespace dioptre {
namespace graphics {

class Geometry {
public:
  ~Geometry() {}
  std::vector<glm::vec3> getData();

protected:
  std::vector<glm::vec3> vertices_;
}; // Geometry

} // graphics
} // dioptre

#endif
