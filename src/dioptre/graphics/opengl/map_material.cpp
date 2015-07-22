#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "dioptre/graphics/opengl/map_material.h"
#include "dioptre/graphics/opengl/shader_factory.h"
#include "dioptre/graphics/opengl/texture_factory.h"
#include "dioptre/graphics/opengl/error.h"

namespace dioptre {
namespace graphics {
namespace opengl {

MapMaterial::MapMaterial() :
  dioptre::graphics::MapMaterial(),
  lightPositionLocation_(-1),
  matrixLocation_(-1),
  viewLocation_(-1),
  matrixViewProjectionLocation_(-1),
  projectorMatrixLocation_(-1) {

}

void MapMaterial::initialize() {
  ShaderFeatures features(FeatureNone);

  // Use material
  dioptre::graphics::opengl::Shader* shader = dioptre::graphics::opengl::ShaderFactory::getShader(features, "map.vert", "map.frag");
	programId_ = shader->getProgram();

  if (texture_ != nullptr) {
    LOG4CXX_INFO(logger_, "Initializing texture...");
    glTexture_ = (Texture*)texture_;
    glTexture_->initialize();
  }

  projectedTexture_ = dioptre::graphics::opengl::TextureFactory::getTexture("selection.dds");
  projectedTexture_->setWrapS(GL_CLAMP_TO_BORDER);
  projectedTexture_->setWrapT(GL_CLAMP_TO_BORDER);
  projectedTexture_->initialize();

  // check OpenGL error
  check_gl_error();
}

void MapMaterial::update() {
  glUseProgram(programId_);

  if (texture_ != nullptr) {
    glTexture_->updateGL(programId_, "textureSampler", true);
  }

  projectedTexture_->updateGL(programId_, "ProjectorTex", false);

  glm::vec3 lightPosition(0.0, 100.0, 0.0);

  if (lightPositionLocation_ == -1) {
    lightPositionLocation_ = glGetUniformLocation(programId_, "LightPosition_worldspace");
  }
  glUniform3fv(lightPositionLocation_, 1, glm::value_ptr(lightPosition));

  // check OpenGL error
  check_gl_error();
}

void MapMaterial::setMVP(glm::mat4 m, glm::mat4 v, glm::mat4 mvp) {
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

void MapMaterial::setProjection(glm::mat4 p) {
  if (projectorMatrixLocation_ == -1) {
    projectorMatrixLocation_ = glGetUniformLocation(programId_, "ProjectorMatrix");
  }
  glUniformMatrix4fv(projectorMatrixLocation_, 1, GL_FALSE, &p[0][0]);
}

void MapMaterial::destroy() {
  if (texture_ != nullptr) {
    texture_->destroy();
  }
}

} // opengl
} // graphics
} // dioptre
