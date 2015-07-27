#ifndef DIOPTRE_WINDOW_SIZE_H_
#define DIOPTRE_WINDOW_SIZE_H_

namespace dioptre {
namespace window {

/*
 * Size stores the window size.
 */
struct Size {
  double width;
  double height;

  Size(double width, double height) :
    width(width),
    height(height)
  {
  }
};

} // window
} // dioptre

#endif // DIOPTRE_WINDOW_SIZE_H_
