#ifndef DIOPTRE_GRAPHICS_ATLAS_H_
#define DIOPTRE_GRAPHICS_ATLAS_H_

#include <string>
#include <map>

namespace dioptre {
namespace graphics {

class Atlas {

  struct Char {
    int placeX;
    int placeY;
    int placeW;
    int placeH;

    int width;
    int offsetX;
    int offsetY;

    Char()
        : placeX(0), placeY(0), placeW(0), placeH(0), width(0), offsetX(0),
          offsetY(0) {}
  };

public:
  Atlas(std::string file, std::string descriptionFile);
  virtual ~Atlas() {}

  virtual int initialize();

  unsigned char *getImage();
  unsigned char *getDescription();

  int getWidth();
  int getHeight();
  int getComponents();

  std::string getFamily();
  int getFontHeight();
  std::string getStyle();
  int getSize();
  Char getChar(char c);

protected:
  std::string file_;
  std::string descriptionFile_;

  unsigned char *image_;
  unsigned char *description_;

  int width_;
  int height_;
  int components_;

  std::string family_;
  int fontHeight_;
  std::string style_;
  int size_;
  std::map<char, Char> charMap_;

private:
  void loadImage();
  void loadDescription();
}; // Atlas

} // graphics
} // dioptre

#endif // DIOPTRE_GRAPHICS_ATLAS_H_
