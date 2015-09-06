#include "dioptre/graphics/opengl/texture.h"
#include "dioptre/graphics/opengl/atlas.h"
#include "dioptre/graphics/opengl/error.h"

#include <algorithm>

namespace dioptre {
namespace graphics {
namespace opengl {

Atlas::Atlas(std::string file, std::string descriptionFile) :
  dioptre::graphics::Atlas(file, descriptionFile),
  isInitialized_(false),
  index_(dioptre::graphics::opengl::Texture::getNextIndex()),
  textureLocation_(-1)
{
}

int Atlas::initialize() {
  if (isInitialized_) return 0;

  dioptre::graphics::Atlas::initialize();

  // TODO(Tobscher) Use texture class
  // Create a texture that will be used to hold all ASCII glyphs
  glGenTextures(1, &texture_);
  glActiveTexture(GL_TEXTURE0 + index_);
  glBindTexture(GL_TEXTURE_2D, texture_);

  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width_, height_, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_);
  check_gl_error();

  /* We require 1 byte alignment when uploading texture data */
  /* glPixelStorei(GL_UNPACK_ALIGNMENT, 1); */

  /* Clamping to edges is important to prevent artifacts when scaling */
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

  /* Linear filtering usually looks best for text */
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  isInitialized_ = true;

  return 0;
}

void Atlas::updateGL(GLuint programId) {
  if (textureLocation_ == -1) {
    textureLocation_  = glGetUniformLocation(programId, "tex");
  }

  // check OpenGL error
  check_gl_error();

  glActiveTexture(GL_TEXTURE0 + index_);
  glBindTexture(GL_TEXTURE_2D, texture_);

  glUniform1i(textureLocation_, index_);
}

Atlas::~Atlas() {
  glDeleteTextures(1, &texture_);
}

} // opengl
} // graphics
} // dioptre
