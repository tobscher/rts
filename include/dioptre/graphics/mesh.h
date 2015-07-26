#ifndef DIOTRE_GRAPHICS_MESH_H_
#define DIOTRE_GRAPHICS_MESH_H_

#include "dioptre/object.h"
#include "dioptre/graphics/object.h"
#include "dioptre/graphics/geometry.h"
#include "dioptre/graphics/material.h"

namespace dioptre {
namespace graphics {

class Mesh : public Object {
public:
  Mesh(Geometry* geometry, Material* material);

  bool isInitialized();
  void setIsInitialized(bool value);
  Geometry* getGeometry();
  Material* getMaterial();

  ComponentInterface* getComponent();
  void setComponent(ComponentInterface* component);

private:
  bool isInitialized_;

  Geometry* geometry_;
  Material* material_;

  ComponentInterface* component_;
}; // Mesh

} // graphics
} // dioptre

#endif
