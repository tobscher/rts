#ifndef DIOTRE_GRAPHICS_MESH_H_
#define DIOTRE_GRAPHICS_MESH_H_

#include "dioptre/object.h"
#include "object.h"
#include "geometry.h"
#include "material.h"

namespace dioptre {
namespace graphics {

class Mesh : public Object {
public:
  Mesh(Geometry* geometry, Material* material);

  bool isInitialized();
  void setIsInitialized(bool value);
  Geometry* getGeometry();
  Material* getMaterial();

  dioptre::ComponentInterface* getComponent() { return component_; }
  void setComponent(dioptre::ComponentInterface* component) { component_ = component; }

private:
  bool isInitialized_;

  Geometry* geometry_;
  Material* material_;

  dioptre::ComponentInterface* component_;
}; // Mesh

} // graphics
} // dioptre

#endif
