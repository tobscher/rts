#include "dioptre/graphics/debug.h"

namespace dioptre {
namespace graphics {

Debug::Debug() :
  scene_(new Scene()) {

}

void Debug::addLine(glm::vec3 from, glm::vec3 to) {
  lines_->addVertex(from);
  lines_->addVertex(to);
}

void Debug::addCross(glm::vec3 point) {
  int length = 5;
  point.y += 0.01;

  glm::vec3 fromTop(point.x, point.y, point.z - length);
  glm::vec3 toBottom(point.x, point.y, point.z + length);
  glm::vec3 fromLeft(point.x - length, point.y, point.z);
  glm::vec3 toRight(point.x + length, point.y, point.z);

  crosses_->addVertex(fromTop);
  crosses_->addVertex(toBottom);

  crosses_->addVertex(fromLeft);
  crosses_->addVertex(toRight);
}

void Debug::reset() {
  lines_->clearVertices();
}

void Debug::destroy() {
}

} // graphics
} // dioptre
