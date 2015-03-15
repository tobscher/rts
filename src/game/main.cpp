#include "dioptre/application.h"

/* void error_callback(int error, const char* description) { */
/*   fputs(description, stderr); */
/* } */

/* static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) { */
/*   if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) */
/*     glfwSetWindowShouldClose(window, GL_TRUE); */
/* } */

int main(int argc, char *argv[]) {
  dioptre::Application *application = new dioptre::Application(argc, argv);
  application->run();

  return 0;
}
