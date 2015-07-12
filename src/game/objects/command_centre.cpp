#include "command_centre.h"
#include "dioptre/graphics/opengl/basic_material.h"
#include "dioptre/graphics/opengl/box_geometry.h"

namespace objects {

CommandCentre* CommandCentre::spawn() {
  auto commandCentre = new CommandCentre();

  auto building = new dioptre::graphics::opengl::BasicMaterial();
  building->setColor(dioptre::graphics::color(0.5f, 0.5f, 0.5f));
  auto geometry = new dioptre::graphics::opengl::BoxGeometry(5.0f, 5.0f, 5.0f);
  auto mesh = new dioptre::graphics::Mesh(geometry, building);
  mesh->getTransform()->translateY(3.5);
  auto visual = new dioptre::graphics::Component(mesh);
  commandCentre->addComponent(visual);

  return commandCentre;
}

} // objects
