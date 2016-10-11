#ifndef GEO2D_CXX
#define GEO2D_CXX

#include "Geo2D.h"
#include "Geo2D.imp.h"

namespace geo2d {

  template float Signed2DTriArea(const Vector<double>& a,const Vector<double>& b, const Vector<double>& c);
  template float Signed2DTriArea(const Vector<float >& a,const Vector<float >& b, const Vector<float >& c);
  template float Signed2DTriArea(const Vector<int   >& a,const Vector<int   >& b, const Vector<int   >& c);
  template float Signed2DTriArea(const Vector<short >& a,const Vector<short >& b, const Vector<short >& c);

  template bool Intersect(const LineSegment<double>& line1,const LineSegment<double>& line2);
  template bool Intersect(const LineSegment<float >& line1,const LineSegment<float >& line2);
  template bool Intersect(const LineSegment<int   >& line1,const LineSegment<int   >& line2);
  template bool Intersect(const LineSegment<short >& line1,const LineSegment<short >& line2);

  template bool IntersectionPoint(const LineSegment<double>& line1,const LineSegment<double>& line2, Vector<double>& inter_pt);
  template bool IntersectionPoint(const LineSegment<float >& line1,const LineSegment<float >& line2, Vector<float >& inter_pt);
  template bool IntersectionPoint(const LineSegment<int   >& line1,const LineSegment<int   >& line2, Vector<int   >& inter_pt);
  template bool IntersectionPoint(const LineSegment<short >& line1,const LineSegment<short >& line2, Vector<short >& inter_pt);

  template VectorArray<float> IntersectionPoint(const Circle<double>& c, const LineSegment<double>& line);
  template VectorArray<float> IntersectionPoint(const Circle<float >& c, const LineSegment<float >& line);
  template VectorArray<float> IntersectionPoint(const Circle<int   >& c, const LineSegment<int   >& line);
  template VectorArray<float> IntersectionPoint(const Circle<short >& c, const LineSegment<short >& line);

  template VectorArray<float> IntersectionPoint(const Circle<double>& c, const Line<double>& line);
  template VectorArray<float> IntersectionPoint(const Circle<float >& c, const Line<float >& line);
  template VectorArray<float> IntersectionPoint(const Circle<int   >& c, const Line<int   >& line);
  template VectorArray<float> IntersectionPoint(const Circle<short >& c, const Line<short >& line);

  template VectorArray<float> IntersectionPoint(const Circle<double>& c, const HalfLine<double>& line);
  template VectorArray<float> IntersectionPoint(const Circle<float >& c, const HalfLine<float >& line);
  template VectorArray<float> IntersectionPoint(const Circle<int   >& c, const HalfLine<int   >& line);
  template VectorArray<float> IntersectionPoint(const Circle<short >& c, const HalfLine<short >& line);

  template Vector<float> IntersectionPoint(const Line<double>& line1, const Line<double>& line2);
  template Vector<float> IntersectionPoint(const Line<float >& line1, const Line<float >& line2);
  template Vector<float> IntersectionPoint(const Line<int   >& line1, const Line<int   >& line2);
  template Vector<float> IntersectionPoint(const Line<short >& line1, const Line<short >& line2);
  
  template float ClosestPoint(const LineSegment<double>& line, const Vector<double>& pt, Vector<double>& pt1, Vector<double>& pt2);
  template float ClosestPoint(const LineSegment<float >& line, const Vector<float >& pt, Vector<float >& pt1, Vector<float >& pt2);
  template float ClosestPoint(const LineSegment<int   >& line, const Vector<int   >& pt, Vector<int   >& pt1, Vector<int   >& pt2);
  template float ClosestPoint(const LineSegment<short >& line, const Vector<short >& pt, Vector<short >& pt1, Vector<short >& pt2);

  template float ClosestPoint(const HalfLine<double>& line, const Vector<double>& pt, Vector<double>& pt1, Vector<double>& pt2);
  template float ClosestPoint(const HalfLine<float >& line, const Vector<float >& pt, Vector<float >& pt1, Vector<float >& pt2);
  template float ClosestPoint(const HalfLine<int   >& line, const Vector<int   >& pt, Vector<int   >& pt1, Vector<int   >& pt2);
  template float ClosestPoint(const HalfLine<short >& line, const Vector<short >& pt, Vector<short >& pt1, Vector<short >& pt2);
  
  template float ClosestPoint(const Line<double>& line, const Vector<double>& pt, Vector<double>& pt1, Vector<double>& pt2);
  template float ClosestPoint(const Line<float >& line, const Vector<float >& pt, Vector<float >& pt1, Vector<float >& pt2);
  template float ClosestPoint(const Line<int   >& line, const Vector<int   >& pt, Vector<int   >& pt1, Vector<int   >& pt2);
  template float ClosestPoint(const Line<short >& line, const Vector<short >& pt, Vector<short >& pt1, Vector<short >& pt2);

}
#endif
