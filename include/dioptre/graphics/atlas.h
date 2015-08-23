#ifndef DIOPTRE_GRAPHICS_ATLAS_H_
#define DIOPTRE_GRAPHICS_ATLAS_H_

#include "dioptre/font/face.h"

namespace dioptre {
namespace graphics {

class Atlas {
// Maximum texture width
#define MAXWIDTH 1024

public:
  Atlas(dioptre::font::Face* face, int size);
  ~Atlas() {}

  int getSize();

  virtual int initialize() = 0;

  unsigned int width_;  // width of texture
  unsigned int height_; // height of texture

  struct {
    float ax; // advanced.x
    float ay; // advanced.y

    float bw; // bitmap.width
    float bh; // bitmap.height

    float bl; // bitmap.left
    float bt; // bitmap.top

    float tx; // x offset of glyph in texture coordinates
    float ty; // y offset of glyph in texture coordinates
  } c[128];   // character information

protected:
  dioptre::font::Face* face_;
  int size_;
}; // Atlas

} // graphics
} // dioptre

#endif // DIOPTRE_GRAPHICS_ATLAS_H_
