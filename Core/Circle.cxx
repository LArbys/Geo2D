#ifndef CIRCLE_CXX
#define CIRCLE_CXX

#include "Circle.h"
#include "Circle.imp.h"
#include "opencv2/imgproc/imgproc.hpp"

namespace geo2d {

  template <class T>
  Circle<T>::Circle(const Vector<T>& c, const T r)
    : center(),
      radius(r)
  { center.x = c.x; center.y = c.y;}

  template <class T>
  Circle<T>::Circle(const T x, const T y, const T r)
    : center()
    , radius(r)
  {center.x = x; center.y = y;}

  template <class T>
  Circle<T>::Circle(const VectorArray<T>& pts)
  {
    Vector<float> pt;
    float r;
    ::cv::minEnclosingCircle(pts, pt, r);
    center.x = (T)(pt.x);
    center.y = (T)(pt.y);
    radius   = (T)r;
  }
  
  template <class T>
  Circle<T>::Circle(const std::vector<Vector<T> >& pts)
  {
    Vector<float> pt;
    float r;
    ::cv::minEnclosingCircle(pts, pt, r);
    center.x = (T)(pt.x);
    center.y = (T)(pt.y);
    radius   = (T)r;
  }


  template bool contains(const Circle<double>& circle, const Vector<double>& pt, double& measureDist);
  template bool contains(const Circle<float >& circle, const Vector<float >& pt, double& measureDist);
  template bool contains(const Circle<int   >& circle, const Vector<int   >& pt, double& measureDist);
  template bool contains(const Circle<short >& circle, const Vector<short >& pt, double& measureDist);
  
}

template class geo2d::Circle<double>;
template class geo2d::Circle<float >;
template class geo2d::Circle<int   >;
template class geo2d::Circle<short >;

#endif
