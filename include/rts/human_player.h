#ifndef RTS_HUMAN_PLAYER_H_
#define RTS_HUMAN_PLAYER_H_

#include "rts/game_object.h"

namespace rts {

class HumanPlayer : public dioptre::Object {
public:
  HumanPlayer() : Object("ojects.human_player") {}

  void makeCurrent();

  std::vector<rts::GameObject *> getSelectedObjects();
  void select(rts::GameObject *object);
  void unselect(rts::GameObject *object);
  void clearSelection();

  static HumanPlayer *spawn();

private:
  std::vector<rts::GameObject *> selectedObjects_;
}; // HumanPlayer

} // rts

#endif // RTS_HUMAN_PLAYER_H_
