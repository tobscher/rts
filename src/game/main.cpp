#include <memory>

#include "dioptre/application.h"
#include "objects/map.h"
#include "objects/command_centre.h"
#include "objects/human_player.h"

int main(int argc, char *argv[]) {
  dioptre::Application application(argc, argv);
  application.initialize();

  objects::Map* map(objects::Map::spawn());
  objects::CommandCentre* commandCentre(objects::CommandCentre::spawn());
  objects::HumanPlayer* humanPlayer(objects::HumanPlayer::spawn());

  application.addObject(map);
  application.addObject(commandCentre);
  application.addObject(humanPlayer);

  application.run();

  return 0;
}
