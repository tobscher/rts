#ifndef DIOPTRE_FONT_FREETYPE_FONT_H_
#define DIOPTRE_FONT_FREETYPE_FONT_H_

#include "dioptre/font/font_interface.h"

namespace dioptre {
namespace font {
namespace freetype {

class Font : public dioptre::font::FontInterface {
public:
  virtual ~Font() {}

  // Module
  int initialize() { return 0; }
  void destroy() { }
}; // Font

} // freetype
} // font
} // dioptre

#endif // DIOPTRE_FONT_FREETYPE_FONT_H_
