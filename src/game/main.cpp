#include <memory>

#include "dioptre/application.h"
#include "dioptre/object.h"
#include "dioptre/graphics/basic_material.h"
#include "dioptre/graphics/triangle_geometry.h"
#include "dioptre/graphics/component.h"
#include "dioptre/behaviours/rotate.h"

int main(int argc, char *argv[]) {
  dioptre::Application application(argc, argv);
  application.initialize();

  // Global material and geometry
  // Consider geometry and material factory to handle lifetime
  glm::vec3 a = {-1.0f, -1.0f, 0.0f};
  glm::vec3 b = {1.0f, -1.0f, 0.0f};
  glm::vec3 c = {0.0f, 1.0f, 0.0f};
  std::unique_ptr<dioptre::graphics::BasicMaterial> material(new dioptre::graphics::BasicMaterial());
  std::unique_ptr<dioptre::graphics::TriangleGeometry> geometry(new dioptre::graphics::TriangleGeometry(a, b, c));

  // Extract this into level loading once levels are available
  std::unique_ptr<dioptre::Object> cube(new dioptre::Object());

  // Graphics Component
  std::unique_ptr<dioptre::graphics::Mesh> cubeMesh(new dioptre::graphics::Mesh(geometry.get(), material.get()));
  std::unique_ptr<dioptre::graphics::Component> visual(new dioptre::graphics::Component(cubeMesh.get()));
  cube->addComponent(visual.get());

  // Rotator Component
  std::unique_ptr<dioptre::behaviours::Rotate> rotator(new dioptre::behaviours::Rotate());
  cube->addComponent(rotator.get());

  application.addObject(cube.get());

  application.run();

  return 0;
}
