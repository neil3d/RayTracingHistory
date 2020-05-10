#pragma once
#include <memory>
#include <string>

#include "../geometry/Ray.h"
#include "../material/MyMaterial.h"
#include "HitRecord.h"

class MySceneObject {
 public:
  typedef std::shared_ptr<MySceneObject> Ptr;
  MySceneObject(const std::string& szName) : mName(szName) {}
  virtual ~MySceneObject() = default;

  virtual bool hit(const Ray& ray, float tMin, float tMax,
                   HitRecord& outRec) = 0;

  template <typename T, typename ...Args>
  T& createMaterial(Args&& ...args) {
    auto newMtl = std::make_shared<T>(std::forward<Args>(args)...);
    mMateril = newMtl;
    return *newMtl;
  }

 protected:
  std::string mName;
  MyMaterial::Ptr mMateril;

 public:
  MySceneObject(const MySceneObject&) = delete;
  MySceneObject& operator=(const MySceneObject&) = delete;
};