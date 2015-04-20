#ifndef DIOPTRE_MATH_ID_H_
#define DIOPTRE_MATH_ID_H_

namespace dioptre {
namespace math {

class Id {
public:
  static int next();

private:
  static int current_;
};

}
}

#endif // DIOPTRE_MATH_ID_H_
