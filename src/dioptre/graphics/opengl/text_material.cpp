#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "dioptre/graphics/opengl/text_material.h"
#include "dioptre/graphics/opengl/shader_factory.h"
#include "dioptre/graphics/opengl/error.h"

namespace dioptre {
namespace graphics {
namespace opengl {

TextMaterial::TextMaterial(dioptre::graphics::opengl::Atlas* atlas) :
  atlas_(atlas),
  diffuseLocation_(-1),
  matrixViewProjectionLocation_(-1) {

}

void TextMaterial::initialize() {
  ShaderFeatures features(FeatureColor);

  // Use material
  dioptre::graphics::opengl::Shader* shader = dioptre::graphics::opengl::ShaderFactory::getShader(features, "text.vert", "text.frag");
	programId_ = shader->getProgram();

  if (!atlas_->getIsInitialized()) {
    atlas_->initialize();
  }

  // check OpenGL error
  check_gl_error();
}

void TextMaterial::update() {
  glUseProgram(programId_);

  if (diffuseLocation_ == -1) {
    diffuseLocation_ = glGetUniformLocation(programId_, "diffuse");
  }
  glUniform3fv(diffuseLocation_, 1, glm::value_ptr(color_));

  atlas_->updateGL(programId_);
}

void TextMaterial::setMVP(glm::mat4 m, glm::mat4 v, glm::mat4 mvp) {
  /* if (matrixViewProjectionLocation_ == -1) { */
  /*   matrixViewProjectionLocation_ = glGetUniformLocation(programId_, "MVP"); */
  /* } */
  /* glUniformMatrix4fv(matrixViewProjectionLocation_, 1, GL_FALSE, &mvp[0][0]); */
}

void TextMaterial::destroy() {
}

} // opengl
} // graphics
} // dioptre
