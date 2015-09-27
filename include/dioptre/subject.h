#ifndef DIOPTRE_SUBJECT_H_
#define DIOPTRE_SUBJECT_H_

#include <vector>
#include "dioptre/observer.h"

namespace dioptre {

template <class T> class Subject {
public:
  Subject() {}
  virtual ~Subject() {}

  void attach(Observer<T> *observer) { observers_.push_back(observer); }
  void notify() {
    for (auto it = observers_.begin(); it != observers_.end(); it++)
      (*it)->changed(static_cast<T *>(this));
  }

private:
  std::vector<Observer<T> *> observers_;
}; // Subject

} // dioptre

#endif // DIOPTRE_SUBJECT_H_
