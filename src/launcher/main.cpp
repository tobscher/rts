#include "dioptre/application.h"

#include "rts/map.h"
#include "rts/command_centre.h"
#include "rts/unit.h"
#include "rts/human_player.h"

int main(int argc, char *argv[]) {
  dioptre::Application application(argc, argv);
  application.initialize();

  rts::Map* map(rts::Map::spawn());
  rts::CommandCentre* commandCentre(rts::CommandCentre::spawn());
  rts::HumanPlayer* humanPlayer(rts::HumanPlayer::spawn());

  application.addObject(map);
  application.addObject(commandCentre);
  application.addObject(humanPlayer);

  // Add some units
  for (int i = 0; i < 5; i++) {
    rts::Unit* unit(rts::Unit::spawn());
    auto transform = unit->getTransform();

    transform->translateX(-10 + (i * 5));
    transform->translateZ(10);

    application.addObject(unit);
  }

  application.run();

  return 0;
}
