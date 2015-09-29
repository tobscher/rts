#include "dioptre/graphics/component.h"
#include "dioptre/locator.h"

namespace dioptre {
namespace graphics {

Component::Component(Mesh *mesh, int layerIndex)
    : ComponentInterface("dioptre.graphics.component"), mesh_(mesh),
      projector_(nullptr) {
  mesh->setComponent(this);

  // TODO(tobscher) on initialize
  auto graphicsService = dioptre::Locator::getInstance<GraphicsInterface>(
      dioptre::Module::M_GRAPHICS);
  auto layer = graphicsService->getLayer(layerIndex);
  auto scene = layer->getScene();
  scene->add(mesh);

  transformObserver_ = new dioptre::graphics::TransformObserver(this);
}

int Component::initialize() {
  dioptre::ComponentInterface::initialize();

  auto transform = object_->getTransform();
  transform->attach(transformObserver_);

  return 0;
}

Component::~Component() { delete mesh_; }

Mesh *Component::getMesh() { return mesh_; }

void Component::update() {}

Projector *Component::getProjector() { return projector_; }

void Component::setProjector(Projector *projector) { projector_ = projector; }

void Component::makeCurrent() {
  if (!projector_) {
    return;
  }

  projector_->makeCurrent();
}

} // graphics
} // dioptre
