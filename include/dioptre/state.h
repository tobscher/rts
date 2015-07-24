#ifndef DIOPTRE_STATE_H_
#define DIOPTRE_STATE_H_

#include "dioptre/transform.h"

namespace dioptre {

template <class T>
class State {
public:
  State() :
    previous_(new T()),
    current_(new T()) {}

  T* getCurrent() { return current_; }
  T* getPrevious() { return previous_; }
  void makeCurrent() {
    previous_->setMatrix(current_->getMatrix());
  }

private:
  T* previous_;
  T* current_;
}; // State

} // dioptre

#endif // DIOPTRE_STATE_H_
