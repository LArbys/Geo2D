#ifndef GEO2D_H
#define GEO2D_H

#include "Line.h"
#include "HalfLine.h"
#include "LineSegment.h"
#include "Circle.h"
#include "VectorArray.h"

namespace geo2d {

  template <class T>
  float Signed2DTriArea(const Vector<T>&,const Vector<T>&, const Vector<T>&);

  template <class T>
  bool Intersection(const LineSegment<T>& line1,const LineSegment<T>& line2);

  template <class T>
  bool Intersection(const LineSegment<T>& line1,const LineSegment<T>& line2,Vector<T>& inter_pt);

  template <class T>
  VectorArray<float> Intersection(const Circle<T>& c, const LineSegment<T>& line);

  template <class T>
  VectorArray<float> Intersection(const Circle<T>& c, const HalfLine<T>& line);

  template <class T>
  VectorArray<float> Intersection(const Circle<T>& c, const Line<T>& line);

  template <class T>
  Vector<float> Intersection(const Line<T>& line1, const Line<T>& line2);

  template <class T>
  float ClosestPoint(const LineSegment<T>& line, const Vector<T>& pt, Vector<T>& pt1, Vector<T>& pt2);

  template <class T>
  float ClosestPoint(const HalfLine<T>& line, const Vector<T>& pt, Vector<T>& pt1, Vector<T>& pt2);

  template <class T>
  float ClosestPoint(const Line<T>& line, const Vector<T>& pt, Vector<T>& pt1, Vector<T>& pt2);
  
}


#endif
