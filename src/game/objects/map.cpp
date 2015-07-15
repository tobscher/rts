#include "map.h"

#include "dioptre/graphics/opengl/texture.h"
#include "dioptre/graphics/opengl/basic_material.h"
#include "dioptre/graphics/opengl/box_geometry.h"

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
  dioptre::graphics::Mesh* mesh = new dioptre::graphics::Mesh(geometry, material);
  dioptre::graphics::Component* visual = new dioptre::graphics::Component(mesh);
  map->addComponent(visual);

  return map;
}

} // objects
