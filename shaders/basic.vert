#version 330 core

// Input vertex data, different for all executions of this shader.
layout(location = 0) in vec3 vertexPosition_modelspace;
uniform mat4 MVP;

void main() {
  // Output position of the vertex, in clip space : MVP * position
  vec4 v = vec4(vertexPosition_modelspace,1); // Transform an homogeneous 4D vector
  gl_Position = MVP * v;
}
