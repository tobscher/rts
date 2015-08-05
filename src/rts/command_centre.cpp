#include "rts/command_centre.h"
#include "rts/human_player.h"

#include "dioptre/application.h"
#include "dioptre/graphics/component.h"
#include "dioptre/graphics/projector.h"
#include "dioptre/graphics/opengl/basic_material.h"
#include "dioptre/graphics/opengl/box_geometry.h"
#include "dioptre/graphics/opengl/texture_factory.h"

#include "dioptre/physics/component.h"
#include "dioptre/physics/bullet/box_shape.h"

#include <iostream>

namespace rts {

void CommandCentre::handleClick(glm::vec3 hitPoint) {
  // Extract to selection class
  auto application = dioptre::Application::getInstance();
  auto humanPlayer = application->getObject<rts::HumanPlayer>();
  humanPlayer->clearSelection();
  humanPlayer->select(this);
}

CommandCentre* CommandCentre::spawn(Map* map) {
  auto commandCentre = new CommandCentre();
  commandCentre->getTransform()->translateY(0.5);

  // Material
  auto material = new dioptre::graphics::opengl::BasicMaterial();
  material->setColor(dioptre::graphics::color(0.3f, 0.3f, 0.3f));

  // Geometry
  auto geometry = new dioptre::graphics::opengl::BoxGeometry(5.0f * cellSize, 1.0f, 5.0f * cellSize);

  // Mesh
  auto mesh = new dioptre::graphics::Mesh(geometry, material);

  // Projector
  auto projector = new dioptre::graphics::Projector(40.0, 1.0, 1, 100);
  projector->getTransform()->setPosition(0.0, 12.0, 0.0);
  projector->getTransform()->setUp(glm::vec3(0.0, 0.0, -1.0));
  projector->getTransform()->lookAt(commandCentre->getTransform()->getPosition());
  projector->setTarget(map->getComponent<dioptre::graphics::Component>()->getMesh());

  auto visual = new dioptre::graphics::Component(mesh);
  visual->setProjector(projector);
  commandCentre->addComponent(visual);

  auto shape = new dioptre::physics::bullet::BoxShape(2.5f * cellSize, 0.5f, 2.5f * cellSize);
  auto rigidBody = new dioptre::physics::RigidBody(shape);
  auto physics = new dioptre::physics::Component(rigidBody);
  commandCentre->addComponent(physics);

  return commandCentre;
}

} // rts
