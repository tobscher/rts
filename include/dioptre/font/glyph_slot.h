#ifndef DIOPTRE_FONT_GLYPH_SLOT_H_
#define DIOPTRE_FONT_GLYPH_SLOT_H_

#include "dioptre/font/bitmap.h"
#include "dioptre/font/advance.h"

namespace dioptre {
namespace font {

class GlyphSlot {
public:
  GlyphSlot(Bitmap* bitmap, Advance* advance);
  virtual ~GlyphSlot() {}

  Bitmap* getBitmap();
  Advance* getAdvance();

  virtual int getBitmapLeft() = 0;
  virtual int getBitmapTop() = 0;

private:
  Bitmap* bitmap_;
  Advance* advance_;
}; // GlyphSlot

} // font
} // dioptre

#endif // DIOPTRE_FONT_GLYPH_SLOT_H_
