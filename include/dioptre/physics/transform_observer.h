#ifndef DIOPTRE_PHYSICS_TRANSFORM_OBSERVER_H_
#define DIOPTRE_PHYSICS_TRANSFORM_OBSERVER_H_

#include "dioptre/observer.h"
#include "dioptre/transform.h"

namespace dioptre {
namespace physics {

class Component;
class TransformObserver : public dioptre::Observer<dioptre::Transform> {
public:
  TransformObserver(dioptre::physics::Component *component);

  void changed(dioptre::Transform *transform);

private:
  dioptre::physics::Component *component_;
}; // TransformObserver

} // physics
} // dioptre

#endif // DIOPTRE_PHYSICS_TRANSFORM_OBSERVER_H_
