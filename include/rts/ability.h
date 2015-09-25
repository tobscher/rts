#ifndef RTS_ABILITIES_H_
#define RTS_ABILITIES_H_

#include <string>

namespace rts {

class GameObject;
enum AbilityType { A_MOVE }; // AbilityType
class Ability {

public:
  Ability(std::string name, rts::GameObject *gameObject);
  virtual ~Ability() {}

  virtual int initialize() = 0;
  virtual void update() = 0;
  virtual void destroy() = 0;

private:
  std::string name_;
  rts::GameObject *gameObject_;
}; // Ability

} // rts

#endif // RTS_ABILITIES_H_
