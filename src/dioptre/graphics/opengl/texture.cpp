#include "dioptre/graphics/opengl/texture.h"
#include "stb_image.h"
#include "glm/gtc/type_ptr.hpp"

#include <iostream>

namespace dioptre {
namespace graphics {
namespace opengl {

int Texture::initialize() {
  glGenTextures(1, &texture_);
  glBindTexture(GL_TEXTURE_2D, texture_);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

  if (components_ == 3)
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width_, height_, 0, GL_RGB, GL_UNSIGNED_BYTE, image_);
  else if (components_ == 4)
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width_, height_, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_);

  glBindTexture(GL_TEXTURE_2D, 0);

  // no longer needed
  stbi_image_free(image_);

  return 0;
}

void Texture::updateGL(GLuint programId) {
  GLuint textureLocation  = glGetUniformLocation(programId, "textureSampler");
  GLuint repeatLocation  = glGetUniformLocation(programId, "repeat");

  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, texture_);

  glUniform1i(textureLocation, 0);
  glUniform2fv(repeatLocation, 1, glm::value_ptr(repeat_));
}

void Texture::update() {
}

void Texture::destroy() {
  glDeleteTextures(1, &texture_);
}

} // opengl
} // graphics
} // dioptre
