#include <iostream>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include <glm/gtc/type_ptr.hpp>

#include "dioptre/graphics/opengl.h"
#include "dioptre/graphics/opengl/error.h"
#include "dioptre/graphics/opengl/graphics.h"
#include "dioptre/math/triangle.h"
#include "dioptre/graphics/opengl/shader_factory.h"

namespace dioptre {
namespace graphics {
namespace opengl {

// TODO(Tobscher) Take clear color from settings.
int Graphics::initialize() {
  glewExperimental = true; // Needed in core profile
  if (glewInit() != GLEW_OK) {
    fprintf(stderr, "Failed to initialize GLEW\n");
    return -1;
  }
  glGetError();

  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

  // Enable depth test
  glEnable(GL_DEPTH_TEST);
  // Accept fragment if it closer to the camera than the former one
  glDepthFunc(GL_LESS);

  glGenVertexArrays(1, &vertexArrayId_);
  glBindVertexArray(vertexArrayId_);

  check_gl_error();

  LOG4CXX_INFO(logger_, "Vertex array: " << vertexArrayId_);

  debugMaterial_ = new dioptre::graphics::opengl::DebugMaterial();
  debugMaterial_->setColor(dioptre::graphics::color(1.0f, 0.0f, 0.0f));

  debugGeometry_ = new dioptre::graphics::opengl::Geometry();

  auto mesh = new dioptre::graphics::Mesh(debugGeometry_, debugMaterial_);
  debugScene_->add(mesh);

  return 0;
}

void Graphics::initializeScene() {
  LOG4CXX_INFO(logger_, "Scene initialization started.");
  for (auto it = scene_->begin(); it != scene_->end(); it++) {
    initializeMesh(*it);
  }
  LOG4CXX_INFO(logger_, "Scene initialization finished.");
}

void Graphics::initializeMesh(Mesh* mesh) {
  if (mesh->isInitialized()) return;

  LOG4CXX_INFO(logger_, "Initializing mesh...");

  // Initialize material
  auto material = mesh->getMaterial();
  if (!material->isInitialized()) {
    material->initialize();
    material->setIsInitialized(true);
  }

  LOG4CXX_INFO(logger_, "Initialized material...");

  auto geometry = mesh->getGeometry();
  if (!geometry->isInitialized()) {
    LOG4CXX_INFO(logger_, "Geometry not initialized.");
    geometry->initialize();
    geometry->setIsInitialized(true);
  } else {
    LOG4CXX_INFO(logger_, "Geometry already initialized.");
  }

  LOG4CXX_INFO(logger_, "Initialized geometry...");

  mesh->setIsInitialized(true);
}

void Graphics::resize(int width, int height) {
  // Set the viewport to window dimensions
  glViewport(0, 0, width, height);
}

void Graphics::render() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  renderScene(scene_.get());
  renderScene(debugScene_.get());
}

void Graphics::renderScene(Scene* scene) {
  for (auto it = scene->begin(); it != scene->end(); it++) {
    auto mesh = *it;

    if (!mesh->isInitialized()) {
      initializeMesh(mesh);
    }

    glm::mat4 projection = camera_->getProjectionMatrix();
    glm::mat4 view = glm::inverse(camera_->getTransform()->getMatrix());
    glm::mat4 model = mesh->getTransform()->getMatrix();
    glm::mat4 mvp = projection * view * model;

    auto material = mesh->getMaterial();
    material->update();
    material->setMVP(model, view, mvp);

    auto geometry = mesh->getGeometry();
    geometry->update();
  }
}

void Graphics::addLine(glm::vec3 from, glm::vec3 to) {
  debugGeometry_->addVertex(from);
  debugGeometry_->addVertex(to);
}

void Graphics::resetDebug() {
  debugGeometry_->clearVertices();
}

void Graphics::destroy() {
  destroyScene(scene_.get());
  destroyScene(debugScene_.get());

  debugMaterial_->destroy();

  ShaderFactory::cleanUp();

	glDeleteVertexArrays(1, &vertexArrayId_);
}

void Graphics::destroyScene(Scene* scene) {
  for (auto it = scene->begin(); it != scene->end(); it++) {
    destroyMesh(*it);
  }
}

void Graphics::destroyMesh(Mesh* mesh) {
  auto geometry = mesh->getGeometry();
  geometry->destroy();
  LOG4CXX_DEBUG(logger_, "Geometry destroyed");

  auto material = mesh->getMaterial();
  material->destroy();
  LOG4CXX_DEBUG(logger_, "Material destroyed");
}

} // opengl
} // graphics
} // dioptre
