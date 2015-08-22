#ifndef DIOPTRE_FONT_FREETYPE_FONT_H_
#define DIOPTRE_FONT_FREETYPE_FONT_H_

#include "dioptre/font/font_interface.h"

#include <ft2build.h>
#include FT_FREETYPE_H

namespace dioptre {
namespace font {
namespace freetype {

class Font : public dioptre::font::FontInterface {
public:
  virtual ~Font() {}

  // Module
  int initialize();
  void destroy();

  FT_Library getLibrary();

private:
  FT_Library library_;
}; // Font

} // freetype
} // font
} // dioptre

#endif // DIOPTRE_FONT_FREETYPE_FONT_H_
