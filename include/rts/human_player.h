#ifndef RTS_HUMAN_PLAYER_H_
#define RTS_HUMAN_PLAYER_H_

#include "dioptre/object.h"

namespace rts {

class HumanPlayer : public dioptre::Object {
public:
  HumanPlayer() : Object("ojects.human_player") {}

  void makeCurrent();

  std::vector<dioptre::Object*> getSelectedObjects();
  void select(dioptre::Object* object);
  void unselect(dioptre::Object* object);

  static HumanPlayer* spawn();

private:
  std::vector<dioptre::Object*> selectedObjects_;
}; // HumanPlayer

} // rts

#endif // RTS_HUMAN_PLAYER_H_
