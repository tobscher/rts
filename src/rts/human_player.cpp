#include "dioptre/application.h"
#include "dioptre/locator.h"
#include "dioptre/graphics/component.h"
#include "dioptre/graphics/text_geometry.h"

#include "rts/human_player.h"
#include "rts/text.h"
#include "rts/components/edge_scroll_component.h"

#include <algorithm>
#include <iostream>

namespace rts {

HumanPlayer *HumanPlayer::spawn() {
  HumanPlayer *humanPlayer = new HumanPlayer();

  auto edgeScrollComponent = new components::EdgeScrollComponent();
  humanPlayer->addComponent(edgeScrollComponent);

  return humanPlayer;
}

void HumanPlayer::makeCurrent() {
  dioptre::Object::makeCurrent();

  auto graphicsService =
      dioptre::Locator::getInstance<dioptre::graphics::GraphicsInterface>(
          dioptre::Module::M_GRAPHICS);
  auto layer = graphicsService->getLayer(0);
  auto camera = layer->getCamera();

  camera->makeCurrent();
}

std::vector<rts::GameObject *> HumanPlayer::getSelectedObjects() {
  return selectedObjects_;
}

void HumanPlayer::select(rts::GameObject *object) {
  if (std::find(selectedObjects_.begin(), selectedObjects_.end(), object) !=
      selectedObjects_.end()) {
    return;
  }

  auto graphicsService =
      dioptre::Locator::getInstance<dioptre::graphics::GraphicsInterface>(
          dioptre::Module::M_GRAPHICS);
  auto component = object->getComponent<dioptre::graphics::Component>();

  if (component) {
    auto projector = component->getProjector();
    graphicsService->setProjector(projector);
  }

  selectedObjects_.push_back(object);

  // TODO(Tobscher) Extract this
  auto application = dioptre::Application::getInstance();
  if (application == nullptr)
    return;

  auto text = application->getObject<rts::Text>();
  auto textComponent = text->getComponent<dioptre::graphics::Component>();
  auto mesh = textComponent->getMesh();
  auto geometry = (dioptre::graphics::TextGeometry *)mesh->getGeometry();
  geometry->setText(object->getName());
}

void HumanPlayer::unselect(rts::GameObject *object) {
  auto it = std::find(selectedObjects_.begin(), selectedObjects_.end(), object);
  if (it == selectedObjects_.end()) {
    return;
  }

  selectedObjects_.erase(it);
}

void HumanPlayer::clearSelection() { selectedObjects_.clear(); }

} // rts
