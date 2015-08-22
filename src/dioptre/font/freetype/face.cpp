#include "dioptre/font/freetype/font.h"
#include "dioptre/font/freetype/face.h"
#include "dioptre/locator.h"

#include <exception>
#include <stdexcept>

namespace dioptre {
namespace font {
namespace freetype {

Face::Face(std::string fontFile) :
  dioptre::font::Face(fontFile)
{
  auto font = dioptre::Locator::getInstance<dioptre::font::freetype::Font>(dioptre::Module::M_FONT);
  auto filesystem = dioptre::Locator::getInstance<dioptre::filesystem::FilesystemInterface>(dioptre::Module::M_FILESYSTEM);

  auto size = filesystem->getSize(fontFile);

  unsigned char* buffer = new unsigned char[size];
  auto read = filesystem->read(fontFile, buffer, size);

  if (FT_New_Memory_Face(font->getLibrary(), buffer, size, 0, &face_)) {
    std::string error("Unable to load font: ");
    error.append(fontFile);

    throw std::runtime_error(error);
  }

  glyphSlot_ = new GlyphSlot(face_->glyph);

  delete buffer;
}

int Face::loadChar(int i) {
  return FT_Load_Char(face_, i, FT_LOAD_RENDER);
}

void Face::setSize(int width, int height) {
  FT_Set_Pixel_Sizes(face_, width, height);
}

GlyphSlot* Face::getGlyphSlot() {
  return glyphSlot_;
}

Face::~Face() {
  FT_Done_Face(face_);
}

} // freetype
} // font
} // dioptre
