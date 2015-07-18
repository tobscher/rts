#include "map.h"

#include "dioptre/graphics/component.h"
#include "dioptre/graphics/opengl/texture.h"
#include "dioptre/graphics/opengl/basic_material.h"
#include "dioptre/graphics/opengl/box_geometry.h"

#include "dioptre/physics/component.h"
#include "dioptre/physics/bullet/box_shape.h"

namespace objects {

Map* Map::spawn() {
  auto material = new dioptre::graphics::opengl::BasicMaterial();
  dioptre::graphics::opengl::Texture* texture = new dioptre::graphics::opengl::Texture("ground.dds");
  texture->setRepeat(glm::vec2(15,15));
  material->setTexture(texture);

  auto geometry = new dioptre::graphics::opengl::BoxGeometry(256.0f,1.0f,256.0f);

  // Extract this into level loading once levels are available
  Map* map = new Map();

  // Graphics Component
  auto mesh = new dioptre::graphics::Mesh(geometry, material);
  auto visual = new dioptre::graphics::Component(mesh);
  map->addComponent(visual);

  auto shape = new dioptre::physics::bullet::BoxShape(128.0f, 0.5f, 128.0f);
  auto rigidBody = new dioptre::physics::RigidBody(shape);
  auto physics = new dioptre::physics::Component(rigidBody);
  map->addComponent(physics);

  return map;
}

} // objects
