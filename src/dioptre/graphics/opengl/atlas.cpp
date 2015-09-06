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
  /* // Move this to initialize method */
  /* face_->setSize(0, size); */

  /* // FT_GlyphSlot g = face->glyph; */
  /* auto glyph = face_->getGlyphSlot(); */

  /* unsigned int roww = 0; */
  /* unsigned int rowh = 0; */
  /* width_ = 0; */
  /* height_ = 0; */

  /* memset(c, 0, sizeof c); */

  /* /1* Find minimum size for a texture holding all visible ASCII characters *1/ */
  /* for (int i = 32; i < 128; i++) { */
  /*   if (face_->loadChar(i)) { */
  /*     fprintf(stderr, "Loading character %c failed!\n", i); */
  /*     continue; */
  /*   } */

  /*   auto bitmap = glyph->getBitmap(); */

  /*   if (roww + bitmap->getWidth() + 1 >= MAXWIDTH) { */
  /*     width_ = std::max(width_, roww); */
  /*     height_ += rowh; */
  /*     roww = 0; */
  /*     rowh = 0; */
  /*   } */

  /*   roww += bitmap->getWidth() + 1; */
  /*   rowh = std::max(rowh, bitmap->getRows()); */
  /* } */

  /* width_ = std::max(width_, roww); */
  /* height_ += rowh; */
}

int Atlas::initialize() {
  return 0;
  /* if (isInitialized_) return 0; */

  /* /1* Create a texture that will be used to hold all ASCII glyphs *1/ */
  /* glGenTextures(1, &texture_); */
  /* glActiveTexture(GL_TEXTURE0 + index_); */
  /* glBindTexture(GL_TEXTURE_2D, texture_); */

  /* glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, width_, height_, 0, GL_RED, GL_UNSIGNED_BYTE, 0); */
  /* check_gl_error(); */

  /* /1* We require 1 byte alignment when uploading texture data *1/ */
  /* glPixelStorei(GL_UNPACK_ALIGNMENT, 1); */

  /* /1* Clamping to edges is important to prevent artifacts when scaling *1/ */
  /* glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); */
  /* glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE); */

  /* /1* Linear filtering usually looks best for text *1/ */
  /* glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); */
  /* glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); */

  /* /1* Paste all glyph bitmaps into the texture, remembering the offset *1/ */
  /* int ox = 0; */
  /* int oy = 0; */

  /* unsigned int rowh = 0; */

  /* auto glyph = face_->getGlyphSlot(); */

  /* for (int i = 32; i < 128; i++) { */
  /*   if (face_->loadChar(i)) { */
  /*     fprintf(stderr, "Loading character %c failed!\n", i); */
  /*     continue; */
  /*   } */

  /*   auto bitmap = glyph->getBitmap(); */
  /*   auto advance = glyph->getAdvance(); */

  /*   if (ox + bitmap->getWidth() + 1 >= MAXWIDTH) { */
  /*     oy += rowh; */
  /*     rowh = 0; */
  /*     ox = 0; */
  /*   } */

  /*   glTexSubImage2D(GL_TEXTURE_2D, 0, ox, oy, bitmap->getWidth(), bitmap->getRows(), GL_RED, GL_UNSIGNED_BYTE, bitmap->getBuffer()); */
  /*   c[i].ax = advance->getX() >> 6; */
  /*   c[i].ay = advance->getY() >> 6; */

  /*   c[i].bw = bitmap->getWidth(); */
  /*   c[i].bh = bitmap->getRows(); */

  /*   c[i].bl = glyph->getBitmapLeft(); */
  /*   c[i].bt = glyph->getBitmapTop(); */

  /*   c[i].tx = ox / (float)width_; */
  /*   c[i].ty = oy / (float)height_; */

  /*   rowh = std::max(rowh, bitmap->getRows()); */
  /*   ox += bitmap->getWidth() + 1; */
  /* } */

  /* glBindTexture(GL_TEXTURE_2D, 0); */

  /* fprintf(stderr, "Generated a %d x %d (%d kb) texture atlas\n", width_, height_, width_ * height_ / 1024); */

  /* isInitialized_ = true; */

  /* return 0; */
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
