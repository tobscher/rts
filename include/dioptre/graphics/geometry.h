#ifndef DIOTRE_GRAPHICS_GEOMETRY_H_
#define DIOTRE_GRAPHICS_GEOMETRY_H_

#include <vector>
#include <memory>
#include "glm/glm.hpp"
#include "spdlog/spdlog.h"

namespace dioptre {
namespace graphics {

class Geometry {
public:
  Geometry();
  virtual ~Geometry() {}

  std::vector<glm::vec4> getCombinedData();
  std::vector<glm::vec3> getData();
  std::vector<glm::vec2> getUVData();
  std::vector<glm::vec3> getNormalData();
  std::vector<glm::uvec3> getFaceData();

  bool isInitialized();
  void setIsInitialized(bool value);

  void addCombined(glm::vec4 combined);
  void addVertex(glm::vec3 vertex);
  void addUV(glm::vec2 uv);
  void addNormal(glm::vec3 normal);
  void addFace(glm::uvec3 face);

  void clearCombined();
  void clearVertices();
  void clearUVs();
  void clearNormals();
  void clearFaces();

  bool getIsDirty() { return isDirty_; }
  bool setIsDirty(bool isDirty) { return isDirty_ = isDirty; }

  virtual void initialize() = 0;
  virtual void update() = 0;
  virtual void destroy() = 0;

protected:
  std::shared_ptr<spdlog::logger> logger_;

  bool isDirty_;

  std::vector<glm::vec4> combined_;
  std::vector<glm::vec3> vertices_;
  std::vector<glm::vec2> uvs_;
  std::vector<glm::vec3> normals_;
  std::vector<glm::uvec3> faces_;

private:
  bool isInitialized_;
}; // Geometry

} // graphics
} // dioptre

#endif
