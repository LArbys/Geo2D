#ifndef CONTOUR_IMP_H
#define CONTOUR_IMP_H

#include "opencv2/imgproc/imgproc.hpp"

namespace geo2d {

  template <class T>
  double contains(const Vector2DArray<T>& contour, Vector2D<T>& pt, bool measureDist)
  { return ::cv::pointPolygonTest(contour,pt,measureDist); }

}
#endif
