#ifndef GEO2D_CXX
#define GEO2D_CXX

#include "Geo2D.h"
#include "Geo2D.imp.h"

namespace geo2d {

  template float Signed2DTriArea(const Vector<double>& a,const Vector<double>& b, const Vector<double>& c);
  template float Signed2DTriArea(const Vector<float >& a,const Vector<float >& b, const Vector<float >& c);
  template float Signed2DTriArea(const Vector<int   >& a,const Vector<int   >& b, const Vector<int   >& c);
  template float Signed2DTriArea(const Vector<short >& a,const Vector<short >& b, const Vector<short >& c);

  template bool SegmentIntersection(const LineSegment<double>& a,const LineSegment<double>& b, Vector<double>& inter_pt);
  template bool SegmentIntersection(const LineSegment<float >& a,const LineSegment<float >& b, Vector<float >& inter_pt);
  template bool SegmentIntersection(const LineSegment<int   >& a,const LineSegment<int   >& b, Vector<int   >& inter_pt);
  template bool SegmentIntersection(const LineSegment<short >& a,const LineSegment<short >& b, Vector<short >& inter_pt);


  template bool SegmentIntersection(const Vector<double>& a, const Vector<double>& b, const Vector<double>& c, const Vector<double>& d);
  template bool SegmentIntersection(const Vector<float>& a, const Vector<float>& b, const Vector<float>& c, const Vector<float>& d);
  template bool SegmentIntersection(const Vector<int>& a, const Vector<int>& b, const Vector<int>& c, const Vector<int>& d);
  template bool SegmentIntersection(const Vector<short>& a, const Vector<short>& b, const Vector<short>& c, const Vector<short>& d);

  
  template bool SegmentIntersection(const Vector<double>& a,
				    const Vector<double>& b,
				    const Vector<double>& c,
				    const Vector<double>& d,
				    Vector<double>& inter_pt);
  
  template bool SegmentIntersection(const Vector<float>& a,
				    const Vector<float>& b,
				    const Vector<float>& c,
				    const Vector<float>& d,
				    Vector<float>& inter_pt);
  
  template bool SegmentIntersection(const Vector<int>& a,
				    const Vector<int>& b,
				    const Vector<int>& c,
				    const Vector<int>& d,
				    Vector<int>& inter_pt);
  
  template bool SegmentIntersection(const Vector<short>& a,
				    const Vector<short>& b,
				    const Vector<short>& c,
				    const Vector<short>& d,
				    Vector<short>& inter_pt);

  template VectorArray<float> Intersection(const Circle<double>& c, const LineSegment<double>& line);
  template VectorArray<float> Intersection(const Circle<float >& c, const LineSegment<float >& line);
  template VectorArray<float> Intersection(const Circle<int   >& c, const LineSegment<int   >& line);
  template VectorArray<float> Intersection(const Circle<short >& c, const LineSegment<short >& line);

  template VectorArray<float> Intersection(const Circle<double>& c, const Line<double>& line);
  template VectorArray<float> Intersection(const Circle<float >& c, const Line<float >& line);
  template VectorArray<float> Intersection(const Circle<int   >& c, const Line<int   >& line);
  template VectorArray<float> Intersection(const Circle<short >& c, const Line<short >& line);

  template VectorArray<float> Intersection(const Circle<double>& c, const HalfLine<double>& line);
  template VectorArray<float> Intersection(const Circle<float >& c, const HalfLine<float >& line);
  template VectorArray<float> Intersection(const Circle<int   >& c, const HalfLine<int   >& line);
  template VectorArray<float> Intersection(const Circle<short >& c, const HalfLine<short >& line);



  template Vector<float> LineIntersect(const Vector<double>& v1, const Vector<double>& v2, const Vector<double>& v3, const Vector<double>& v4);
  template Vector<float> LineIntersect(const Vector<float >& v1, const Vector<float >& v2, const Vector<float >& v3, const Vector<float >& v4);
  template Vector<float> LineIntersect(const Vector<int   >& v1, const Vector<int   >& v2, const Vector<int   >& v3, const Vector<int   >& v4);
  template Vector<float> LineIntersect(const Vector<short >& v1, const Vector<short >& v2, const Vector<short >& v3, const Vector<short >& v4);

  template Vector<float> ClosestPtOnLine(const Vector<double>& l_pt1, const Vector<double>& l_pt2, const Vector<double>& pt);
  template Vector<float> ClosestPtOnLine(const Vector<float >& l_pt1, const Vector<float >& l_pt2, const Vector<float  >& pt);
  template Vector<float> ClosestPtOnLine(const Vector<int   >& l_pt1, const Vector<int   >& l_pt2, const Vector<int      >& pt);
  template Vector<float> ClosestPtOnLine(const Vector<short >& l_pt1, const Vector<short >& l_pt2, const Vector<short  >& pt);
  
  

}
#endif
