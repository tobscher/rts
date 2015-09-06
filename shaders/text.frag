#version 330 core

in vec2 texpos;

uniform sampler2D tex;
uniform vec3 diffuse;

// Ouput data
out vec4 color;

void main() {
  /* color = texture(tex, texpos) * vec4(1.0,0.0,0.0,1.0); */
  color = texture(tex, texpos);
  /* color = vec4(1.0,0.0,0.0,1.0); */
}
