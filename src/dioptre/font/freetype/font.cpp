#include "dioptre/font/freetype/font.h"

namespace dioptre {
namespace font {
namespace freetype {

int Font::initialize() {
  if (FT_Init_FreeType(&library_)) {
    logger_->error("Could not init freetype library");
    return -1;
  }

  return 0;
}

FT_Library Font::getLibrary() {
  return library_;
}

void Font::destroy() {
  FT_Done_FreeType(library_);
}

} // freetype
} // font
} // dioptre
