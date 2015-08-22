#version 330 core

in vec2 texpos;

uniform sampler2D tex;
uniform vec3 diffuse;

// Ouput data
out vec4 color;

void main() {
  color = vec4(1, 1, 1, texture(tex, texpos).r) * vec4(diffuse, 1.0);
}
