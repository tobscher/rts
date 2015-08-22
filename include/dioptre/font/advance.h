#ifndef DIOPTRE_FONT_ADVANCE_H_
#define DIOPTRE_FONT_ADVANCE_H_

namespace dioptre {
namespace font {

class Advance {
public:
  virtual int getX() = 0;
  virtual int getY() = 0;
}; // Advance

} // font
} // dioptre

#endif // DIOPTRE_FONT_ADVANCE_H_
