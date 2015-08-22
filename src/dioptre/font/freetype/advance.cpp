#include "dioptre/font/freetype/advance.h"

namespace dioptre {
namespace font {
namespace freetype {

Advance::Advance(FT_GlyphSlot slot) :
  slot_(slot)
{
}

int Advance::getX() {
  return slot_->advance.x;
}

int Advance::getY() {
  return slot_->advance.y;
}

} // freetype
} // font
} // dioptre
