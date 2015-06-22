#include <dioptre/graphics/texture.h>
#include "map.h"
#include "dioptre/graphics/opengl/basic_material.h"
#include "dioptre/graphics/opengl/box_geometry.h"

namespace objects {

Map* Map::spawn() {
  auto material = new dioptre::graphics::opengl::BasicMaterial();
//  material->setColor(dioptre::graphics::color(0.761f, 0.698f, 0.502f));
  dioptre::graphics::Texture* texture = new dioptre::graphics::Texture("");
  material->setTexture(texture);

  auto geometry = new dioptre::graphics::opengl::BoxGeometry(200.0f,1.0f,200.0f);

  // Extract this into level loading once levels are available
  Map* map = new Map();

  // Graphics Component
  dioptre::graphics::Mesh* mesh = new dioptre::graphics::Mesh(geometry, material);
  dioptre::graphics::Component* visual = new dioptre::graphics::Component(mesh);
  map->addComponent(visual);

  return map;
}

} // objects