#ifndef DIOPTRE_GRAPHICS_TEXT_GEOMETRY_H_
#define DIOPTRE_GRAPHICS_TEXT_GEOMETRY_H_

#include "geometry.h"

namespace dioptre {
namespace graphics {

class TextGeometry : public Geometry {
public:
  TextGeometry(std::string text, glm::vec2 position);
  virtual ~TextGeometry() {}

protected:
  std::string text_;
  glm::vec2 position_;

}; // TextGeometry

} // graphics
} // dioptre

#endif // DIOPTRE_GRAPHICS_TEXT_GEOMETRY_H_
