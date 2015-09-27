#ifndef DIOPTRE_OBSERVER_H_
#define DIOPTRE_OBSERVER_H_

namespace dioptre {

template <class T> class Observer {
public:
  Observer() {}
  virtual ~Observer() {}
  virtual void changed(T *subject) = 0;
};

} // dioptre

#endif // DIOPTRE_OBSERVER_H_
