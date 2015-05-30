#include "dioptre/behaviours/rotate.h"
#include "dioptre/object.h"

namespace dioptre {
namespace behaviours {

void Rotate::update() {
  auto object = getObject();
  auto graphicsComponent = object->getComponent<dioptre::graphics::Component>();
  graphicsComponent->rotateX(0.01f);
  graphicsComponent->rotateY(0.02f);
}

}
}
