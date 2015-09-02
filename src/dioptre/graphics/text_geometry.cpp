#include "dioptre/graphics/text_geometry.h"

namespace dioptre {
namespace graphics {

TextGeometry::TextGeometry(std::string text) :
  text_(text)
{
}

void TextGeometry::setText(std::string text) {
  text_ = text;
}

} // graphics
} // dioptre
