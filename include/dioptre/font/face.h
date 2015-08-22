#ifndef DIOPTRE_FONT_FACE_H_
#define DIOPTRE_FONT_FACE_H_

#include <string>
#include "dioptre/font/glyph_slot.h"

namespace dioptre {
namespace font {

class Face {
public:
  Face(std::string fontFile);
  virtual ~Face() {}

  virtual int loadChar(int i) = 0;
  virtual void setSize(int width, int height) = 0;
  virtual GlyphSlot* getGlyphSlot() = 0;

protected:
  std::string fontFile_;
}; // Face

} // font
} // dioptre

#endif // DIOPTRE_FONT_FACE_H_
