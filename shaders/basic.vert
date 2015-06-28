#version 330 core

// Input vertex data, different for all executions of this shader.
layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec2 vertexUV;

out vec2 UV;

uniform mat4 MVP;
uniform vec2 repeat;

void main() {
  // Output position of the vertex, in clip space : MVP * position
  vec4 v = vec4(vertexPosition_modelspace,1); // Transform an homogeneous 4D vector
  gl_Position = MVP * v;

#ifdef USE_TEXTURE
  UV = vertexUV * repeat;
#endif
}
