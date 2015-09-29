#include "dioptre/graphics/opengl/texture.h"
#include "dioptre/graphics/opengl/error.h"
#include "dioptre/locator.h"
#include "glm/gtc/type_ptr.hpp"

#include "SOIL2.h"

#include <iostream>

namespace dioptre {
namespace graphics {
namespace opengl {

int Texture::nextIndex_ = 0;

Texture::Texture(std::string imagePath)
    : isInitialized_(false), textureLocation_(-1), repeatLocation_(-1),
      dioptre::graphics::Texture(imagePath), index_(getNextIndex()),
      wrapS_(GL_REPEAT), wrapT_(GL_REPEAT) {}

int Texture::initialize() {
  if (isInitialized_)
    return 0;

  glGenTextures(1, &texture_);
  glActiveTexture(GL_TEXTURE0 + index_);
  glBindTexture(GL_TEXTURE_2D, texture_);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapS_);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapT_);

  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width_, height_, 0, GL_RGBA,
               GL_UNSIGNED_BYTE, image_);

  glBindTexture(GL_TEXTURE_2D, 0);

  // no longer needed
  SOIL_free_image_data(image_);

  isInitialized_ = true;

  return 0;
}

void Texture::updateGL(GLuint programId, const char *sampler, bool setRepeat) {
  if (textureLocation_ == -1) {
    textureLocation_ = glGetUniformLocation(programId, sampler);
  }

  if (setRepeat) {
    if (repeatLocation_ == -1) {
      repeatLocation_ = glGetUniformLocation(programId, "repeat");
    }
    glUniform2fv(repeatLocation_, 1, glm::value_ptr(repeat_));
  }

  glActiveTexture(GL_TEXTURE0 + index_);
  glBindTexture(GL_TEXTURE_2D, texture_);

  glUniform1i(textureLocation_, index_);
}

void Texture::update() {}

void Texture::destroy() { glDeleteTextures(1, &texture_); }

} // opengl
} // graphics
} // dioptre
