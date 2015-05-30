#ifndef DIOPTRE_GRAPHICS_COMPONENT_H_
#define DIOPTRE_GRAPHICS_COMPONENT_H_

#include "dioptre/component_interface.h"
#include "dioptre/graphics/mesh.h"
#include "glm/glm.hpp"

namespace dioptre {
namespace graphics {

class Component : public dioptre::ComponentInterface {
public:
  Component(Mesh* mesh);
  void update();

  // Translation
  void setPosition(glm::float32 x, glm::float32 y, glm::float32 z);
  void translateX(glm::float32 x);
  void translateY(glm::float32 y);
  void translateZ(glm::float32 z);
  void translate(glm::vec3 v);

  // Scale
  void setScale(glm::float32 x, glm::float32 y, glm::float32 z);

  // Rotation
  void rotateX(glm::float32 angle);
  void rotateY(glm::float32 angle);
  void rotateZ(glm::float32 angle);

private:
  Mesh* mesh_;
};

}
}

#endif // DIOPTRE_GRAPHICS_COMPONENT_H_
