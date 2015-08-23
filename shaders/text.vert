#version 330 core

layout(location = 0) in vec4 coord;

uniform vec2 windowSize;
out vec2 texpos;

void main(void) {
  vec2 vertexPos = coord.xy - vec2(windowSize.x/2.0,windowSize.y/2.0); // [0..800][0..600] -> [-400..400][-300..300]
  vertexPos /= vec2(windowSize.x/2.0,windowSize.y/2.0);

  gl_Position = vec4(vertexPos, 0, 1);
  texpos = coord.zw;
}
