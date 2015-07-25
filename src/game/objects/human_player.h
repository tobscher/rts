#include "dioptre/object.h"

namespace objects {

class HumanPlayer : public dioptre::Object {
public:
  HumanPlayer() : Object("ojects.human_player") {}

  void makeCurrent();
  void select(dioptre::Object* object);
  static HumanPlayer* spawn();

private:
  std::vector<dioptre::Object*> selectedObjects_;
}; // HumanPlayer

} // objects
