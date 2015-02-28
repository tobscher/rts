#include <iostream>

#include <GL/glew.h>
#include "engine/graphics.h"

int Initialize() {
  glewExperimental = true; // Needed in core profile
  if (glewInit() != GLEW_OK) {
    fprintf(stderr, "Failed to initialize GLEW\n");
    return -1;
  }
  glClearColor(1.0f, 0.0f, 0.0f, 1.0f);

  return 0;
}

void Resize(int width, int height) {
  // Set the viewport to window dimensions
  glViewport( 0, 0, width, height);
}

void Render() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
