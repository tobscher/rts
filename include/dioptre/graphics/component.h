#ifndef DIOPTRE_GRAPHICS_COMPONENT_H_
#define DIOPTRE_GRAPHICS_COMPONENT_H_

#include "dioptre/component_interface.h"
#include "dioptre/graphics/projector.h"
#include "dioptre/graphics/mesh.h"
#include "glm/glm.hpp"

namespace dioptre {
namespace graphics {

class Component : public dioptre::ComponentInterface {
public:
  Component(Mesh* mesh, int layerIndex = 0);
  ~Component();

  void update();

  Mesh* getMesh();

  void setProjector(Projector* projector);
  Projector* getProjector();

private:
  Mesh* mesh_;
  Projector* projector_;
};

} // graphics
} // dioptre

#endif // DIOPTRE_GRAPHICS_COMPONENT_H_
