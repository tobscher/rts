#ifndef DIOPTRE_FONT_BITMAP_H_
#define DIOPTRE_FONT_BITMAP_H_

namespace dioptre {
namespace font {

class Bitmap {
public:
  virtual unsigned int getWidth() = 0;
  virtual unsigned int getRows() = 0;
  virtual unsigned char* getBuffer() = 0;
}; // Bitmap

} // font
} // dioptre

#endif // DIOPTRE_FONT_BITMAP_H_
