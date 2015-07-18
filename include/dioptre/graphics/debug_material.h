#ifndef DIOTRE_GRAPHICS_DEBUG_MATERIAL_H_
#define DIOTRE_GRAPHICS_DEBUG_MATERIAL_H_

#include "material.h"

namespace dioptre {
namespace graphics {

class DebugMaterial : public Material {
public:
  virtual ~DebugMaterial() {}

  void setColor(color color);
  color getColor();

protected:
  color color_;
}; // DebugMaterial

} // graphics
} // dioptre

#endif // DIOTRE_GRAPHICS_DEBUG_MATERIAL_H_
