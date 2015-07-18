#include "dioptre/graphics/opengl/debug.h"
#include "dioptre/graphics/opengl/debug_material.h"
#include "dioptre/graphics/opengl/geometry.h"

namespace dioptre {
namespace graphics {
namespace opengl {

int Debug::initialize() {
  material_ = new dioptre::graphics::opengl::DebugMaterial();
  material_->setColor(dioptre::graphics::color(1.0f, 0.0f, 0.0f));

  geometry_ = new dioptre::graphics::opengl::Geometry(GL_LINES);

  auto mesh = new dioptre::graphics::Mesh(geometry_, material_);
  scene_->add(mesh);

  return 0;
}

} // opengl
} // graphics
} // dioptre
