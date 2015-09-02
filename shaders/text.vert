#version 330 core

layout(location = 0) in vec4 coord;

uniform vec2 windowSize;
uniform mat4 MVP;

out vec2 texpos;

void main(void) {
  vec4 v = vec4(coord.xy, 0, 1);

  gl_Position = MVP * v;
  texpos = coord.zw;
}
