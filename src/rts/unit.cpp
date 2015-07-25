#include "rts/unit.h"

#include "dioptre/graphics/component.h"
#include "dioptre/graphics/opengl/basic_material.h"
#include "dioptre/graphics/opengl/box_geometry.h"

#include "dioptre/physics/component.h"
#include "dioptre/physics/bullet/box_shape.h"

namespace rts {

Unit* Unit::spawn() {
  auto unit = new Unit();
  unit->getTransform()->translateY(3.5);

  auto building = new dioptre::graphics::opengl::BasicMaterial();
  building->setColor(dioptre::graphics::color(0.7f, 0.7f, 0.7f));
  auto geometry = new dioptre::graphics::opengl::BoxGeometry(2.0f, 5.0f, 2.0f);
  auto mesh = new dioptre::graphics::Mesh(geometry, building);
  auto visual = new dioptre::graphics::Component(mesh);
  unit->addComponent(visual);

  auto shape = new dioptre::physics::bullet::BoxShape(1.0f, 2.5f, 1.0f);
  auto rigidBody = new dioptre::physics::RigidBody(shape);
  auto physics = new dioptre::physics::Component(rigidBody);
  unit->addComponent(physics);

  return unit;
}

} // rts
