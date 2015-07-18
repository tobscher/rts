#include "dioptre/graphics/line_geometry.h"

namespace dioptre {
namespace graphics {

LineGeometry::LineGeometry(glm::vec3 from, glm::vec3 to) :
  from_(from),
  to_(to)
{
  vertices_.push_back(from);
  vertices_.push_back(to);
}

} // graphics
} // dioptre
