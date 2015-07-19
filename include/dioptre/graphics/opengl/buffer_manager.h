#ifndef DIOPTRE_GRAPHICS_OPENGL_BUFFER_MANAGER_H_
#define DIOPTRE_GRAPHICS_OPENGL_BUFFER_MANAGER_H_

#include "dioptre/graphics/opengl.h"
#include "dioptre/graphics/geometry.h"

namespace dioptre {
namespace graphics {
namespace opengl {

class BufferManager {
public:
  BufferManager(dioptre::graphics::Geometry* geometry);

  void initializeVertexBuffer();
  void initializeUVBuffer();
  void initializeNormalBuffer();

  void setVertexBuffer();
  void setUVBuffer();
  void setNormalBuffer();

  void disableVertexBuffer();
  void disableUVBuffer();
  void disableNormalBuffer();

  void destroyVertexBuffer();
  void destroyUVBuffer();
  void destroyNormalBuffer();

private:
  dioptre::graphics::Geometry* geometry_;

  bool vertexBufferInitialized_;
  bool uVBufferInitialized_;
  bool normalBufferInitialized_;

  GLuint vertexBuffer_;
  GLuint uvBuffer_;
  GLuint normalBuffer_;
};

} // opengl
} // graphics
} // dioptre

#endif // DIOPTRE_GRAPHICS_OPENGL_BUFFER_MANAGER_H_
