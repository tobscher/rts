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
  ShaderFeatures features(FeatureNone);

  if (texture_ == nullptr) {
    features = features | FeatureColor;
  } else {
    features = features | FeatureTexture;
  }

  // Use material
  dioptre::graphics::opengl::Shader shader(features);
	programId_ = shader.loadFromFile("basic.vert", "basic.frag");

  if (texture_ != nullptr) {
    std::cout << "Initializing texture..." << std::endl;
    glTexture_ = (Texture*)texture_;
    glTexture_->initialize();
  }
}

void BasicMaterial::update() {
  glUseProgram(programId_);

  if (texture_ == nullptr) {
    GLint diffuseLocation = glGetUniformLocation(programId_, "diffuse");
    glUniform3fv(diffuseLocation, 1, glm::value_ptr(color_));
  } else {
    glTexture_->updateGL(programId_);
  }

  glm::vec3 lightPosition(0.0, 100.0, 0.0);
  GLuint lightPositionId = glGetUniformLocation(programId_, "LightPosition_worldspace");
  glUniform3fv(lightPositionId, 1, glm::value_ptr(lightPosition));
}

void BasicMaterial::setMVP(glm::mat4 m, glm::mat4 v, glm::mat4 mvp) {
  GLuint mId = glGetUniformLocation(programId_, "M");
  glUniformMatrix4fv(mId, 1, GL_FALSE, &m[0][0]);

  GLuint vId = glGetUniformLocation(programId_, "V");
  glUniformMatrix4fv(vId, 1, GL_FALSE, &v[0][0]);

  GLuint matrixId = glGetUniformLocation(programId_, "MVP");
  glUniformMatrix4fv(matrixId, 1, GL_FALSE, &mvp[0][0]);
}

void BasicMaterial::destroy() {
  glDeleteProgram(programId_);
}

} // opengl
} // graphics
} // dioptre
