#include "dioptre/graphics/text_geometry.h"

namespace dioptre {
namespace graphics {

TextGeometry::TextGeometry(std::string text, glm::vec2 position) :
  text_(text),
  position_(position)
{
}

} // graphics
} // dioptre
