#include <iostream>

#include "glm/glm.hpp"
#include <glm/gtc/type_ptr.hpp>

#include "dioptre/graphics/opengl.h"
#include "dioptre/graphics/opengl/graphics.h"
#include "dioptre/math/triangle.h"
#include "dioptre/graphics/opengl/shader.h"
#include "dioptre/debug.h"

namespace dioptre {
namespace graphics {
namespace opengl {

int Graphics::initialize() {
  glewExperimental = true; // Needed in core profile
  if (glewInit() != GLEW_OK) {
    fprintf(stderr, "Failed to initialize GLEW\n");
    return -1;
  }
  glClearColor(0.0f, 0.0f, 0.4f, 1.0f);

  glGenVertexArrays(1, &vertexArrayId_);
  glBindVertexArray(vertexArrayId_);

  // Use material
  dioptre::graphics::opengl::Shader shader;
	programId_ = shader.loadFromFile("simple.vert", "simple.frag");

  for (auto it = scene_->begin(); it != scene_->end(); it++) {
    initializeMesh(*it);
  }

  return 0;
}

void Graphics::initializeMesh(Mesh* mesh) {
  if (mesh->isInitialized()) return;

  debug("Initializing mesh...");

  // Initialize material
  auto material = mesh->getMaterial();
  if (!material->isInitialized()) {
    material->initialize();
    material->setIsInitialized(true);
  }

  /* auto geometry = mesh->getGeometry(); */
  /* if (!geometry->isInitialized()) { */
  /*   geometry->initialize(); */
  /*   geometry->setIsInitialized(true); */
  /* } */

  // Initialize geometry
  GLuint vertexBuffer;
  glGenBuffers(1, &vertexBuffer);
  vertexBuffers_[mesh->getId()] = vertexBuffer;
  glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
  auto bufferData = mesh->getGeometry()->getData();
  // Give our vertices to OpenGL.
  glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * bufferData.size(), &bufferData[0], GL_STATIC_DRAW);

  mesh->setIsInitialized(true);
}

void Graphics::resize(int width, int height) {
  // Set the viewport to window dimensions
  glViewport(0, 0, width, height);
}

void Graphics::render() {
  glClear(GL_COLOR_BUFFER_BIT);

  for (auto it = scene_->begin(); it != scene_->end(); it++) {
    if (!(*it)->isInitialized()) {
      initializeMesh(*it);
    }
    renderMesh(*it);
  }
}

void Graphics::renderMesh(Mesh* mesh) {
  auto material = mesh->getMaterial();
  material->update();

  /* auto geometry = mesh->getGeometry(); */
  /* geometry->update(); */

  auto data = mesh->getGeometry()->getData();

  // 1st attribute buffer : vertices
  glEnableVertexAttribArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, vertexBuffers_[mesh->getId()]);
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

void Graphics::destroy() {
  for (auto it = scene_->begin(); it != scene_->end(); it++) {
    destroyMesh(*it);
  }
}

void Graphics::destroyMesh(Mesh* mesh) {
	// Cleanup VBO
	glDeleteBuffers(1, &vertexBuffers_[mesh->getId()]);
	glDeleteVertexArrays(1, &vertexArrayId_);
	glDeleteProgram(programId_);
}

} // opengl
} // graphics
} // dioptre
