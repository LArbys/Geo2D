#ifndef HALFLINE_CXX
#define HALFLINE_CXX

#include "HalfLine.h"
#include "HalfLine.imp.h"

namespace geo2d {

  template class HalfLine<double>;
  template class HalfLine<float >;
  template class HalfLine<int   >;
  template class HalfLine<short >;

  template double angle(const HalfLine<double>&);
  template double angle(const HalfLine<float >&);
  template double angle(const HalfLine<int   >&);
  template double angle(const HalfLine<short >&);

}
#endif
