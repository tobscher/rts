#include <iostream>

#include "dioptre/graphics/opengl.h"
#include "dioptre/graphics/opengl/shader.h"
#include "dioptre/graphics/opengl/renderer.h"

namespace dioptre {
namespace graphics {
namespace opengl {

Renderer::Renderer(dioptre::window::WindowInterface* window)
  : window_(window) {
}

int Renderer::Initialize() {
  glewExperimental = true; // Needed in core profile
  if (glewInit() != GLEW_OK) {
    fprintf(stderr, "Failed to initialize GLEW\n");
    return -1;
  }
  glClearColor(0.0f, 0.0f, 0.4f, 1.0f);

  glGenVertexArrays(1, &vertexArrayId_);
  glBindVertexArray(vertexArrayId_);

	// Create and compile our GLSL program from the shaders
	programId_ = dioptre::graphics::opengl::LoadShaders("simple.vert", "simple.frag");

  // Generate 1 buffer, put the resulting identifier in vertexBuffer
  glGenBuffers(1, &vertexBuffer_);

  // The following commands will talk about our 'vertexBuffer' buffer
  glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer_);

  // Give our vertices to OpenGL.
  glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

  return 0;
}

void Renderer::Resize(int width, int height) {
  // Set the viewport to window dimensions
  glViewport( 0, 0, width, height);
}

void Renderer::Render() {
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

void Renderer::Destroy() {
	// Cleanup VBO
	glDeleteBuffers(1, &vertexBuffer_);
	glDeleteVertexArrays(1, &vertexArrayId_);
	glDeleteProgram(programId_);
}

}
}
}
