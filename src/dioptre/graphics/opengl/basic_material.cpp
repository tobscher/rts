#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "dioptre/graphics/opengl/basic_material.h"
#include "dioptre/graphics/opengl/shader_factory.h"
#include "dioptre/graphics/opengl/texture_factory.h"
#include "dioptre/graphics/opengl/error.h"

namespace dioptre {
namespace graphics {
namespace opengl {

BasicMaterial::BasicMaterial() :
  dioptre::graphics::BasicMaterial(),
  diffuseLocation_(-1),
  lightPositionLocation_(-1),
  matrixLocation_(-1),
  viewLocation_(-1),
  matrixViewProjectionLocation_(-1) {

}

void BasicMaterial::initialize() {
  ShaderFeatures features(FeatureNone);

  if (texture_ == nullptr) {
    features = features | FeatureColor;
  } else {
    features = features | FeatureTexture;
  }

  // Use material
  dioptre::graphics::opengl::Shader* shader = dioptre::graphics::opengl::ShaderFactory::getShader(features, "basic.vert", "basic.frag");
	programId_ = shader->getProgram();

  if (texture_ != nullptr) {
    glTexture_ = (Texture*)texture_;
    glTexture_->initialize();
  }

  // check OpenGL error
  check_gl_error();
}

void BasicMaterial::update() {
  glUseProgram(programId_);

  if (texture_ == nullptr) {
    if (diffuseLocation_ == -1) {
      diffuseLocation_ = glGetUniformLocation(programId_, "diffuse");
    }
    glUniform3fv(diffuseLocation_, 1, glm::value_ptr(color_));
  } else {
    glTexture_->updateGL(programId_, "textureSampler", true);
  }

  glm::vec3 lightPosition(0.0, 100.0, 0.0);

  if (lightPositionLocation_ == -1) {
    lightPositionLocation_ = glGetUniformLocation(programId_, "LightPosition_worldspace");
  }
  glUniform3fv(lightPositionLocation_, 1, glm::value_ptr(lightPosition));

  // check OpenGL error
  check_gl_error();
}

void BasicMaterial::setMVP(glm::mat4 m, glm::mat4 v, glm::mat4 mvp) {
  if (matrixLocation_ == -1) {
    matrixLocation_ = glGetUniformLocation(programId_, "M");
  }
  glUniformMatrix4fv(matrixLocation_, 1, GL_FALSE, &m[0][0]);

  if (viewLocation_ == -1) {
    viewLocation_ = glGetUniformLocation(programId_, "V");
  }
  glUniformMatrix4fv(viewLocation_, 1, GL_FALSE, &v[0][0]);

  if (matrixViewProjectionLocation_ == -1) {
    matrixViewProjectionLocation_ = glGetUniformLocation(programId_, "MVP");
  }
  glUniformMatrix4fv(matrixViewProjectionLocation_, 1, GL_FALSE, &mvp[0][0]);
}

void BasicMaterial::destroy() {
  if (texture_ != nullptr) {
    texture_->destroy();
  }
}

} // opengl
} // graphics
} // dioptre
