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
    LOG4CXX_INFO(logger_, "Initializing texture...");
    glTexture_ = (Texture*)texture_;
    glTexture_->initialize();
  }

  glTexture2_ = dioptre::graphics::opengl::TextureFactory::getTexture("selection.png");
  glTexture2_->setWrapS(GL_CLAMP_TO_BORDER);
  glTexture2_->setWrapT(GL_CLAMP_TO_BORDER);
  glTexture2_->initialize();

  // check OpenGL error
  check_gl_error();
}

void BasicMaterial::update() {
  glUseProgram(programId_);

  if (texture_ == nullptr) {
    GLint diffuseLocation = glGetUniformLocation(programId_, "diffuse");
    glUniform3fv(diffuseLocation, 1, glm::value_ptr(color_));
  } else {
    glTexture_->updateGL(programId_, "textureSampler", true);
  }

  glTexture2_->updateGL(programId_, "ProjectorTex", false);

  glm::vec3 lightPosition(0.0, 100.0, 0.0);
  GLuint lightPositionId = glGetUniformLocation(programId_, "LightPosition_worldspace");
  glUniform3fv(lightPositionId, 1, glm::value_ptr(lightPosition));

  // check OpenGL error
  check_gl_error();
}

void BasicMaterial::setMVP(glm::mat4 m, glm::mat4 v, glm::mat4 mvp) {
  GLuint mId = glGetUniformLocation(programId_, "M");
  glUniformMatrix4fv(mId, 1, GL_FALSE, &m[0][0]);

  GLuint vId = glGetUniformLocation(programId_, "V");
  glUniformMatrix4fv(vId, 1, GL_FALSE, &v[0][0]);

  GLuint matrixId = glGetUniformLocation(programId_, "MVP");
  glUniformMatrix4fv(matrixId, 1, GL_FALSE, &mvp[0][0]);
}

void BasicMaterial::setProjection(glm::mat4 p) {
  GLuint mId = glGetUniformLocation(programId_, "ProjectorMatrix");
  glUniformMatrix4fv(mId, 1, GL_FALSE, &p[0][0]);
}

void BasicMaterial::destroy() {
  if (texture_ != nullptr) {
    texture_->destroy();
  }
}

} // opengl
} // graphics
} // dioptre
