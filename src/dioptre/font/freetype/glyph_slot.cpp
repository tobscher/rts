#include "dioptre/font/freetype/glyph_slot.h"
#include "dioptre/font/freetype/bitmap.h"
#include "dioptre/font/freetype/advance.h"

namespace dioptre {
namespace font {
namespace freetype {

using dioptre::font::freetype::Bitmap;
using dioptre::font::freetype::Advance;

GlyphSlot::GlyphSlot(FT_GlyphSlot slot) :
  dioptre::font::GlyphSlot(new Bitmap(slot), new Advance(slot)),
  slot_(slot)
{
}

int GlyphSlot::getBitmapLeft() {
  return slot_->bitmap_left;
}

int GlyphSlot::getBitmapTop() {
  return slot_->bitmap_top;
}

} // freetype
} // font
} // dioptre
