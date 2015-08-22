#ifndef DIOPTRE_FONT_FREETYPE_ADVANCE_H_
#define DIOPTRE_FONT_FREETYPE_ADVANCE_H_

#include <ft2build.h>
#include FT_FREETYPE_H

#include "dioptre/font/advance.h"

namespace dioptre {
namespace font {
namespace freetype {

class Advance : public dioptre::font::Advance {
public:
  Advance(FT_GlyphSlot slot);

  int getX();
  int getY();

private:
  FT_GlyphSlot slot_;
}; // Advance

} // freetype

} // font
} // dioptre

#endif // DIOPTRE_FONT_ADVANCE_H_
