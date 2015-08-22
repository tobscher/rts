#ifndef DIOPTRE_FONT_FREETYPE_FACE_H_
#define DIOPTRE_FONT_FREETYPE_FACE_H_

#include "dioptre/font/face.h"
#include "dioptre/font/freetype/glyph_slot.h"

#include <ft2build.h>
#include FT_FREETYPE_H

namespace dioptre {
namespace font {
namespace freetype {

class Face : public dioptre::font::Face {
public:
  Face(std::string fontFile);
  ~Face();

  int loadChar(int i);
  void setSize(int width, int height);
  GlyphSlot* getGlyphSlot();

private:
  FT_Face face_;
  GlyphSlot* glyphSlot_;
}; // Face

} // freetype
} // font
} // dioptre

#endif // DIOPTRE_FONT_FREETYPE_FACE_H_
