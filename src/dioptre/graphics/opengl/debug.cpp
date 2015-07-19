#include "dioptre/graphics/opengl/debug.h"
#include "dioptre/graphics/opengl/debug_material.h"
#include "dioptre/graphics/opengl/geometry.h"

namespace dioptre {
namespace graphics {
namespace opengl {

int Debug::initialize() {
  material_ = new dioptre::graphics::opengl::DebugMaterial();
  material_->setColor(dioptre::graphics::color(1.0f, 0.0f, 0.0f));

  lines_ = new dioptre::graphics::opengl::Geometry(GL_LINES);
  auto mesh = new dioptre::graphics::Mesh(lines_, material_);
  scene_->add(mesh);

  crosses_ = new dioptre::graphics::opengl::Geometry(GL_LINES);
  auto crossMesh = new dioptre::graphics::Mesh(crosses_, material_);
  scene_->add(crossMesh);

  return 0;
}

} // opengl
} // graphics
} // dioptre
