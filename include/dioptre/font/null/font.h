#ifndef DIOPTRE_FONT_NULL_FONT_H_
#define DIOPTRE_FONT_NULL_FONT_H_

#include "dioptre/font/font_interface.h"

namespace dioptre {
namespace font {
namespace null {

class Font : public dioptre::font::FontInterface {
public:
  virtual ~Font() {}

  // Module
  int initialize() { return 0; }
  void destroy() { }
}; // Font

} // null
} // font
} // dioptre

#endif // DIOPTRE_FONT_NULL_FONT_H_
