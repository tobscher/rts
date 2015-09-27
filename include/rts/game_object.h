#ifndef RTS_GAME_OBJECT_H_
#define RTS_GAME_OBJECT_H_

#include "dioptre/object.h"
#include "rts/ability.h"

namespace rts {

class GameObject : public dioptre::Object {
public:
  GameObject(std::string name);
  virtual ~GameObject();

  bool hasAbility(rts::AbilityType type);
  rts::Ability *getAbility(rts::AbilityType type);

  void update();

protected:
  std::map<rts::AbilityType, rts::Ability *> abilities_;

  void addAbility(rts::AbilityType type, rts::Ability *ability);
}; // GameObject

} // rts

#endif // RTS_GAME_OBJECT_H_
