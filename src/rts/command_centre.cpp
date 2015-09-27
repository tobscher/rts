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
#include "dioptre/physics/bullet/rigid_body.h"

namespace rts {

CommandCentre::CommandCentre() : rts::GameObject("objects.command_centre") {
  selector_ = std::unique_ptr<rts::Selector>(new rts::Selector(this));
}

void CommandCentre::handleClick(glm::vec3 hitPoint) { selector_->select(); }

Selector *CommandCentre::getSelector() { return selector_.get(); }

CommandCentre *CommandCentre::spawn(Map *map) {
  auto commandCentre = new CommandCentre();
  commandCentre->getTransform()->translateY(0.5);

  // Material
  auto material = new dioptre::graphics::opengl::BasicMaterial();
  material->setColor(dioptre::graphics::color(0.3f, 0.3f, 0.3f));

  // Geometry
  auto geometry = new dioptre::graphics::opengl::BoxGeometry(
      5.0f * cellSize, 1.0f, 5.0f * cellSize);

  // Mesh
  auto mesh = new dioptre::graphics::Mesh(geometry, material);

  // Visual component
  auto visual = new dioptre::graphics::Component(mesh);
  commandCentre->addComponent(visual);

  // Selector
  commandCentre->getSelector()->setTarget(map, 12.0);

  auto shape = new dioptre::physics::bullet::BoxShape(2.5f * cellSize, 0.5f,
                                                      2.5f * cellSize);
  auto rigidBody = new dioptre::physics::bullet::RigidBody(
      shape, commandCentre->getTransform());
  auto physics = new dioptre::physics::Component(rigidBody);
  commandCentre->addComponent(physics);

  return commandCentre;
}

} // rts
