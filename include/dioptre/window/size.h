#ifndef DIOPTRE_WINDOW_SIZE_H_
#define DIOPTRE_WINDOW_SIZE_H_

namespace dioptre {
namespace window {

/*
 * Size stores the window size.
 */
struct Size {
  int width;
  int height;

  Size(int width, int height) :
    width(width),
    height(height)
  {
  }
};

} // window
} // dioptre

#endif // DIOPTRE_WINDOW_SIZE_H_
