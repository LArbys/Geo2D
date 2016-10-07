#ifndef GEO2D_CXX
#define GEO2D_CXX

#include "Geo2D.h"
#include "Geo2D.imp.h"

namespace geo2d {

  template float Signed2DTriArea(const Vector2D<double>& a,const Vector2D<double>& b, const Vector2D<double>& c);
  template float Signed2DTriArea(const Vector2D<float >& a,const Vector2D<float >& b, const Vector2D<float >& c);
  template float Signed2DTriArea(const Vector2D<int   >& a,const Vector2D<int   >& b, const Vector2D<int   >& c);
  template float Signed2DTriArea(const Vector2D<short >& a,const Vector2D<short >& b, const Vector2D<short >& c);

  template bool SegmentSegmentTest(const LineSegment<double>& a,const LineSegment<double>& b, Vector2D<double>& c);
  template bool SegmentSegmentTest(const LineSegment<float >& a,const LineSegment<float >& b, Vector2D<float >& c);
  template bool SegmentSegmentTest(const LineSegment<int   >& a,const LineSegment<int   >& b, Vector2D<int   >& c);
  template bool SegmentSegmentTest(const LineSegment<short >& a,const LineSegment<short >& b, Vector2D<short >& c);

  template Vector2DArray<float> Intersection(const Circle<double>& c, const LineSegment<double>& line);
  template Vector2DArray<float> Intersection(const Circle<float >& c, const LineSegment<float >& line);
  template Vector2DArray<float> Intersection(const Circle<int   >& c, const LineSegment<int   >& line);
  template Vector2DArray<float> Intersection(const Circle<short >& c, const LineSegment<short >& line);

  template Vector2DArray<float> Intersection(const Circle<double>& c, const Line<double>& line);
  template Vector2DArray<float> Intersection(const Circle<float >& c, const Line<float >& line);
  template Vector2DArray<float> Intersection(const Circle<int   >& c, const Line<int   >& line);
  template Vector2DArray<float> Intersection(const Circle<short >& c, const Line<short >& line);

  template Vector2DArray<float> Intersection(const Circle<double>& c, const HalfLine<double>& line);
  template Vector2DArray<float> Intersection(const Circle<float >& c, const HalfLine<float >& line);
  template Vector2DArray<float> Intersection(const Circle<int   >& c, const HalfLine<int   >& line);
  template Vector2DArray<float> Intersection(const Circle<short >& c, const HalfLine<short >& line);

}
#endif
