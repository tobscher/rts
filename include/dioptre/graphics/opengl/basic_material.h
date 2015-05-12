#ifndef DIOPTRE_GRAPHICS_OPENGL_BASIC_MATERIAL_H_
#define DIOPTRE_GRAPHICS_OPENGL_BASIC_MATERIAL_H_

#include "dioptre/graphics/basic_material.h"
#include "dioptre/graphics/opengl.h"

namespace dioptre {
namespace graphics {
namespace opengl {

class BasicMaterial : public dioptre::graphics::BasicMaterial {
public:
  void initialize();
  void update();

protected:
  GLuint programId_;
}; // BasicMaterial

} // opengl
} // graphics
} // dioptre

#endif // DIOPTRE_GRAPHICS_OPENGL_BASIC_MATERIAL_H_
