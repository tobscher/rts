#include "command_centre.h"

#include "dioptre/graphics/component.h"
#include "dioptre/graphics/opengl/basic_material.h"
#include "dioptre/graphics/opengl/box_geometry.h"

#include "dioptre/physics/component.h"
#include "dioptre/physics/bullet/box_shape.h"

namespace objects {

CommandCentre* CommandCentre::spawn() {
  auto commandCentre = new CommandCentre();
  commandCentre->getTransform()->translateY(3.5);

  // Material
  auto building = new dioptre::graphics::opengl::BasicMaterial();
  building->setColor(dioptre::graphics::color(0.5f, 0.5f, 0.5f));

  // Geometry
  auto geometry = new dioptre::graphics::opengl::BoxGeometry(5.0f, 5.0f, 5.0f);

  // Mesh
  auto mesh = new dioptre::graphics::Mesh(geometry, building);
  auto visual = new dioptre::graphics::Component(mesh);
  commandCentre->addComponent(visual);

  auto shape = new dioptre::physics::bullet::BoxShape(2.5f, 2.5f, 2.5f);
  auto rigidBody = new dioptre::physics::RigidBody(shape);
  auto physics = new dioptre::physics::Component(rigidBody);
  commandCentre->addComponent(physics);

  return commandCentre;
}

} // objects
