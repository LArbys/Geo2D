#ifndef CONTOUR_IMP_H
#define CONTOUR_IMP_H

#include "opencv2/imgproc/imgproc.hpp"

namespace geo2d {

  template <class T>
  double contains(const VectorArray<T>& contour, Vector<T>& pt, bool measureDist)
  { return ::cv::pointPolygonTest(contour,pt,measureDist); }

}
#endif
