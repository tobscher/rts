#include "dioptre/graphics/opengl/buffer_manager.h"
#include "dioptre/graphics/opengl/error.h"
#include "dioptre/graphics/opengl.h"

namespace dioptre {
namespace graphics {
namespace opengl {

BufferManager::BufferManager(dioptre::graphics::Geometry* geometry) :
  geometry_(geometry),
  vertexBufferInitialized_(false),
  uVBufferInitialized_(false),
  normalBufferInitialized_(false)
{

}

void BufferManager::initializeVertexBuffer() {
  if (vertexBufferInitialized_) return;
  auto bufferData = geometry_->getData();

  if (bufferData.size() == 0) return;

  // Initialize geometry
  glGenBuffers(1, &vertexBuffer_);
  glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer_);
  glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * bufferData.size(), &bufferData[0], GL_STATIC_DRAW);

  std::cout << "Vertex Buffer: " << vertexBuffer_ << std::endl;

  // check OpenGL error
  check_gl_error();

  vertexBufferInitialized_ = true;
}

void BufferManager::initializeUVBuffer() {
  if (uVBufferInitialized_) return;

  auto uvBufferData = geometry_->getUVData();
  if (uvBufferData.size() == 0) return;

  glGenBuffers(1, &uvBuffer_);
  glBindBuffer(GL_ARRAY_BUFFER, uvBuffer_);
  glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec2) * uvBufferData.size(), &uvBufferData[0], GL_STATIC_DRAW);

  std::cout << "UV Buffer: " << uvBuffer_ << std::endl;

  // check OpenGL error
  check_gl_error();

  uVBufferInitialized_ = true;
}

void BufferManager::initializeNormalBuffer() {
  if (normalBufferInitialized_) return;

  auto normalBufferData = geometry_->getNormalData();
  if (normalBufferData.size() == 0) return;

  glGenBuffers(1, &normalBuffer_);
  glBindBuffer(GL_ARRAY_BUFFER, normalBuffer_);
  glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * normalBufferData.size(), &normalBufferData[0], GL_STATIC_DRAW);

  std::cout << "Normal Buffer: " << normalBuffer_ << std::endl;

  // check OpenGL error
  check_gl_error();

  normalBufferInitialized_ = true;
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
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * data.size(), &data[0], GL_STATIC_DRAW);
  }

  // 1st attribute buffer : vertices
  glEnableVertexAttribArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer_);
  glVertexAttribPointer(
     0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
     3,                  // size
     GL_FLOAT,           // type
     GL_FALSE,           // normalized?
     0,                  // stride
     (void*)0            // array buffer offset
  );
}

void BufferManager::setUVBuffer() {
  if (!uVBufferInitialized_) return;

  // 2nd attribute buffer : UVs
  glEnableVertexAttribArray(1);
  glBindBuffer(GL_ARRAY_BUFFER, uvBuffer_);

  if (geometry_->getIsDirty()) {
    auto bufferData = geometry_->getData();
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * bufferData.size(), &bufferData[0], GL_STATIC_DRAW);
  }
  glVertexAttribPointer(
     1,                  // attribute 1. No particular reason for 1, but must match the layout in the shader.
     2,                  // size
     GL_FLOAT,           // type
     GL_FALSE,           // normalized?
     0,                  // stride
     (void*)0            // array buffer offset
  );
}

void BufferManager::setNormalBuffer() {
  if (!normalBufferInitialized_) return;

  glEnableVertexAttribArray(2);
  glBindBuffer(GL_ARRAY_BUFFER, normalBuffer_);
  glVertexAttribPointer(
     2,                  // attribute 2. No particular reason for 2, but must match the layout in the shader.
     3,                  // size
     GL_FLOAT,           // type
     GL_FALSE,           // normalized?
     0,                  // stride
     (void*)0            // array buffer offset
  );
}

void BufferManager::disableVertexBuffer() {
  if (!vertexBufferInitialized_) return;
  glDisableVertexAttribArray(0);
}

void BufferManager::disableUVBuffer() {
  if (!uVBufferInitialized_) return;
  glDisableVertexAttribArray(1);
}

void BufferManager::disableNormalBuffer() {
  if (!normalBufferInitialized_) return;
  glDisableVertexAttribArray(2);
}

void BufferManager::destroyVertexBuffer() {
  if (!vertexBufferInitialized_) return;
  glDeleteBuffers(1, &vertexBuffer_);
}

void BufferManager::destroyUVBuffer() {
  if (!uVBufferInitialized_) return;
  glDeleteBuffers(1, &uvBuffer_);
}

void BufferManager::destroyNormalBuffer() {
  if (!normalBufferInitialized_) return;
  glDeleteBuffers(1, &normalBuffer_);
}

} // opengl
} // graphics
} // dioptre
