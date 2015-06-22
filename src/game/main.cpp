#include <memory>

#include "dioptre/application.h"
#include "objects/map.h"
#include "objects/command_centre.h"

int main(int argc, char *argv[]) {
  dioptre::Application application(argc, argv);
  application.initialize();

  std::unique_ptr<objects::Map> map(objects::Map::spawn());
  std::unique_ptr<objects::CommandCentre> commandCentre(objects::CommandCentre::spawn());
  application.addObject(map.get());
  application.addObject(commandCentre.get());

  application.run();

  return 0;
}
