#ifndef DIOPTRE_GRAPHICS_OPENGL_TEXTURE_H_
#define DIOPTRE_GRAPHICS_OPENGL_TEXTURE_H_

#include "dioptre/graphics/opengl.h"
#include "dioptre/graphics/texture.h"

#include <string>

namespace dioptre {
namespace graphics {
namespace opengl {

class Texture : public dioptre::graphics::Texture {
public:
  Texture(std::string imagePath);

  int initialize();
  void update();
  void updateGL(GLuint programId, const char* sampler, bool setRepeat);
  void destroy();

  GLuint getTexture();

  void setWrapS(GLint wrapS) { wrapS_ = wrapS; }
  void setWrapT(GLint wrapT) { wrapT_ = wrapT; }

  static int getNextIndex() { return nextIndex_++; }

private:
  static int nextIndex_;

  int index_;
  GLuint texture_;
  GLint wrapS_;
  GLint wrapT_;
}; // Texture

} // opengl
} // graphics
} // dioptre

#endif // DIOPTRE_GRAPHICS_OPENGL_TEXTURE_H_
