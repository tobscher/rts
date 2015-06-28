#version 330 core

in vec2 UV;

uniform vec3 diffuse;
uniform sampler2D textureSampler;

// Ouput data
out vec3 color;

void main() {
#ifdef USE_COLOR
  color = diffuse;
#endif

#ifdef USE_TEXTURE
  color = texture(textureSampler, UV).rgb;
#endif
}
