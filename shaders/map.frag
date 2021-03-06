#version 330 core

in vec3 Position_worldspace;
in vec3 Normal_cameraspace;
in vec3 EyeDirection_cameraspace;
in vec3 LightDirection_cameraspace;

uniform vec3 diffuse;
out vec4 color;

// grid
in vec2 UV;
uniform sampler2D textureSampler;

// Projection
in vec4 ProjTexCoord;

uniform mat4 MV;
uniform vec3 LightPosition_worldspace;

uniform sampler2D ProjectorTex;

void main() {
  vec3 MaterialDiffuseColor = vec3(texture(textureSampler, UV).rgb) * diffuse;

  vec3 LightColor = vec3(1,1,1);
  float LightPower = 8000.0f;
  vec3 MaterialAmbientColor = vec3(0.1,0.1,0.1) * MaterialDiffuseColor;
  vec3 MaterialSpecularColor = vec3(0.3,0.3,0.3);
  float distance = length( LightPosition_worldspace - Position_worldspace );
  vec3 n = normalize( Normal_cameraspace );
  vec3 l = normalize( LightDirection_cameraspace );
  float cosTheta = clamp( dot( n,l ), 0,1 );
  vec3 E = normalize(EyeDirection_cameraspace);
  vec3 R = reflect(-l,n);
  float cosAlpha = clamp( dot( E,R ), 0,1 );

  vec3 c = MaterialAmbientColor +
    MaterialDiffuseColor * LightColor * LightPower * cosTheta / (distance*distance) +
    MaterialSpecularColor * LightColor * LightPower * pow(cosAlpha,5) / (distance*distance);

  vec4 projected = vec4(0.0);
  if (ProjTexCoord.z > 0.0) {
    projected = textureProj(ProjectorTex, ProjTexCoord);
  }

  color = vec4(c, 1.0) + projected * 0.5;
}
