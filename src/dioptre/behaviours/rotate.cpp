#include "dioptre/behaviours/rotate.h"
#include "dioptre/object.h"

namespace dioptre {
namespace behaviours {

void Rotate::update() {
  auto object = getObject();
  auto graphicsComponent = object->getComponent<dioptre::graphics::Component>();
  graphicsComponent->rotateY(0.02f);
}

}
}
