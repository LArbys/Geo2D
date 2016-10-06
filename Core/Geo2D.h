#ifndef GEO2D_H
#define GEO2D_H

#include <LineSegment.h>

namespace geo2d {

  template <class T>
  float Signed2DTriArea(const Vector2D<T>&,const Vector2D<T>&, const Vector2D<T>&);
  
  template <class T>
  bool SegmentSegmentTest(const LineSegment<T>&,const LineSegment<T>&,Vector2D<T>&);

}


#endif
