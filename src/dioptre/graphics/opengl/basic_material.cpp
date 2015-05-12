#include "dioptre/graphics/opengl/basic_material.h"
#include <glm/gtc/type_ptr.hpp>
#include "dioptre/graphics/opengl/shader.h"

namespace dioptre {
namespace graphics {
namespace opengl {

void BasicMaterial::initialize() {
  // Use material
  dioptre::graphics::opengl::Shader shader;
	programId_ = shader.loadFromFile("simple.vert", "simple.frag");
}

void BasicMaterial::update() {
  glUseProgram(programId_);
  GLint diffuseLocation = glGetUniformLocation(programId_, "diffuse");
  glUniform3fv(diffuseLocation, 1, glm::value_ptr(color_));
}

} // opengl
} // graphics
} // dioptre
