#include "dioptre/font/glyph_slot.h"

namespace dioptre {
namespace font {

GlyphSlot::GlyphSlot(Bitmap* bitmap, Advance* advance) :
  bitmap_(bitmap),
  advance_(advance)
{
}

Bitmap* GlyphSlot::getBitmap() {
  return bitmap_;
}

Advance* GlyphSlot::getAdvance() {
  return advance_;
}

} // font
} // dioptre
