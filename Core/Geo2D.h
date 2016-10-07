#ifndef GEO2D_H
#define GEO2D_H

#include "Line.h"
#include "HalfLine.h"
#include "LineSegment.h"
#include "Circle.h"
#include "Vector2DArray.h"

namespace geo2d {

  template <class T>
  float Signed2DTriArea(const Vector2D<T>&,const Vector2D<T>&, const Vector2D<T>&);
  
  template <class T>
  bool SegmentSegmentTest(const LineSegment<T>&,const LineSegment<T>&,Vector2D<T>&);

  template <class T>
  Vector2DArray<float> Intersection(const Circle<T>& c, const LineSegment<T>& line);

  template <class T>
  Vector2DArray<float> Intersection(const Circle<T>& c, const HalfLine<T>& line);

  template <class T>
  Vector2DArray<float> Intersection(const Circle<T>& c, const Line<T>& line);

}


#endif
