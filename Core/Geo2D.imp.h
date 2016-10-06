#ifndef GEO2DIMP_H
#define GEO2DIMP_H

#include <LineSegment.h>

namespace geo2d {
  
  template <class T>
  float Signed2DTriArea(const Vector2D<T>& a,const Vector2D<T>& b, const Vector2D<T>& c)
  { return (a.x - c.x) * (b.y - c.y) - (a.y - c.y) * (b.x - c.x); }
  
  template <class T>
  bool SegmentSegmentTest(const LineSegment<T>& line1,const LineSegment<T>& line2,Vector2D<T>& inter_pt) {
    float t;
    float a1 = Signed2DTriArea(line1.pt1, line1.pt2, line2.pt2);
    float a2 = Signed2DTriArea(line1.pt1, line1.pt2, line2.pt1);
    if (a1 * a2 < 0.0f) {
      float a3 = Signed2DTriArea(line2.pt1, line2.pt2, line1.pt1); 
      float a4 = a3 + a2 - a1;
      if (a3 * a4 < 0.0f) {
	t = a3 / (a3 - a4);
	inter_pt = line1.pt1 + t * (line1.pt2 - line1.pt1);
	return true;
      }
    }
    return false;
  }
  
}


#endif
