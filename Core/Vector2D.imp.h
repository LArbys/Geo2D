#ifndef VECTOR2D_IMP_H
#define VECTOR2D_IMP_H

#include <cmath>

namespace geo2d {

  template <class T>
  using Vector2D = ::cv::Point_<T>;

  template <class T>
  double angle(const Vector2D<T>& obj)
  { return atan2(obj.y,obj.x) / M_PI * 180.; }
  template <class T>
  double angle(const Vector2D<T>& obj1, const Vector2D<T>& obj2)
  { return atan2(obj2.y-obj1.y,obj2.x-obj1.x) / M_PI * 180.; }

  template <class T>
  Vector2D<T> dir(const Vector2D<T>& obj1, const Vector2D<T>& obj2)
  { auto res = obj2; res.x -= obj1.x; res.y -= obj1.y; return res; }

  template <class T>
  Vector2D<T> dir(double angle)
  { Vector2D<T> res; res.x = cos(M_PI * angle / 180.); res.y = sqrt(1. - res.x * res.x); return res; }

  template <class T>
  T length2(const Vector2D<T>& obj)
  { return pow(obj.x,2)+pow(obj.y,2); }

  template <class T>
  T dist2(const Vector2D<T>& obj1, const Vector2D<T>& obj2)
  { auto obj = obj1; obj.x -= obj2.x; obj.y -= obj2.y; return length2(obj); }

  template <class T>
  T length(const Vector2D<T>& obj)
  { return sqrt(length2(obj)); }

  template <class T>
  T dist(const Vector2D<T>& obj1, const Vector2D<T>& obj2)
  { return sqrt(dist2(obj1,obj2)); }
}

#endif


