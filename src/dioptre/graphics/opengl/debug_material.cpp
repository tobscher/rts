#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "dioptre/graphics/opengl/debug_material.h"
#include "dioptre/graphics/opengl/shader_factory.h"
#include "dioptre/graphics/opengl/error.h"

namespace dioptre {
namespace graphics {
namespace opengl {

void DebugMaterial::initialize() {
  ShaderFeatures features(FeatureColor);

  // Use material
  dioptre::graphics::opengl::Shader* shader = dioptre::graphics::opengl::ShaderFactory::getShader(features, "debug.vert", "debug.frag");
	programId_ = shader->getProgram();

  // check OpenGL error
  check_gl_error();
}

void DebugMaterial::update() {
  glUseProgram(programId_);

  GLint diffuseLocation = glGetUniformLocation(programId_, "diffuse");
  glUniform3fv(diffuseLocation, 1, glm::value_ptr(color_));

  // check OpenGL error
  check_gl_error();
}

void DebugMaterial::setMVP(glm::mat4 m, glm::mat4 v, glm::mat4 mvp) {
  GLuint matrixId = glGetUniformLocation(programId_, "MVP");
  glUniformMatrix4fv(matrixId, 1, GL_FALSE, &mvp[0][0]);
}

void DebugMaterial::destroy() {
}

} // opengl
} // graphics
} // dioptre
