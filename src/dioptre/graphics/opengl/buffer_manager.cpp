#include "dioptre/graphics/opengl/buffer_manager.h"
#include "dioptre/graphics/opengl/error.h"
#include "dioptre/graphics/opengl.h"

namespace dioptre {
namespace graphics {
namespace opengl {

BufferManager::BufferManager(dioptre::graphics::Geometry *geometry)
    : geometry_(geometry), combinedBufferInitialized_(false),
      vertexBufferInitialized_(false), uVBufferInitialized_(false),
      normalBufferInitialized_(false), indexBufferInitialized_(false) {
  logger_ = spdlog::get("dioptre");
}

void BufferManager::initializeCombinedBuffer() {
  if (combinedBufferInitialized_)
    return;
  auto bufferData = geometry_->getCombinedData();

  if (bufferData.size() == 0)
    return;

  // Initialize geometry
  glGenBuffers(1, &combinedBuffer_);
  glBindBuffer(GL_ARRAY_BUFFER, combinedBuffer_);
  glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec4) * bufferData.size(),
               &bufferData[0], GL_DYNAMIC_DRAW);

  logger_->debug("Combined Buffer: ") << combinedBuffer_;

  // check OpenGL error
  check_gl_error();

  combinedBufferInitialized_ = true;
}

void BufferManager::initializeVertexBuffer() {
  if (vertexBufferInitialized_)
    return;
  auto bufferData = geometry_->getData();

  if (bufferData.size() == 0)
    return;

  // Initialize geometry
  glGenBuffers(1, &vertexBuffer_);
  glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer_);
  glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * bufferData.size(),
               &bufferData[0], GL_STATIC_DRAW);

  logger_->debug("Vertex Buffer: ") << vertexBuffer_;

  // check OpenGL error
  check_gl_error();

  vertexBufferInitialized_ = true;
}

void BufferManager::initializeUVBuffer() {
  if (uVBufferInitialized_)
    return;

  auto uvBufferData = geometry_->getUVData();
  if (uvBufferData.size() == 0)
    return;

  glGenBuffers(1, &uvBuffer_);
  glBindBuffer(GL_ARRAY_BUFFER, uvBuffer_);
  glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec2) * uvBufferData.size(),
               &uvBufferData[0], GL_STATIC_DRAW);

  logger_->debug("UV Buffer: ") << uvBuffer_;

  // check OpenGL error
  check_gl_error();

  uVBufferInitialized_ = true;
}

void BufferManager::initializeNormalBuffer() {
  if (normalBufferInitialized_)
    return;

  auto normalBufferData = geometry_->getNormalData();
  if (normalBufferData.size() == 0)
    return;

  glGenBuffers(1, &normalBuffer_);
  glBindBuffer(GL_ARRAY_BUFFER, normalBuffer_);
  glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * normalBufferData.size(),
               &normalBufferData[0], GL_STATIC_DRAW);

  logger_->debug("Normal Buffer: ") << normalBuffer_;

  // check OpenGL error
  check_gl_error();

  normalBufferInitialized_ = true;
}

void BufferManager::initializeIndexBuffer() {
  if (indexBufferInitialized_)
    return;
  auto bufferData = geometry_->getFaceData();

  if (bufferData.size() == 0)
    return;

  // Initialize geometry
  glGenBuffers(1, &indexBuffer_);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer_);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(glm::uvec3) * bufferData.size(),
               &bufferData[0], GL_STATIC_DRAW);

  logger_->debug("Index Buffer: ") << indexBuffer_;

  // check OpenGL error
  check_gl_error();

  indexBufferInitialized_ = true;
}

void BufferManager::setCombinedBuffer() {
  auto data = geometry_->getCombinedData();

  if (data.size() == 0) {
    return;
  }

  if (!combinedBufferInitialized_) {
    initializeCombinedBuffer();
  } else if (geometry_->getIsDirty()) {
    glBindBuffer(GL_ARRAY_BUFFER, combinedBuffer_);
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec4) * data.size(), &data[0],
                 GL_DYNAMIC_DRAW);
  }

  // 1st attribute buffer : vertices
  glEnableVertexAttribArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, combinedBuffer_);
  glVertexAttribPointer(0, // attribute 0. No particular reason for 0, but must
                           // match the layout in the shader.
                        4, // size
                        GL_FLOAT, // type
                        GL_FALSE, // normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
  check_gl_error();
}

void BufferManager::setVertexBuffer() {
  auto data = geometry_->getData();

  if (data.size() == 0) {
    return;
  }

  if (!vertexBufferInitialized_) {
    initializeVertexBuffer();
  } else if (geometry_->getIsDirty()) {
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer_);
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * data.size(), &data[0],
                 GL_STATIC_DRAW);
  }

  // 1st attribute buffer : vertices
  glEnableVertexAttribArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer_);
  glVertexAttribPointer(0, // attribute 0. No particular reason for 0, but must
                           // match the layout in the shader.
                        3, // size
                        GL_FLOAT, // type
                        GL_FALSE, // normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
}

void BufferManager::setUVBuffer() {
  if (!uVBufferInitialized_)
    return;

  // 2nd attribute buffer : UVs
  glEnableVertexAttribArray(1);
  glBindBuffer(GL_ARRAY_BUFFER, uvBuffer_);

  if (geometry_->getIsDirty()) {
    auto bufferData = geometry_->getData();
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * bufferData.size(),
                 &bufferData[0], GL_STATIC_DRAW);
  }
  glVertexAttribPointer(1, // attribute 1. No particular reason for 1, but must
                           // match the layout in the shader.
                        2, // size
                        GL_FLOAT, // type
                        GL_FALSE, // normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
}

void BufferManager::setNormalBuffer() {
  if (!normalBufferInitialized_)
    return;

  glEnableVertexAttribArray(2);
  glBindBuffer(GL_ARRAY_BUFFER, normalBuffer_);
  glVertexAttribPointer(2, // attribute 2. No particular reason for 2, but must
                           // match the layout in the shader.
                        3, // size
                        GL_FLOAT, // type
                        GL_FALSE, // normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
}

void BufferManager::setIndexBuffer() {
  auto data = geometry_->getFaceData();

  if (data.size() == 0) {
    return;
  }

  if (!indexBufferInitialized_) {
    initializeIndexBuffer();
  } else if (geometry_->getIsDirty()) {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer_);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(glm::uvec3) * data.size(),
                 &data[0], GL_STATIC_DRAW);
  }

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer_);
}

void BufferManager::disableCombinedBuffer() {
  if (!combinedBufferInitialized_)
    return;
  glDisableVertexAttribArray(0);
}

void BufferManager::disableVertexBuffer() {
  if (!vertexBufferInitialized_)
    return;
  glDisableVertexAttribArray(0);
}

void BufferManager::disableUVBuffer() {
  if (!uVBufferInitialized_)
    return;
  glDisableVertexAttribArray(1);
}

void BufferManager::disableNormalBuffer() {
  if (!normalBufferInitialized_)
    return;
  glDisableVertexAttribArray(2);
}

void BufferManager::destroyCombinedBuffer() {
  if (!combinedBufferInitialized_)
    return;
  glDeleteBuffers(1, &combinedBuffer_);
}

void BufferManager::destroyVertexBuffer() {
  if (!vertexBufferInitialized_)
    return;
  glDeleteBuffers(1, &vertexBuffer_);
}

void BufferManager::destroyUVBuffer() {
  if (!uVBufferInitialized_)
    return;
  glDeleteBuffers(1, &uvBuffer_);
}

void BufferManager::destroyNormalBuffer() {
  if (!normalBufferInitialized_)
    return;
  glDeleteBuffers(1, &normalBuffer_);
}

void BufferManager::destroyIndexBuffer() {
  if (!indexBufferInitialized_)
    return;
  glDeleteBuffers(1, &indexBuffer_);
}

} // opengl
} // graphics
} // dioptre
