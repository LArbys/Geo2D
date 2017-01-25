#ifndef LINE_CXX
#define LINE_CXX

#include "Line.h"
#include "Line.imp.h"

namespace geo2d {

  template class Line<double>;
  template class Line<float >;
  template class Line<int   >;
  template class Line<short >;

  template double angle(const Line<double>&);
  template double angle(const Line<float >&);
  template double angle(const Line<int   >&);
  template double angle(const Line<short >&);


  template double angle(const Line<double>&, const Line<double>&);
  template double angle(const Line<float >&, const Line<float >&);
  template double angle(const Line<int   >&, const Line<int   >&);
  template double angle(const Line<short >&, const Line<short >&);
  
}

#endif
