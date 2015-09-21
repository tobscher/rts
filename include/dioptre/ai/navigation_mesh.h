#ifndef DIOPTRE_AI_NAVIGATION_MESH_H_
#define DIOPTRE_AI_NAVIGATION_MESH_H_

namespace dioptre {
namespace ai {

class NavigationMesh {
public:
  virtual ~NavigationMesh() {}

  virtual void build() = 0;
}; // NavigationMesh

} // ai
} // dioptre

#endif // DIOPTRE_AI_NAVIGATION_MESH_H_
