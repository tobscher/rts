#ifndef DIOPTRE_PHYSICS_SHAPE_H_
#define DIOPTRE_PHYSICS_SHAPE_H_

namespace dioptre {
namespace physics {

enum ShapeType {
  SHAPE_BOX
};

class Shape {
public:
  virtual ShapeType getShapeType() = 0;

private:
  ShapeType ShapeType_;
}; // Shape

} // physics
} // dioptre

#endif // DIOPTRE_PHYSICS_SHAPE_H_
