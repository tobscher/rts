#version 330 core

uniform vec3 diffuse;

// Ouput data
out vec3 color;

void main() {
  color = diffuse;
}
