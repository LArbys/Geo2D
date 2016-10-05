#ifndef CONTOUR_CXX
#define CONTOUR_CXX

#include "Contour.h"
#include "Contour.imp.h"

namespace geo2d {
  template double contains(const Vector2DArray<double>& contour, Vector2D<double>& pt, bool measureDist);
  template double contains(const Vector2DArray<float >& contour, Vector2D<float >& pt, bool measureDist);
  template double contains(const Vector2DArray<int   >& contour, Vector2D<int   >& pt, bool measureDist);
  template double contains(const Vector2DArray<short >& contour, Vector2D<short >& pt, bool measureDist);
}
#endif
