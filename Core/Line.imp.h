#include "Line.h"

namespace geo2d {

  template <class T>
  double angle(const Line<T>& l)
  { return geo2d::angle(l.dir); }

}
