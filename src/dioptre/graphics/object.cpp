#include "dioptre/graphics/object.h"
#include "dioptre/math/id.h"

namespace dioptre {
namespace graphics {

Object::Object() :
    id_(dioptre::math::Id::next()),
    matrix_(glm::mat4x4()),
    position_(glm::vec3()),
    scale_(glm::vec3(1,1,1)) {
}

int Object::getId() {
  return id_;
}

} // graphics
} // dioptre
