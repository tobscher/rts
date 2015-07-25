#include "dioptre/locator.h"

#include "rts/human_player.h"
#include "rts/components/edge_scroll_component.h"

#include <algorithm>

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
  auto camera = graphicsService->getCamera();

  camera->makeCurrent();
}

std::vector<dioptre::Object*> HumanPlayer::getSelectedObjects() {
  return selectedObjects_;
}

void HumanPlayer::select(dioptre::Object* object) {
  if (std::find(selectedObjects_.begin(), selectedObjects_.end(), object) != selectedObjects_.end()) {
    return;
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

} // rts
