#include <iostream>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/transform.hpp>

#include "dioptre/debug.h"
#include "dioptre/graphics/opengl.h"
#include "dioptre/graphics/opengl/error.h"
#include "dioptre/graphics/opengl/graphics.h"
#include "dioptre/graphics/opengl/debug.h"
#include "dioptre/graphics/opengl/shader_factory.h"
#include "dioptre/graphics/opengl/texture_factory.h"

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

  auto debug = new dioptre::graphics::opengl::Debug();
  debug->initialize();
  setDebug(debug);

  projector_ = new dioptre::graphics::Projector(40.0, 1280.0/800.0, 1, 100);
  projector_->getTransform()->setPosition(0.0, 10.0, 0.0);
  projector_->getTransform()->rotateX(-1.57079633);

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

  if (debug_) {
    renderScene(debug_->getScene());
  }
}

void Graphics::renderScene(Scene* scene) {
  for (auto it = scene->begin(); it != scene->end(); it++) {
    auto mesh = *it;

    if (!mesh->isInitialized()) {
      initializeMesh(mesh);
    }

    glm::mat4 matrix;
    auto component = mesh->getComponent();

    // If mesh does not have a component it's likely to not have a changed position,
    // so just use identity matrix.
    if (component != nullptr) {
      auto object = component->getObject();
      auto transform = object->getTransform();
      matrix = transform->getMatrix();
    }

    glm::mat4 projection = camera_->getProjectionMatrix();
    glm::mat4 view = glm::inverse(camera_->getTransform()->getMatrix());
    glm::mat4 model = matrix;
    glm::mat4 mvp = projection * view * model;

    glm::mat4 projView = glm::inverse(projector_->getTransform()->getMatrix());
    glm::mat4 projProj = projector_->getProjectionMatrix();
    glm::mat4 projScaleTrans = glm::translate(glm::vec3(0.5f)) *
                            glm::scale(glm::vec3(0.5f));

    glm::mat4 projectorMatrix = projScaleTrans * projProj * projView;

    auto material = mesh->getMaterial();
    material->update();
    material->setMVP(model, view, mvp);
    material->setProjection(projectorMatrix);

    auto geometry = mesh->getGeometry();
    geometry->update();
  }
}

void Graphics::destroy() {
  destroyScene(scene_.get());

  if (debug_) {
    destroyScene(debug_->getScene());
  }

  TextureFactory::cleanUp();
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
