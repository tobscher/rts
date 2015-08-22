#ifndef DIOPTRE_FONT_FREETYPE_GLYPH_SLOT_H_
#define DIOPTRE_FONT_FREETYPE_GLYPH_SLOT_H_

#include "dioptre/font/glyph_slot.h"

#include <ft2build.h>
#include FT_FREETYPE_H

namespace dioptre {
namespace font {
namespace freetype {

class GlyphSlot : public dioptre::font::GlyphSlot {
public:
  GlyphSlot(FT_GlyphSlot glyphSlot);

  int getBitmapLeft();
  int getBitmapTop();

private:
  FT_GlyphSlot slot_;
}; // GlyphSlot

} // freeetype
} // font
} // dioptre

#endif // DIOPTRE_FONT_FREETYPE_GLYPH_SLOT_H_
