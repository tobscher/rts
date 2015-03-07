#ifndef DIOPTRE_WINDOW_INTERFACE_WINDOW_H_
#define DIOPTRE_WINDOW_INTERFACE_WINDOW_H_

namespace dioptre {
namespace window {

class WindowInterface {
public:
  virtual int create() = 0;
  virtual void destroy() = 0;
  virtual bool shouldClose() = 0;
  virtual void swapBuffers() = 0;
}; // Window

} // window
} // dioptre

#endif // DIOPTRE_WINDOW_INTERFACE_WINDOW_H_
