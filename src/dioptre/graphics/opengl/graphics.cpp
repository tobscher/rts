#include <iostream>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
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

  debug("Initialized material...");

  auto geometry = mesh->getGeometry();
  if (!geometry->isInitialized()) {
    geometry->initialize();
    geometry->setIsInitialized(true);
  }

  debug("Initialized geometry...");

  mesh->setIsInitialized(true);
}

void Graphics::resize(int width, int height) {
  // Set the viewport to window dimensions
  glViewport(0, 0, width, height);
}

void Graphics::render(Scene* scene, Camera* camera) {
  glClear(GL_COLOR_BUFFER_BIT);

  for (auto it = scene_->begin(); it != scene_->end(); it++) {
    if (!(*it)->isInitialized()) {
      initializeMesh(*it);
    }

    auto mesh = *it;

    // Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
    glm::mat4 projection = camera->getProjectionMatrix();
    glm::mat4 view = glm::inverse(camera->getTransform()->getMatrix());
    glm::mat4 model = mesh->getTransform()->getMatrix();  // Changes for each model !
    glm::mat4 mvp = projection * view * model;

    auto material = mesh->getMaterial();
    material->update();
    material->setMVP(mvp);

    auto geometry = mesh->getGeometry();
    geometry->update();
  }
}

void Graphics::destroy() {
  for (auto it = scene_->begin(); it != scene_->end(); it++) {
    destroyMesh(*it);
  }
	glDeleteVertexArrays(1, &vertexArrayId_);
}

void Graphics::destroyMesh(Mesh* mesh) {
  auto geometry = mesh->getGeometry();
  geometry->destroy();

  auto material = mesh->getMaterial();
  material->destroy();
}

} // opengl
} // graphics
} // dioptre
