#pragma once
#include <vector>

#include "MySceneObject.h"

namespace RTKit2 {

class TriangleMesh : public MySceneObject {
 public:
  typedef std::shared_ptr<TriangleMesh> Ptr;

  using MySceneObject::MySceneObject;

  virtual ~TriangleMesh();

  void createFromObj(const std::string& assetKey, const Transform& trans);

 protected:
  RTCGeometry mGeometry = nullptr;
};

}  // namespace RTKit2