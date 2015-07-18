#include "unit.h"
#include "dioptre/graphics/opengl/basic_material.h"
#include "dioptre/graphics/opengl/box_geometry.h"
#include "dioptre/physics/component.h"
#include "dioptre/physics/bullet/box_shape.h"

namespace objects {

Unit* Unit::spawn() {
  auto unit = new Unit();

  auto building = new dioptre::graphics::opengl::BasicMaterial();
  building->setColor(dioptre::graphics::color(0.7f, 0.7f, 0.7f));
  auto geometry = new dioptre::graphics::opengl::BoxGeometry(2.0f, 5.0f, 2.0f);
  auto mesh = new dioptre::graphics::Mesh(geometry, building);
  mesh->getTransform()->translateY(3.5);
  auto visual = new dioptre::graphics::Component(mesh);
  unit->addComponent(visual);

  /* auto shape = new dioptre::physics::bullet::BoxShape(1.0f, 2.5f, 1.0f); */
  /* auto rigidBody = new dioptre::physics::RigidBody(shape); */
  /* rigidBody->translateY(3.5); */
  /* auto physics = new dioptre::physics::Component(rigidBody); */
  /* unit->addComponent(physics); */

  return unit;
}

} // objects
