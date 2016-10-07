
#include "LineSegment.h"
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
  Vector2D<T> dir(const LineSegment<T>& l)
  { return geo2d::dir(l.pt1,l.pt2); }

}
