#include <iostream>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtx/matrix_interpolation.hpp"
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/transform.hpp>

#include "dioptre/debug.h"
#include "dioptre/graphics/component.h"
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
  glewExperimental = GL_TRUE; // Needed in core profile
  if (glewInit() != GLEW_OK) {
    fprintf(stderr, "Failed to initialize GLEW\n");
    return -1;
  }
  glGetError();

  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

  // Enable depth test
  glEnable(GL_DEPTH_TEST);

  // Accept fragment if it closer to the camera than the former one
  glDepthFunc(GL_LEQUAL);

  // Enable blending for textures with alpha channel
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  glGenVertexArrays(1, &vertexArrayId_);
  glBindVertexArray(vertexArrayId_);

  check_gl_error();

  logger_->info("Vertex array: ") << vertexArrayId_;

  return 0;
}

void Graphics::initializeScene() {
  logger_->info("Scene initialization started.");

  auto mainLayer = layers_[0];
  auto debug = new dioptre::graphics::opengl::Debug(mainLayer->getCamera());
  debug->initialize();
  addLayer(debug);

  for (auto layer : layers_) {
    auto scene = layer->getScene();

    for (auto it = scene->begin(); it != scene->end(); it++) {
      initializeMesh(*it);
    }
  }
  logger_->info("Scene initialization finished.");
}

void Graphics::initializeMesh(Mesh* mesh) {
  if (mesh->isInitialized()) return;

  logger_->info("Initializing mesh...");

  // Initialize material
  auto material = mesh->getMaterial();
  if (!material->isInitialized()) {
    material->initialize();
    material->setIsInitialized(true);
  }

  logger_->info("Initialized material...");

  auto geometry = mesh->getGeometry();
  if (!geometry->isInitialized()) {
    logger_->info("Geometry not initialized.");
    geometry->initialize();
    geometry->setIsInitialized(true);
  } else {
    logger_->info("Geometry already initialized.");
  }

  logger_->info("Initialized geometry...");

  mesh->setIsInitialized(true);
}

void Graphics::resize(int width, int height) {
  // Set the viewport to window dimensions
  glViewport(0, 0, width, height);
}

void Graphics::render(const double alpha) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  for (auto layer : layers_) {
    renderScene(layer->getScene(), layer->getCamera(), alpha);
  }
}

void Graphics::renderScene(Scene* scene, Camera* camera, float alpha) {
  for (auto it = scene->begin(); it != scene->end(); it++) {
    auto mesh = *it;

    if (!mesh->isInitialized()) {
      initializeMesh(mesh);
    }

    glm::mat4 matrix;
    auto component = dynamic_cast<dioptre::graphics::Component*>(mesh->getComponent());

    // If mesh does not have a component it's likely to not have a changed position,
    // so just use identity matrix.
    if (component != nullptr) {
      auto object = component->getObject();
      auto transform = object->getTransform();
      matrix = transform->getMatrix();
    }

    // Camera
    glm::mat4 projection = camera->getProjectionMatrix();

    // Interpolate between previous and current frame for smoother transiations
    glm::mat4 previousView = camera->getState()->getPrevious()->getMatrixWorldInverse();
    glm::mat4 currentView = camera->getState()->getCurrent()->getMatrixWorldInverse();
    glm::mat4 view = glm::interpolate(previousView, currentView, alpha);

    glm::mat4 model = matrix;
    glm::mat4 mvp = projection * view * model;

    auto material = mesh->getMaterial();
    material->update();
    material->setMVP(model, view, mvp);

    if (projector_ != nullptr) {
      if (projector_->getTarget() == mesh) {
        glm::mat4 projView = projector_->getTransform()->getMatrixWorldInverse();
        glm::mat4 projProj = projector_->getProjectionMatrix();
        glm::mat4 projScaleTrans = glm::translate(glm::vec3(0.5f)) *
          glm::scale(glm::vec3(0.5f));

        glm::mat4 projectorMatrix = projScaleTrans * projProj * projView;
        material->setProjection(projectorMatrix);
      }
    }

    auto geometry = mesh->getGeometry();
    geometry->update();

    // Not dirty anymore
    geometry->setIsDirty(false);
  }
}

void Graphics::destroy() {
  for (auto layer : layers_) {
    destroyScene(layer->getScene());
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
  logger_->debug("Geometry destroyed");

  auto material = mesh->getMaterial();
  material->destroy();
  logger_->debug("Material destroyed");
}

} // opengl
} // graphics
} // dioptre
