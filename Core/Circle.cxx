#ifndef CIRCLE_CXX
#define CIRCLE_CXX

#include "Circle.h"

namespace geo2d {

  template <class T>
  Circle<T>::Circle(const Vector2D<T>& c, const T r)
    : center(),
      radius(r)
  { center.x = c.x; center.y = c.y;}

  template <class T>
  Circle<T>::Circle(const T x, const T y, const T r)
    : center()
    , radius(r)
  {center.x = x; center.y = y;}

}

template class geo2d::Circle<double>;
template class geo2d::Circle<float >;
template class geo2d::Circle<int   >;
template class geo2d::Circle<short >;
#endif
