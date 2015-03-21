#include <iostream>

#include "glm/glm.hpp"

#include "dioptre/graphics/opengl.h"
#include "dioptre/graphics/opengl/graphics.h"
#include "dioptre/math/triangle.h"
#include "shader.h"

namespace dioptre {
namespace graphics {
namespace opengl {

Graphics::Graphics(dioptre::window::WindowInterface* window)
  : window_(window) {
}

int Graphics::Initialize() {
  glewExperimental = true; // Needed in core profile
  if (glewInit() != GLEW_OK) {
    fprintf(stderr, "Failed to initialize GLEW\n");
    return -1;
  }
  glClearColor(0.0f, 0.0f, 0.4f, 1.0f);

  glGenVertexArrays(1, &vertexArrayId_);
  glBindVertexArray(vertexArrayId_);

	// Create and compile our GLSL program from the shaders
  dioptre::graphics::opengl::Shader shader;
	programId_ = shader.loadFromFile("simple.vert", "simple.frag");

  // Generate 1 buffer, put the resulting identifier in vertexBuffer
  glGenBuffers(1, &vertexBuffer_);

  // The following commands will talk about our 'vertexBuffer' buffer
  glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer_);

  // Extract this once scene is available
  glm::vec3 a = {-1.0f, -1.0f, 0.0f};
  glm::vec3 b = {1.0f, -1.0f, 0.0f};
  glm::vec3 c = {0.0f, 1.0f, 0.0f};

  dioptre::math::Triangle triangle(a, b, c);

  auto data = triangle.data();
  float bufferData[data.size() * 3];

  int i = 0;
  for (auto it = data.cbegin(); it != data.cend(); ++it) {
    bufferData[i++] = it->x;
    bufferData[i++] = it->y;
    bufferData[i++] = it->z;
  }

  // Give our vertices to OpenGL.
  glBufferData(GL_ARRAY_BUFFER, sizeof(bufferData), bufferData, GL_STATIC_DRAW);

  return 0;
}

void Graphics::Resize(int width, int height) {
  // Set the viewport to window dimensions
  glViewport( 0, 0, width, height);
}

void Graphics::Render() {
  glClear(GL_COLOR_BUFFER_BIT);

  // Use our shader
  glUseProgram(programId_);

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

  // Draw the triangle !
  glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
  glDisableVertexAttribArray(0);
}

void Graphics::Destroy() {
	// Cleanup VBO
	glDeleteBuffers(1, &vertexBuffer_);
	glDeleteVertexArrays(1, &vertexArrayId_);
	glDeleteProgram(programId_);
}

}
}
}
