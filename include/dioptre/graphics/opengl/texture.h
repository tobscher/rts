#ifndef DIOPTRE_GRAPHICS_OPENGL_TEXTURE_H_
#define DIOPTRE_GRAPHICS_OPENGL_TEXTURE_H_

#include "dioptre/graphics/opengl.h"
#include "dioptre/graphics/texture.h"

#include <string>

namespace dioptre {
namespace graphics {
namespace opengl {

class TextureFactory;
class Texture : public dioptre::graphics::Texture {
friend class TextureFactory;

public:

  int initialize();
  void update();
  void updateGL(GLuint programId, const char* sampler, bool setRepeat);
  void destroy();

  GLuint getTexture();

  void setWrapS(GLint wrapS) { wrapS_ = wrapS; }
  void setWrapT(GLint wrapT) { wrapT_ = wrapT; }

  bool getIsInitialized() { return isInitialized_; }

  static int getNextIndex() { return nextIndex_++; }

private:
  bool isInitialized_;
  Texture(std::string imagePath);
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
