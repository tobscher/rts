#include "dioptre/physics/bullet/physics.h"
#include "dioptre/physics/bullet/shape.h"
#include "dioptre/locator.h"

#include <iostream>

namespace dioptre {
namespace physics {
namespace bullet {

int Physics::initialize() {
  broadphase_ = std::unique_ptr<btBroadphaseInterface>(new btDbvtBroadphase());
  collisionConfiguration_ = std::unique_ptr<btDefaultCollisionConfiguration>(
      new btDefaultCollisionConfiguration());
  dispatcher_ = std::unique_ptr<btCollisionDispatcher>(
      new btCollisionDispatcher(collisionConfiguration_.get()));
  solver_ = std::unique_ptr<btSequentialImpulseConstraintSolver>(
      new btSequentialImpulseConstraintSolver);

  dynamicsWorld_ =
      std::unique_ptr<btDiscreteDynamicsWorld>(new btDiscreteDynamicsWorld(
          dispatcher_.get(), broadphase_.get(), solver_.get(),
          collisionConfiguration_.get()));

  auto gravity = world_->getGravity();
  dynamicsWorld_->setGravity(btVector3(gravity.x, gravity.y, gravity.z));

  debugDrawer_ = std::unique_ptr<DebugDrawer>(new DebugDrawer());
  debugDrawer_->setDebugMode(btIDebugDraw::DBG_DrawWireframe);
  dynamicsWorld_->setDebugDrawer(debugDrawer_.get());

  logger_->info("Bullet engine initialized.");

  return 0;
}

void Physics::initializeWorld() {
  logger_->info("Initializing physics world.");
  for (auto it = world_->begin(); it != world_->end(); it++) {
    initializeRigidBody(*it);
  }
}

void Physics::initializeRigidBody(dioptre::physics::RigidBody *body) {
  auto shape =
      dynamic_cast<dioptre::physics::bullet::Shape *>(body->getShape());
  btCollisionShape *boxCollisionShape = shape->getCollisionShape();

  auto component = body->getComponent();
  auto object = component->getObject();
  auto transform = object->getTransform();
  auto position = transform->getPosition();
  auto orientation =
      body->getComponent()->getObject()->getTransform()->getOrientation();
  auto inertia = body->getInertia();
  auto mass = body->getMass();

  logger_->info("Initializing rigid body.") << object->getName();

  btDefaultMotionState *motionstate = new btDefaultMotionState(btTransform(
      btQuaternion(orientation.x, orientation.y, orientation.z, orientation.w),
      btVector3(position.x, position.y, position.z)));

  btRigidBody::btRigidBodyConstructionInfo rigidBodyCI(
      mass, // mass, in kg. 0 -> Static object, will never move.
      motionstate,
      boxCollisionShape,                         // collision shape of body
      btVector3(inertia.x, inertia.y, inertia.z) // local inertia
      );

  btRigidBody *rigidBody = new btRigidBody(rigidBodyCI);

  rigidBodies_.push_back(rigidBody);
  dynamicsWorld_->addRigidBody(rigidBody);

  rigidBody->setUserPointer(object);
}

void ScreenPosToWorldRay(
    double mouseX, double mouseY, // Mouse position, in pixels, from bottom-left
                                  // corner of the window
    int screenWidth, int screenHeight, // Window size, in pixels
    glm::mat4 ViewMatrix,              // Camera position and orientation
    glm::mat4 ProjectionMatrix, // Camera parameters (ratio, field of view, near
                                // and far planes)
    glm::vec3 &out_origin, // Ouput : Origin of the ray. /!\ Starts at the near
                           // plane, so if you want the ray to start at the
                           // camera's position instead, ignore this.
    glm::vec3 &out_direction // Ouput : Direction, in world space, of the ray
                             // that goes "through" the mouse.
    ) {

  // The ray Start and End positions, in Normalized Device Coordinates (Have you
  // read Tutorial 4 ?)
  glm::vec4 lRayStart_NDC(
      ((float)mouseX / (float)screenWidth - 0.5f) * 2.0f,  // [0,1024] -> [-1,1]
      ((float)mouseY / (float)screenHeight - 0.5f) * 2.0f, // [0, 768] -> [-1,1]
      -1.0, // The near plane maps to Z=-1 in Normalized Device Coordinates
      1.0f);
  glm::vec4 lRayEnd_NDC(((float)mouseX / (float)screenWidth - 0.5f) * 2.0f,
                        ((float)mouseY / (float)screenHeight - 0.5f) * 2.0f,
                        0.0, 1.0f);

  // Faster way (just one inverse)
  glm::mat4 M = glm::inverse(ProjectionMatrix * ViewMatrix);
  glm::vec4 lRayStart_world = M * lRayStart_NDC;
  lRayStart_world /= lRayStart_world.w;
  glm::vec4 lRayEnd_world = M * lRayEnd_NDC;
  lRayEnd_world /= lRayEnd_world.w;

  glm::vec3 lRayDir_world(lRayEnd_world - lRayStart_world);
  lRayDir_world = glm::normalize(lRayDir_world);

  out_origin = glm::vec3(lRayStart_world);
  out_direction = glm::normalize(lRayDir_world);
}

void Physics::castRay(dioptre::mouse::Position position) {
  logger_->info("Casting ray at:") << position.x << "x" << position.y;

  auto graphics =
      dioptre::Locator::getInstance<dioptre::graphics::GraphicsInterface>(
          dioptre::Module::M_GRAPHICS);
  auto debug = (dioptre::graphics::Debug *)graphics->getLayer(2);
  auto layer = graphics->getLayer(0);
  auto camera = layer->getCamera();
  auto window = dioptre::Locator::getInstance<dioptre::window::WindowInterface>(
      dioptre::Module::M_WINDOW);
  auto size = window->getSize();

  auto view = glm::inverse(camera->getTransform()->getMatrix());
  auto projection = camera->getProjectionMatrix();

  position.y = size.height - position.y;
  glm::vec3 rayStart;
  glm::vec3 rayEnd;
  glm::vec3 rayDirection;
  ScreenPosToWorldRay(position.x, position.y, size.width, size.height, view,
                      projection, rayStart, rayDirection);

  rayDirection = rayDirection * 1000.0f;
  rayEnd = rayStart + rayDirection;

  btCollisionWorld::ClosestRayResultCallback rayCallback(
      btVector3(rayStart.x, rayStart.y, rayStart.z),
      btVector3(rayEnd.x, rayEnd.y, rayEnd.z));

  dynamicsWorld_->rayTest(btVector3(rayStart.x, rayStart.y, rayStart.z),
                          btVector3(rayEnd.x, rayEnd.y, rayEnd.z), rayCallback);

  if (rayCallback.hasHit()) {
    logger_->info("Ray hit object.");

    auto hitPoint = rayCallback.m_hitPointWorld;
    glm::vec3 glmHitPoint = glm::vec3(hitPoint.x(), hitPoint.y(), hitPoint.z());
    /* debug->addCross(glmHitPoint); */

    dioptre::Object *object = static_cast<dioptre::Object *>(
        rayCallback.m_collisionObject->getUserPointer());
    object->handleClick(glmHitPoint);
  } else {
    logger_->info("Ray hit background.");
  }
}

void Physics::debug() { dynamicsWorld_->debugDrawWorld(); }

void Physics::simulate() {}

void Physics::destroy() {}

} // bullet
} // physics
} // dioptre
