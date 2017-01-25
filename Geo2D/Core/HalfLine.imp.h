#include "HalfLine.h"
#include "spoon.h"
#include <sstream>

namespace geo2d {

  template <class T>
  T HalfLine<T>::x(T y) const
  {
    if(dir.x==0.0f) return pt.x;
    if(dir.y==0.0f) throw spoon("Slope is 0: no unique X can be found...");
    if(dir.y>0.0f && y < pt.y) {
      std::stringstream ss;
      ss << "No point exists at y=" << y;
      throw spoon(ss.str());
    }
    if(dir.y<0.0f && y > pt.y){
      std::stringstream ss;
      ss << "No point exists at y=" << y;
      throw spoon(ss.str());
    }
    return pt.x + dir.x * (y - pt.y) / dir.y;
  }

  template <class T>
  T HalfLine<T>::y(T x) const
  {
    if(dir.x==0.0f) throw spoon("Slope is inf: no unique Y can be found...");
    if(dir.y==0.0f) return pt.y;
    if(dir.x>0.0f && x < pt.x) {
      std::stringstream ss;
      ss << "No point exists at x=" << x;
      throw spoon(ss.str());
    }
    if(dir.x<0.0f && x > pt.x){
      std::stringstream ss;
      ss << "No point exists at x=" << x;
      throw spoon(ss.str());
    }
    return pt.y + dir.y * (x - pt.x) / dir.x;
  }

  template <class T>
  double angle(const HalfLine<T>& l)
  { return geo2d::angle(l); }

}
