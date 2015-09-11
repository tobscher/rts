#version 330 core

in vec2 texpos;

uniform sampler2D tex;
uniform vec3 diffuse;

// Ouput data
out vec4 color;

void main() {
  /* color = texture(tex, texpos) * vec4(diffuse, 1.0); */

  // With outline
  vec2 TexCoord = texpos;
  vec2 Offset = 1.0 / textureSize(tex, 0);

  vec4 n = texture(tex, vec2(TexCoord.x, TexCoord.y - Offset.y));
  vec4 e = texture(tex, vec2(TexCoord.x + Offset.x, TexCoord.y));
  vec4 s = texture(tex, vec2(TexCoord.x, TexCoord.y + Offset.y));
  vec4 w = texture(tex, vec2(TexCoord.x - Offset.x, TexCoord.y));

  vec4 TexColor = texture(tex, TexCoord);

  float GrowedAlpha = TexColor.a;
  GrowedAlpha = mix(GrowedAlpha, 1.0, s.a);
  GrowedAlpha = mix(GrowedAlpha, 1.0, w.a);
  GrowedAlpha = mix(GrowedAlpha, 1.0, n.a);
  GrowedAlpha = mix(GrowedAlpha, 1.0, e.a);

  vec4 OutlineColorWithNewAlpha = vec4(0.0,0.0,0.0,1.0);
  OutlineColorWithNewAlpha.a = GrowedAlpha;
  vec4 CharColor = TexColor * vec4(diffuse, 1.0);

  color = mix(OutlineColorWithNewAlpha, CharColor, CharColor.a);
}
