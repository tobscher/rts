#include "dioptre/graphics/object.h"
#include "dioptre/math/id.h"

namespace dioptre {
namespace graphics {

Object::Object() :
    id_(dioptre::math::Id::next()) {
}

int Object::getId() {
  return id_;
}

Transform Object::getTransform() {
  return transform_;
}

} // graphics
} // dioptre
