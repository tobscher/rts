#ifndef DIOPTRE_GRAPHICS_TEXT_GEOMETRY_H_
#define DIOPTRE_GRAPHICS_TEXT_GEOMETRY_H_

#include "geometry.h"

#include <string>

namespace dioptre {
namespace graphics {

class TextGeometry : public Geometry {
public:
  explicit TextGeometry(std::string text);
  virtual ~TextGeometry() {}

  virtual void setText(std::string text);

protected:
  std::string text_;

}; // TextGeometry

} // graphics
} // dioptre

#endif // DIOPTRE_GRAPHICS_TEXT_GEOMETRY_H_
