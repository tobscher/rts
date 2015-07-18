#ifndef DIOPTRE_PHYSICS_BULLET_DEBUG_DRAWER_H_
#define DIOPTRE_PHYSICS_BULLET_DEBUG_DRAWER_H_

#include "LinearMath/btIDebugDraw.h"
#include "dioptre/graphics/graphics_interface.h"

namespace dioptre {
namespace physics {
namespace bullet {

class DebugDrawer : public btIDebugDraw {
public:
  DebugDrawer();

  void drawLine(const btVector3& from, const btVector3& to, const btVector3& color);
  void drawContactPoint(const btVector3& PointOnB, const btVector3& normalOnB, btScalar distance, int lifeTime, const btVector3& color);
  void reportErrorWarning(const char* warningString);
  void draw3dText(const btVector3& location, const char* textString);
  void setDebugMode(int debugMode) { debugMode_ = debugMode; }
  int getDebugMode() const { return debugMode_; };

private:
  int debugMode_;
  dioptre::graphics::GraphicsInterface* graphics_;
}; // DebugDrawer

} // bullet
} // physics
} // dioptre

#endif
