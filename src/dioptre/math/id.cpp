#include "dioptre/math/id.h"

namespace dioptre {
namespace math {

int Id::current_ = 0;

int Id::next() {
  return ++current_;
}

}
}
