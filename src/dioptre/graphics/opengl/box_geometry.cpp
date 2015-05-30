#include "dioptre/graphics/opengl/box_geometry.h"
#include "dioptre/graphics/opengl.h"

#include "dioptre/debug.h"

namespace dioptre {
namespace graphics {
namespace opengl {

BoxGeometry::BoxGeometry(glm::float32 width, glm::float32 height, glm::float32 depth) :
  dioptre::graphics::BoxGeometry(width, height, depth) {
}

// TODO(Tobscher) Extract into base class.
void BoxGeometry::initialize() {
  // Initialize geometry
  glGenBuffers(1, &vertexBuffer_);
  glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer_);
  auto bufferData = getData();

  // Give our vertices to OpenGL.
  glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * bufferData.size(), &bufferData[0], GL_STATIC_DRAW);
}

void BoxGeometry::update() {
  auto data = getData();

  // 1st attribute buffer : vertices
  glEnableVertexAttribArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer_);
  glVertexAttribPointer(
     0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
     3,        // size
     GL_FLOAT,           // type
     GL_FALSE,           // normalized?
     0,                  // stride
     (void*)0            // array buffer offset
  );

  glDrawArrays(GL_TRIANGLES, 0, data.size());
  glDisableVertexAttribArray(0);
}

void BoxGeometry::destroy() {
  glDeleteBuffers(1, &vertexBuffer_);
}

} // opengl
} // graphics
} // dioptre
