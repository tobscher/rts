#ifndef RTS_SHADER_FEATURES_H
#define RTS_SHADER_FEATURES_H

#include <string>

namespace dioptre {
namespace graphics {
namespace opengl {

enum ShaderFeatures {
  FeatureNone = 0,
  FeatureColor = 1,
  FeatureTexture = 2
}; // ShaderFeatures

inline ShaderFeatures operator|(ShaderFeatures a, ShaderFeatures b) {
  return static_cast<ShaderFeatures>(static_cast<int>(a) | static_cast<int>(b));
}

inline ShaderFeatures operator&(ShaderFeatures a, ShaderFeatures b) {
  return static_cast<ShaderFeatures>(static_cast<int>(a) & static_cast<int>(b));
}

const std::string USE_COLOR("#define USE_COLOR\n");
const std::string USE_TEXTURE("#define USE_TEXTURE\n");

} // opengl
} // graphics
} // dioptre

#endif //RTS_SHADER_FEATURES_H
