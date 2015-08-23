#include "dioptre/graphics/atlas.h"

namespace dioptre {
namespace graphics {

Atlas::Atlas(dioptre::font::Face* face, int size) :
  face_(face),
  size_(size) {

}

int Atlas::getSize() {
  return size_;
}

} // graphics
} // dioptre
