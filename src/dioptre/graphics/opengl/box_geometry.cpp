#include "dioptre/graphics/opengl/box_geometry.h"
#include "dioptre/graphics/opengl.h"
#include "dioptre/graphics/opengl/error.h"

#include <iostream>

using dioptre::graphics::opengl::BufferManager;

namespace dioptre {
namespace graphics {
namespace opengl {

BoxGeometry::BoxGeometry(glm::float32 width, glm::float32 height,
                         glm::float32 depth)
    : dioptre::graphics::BoxGeometry(width, height, depth) {
  bufferManager_ = std::unique_ptr<BufferManager>(new BufferManager(this));
}

void BoxGeometry::initialize() {
  bufferManager_->initializeVertexBuffer();
  bufferManager_->initializeUVBuffer();
  bufferManager_->initializeNormalBuffer();
  bufferManager_->initializeIndexBuffer();
}

void BoxGeometry::update() {

  bufferManager_->setVertexBuffer();
  bufferManager_->setUVBuffer();
  bufferManager_->setNormalBuffer();
  bufferManager_->setIndexBuffer();

  if (faces_.size() > 0) {
    auto data = getFaceData();
    glDrawElements(GL_TRIANGLES, data.size() * 3, GL_UNSIGNED_INT, (void *)0);
  } else {
    auto data = getData();
    glDrawArrays(GL_TRIANGLES, 0, data.size());
  }

  bufferManager_->disableVertexBuffer();
  bufferManager_->disableUVBuffer();
  bufferManager_->disableNormalBuffer();
}

void BoxGeometry::destroy() {
  bufferManager_->destroyVertexBuffer();
  bufferManager_->destroyUVBuffer();
  bufferManager_->destroyNormalBuffer();
  bufferManager_->destroyIndexBuffer();
}

} // opengl
} // graphics
} // dioptre
