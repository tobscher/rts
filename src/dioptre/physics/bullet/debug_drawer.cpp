#include "dioptre/physics/bullet/debug_drawer.h"
#include "dioptre/locator.h"

#include <iostream>

namespace dioptre {
namespace physics {
namespace bullet {

DebugDrawer::DebugDrawer() : debugMode_(0) {
  graphics_ =
      dioptre::Locator::getInstance<dioptre::graphics::GraphicsInterface>(
          dioptre::Module::M_GRAPHICS);
}

void DebugDrawer::drawLine(const btVector3 &from, const btVector3 &to,
                           const btVector3 &color) {
  // TODO(tobscher) don't use magic numbers
  auto debug = (dioptre::graphics::Debug *)graphics_->getLayer(2);

  if (debug) {
    /* debug->addLine(glm::vec3(from.x(), from.y(), from.z()), */
    /*                glm::vec3(to.x(), to.y(), to.z())); */
  } else {
    std::cout << "DebugDrawer -  Error: "
              << "No debug drawer attached." << std::endl;
  }
}

void DebugDrawer::drawContactPoint(const btVector3 &PointOnB,
                                   const btVector3 &normalOnB,
                                   btScalar distance, int lifeTime,
                                   const btVector3 &color) {}

void DebugDrawer::reportErrorWarning(const char *warningString) {
  std::cout << "DebugDrawer - Error: " << warningString << std::endl;
}

void DebugDrawer::draw3dText(const btVector3 &location,
                             const char *textString) {}

} // bullet
} // physics
} // dioptre
