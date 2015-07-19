#include "dioptre/graphics/opengl/geometry.h"
#include "dioptre/graphics/opengl.h"
#include "dioptre/graphics/opengl/error.h"

#include <iostream>

using dioptre::graphics::opengl::BufferManager;

namespace dioptre {
namespace graphics {
namespace opengl {

Geometry::Geometry(GLenum drawMode) :
  drawMode_(drawMode) {
  bufferManager_ = std::unique_ptr<BufferManager>(new BufferManager(this));
}

void Geometry::initialize() {
  bufferManager_->initializeVertexBuffer();
  bufferManager_->initializeUVBuffer();
  bufferManager_->initializeNormalBuffer();
}

void Geometry::update() {
  auto data = getData();

  bufferManager_->setVertexBuffer();
  bufferManager_->setUVBuffer();
  bufferManager_->setNormalBuffer();

  if (data.size() > 0) {
    glDrawArrays(drawMode_, 0, data.size());
  }

  bufferManager_->disableVertexBuffer();
  bufferManager_->disableUVBuffer();
  bufferManager_->disableNormalBuffer();
}

void Geometry::destroy() {
  bufferManager_->destroyVertexBuffer();
  bufferManager_->destroyUVBuffer();
  bufferManager_->destroyNormalBuffer();
}

} // opengl
} // graphics
} // dioptre
