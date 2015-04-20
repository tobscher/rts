#ifndef DIOPTRE_GRAPHICS_OBJECT_H_
#define DIOPTRE_GRAPHICS_OBJECT_H_

#include "glm/glm.hpp"

namespace dioptre {
namespace graphics {

class Object {
public:
  Object();
  virtual ~Object() {};

  int getId();

private:
  int id_;

  glm::mat4x4 matrix_;
  glm::vec3 position_;
  glm::vec3 scale_;
}; // Object

} // graphics
} // dioptre

#endif
