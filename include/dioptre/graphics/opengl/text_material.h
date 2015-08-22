#ifndef DIOPTRE_GRAPHICS_OPENGL_TEXT_MATERIAL_H_
#define DIOPTRE_GRAPHICS_OPENGL_TEXT_MATERIAL_H_

#include "dioptre/graphics/text_material.h"
#include "dioptre/graphics/opengl.h"
#include "dioptre/graphics/opengl/texture.h"
#include "dioptre/graphics/opengl/atlas.h"
#include "glm/glm.hpp"

namespace dioptre {
namespace graphics {
namespace opengl {

class TextMaterial : public dioptre::graphics::TextMaterial {
public:
  TextMaterial(dioptre::graphics::opengl::Atlas* atlas);

  void initialize();
  void update();
  void destroy();

  void setMVP(glm::mat4 m, glm::mat4 v, glm::mat4 mvp);

protected:
  dioptre::graphics::opengl::Atlas* atlas_;
  GLuint programId_;

  GLint diffuseLocation_;
  GLint matrixViewProjectionLocation_;
}; // TextMaterial

} // opengl
} // graphics
} // dioptre

#endif // DIOPTRE_GRAPHICS_OPENGL_TEXT_MATERIAL_H_
