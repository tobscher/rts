#ifndef DIOPTRE_GRAPHICS_OPENGL_BASIC_MATERIAL_H_
#define DIOPTRE_GRAPHICS_OPENGL_BASIC_MATERIAL_H_

#include "dioptre/graphics/basic_material.h"
#include "dioptre/graphics/opengl.h"
#include "dioptre/graphics/opengl/texture.h"
#include "glm/glm.hpp"

namespace dioptre {
namespace graphics {
namespace opengl {

class BasicMaterial : public dioptre::graphics::BasicMaterial {
public:
  BasicMaterial();

  void initialize();
  void update();
  void destroy();

  void setMVP(glm::mat4 &m, glm::mat4 &v, glm::mat4 &mvp);

protected:
  GLuint programId_;

  GLint diffuseLocation_;
  GLint lightPositionLocation_;
  GLint matrixLocation_;
  GLint viewLocation_;
  GLint matrixViewProjectionLocation_;


  dioptre::graphics::opengl::Texture* glTexture_;
  dioptre::graphics::opengl::Texture* glTexture2_;
}; // BasicMaterial

} // opengl
} // graphics
} // dioptre

#endif // DIOPTRE_GRAPHICS_OPENGL_BASIC_MATERIAL_H_
