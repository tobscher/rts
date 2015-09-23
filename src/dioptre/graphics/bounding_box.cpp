#include "dioptre/graphics/bounding_box.h"

namespace dioptre {
namespace graphics {

BoundingBox::BoundingBox(glm::vec3 min, glm::vec3 max) : min_(min), max_(max) {}

glm::vec3 BoundingBox::getMin() { return min_; }

glm::vec3 BoundingBox::getMax() { return max_; }

} // graphics
} // dioptre
