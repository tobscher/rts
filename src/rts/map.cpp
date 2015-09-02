#include "rts/map.h"

#include "dioptre/graphics/component.h"
#include "dioptre/graphics/opengl/texture_factory.h"
#include "dioptre/graphics/opengl/map_material.h"
#include "dioptre/graphics/opengl/box_geometry.h"

#include "dioptre/physics/component.h"
#include "dioptre/physics/bullet/box_shape.h"

#include <iostream>

namespace rts {

Map* Map::spawn() {
  auto material = new dioptre::graphics::opengl::MapMaterial();
  material->setColor(dioptre::graphics::color(0.51, 0.65, 0.22));
  /* dioptre::graphics::opengl::Texture* texture = dioptre::graphics::opengl::TextureFactory::getTexture("ground.dds"); */
  /* texture->setRepeat(glm::vec2(15,15)); */
  /* material->setTexture(texture); */

  auto width = 128.0 * cellSize;
  auto height = 128.0 * cellSize;

  auto geometry = new dioptre::graphics::opengl::BoxGeometry(width,1.0f,height);

  // Extract this into level loading once levels are available
  Map* map = new Map();

  // Graphics Component
  auto mesh = new dioptre::graphics::Mesh(geometry, material);
  auto visual = new dioptre::graphics::Component(mesh);
  map->addComponent(visual);

  auto shape = new dioptre::physics::bullet::BoxShape(width/2.0, 0.5f, height/2.0);
  auto rigidBody = new dioptre::physics::RigidBody(shape);
  auto physics = new dioptre::physics::Component(rigidBody);
  map->addComponent(physics);

  return map;
}

} // rts
