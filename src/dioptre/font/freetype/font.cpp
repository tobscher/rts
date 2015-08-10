#include "dioptre/font/freetype/font.h"

namespace dioptre {
namespace font {
namespace freetype {

int Font::initialize() {
  if (FT_Init_FreeType(&ft)) {
    logger_->error("Could not init freetype library");
    return -1;
  }

  return 0;
}

void Font::destroy() {
  FT_Done_FreeType(ft);
}

} // freetype
} // font
} // dioptre
