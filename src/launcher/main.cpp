#include "dioptre/application.h"

#include "dioptre/graphics/opengl/graphics.h"
#include "dioptre/window/glfw/window.h"
#include "dioptre/keyboard/glfw/keyboard.h"
#include "dioptre/filesystem/physfs/filesystem.h"
#include "dioptre/mouse/glfw/mouse.h"
#include "dioptre/time/glfw/time.h"
#include "dioptre/physics/bullet/physics.h"

#include "dioptre/graphics/component.h"

#include "rts/map.h"
#include "rts/command_centre.h"
#include "rts/unit.h"
#include "rts/human_player.h"
#include "rts/text.h"

int main(int argc, char *argv[]) {
  auto window = new dioptre::window::glfw::Window();
  auto graphics = new dioptre::graphics::opengl::Graphics();
  auto keyboard = new dioptre::keyboard::glfw::Keyboard();
  auto filesystem = new dioptre::filesystem::physfs::Filesystem();
  auto mouse = new dioptre::mouse::glfw::Mouse();
  auto time = new dioptre::time::glfw::Time();
  auto physics = new dioptre::physics::bullet::Physics();

  dioptre::Application application(argc, argv, window, graphics, keyboard,
                                   filesystem, mouse, time, physics);
  application.initialize();

  rts::Map *map(rts::Map::spawn());
  rts::CommandCentre *commandCentre(rts::CommandCentre::spawn(map));
  rts::HumanPlayer *humanPlayer(rts::HumanPlayer::spawn());
  rts::Text *text(rts::Text::spawn());

  application.addObject(map);
  application.addObject(commandCentre);
  application.addObject(humanPlayer);
  application.addObject(text);

  // Add some units
  for (int i = 0; i < 5; i++) {
    rts::Unit *unit(rts::Unit::spawn(map));
    auto transform = unit->getTransform();
    transform->translate(glm::vec3(-10 + (i * 5), 0, 5));

    application.addObject(unit);
  }

  application.run();

  return 0;
}
