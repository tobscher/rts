#include "dioptre/graphics/opengl/basic_material.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "dioptre/graphics/opengl/shader.h"

#include <iostream>

namespace dioptre {
namespace graphics {
namespace opengl {

void BasicMaterial::initialize() {
  // Use material
  dioptre::graphics::opengl::Shader shader;
	programId_ = shader.loadFromFile("basic.vert", "basic.frag");
}

void BasicMaterial::update() {
  glUseProgram(programId_);

  GLint diffuseLocation = glGetUniformLocation(programId_, "diffuse");
  glUniform3fv(diffuseLocation, 1, glm::value_ptr(color_));
}

void BasicMaterial::setMVP(glm::mat4 mvp) {
  GLuint matrixId = glGetUniformLocation(programId_, "MVP");
  glUniformMatrix4fv(matrixId, 1, GL_FALSE, &mvp[0][0]);
}

void BasicMaterial::destroy() {
  glDeleteProgram(programId_);
}

} // opengl
} // graphics
} // dioptre
