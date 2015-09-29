#ifndef DIOPTRE_GRAPHICS_TRANSFORM_OBSERVER_H_
#define DIOPTRE_GRAPHICS_TRANSFORM_OBSERVER_H_

#include "dioptre/observer.h"
#include "dioptre/transform.h"

namespace dioptre {
namespace graphics {

class Component;
class TransformObserver : public dioptre::Observer<dioptre::Transform> {
public:
  TransformObserver(dioptre::graphics::Component *component);

  void changed(dioptre::Transform *transform);

private:
  dioptre::graphics::Component *component_;
}; // TransformObserver

} // graphics
} // dioptre

#endif // DIOPTRE_GRAPHICS_TRANSFORM_OBSERVER_H_
