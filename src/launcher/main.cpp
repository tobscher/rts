#include "dioptre/application.h"
#include "dioptre/graphics/component.h"

#include "rts/map.h"
#include "rts/command_centre.h"
#include "rts/unit.h"
#include "rts/human_player.h"

int main(int argc, char *argv[]) {
  dioptre::Application application(argc, argv);
  application.initialize();

  rts::Map* map(rts::Map::spawn());
  rts::CommandCentre* commandCentre(rts::CommandCentre::spawn(map));
  rts::HumanPlayer* humanPlayer(rts::HumanPlayer::spawn());

  application.addObject(map);
  application.addObject(commandCentre);
  application.addObject(humanPlayer);

  // Add some units
  for (int i = 0; i < 5; i++) {
    rts::Unit* unit(rts::Unit::spawn(map));
    auto transform = unit->getTransform();
    auto graphicsComponent = unit->getComponent<dioptre::graphics::Component>();

    transform->translateX(-30 + (i * 15));
    transform->translateZ(10);

    graphicsComponent->getProjector()->getTransform()->translateX(-30 + (i * 15));
    graphicsComponent->getProjector()->getTransform()->translateZ(10);

    application.addObject(unit);
  }

  application.run();

  return 0;
}
