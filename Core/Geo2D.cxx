#ifndef GEO2D_CXX
#define GEO2D_CXX

#include "Geo2D.h"
#include "Geo2D.imp.h"

namespace geo2d {

  template float Signed2DTriArea(const Vector2D<double>& a,const Vector2D<double>& b, const Vector2D<double>& c);
  template float Signed2DTriArea(const Vector2D<float >& a,const Vector2D<float >& b, const Vector2D<float >& c);
  template float Signed2DTriArea(const Vector2D<int   >& a,const Vector2D<int   >& b, const Vector2D<int   >& c);
  template float Signed2DTriArea(const Vector2D<short >& a,const Vector2D<short >& b, const Vector2D<short >& c);

  template bool SegmentIntersection(const LineSegment<double>& a,const LineSegment<double>& b, Vector2D<double>& inter_pt);
  template bool SegmentIntersection(const LineSegment<float >& a,const LineSegment<float >& b, Vector2D<float >& inter_pt);
  template bool SegmentIntersection(const LineSegment<int   >& a,const LineSegment<int   >& b, Vector2D<int   >& inter_pt);
  template bool SegmentIntersection(const LineSegment<short >& a,const LineSegment<short >& b, Vector2D<short >& inter_pt);


  template bool SegmentIntersection(const Vector2D<double>& a, const Vector2D<double>& b, const Vector2D<double>& c, const Vector2D<double>& d);
  template bool SegmentIntersection(const Vector2D<float>& a, const Vector2D<float>& b, const Vector2D<float>& c, const Vector2D<float>& d);
  template bool SegmentIntersection(const Vector2D<int>& a, const Vector2D<int>& b, const Vector2D<int>& c, const Vector2D<int>& d);
  template bool SegmentIntersection(const Vector2D<short>& a, const Vector2D<short>& b, const Vector2D<short>& c, const Vector2D<short>& d);

  
  template bool SegmentIntersection(const Vector2D<double>& a,
				    const Vector2D<double>& b,
				    const Vector2D<double>& c,
				    const Vector2D<double>& d,
				    Vector2D<double>& inter_pt);
  
  template bool SegmentIntersection(const Vector2D<float>& a,
				    const Vector2D<float>& b,
				    const Vector2D<float>& c,
				    const Vector2D<float>& d,
				    Vector2D<float>& inter_pt);
  
  template bool SegmentIntersection(const Vector2D<int>& a,
				    const Vector2D<int>& b,
				    const Vector2D<int>& c,
				    const Vector2D<int>& d,
				    Vector2D<int>& inter_pt);
  
  template bool SegmentIntersection(const Vector2D<short>& a,
				    const Vector2D<short>& b,
				    const Vector2D<short>& c,
				    const Vector2D<short>& d,
				    Vector2D<short>& inter_pt);

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



  template Vector2D<float> LineIntersect(const Vector2D<double>& v1, const Vector2D<double>& v2, const Vector2D<double>& v3, const Vector2D<double>& v4);
  template Vector2D<float> LineIntersect(const Vector2D<float >& v1, const Vector2D<float >& v2, const Vector2D<float >& v3, const Vector2D<float >& v4);
  template Vector2D<float> LineIntersect(const Vector2D<int   >& v1, const Vector2D<int   >& v2, const Vector2D<int   >& v3, const Vector2D<int   >& v4);
  template Vector2D<float> LineIntersect(const Vector2D<short >& v1, const Vector2D<short >& v2, const Vector2D<short >& v3, const Vector2D<short >& v4);

  template Vector2D<float> ClosestPtOnLine(const Vector2D<double>& l_pt1, const Vector2D<double>& l_pt2, const Vector2D<double>& pt);
  template Vector2D<float> ClosestPtOnLine(const Vector2D<float >& l_pt1, const Vector2D<float >& l_pt2, const Vector2D<float  >& pt);
  template Vector2D<float> ClosestPtOnLine(const Vector2D<int   >& l_pt1, const Vector2D<int   >& l_pt2, const Vector2D<int      >& pt);
  template Vector2D<float> ClosestPtOnLine(const Vector2D<short >& l_pt1, const Vector2D<short >& l_pt2, const Vector2D<short  >& pt);
  
  

}
#endif
