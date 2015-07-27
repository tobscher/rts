#include "dioptre/graphics/graphics_interface.h"

namespace dioptre {
namespace graphics {

GraphicsInterface::GraphicsInterface() :
  Module("dioptre.graphics")
{
}

void GraphicsInterface::update() {
}

void GraphicsInterface::setProjector(Projector* projector) {
  projector_ = projector;
}

Layer* GraphicsInterface::getLayer(unsigned int index) {
  return layers_[index];
}

void GraphicsInterface::addLayer(Layer* layer) {
  layers_.push_back(layer);
}

} // graphics
} // dioptre
