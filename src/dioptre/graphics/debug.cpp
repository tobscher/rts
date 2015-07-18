#include "dioptre/graphics/debug.h"

namespace dioptre {
namespace graphics {

Debug::Debug() :
  scene_(new Scene()) {

}

void Debug::addLine(glm::vec3 from, glm::vec3 to) {
  geometry_->addVertex(from);
  geometry_->addVertex(to);
}

void Debug::reset() {
  geometry_->clearVertices();
}

void Debug::destroy() {
}

} // graphics
} // dioptre
