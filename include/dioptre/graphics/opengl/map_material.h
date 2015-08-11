#ifndef DIOPTRE_GRAPHICS_OPENGL_MAP_MATERIAL_H_
#define DIOPTRE_GRAPHICS_OPENGL_MAP_MATERIAL_H_

#include "dioptre/graphics/map_material.h"
#include "dioptre/graphics/opengl.h"
#include "dioptre/graphics/opengl/texture.h"
#include "glm/glm.hpp"

namespace dioptre {
namespace graphics {
namespace opengl {

class MapMaterial : public dioptre::graphics::MapMaterial {
public:
  MapMaterial();
  void initialize();
  void update();
  void destroy();

  void setMVP(glm::mat4 &m, glm::mat4 &v, glm::mat4 &mvp);
  void setProjection(glm::mat4 p);
  /* void projectWith(Projector* projector); */

protected:
  GLuint programId_;

  GLint lightPositionLocation_;
  GLint matrixLocation_;
  GLint viewLocation_;
  GLint matrixViewProjectionLocation_;
  GLint projectorMatrixLocation_;

  dioptre::graphics::opengl::Texture* glTexture_;
  dioptre::graphics::opengl::Texture* projectedTexture_;
}; // MapMaterial

} // opengl
} // graphics
} // dioptre

#endif // DIOPTRE_GRAPHICS_OPENGL_MAP_MATERIAL_H_
