#ifndef DIOPTRE_FONT_FREETYPE_BITMAP_H_
#define DIOPTRE_FONT_FREETYPE_BITMAP_H_

#include <ft2build.h>
#include FT_FREETYPE_H

#include "dioptre/font/bitmap.h"

namespace dioptre {
namespace font {
namespace freetype {

class Bitmap : public dioptre::font::Bitmap {
public:
  Bitmap(FT_GlyphSlot slot);

  unsigned int getWidth();
  unsigned int getRows();
  unsigned char* getBuffer();

private:
  FT_GlyphSlot slot_;
}; // Bitmap

} // freetype
} // font
} // dioptre

#endif // DIOPTRE_FONT_FREETYPE_BITMAP_H_
