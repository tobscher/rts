#include "dioptre/graphics/opengl/buffer_manager.h"
#include "dioptre/graphics/opengl/error.h"
#include "dioptre/graphics/opengl.h"

namespace dioptre {
namespace graphics {
namespace opengl {

BufferManager::BufferManager(dioptre::graphics::Geometry* geometry) :
  geometry_(geometry)
{

}

void BufferManager::initializeVertexBuffer() {
  // Initialize geometry
  glGenBuffers(1, &vertexBuffer_);
  glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer_);
  auto bufferData = geometry_->getData();
  glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * bufferData.size(), &bufferData[0], GL_STATIC_DRAW);

  // LOG4CXX_INFO(logger_, "Vertex Buffer: " << vertexBuffer_);

  // check OpenGL error
  check_gl_error();
}

void BufferManager::initializeUVBuffer() {
  glGenBuffers(1, &uvBuffer_);
  glBindBuffer(GL_ARRAY_BUFFER, uvBuffer_);
  auto uvBufferData = geometry_->getUVData();
  glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec2) * uvBufferData.size(), &uvBufferData[0], GL_STATIC_DRAW);

  // LOG4CXX_INFO(logger_, "UV Buffer: " << uvBuffer_);

  // check OpenGL error
  check_gl_error();
}

void BufferManager::initializeNormalBuffer() {
  glGenBuffers(1, &normalBuffer_);
  glBindBuffer(GL_ARRAY_BUFFER, normalBuffer_);
  auto normalBufferData = geometry_->getNormalData();
  glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * normalBufferData.size(), &normalBufferData[0], GL_STATIC_DRAW);

  // LOG4CXX_INFO(logger_, "Normal Buffer: " << normalBuffer_);

  // check OpenGL error
  check_gl_error();
}

void BufferManager::setVertexBuffer() {
  auto data = geometry_->getData();

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
  // 2nd attribute buffer : UVs
  glEnableVertexAttribArray(1);
  glBindBuffer(GL_ARRAY_BUFFER, uvBuffer_);
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
  glDisableVertexAttribArray(0);
}

void BufferManager::disableUVBuffer() {
  glDisableVertexAttribArray(1);
}

void BufferManager::disableNormalBuffer() {
  glDisableVertexAttribArray(2);
}

void BufferManager::destroyVertexBuffer() {
  glDeleteBuffers(1, &vertexBuffer_);
}

void BufferManager::destroyUVBuffer() {
  glDeleteBuffers(1, &uvBuffer_);
}

void BufferManager::destroyNormalBuffer() {
  glDeleteBuffers(1, &normalBuffer_);
}

} // opengl
} // graphics
} // dioptre
