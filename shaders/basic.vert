#version 330 core

// Input vertex data, different for all executions of this shader.
layout(location = 0) in vec3 vertexPosition_modelspace;

#ifdef USE_TEXTURE
  layout(location = 1) in vec2 vertexUV;
  out vec2 UV;
#endif


layout(location = 2) in vec3 vertexNormal_modelspace;

out vec3 Position_worldspace;
out vec3 Normal_cameraspace;
out vec3 EyeDirection_cameraspace;
out vec3 LightDirection_cameraspace;

uniform mat4 MVP;
uniform mat4 V;
uniform mat4 M;
uniform vec3 LightPosition_worldspace;

#ifdef USE_TEXTURE
  uniform vec2 repeat;
#endif

void main() {
  Position_worldspace = (M * vec4(vertexPosition_modelspace,1)).xyz;
  vec3 vertexPosition_cameraspace = ( V * M * vec4(vertexPosition_modelspace,1)).xyz;
  EyeDirection_cameraspace = vec3(0,0,0) - vertexPosition_cameraspace;
  vec3 LightPosition_cameraspace = ( V * vec4(LightPosition_worldspace,1)).xyz;
  LightDirection_cameraspace = LightPosition_cameraspace + EyeDirection_cameraspace;
  Normal_cameraspace = ( V * M * vec4(vertexNormal_modelspace,0)).xyz;

  // Output position of the vertex, in clip space : MVP * position
  vec4 v = vec4(vertexPosition_modelspace,1); // Transform an homogeneous 4D vector
  gl_Position =  MVP * vec4(vertexPosition_modelspace,1);

#ifdef USE_TEXTURE
  UV = vertexUV * repeat;
#endif
}
