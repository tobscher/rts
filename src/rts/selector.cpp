#include "rts/selector.h"
#include "rts/human_player.h"

#include "dioptre/application.h"

namespace rts {

Selector::Selector(dioptre::Object* object) :
  object_(object) {

}

void Selector::select() {
  auto application = dioptre::Application::getInstance();
  auto humanPlayer = application->getObject<rts::HumanPlayer>();
  humanPlayer->clearSelection();
  humanPlayer->select(object_);
}

void Selector::setTarget(dioptre::Object* target, float size) {
  auto projector = new dioptre::graphics::Projector(40.0, 1.0, 1, 100);
  projector->getTransform()->setPosition(0.0, size, 0.0);
  projector->getTransform()->setUp(glm::vec3(0.0, 0.0, -1.0));
  projector->getTransform()->lookAt(object_->getTransform()->getPosition());
  projector->setTarget(target->getComponent<dioptre::graphics::Component>()->getMesh());

  object_->getComponent<dioptre::graphics::Component>()->setProjector(projector);
}

} // rts
