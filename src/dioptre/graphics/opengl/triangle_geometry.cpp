#include "dioptre/graphics/opengl/triangle_geometry.h"
#include "dioptre/graphics/opengl.h"

namespace dioptre {
namespace graphics {
namespace opengl {

TriangleGeometry::TriangleGeometry(glm::vec3 a, glm::vec3 b, glm::vec3 c) :
  dioptre::graphics::TriangleGeometry(a, b, c) {
}

void TriangleGeometry::initialize() {
  // Initialize geometry
  glGenBuffers(1, &vertexBuffer_);
  glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer_);
  auto bufferData = getData();

  // Give our vertices to OpenGL.
  glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * bufferData.size(), &bufferData[0], GL_STATIC_DRAW);
}

void TriangleGeometry::update() {
  auto data = getData();

  // 1st attribute buffer : vertices
  glEnableVertexAttribArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer_);
  glVertexAttribPointer(
     0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
     data.size(),        // size
     GL_FLOAT,           // type
     GL_FALSE,           // normalized?
     0,                  // stride
     (void*)0            // array buffer offset
  );

  // Draw the triangle !
  glDrawArrays(GL_TRIANGLES, 0, data.size());
  glDisableVertexAttribArray(0);
}

void TriangleGeometry::destroy() {
  glDeleteBuffers(1, &vertexBuffer_);
}

} // opengl
} // graphics
} // dioptre
