#include "rts/unit.h"
#include "rts/human_player.h"

#include "dioptre/application.h"
#include "dioptre/graphics/component.h"
#include "dioptre/graphics/opengl/basic_material.h"
#include "dioptre/graphics/opengl/box_geometry.h"

#include "dioptre/physics/component.h"
#include "dioptre/physics/bullet/box_shape.h"

namespace rts {

void Unit::handleClick(glm::vec3 hitPoint) {
  // Extract to selection class
  auto application = dioptre::Application::getInstance();
  auto humanPlayer = application->getObject<rts::HumanPlayer>();
  humanPlayer->clearSelection();
  humanPlayer->select(this);
}

Unit* Unit::spawn(Map* map) {
  auto unit = new Unit();
  unit->getTransform()->translateY(3.5);

  auto building = new dioptre::graphics::opengl::BasicMaterial();
  building->setColor(dioptre::graphics::color(0.7f, 0.7f, 0.7f));
  auto geometry = new dioptre::graphics::opengl::BoxGeometry(2.0f, 5.0f, 2.0f);

  // Mesh
  auto mesh = new dioptre::graphics::Mesh(geometry, building);

  // Projector
  auto projector = new dioptre::graphics::Projector(40.0, 1.0, 1, 100);
  projector->getTransform()->setPosition(0.0, 5.0, 0.0);
  projector->getTransform()->setUp(glm::vec3(0.0, 0.0, -1.0));
  projector->getTransform()->lookAt(unit->getTransform()->getPosition());
  projector->setTarget(map->getComponent<dioptre::graphics::Component>()->getMesh());

  auto visual = new dioptre::graphics::Component(mesh);
  visual->setProjector(projector);
  unit->addComponent(visual);

  auto shape = new dioptre::physics::bullet::BoxShape(1.0f, 2.5f, 1.0f);
  auto rigidBody = new dioptre::physics::RigidBody(shape);
  auto physics = new dioptre::physics::Component(rigidBody);
  unit->addComponent(physics);

  return unit;
}

} // rts
