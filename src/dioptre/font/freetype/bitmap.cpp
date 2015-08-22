#include "dioptre/font/freetype/bitmap.h"

namespace dioptre {
namespace font {
namespace freetype {

Bitmap::Bitmap(FT_GlyphSlot slot) :
  slot_(slot)
{
}

unsigned int Bitmap::getWidth() {
  return slot_->bitmap.width;
}

unsigned int Bitmap::getRows() {
  return slot_->bitmap.rows;
}

unsigned char* Bitmap::getBuffer() {
  return slot_->bitmap.buffer;
}

} // freetype
} // font
} // dioptre
