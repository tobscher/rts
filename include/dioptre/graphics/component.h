#ifndef DIOPTRE_GRAPHICS_COMPONENT_H_
#define DIOPTRE_GRAPHICS_COMPONENT_H_

#include "dioptre/component_interface.h"
#include "dioptre/graphics/mesh.h"

namespace dioptre {
namespace graphics {

class Component : public dioptre::ComponentInterface {
public:
  Component(Mesh* mesh);
  void update();

private:
  Mesh* mesh_;
};

}
}

#endif // DIOPTRE_GRAPHICS_COMPONENT_H_
