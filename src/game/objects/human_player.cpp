#include "dioptre/locator.h"

#include "human_player.h"
#include "components/edge_scroll_component.h"

namespace objects {

HumanPlayer* HumanPlayer::spawn() {
  HumanPlayer* humanPlayer = new HumanPlayer();

  auto edgeScrollComponent = new components::EdgeScrollComponent();
  humanPlayer->addComponent(edgeScrollComponent);

  return humanPlayer;
}

void HumanPlayer::makeCurrent() {
  Object::makeCurrent();

  auto graphicsService = dioptre::Locator::getInstance<dioptre::graphics::GraphicsInterface>(dioptre::Module::M_GRAPHICS);
  auto camera = graphicsService->getCamera();

  camera->makeCurrent();
}

} // objects
