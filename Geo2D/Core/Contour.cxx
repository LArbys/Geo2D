#ifndef CONTOUR_CXX
#define CONTOUR_CXX

#include "Contour.h"
#include "Contour.imp.h"

namespace geo2d {
  template double contains(const VectorArray<double>& contour, Vector<double>& pt, bool measureDist);
  template double contains(const VectorArray<float >& contour, Vector<float >& pt, bool measureDist);
  template double contains(const VectorArray<int   >& contour, Vector<int   >& pt, bool measureDist);
  template double contains(const VectorArray<short >& contour, Vector<short >& pt, bool measureDist);
}
#endif
