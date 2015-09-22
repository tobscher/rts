#ifndef DIOPTRE_GRAPHICS_OPENGL_BUFFER_MANAGER_H_
#define DIOPTRE_GRAPHICS_OPENGL_BUFFER_MANAGER_H_

#include "dioptre/graphics/opengl.h"
#include "dioptre/graphics/geometry.h"

#include <memory>
#include "spdlog/spdlog.h"

namespace dioptre {
namespace graphics {
namespace opengl {

class BufferManager {
public:
  explicit BufferManager(dioptre::graphics::Geometry *geometry);

  void initializeCombinedBuffer();
  void initializeVertexBuffer();
  void initializeUVBuffer();
  void initializeNormalBuffer();
  void initializeIndexBuffer();

  void setCombinedBuffer();
  void setVertexBuffer();
  void setUVBuffer();
  void setNormalBuffer();
  void setIndexBuffer();

  void disableCombinedBuffer();
  void disableVertexBuffer();
  void disableUVBuffer();
  void disableNormalBuffer();

  void destroyCombinedBuffer();
  void destroyVertexBuffer();
  void destroyUVBuffer();
  void destroyNormalBuffer();
  void destroyIndexBuffer();

private:
  std::shared_ptr<spdlog::logger> logger_;

  dioptre::graphics::Geometry *geometry_;

  bool combinedBufferInitialized_;
  bool vertexBufferInitialized_;
  bool uVBufferInitialized_;
  bool normalBufferInitialized_;
  bool indexBufferInitialized_;

  GLuint combinedBuffer_;
  GLuint vertexBuffer_;
  GLuint uvBuffer_;
  GLuint normalBuffer_;
  GLuint indexBuffer_;
};

} // opengl
} // graphics
} // dioptre

#endif // DIOPTRE_GRAPHICS_OPENGL_BUFFER_MANAGER_H_
