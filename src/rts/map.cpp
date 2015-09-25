#include "rts/map.h"
#include "rts/human_player.h"

#include "dioptre/application.h"
#include "dioptre/graphics/component.h"
#include "dioptre/graphics/opengl/texture_factory.h"
#include "dioptre/graphics/opengl/map_material.h"
#include "dioptre/graphics/opengl/box_geometry.h"

#include "dioptre/physics/component.h"
#include "dioptre/physics/bullet/box_shape.h"

#include "dioptre/ai/recast/navigation_mesh.h"
#include "dioptre/ai/detour/navigation_mesh.h"

#include <iostream>

namespace rts {

void Map::handleClick(glm::vec3 hitPoint) {
  auto application = dioptre::Application::getInstance();
  auto humanPlayer = application->getObject<rts::HumanPlayer>();
  auto selected = humanPlayer->getSelectedObjects();

  for (auto it = selected.begin(); it != selected.end(); it++) {
    /* if ((*it)->haAbility(A_MOVE)) { */
    /*   auto moveAbility = (*it)->getAbility<rts::Abilities::Move>(); */
    /*   moveAbility->Move(from, hitPoint); */
    /* } */
  }
}

Map *Map::spawn() {
  auto width = 128.0 * cellSize;
  auto height = 128.0 * cellSize;

  auto material = new dioptre::graphics::opengl::MapMaterial();
  material->setColor(dioptre::graphics::color(0.51, 0.65, 0.22));
  dioptre::graphics::opengl::Texture *texture =
      dioptre::graphics::opengl::TextureFactory::getTexture("grid-4x4.png");
  texture->setRepeat(glm::vec2(width / 4.0, height / 4.0));
  material->setTexture(texture);

  auto geometry =
      new dioptre::graphics::opengl::BoxGeometry(width, 1.0f, height);

  auto navMesh = new dioptre::ai::recast::NavigationMesh(geometry);
  navMesh->build();
  auto navMeshQuery = new dioptre::ai::detour::NavigationMesh(navMesh);
  navMeshQuery->build();
  navMeshQuery->find();

  // Extract this into level loading once levels are available
  Map *map = new Map();

  // Graphics Component
  auto mesh = new dioptre::graphics::Mesh(geometry, material);
  auto visual = new dioptre::graphics::Component(mesh);
  map->addComponent(visual);

  auto shape =
      new dioptre::physics::bullet::BoxShape(width / 2.0, 0.5f, height / 2.0);
  auto rigidBody = new dioptre::physics::RigidBody(shape);
  auto physics = new dioptre::physics::Component(rigidBody);
  map->addComponent(physics);

  return map;
}

} // rts
