#include "Line.h"
#include "spoon.h"

namespace geo2d {

  template <class T>
  T Line<T>::x(T y) const
  {
    if(dir.x==0.0f) return pt.x;
    if(dir.y==0.0f) throw spoon("Slope is 0: no unique X can be found...");
    return pt.x + dir.x * (y - pt.y) / dir.y;
  }

  template <class T>
  T Line<T>::y(T x) const
  {
    if(dir.x==0.0f) throw spoon("Slope is inf: no unique Y can be found...");
    if(dir.y==0.0f) return pt.y;
    return pt.y + dir.y * (x - pt.x) / dir.x;
  }
  
  template <class T>
  double angle(const Line<T>& l)
  { return geo2d::angle(l.dir); }
  
  template <class T>
  double angle(const Line<T>& l1,const Line<T>& l2)
    { return (geo2d::angle(l2.dir)-geo2d::angle(l1.dir)); }

}
