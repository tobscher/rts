#include "rts/unit.h"

#include "dioptre/application.h"
#include "dioptre/graphics/component.h"
#include "dioptre/graphics/opengl/basic_material.h"
#include "dioptre/graphics/opengl/box_geometry.h"

#include "dioptre/physics/component.h"
#include "dioptre/physics/bullet/box_shape.h"
#include "dioptre/physics/bullet/rigid_body.h"

#include "rts/abilities/move.h"

namespace rts {

Unit::Unit() : rts::GameObject("objects.unit") {
  selector_ = std::unique_ptr<rts::Selector>(new rts::Selector(this));
  addAbility(A_MOVE, new rts::abilities::Move(this));
}

void Unit::handleClick(glm::vec3 hitPoint) { selector_->select(); }

Selector *Unit::getSelector() { return selector_.get(); }

Unit *Unit::spawn(Map *map) {
  auto unit = new Unit();
  unit->getTransform()->translateY(1.0);

  auto building = new dioptre::graphics::opengl::BasicMaterial();
  building->setColor(dioptre::graphics::color(0.7f, 0.7f, 0.7f));
  auto geometry = new dioptre::graphics::opengl::BoxGeometry(
      1.0f * cellSize, 2.0f, 1.0f * cellSize);

  // Mesh
  auto mesh = new dioptre::graphics::Mesh(geometry, building);

  // Visual component
  auto visual = new dioptre::graphics::Component(mesh);
  unit->addComponent(visual);

  // Selector
  unit->getSelector()->setTarget(map, 3.0);

  auto shape = new dioptre::physics::bullet::BoxShape(0.5f * cellSize, 1.0f,
                                                      0.5f * cellSize);
  auto rigidBody =
      new dioptre::physics::bullet::RigidBody(shape, unit->getTransform());
  auto physics = new dioptre::physics::Component(rigidBody);
  unit->addComponent(physics);

  unit->initialize();

  return unit;
}

} // rts
