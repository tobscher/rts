#include "dioptre/locator.h"
#include "dioptre/graphics/component.h"

#include "rts/human_player.h"
#include "rts/components/edge_scroll_component.h"

#include <algorithm>
#include <iostream>

namespace rts {

HumanPlayer* HumanPlayer::spawn() {
  HumanPlayer* humanPlayer = new HumanPlayer();

  auto edgeScrollComponent = new components::EdgeScrollComponent();
  humanPlayer->addComponent(edgeScrollComponent);

  return humanPlayer;
}

void HumanPlayer::makeCurrent() {
  dioptre::Object::makeCurrent();

  auto graphicsService = dioptre::Locator::getInstance<dioptre::graphics::GraphicsInterface>(dioptre::Module::M_GRAPHICS);
  auto layer = graphicsService->getLayer(0);
  auto camera = layer->getCamera();

  camera->makeCurrent();
}

std::vector<dioptre::Object*> HumanPlayer::getSelectedObjects() {
  return selectedObjects_;
}

void HumanPlayer::select(dioptre::Object* object) {
  if (std::find(selectedObjects_.begin(), selectedObjects_.end(), object) != selectedObjects_.end()) {
    return;
  }

  auto graphicsService = dioptre::Locator::getInstance<dioptre::graphics::GraphicsInterface>(dioptre::Module::M_GRAPHICS);
  auto component = object->getComponent<dioptre::graphics::Component>();

  if (component) {
    auto projector = component->getProjector();
    graphicsService->setProjector(projector);
  }

  selectedObjects_.push_back(object);
}

void HumanPlayer::unselect(dioptre::Object* object) {
  auto it = std::find(selectedObjects_.begin(), selectedObjects_.end(), object);
  if (it == selectedObjects_.end()) {
    return;
  }

  selectedObjects_.erase(it);
}

void HumanPlayer::clearSelection() {
  selectedObjects_.clear();
}

} // rts
