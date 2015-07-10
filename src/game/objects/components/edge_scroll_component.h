#ifndef OBJECTS_COMPONENTS_EDGE_SCROLL_COMPONENT_H_
#define OBJECTS_COMPONENTS_EDGE_SCROLL_COMPONENT_H_

#include "dioptre/component_interface.h"

namespace objects {
namespace components {

class EdgeScrollComponent : public dioptre::ComponentInterface {
public:
  EdgeScrollComponent();
  void update();

private:
  double scrollSpeed_;
  double scrollThreshold_;
}; // EdgeScrollComponent

} // components
} // objects

#endif // OBJECTS_COMPONENTS_EDGE_SCROLL_COMPONENT_H_
