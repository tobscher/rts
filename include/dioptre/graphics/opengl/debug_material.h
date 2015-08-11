#ifndef DIOPTRE_GRAPHICS_OPENGL_DEBUG_MATERIAL_H_
#define DIOPTRE_GRAPHICS_OPENGL_DEBUG_MATERIAL_H_

#include "dioptre/graphics/debug_material.h"
#include "dioptre/graphics/opengl.h"
#include "dioptre/graphics/opengl/texture.h"
#include "glm/glm.hpp"

namespace dioptre {
namespace graphics {
namespace opengl {

class DebugMaterial : public dioptre::graphics::DebugMaterial {
public:
  DebugMaterial();

  void initialize();
  void update();
  void destroy();

  void setMVP(glm::mat4 &m, glm::mat4 &v, glm::mat4 &mvp);

protected:
  GLuint programId_;

  GLint diffuseLocation_;
  GLint matrixViewProjectionLocation_;
}; // DebugMaterial

} // opengl
} // graphics
} // dioptre

#endif // DIOPTRE_GRAPHICS_OPENGL_DEBUG_MATERIAL_H_
