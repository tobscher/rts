#ifndef RTS_COMPONENTS_EDGE_SCROLL_COMPONENT_H_
#define RTS_COMPONENTS_EDGE_SCROLL_COMPONENT_H_

#include "dioptre/component_interface.h"

namespace rts {
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
} // rts

#endif // RTS_COMPONENTS_EDGE_SCROLL_COMPONENT_H_
