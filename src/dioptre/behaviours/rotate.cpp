#include "dioptre/behaviours/rotate.h"
#include "dioptre/object.h"

namespace dioptre {
namespace behaviours {

void Rotate::update() {
  auto object = getObject();
  auto transform = object->getTransform();
  transform->rotateX(0.01f);
  transform->rotateY(0.02f);
}

} // behaviours
} // dioptre
