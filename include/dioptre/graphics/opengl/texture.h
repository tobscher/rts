#ifndef DIOPTRE_GRAPHICS_OPENGL_TEXTURE_H_
#define DIOPTRE_GRAPHICS_OPENGL_TEXTURE_H_

#include "dioptre/graphics/opengl.h"
#include "dioptre/graphics/texture.h"

namespace dioptre {
namespace graphics {
namespace opengl {

class Texture : public dioptre::graphics::Texture {
public:
  Texture(std::string imagePath) : dioptre::graphics::Texture(imagePath) {}

  int initialize();
  void update();
  void updateGL(GLuint programId);
  void destroy();

  GLuint getTexture();

private:
  GLuint texture_;
}; // Texture

} // opengl
} // graphics
} // dioptre

#endif // DIOPTRE_GRAPHICS_OPENGL_TEXTURE_H_
