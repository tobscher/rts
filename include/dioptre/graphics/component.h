#ifndef DIOPTRE_GRAPHICS_COMPONENT_H_
#define DIOPTRE_GRAPHICS_COMPONENT_H_

#include "dioptre/component_interface.h"
#include "dioptre/graphics/projector.h"
#include "dioptre/graphics/mesh.h"
#include "dioptre/graphics/transform_observer.h"

#include "glm/glm.hpp"

namespace dioptre {
namespace graphics {

class Component : public dioptre::ComponentInterface {
public:
  explicit Component(Mesh *mesh, int layerIndex = 0);
  ~Component();

  int initialize();
  void update();
  void makeCurrent();

  Mesh *getMesh();

  void setProjector(Projector *projector);
  Projector *getProjector();

private:
  Mesh *mesh_;
  Projector *projector_;
  dioptre::graphics::TransformObserver *transformObserver_;
};

} // graphics
} // dioptre

#endif // DIOPTRE_GRAPHICS_COMPONENT_H_
