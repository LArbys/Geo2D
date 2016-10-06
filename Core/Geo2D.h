#ifndef GEO2D_H
#define GEO2D_H

#include <LineSegment.h>

namespace geo2d {
  
  template <class T>
  inline float Signed2DTriArea(const Vector2D<T>& a,const Vector2D<T>& b, const Vector2D<T>& c)
  {
    return (a.x - c.x) * (b.y - c.y) - (a.y - c.y) * (b.x - c.x);
  }
  
  template <class T>
  /// Test if segments line1 and cd line2. If they do, compute and return
  //  the intersection position p
  inline bool SegmentSegmentTest(const LineSegment<T>& line1,
				 const LineSegment<T>& line2,
				 Vector2D<T>& inter_pt) {
    float t;
    float a1 = Signed2DTriArea(line1.p1, line1.p2, line2.p2);
    float a2 = Signed2DTriArea(line1.p1, line1.p2, line2.p1);
    if (a1 * a2 < 0.0f) {
      float a3 = Signed2DTriArea(line2.p1, line2.p2, line1.p1); 
      float a4 = a3 + a2 - a1;
      if (a3 * a4 < 0.0f) {
	t = a3 / (a3 - a4);
	inter_pt = line1.p1 + t * (line1.p2 - line1.p1);
	return true;
      }
    }
    return false;
  }
}


#endif
