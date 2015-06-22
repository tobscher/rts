#include "command_centre.h"
#include "dioptre/graphics/opengl/basic_material.h"
#include "dioptre/graphics/opengl/box_geometry.h"

namespace objects {

CommandCentre* CommandCentre::spawn() {
  auto building = new dioptre::graphics::opengl::BasicMaterial();
  building->setColor(dioptre::graphics::color(0.5f, 0.5f, 0.5f));

  auto geometry = new dioptre::graphics::opengl::BoxGeometry(5.0f, 5.0f, 5.0f);

  CommandCentre* commandCentre = new CommandCentre();

  dioptre::graphics::Mesh* mesh = new dioptre::graphics::Mesh(geometry, building);
  dioptre::graphics::Component* visual = new dioptre::graphics::Component(mesh);
  commandCentre->addComponent(visual);

  return commandCentre;
}

} // objects