#include "LineSegment.h"
#include "spoon.h"

namespace geo2d {

  template <class T>
  double length(const LineSegment<T>& l) 
  { return geo2d::dist(l.pt1,l.pt2); }

  template <class T>
  double length2(const LineSegment<T>& l)
  { return dist2(l.pt1,l.pt2); }

  template <class T>
  double angle(const LineSegment<T>& l)
  { return angle(l.pt1,l.pt2); }

  template <class T>
  Vector<T> dir(const LineSegment<T>& l)
  { return geo2d::dir(l.pt1,l.pt2); }

  
  template <class T>
  T LineSegment<T>::x(T y) const
  {
    T ty = pt1.y > pt2.y ? pt1.y : pt2.y;
    T by = pt1.y > pt2.y ? pt2.y : pt1.y;

    if (y > ty) throw spoon("Requested pt off segment");
    if (y < by) throw spoon("Requested pt off segment");

    auto dir_=dir(*this);
    if(dir_.x==0.0f) return pt1.x;
    if(dir_.y==0.0f) throw spoon("Slope is 0: no unique X can be found...");

    return pt1.x + dir_.x * (y - pt1.y) / dir_.y;
  }

  template <class T>
  T LineSegment<T>::y(T x) const
  {
    T rx = pt1.x > pt2.x ? pt1.x : pt2.x;
    T lx = pt1.x > pt2.x ? pt2.x : pt1.x;

    if (x > rx) throw spoon("Requested pt off segment");
    if (x < lx) throw spoon("Requested pt off segment");
    
    auto dir_=dir(*this);
    if(dir_.x==0.0f) throw spoon("Slope is inf: no unique Y can be found...");
    if(dir_.y==0.0f) return pt1.y;

    return pt1.y + dir_.y * (x - pt1.x) / dir_.x;
  }
  


}
