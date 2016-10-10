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
  bool Intersection(const LineSegment<T>&,const LineSegment<T>&,Vector<T>&);
  
  template <class T>
  bool Intersection(const LineSegment<T>&,const LineSegment<T>&);

  template <class T>
  VectorArray<float> Intersection(const Circle<T>& c, const LineSegment<T>& line);

  template <class T>
  VectorArray<float> Intersection(const Circle<T>& c, const HalfLine<T>& line);

  template <class T>
  VectorArray<float> Intersection(const Circle<T>& c, const Line<T>& line);

  template <class T>
  Vector<float> Intersection(const Line<T>&, const Line<T>&);

  template <class T>
  Vector<float> ClosestPtOnLine(const Vector<T>& l_pt1, const Vector<T>& l_pt2, const Vector<T>& pt);
  
}


#endif
