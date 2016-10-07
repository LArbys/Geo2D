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

  template <class T>
  Vector2DArray<float> Intersection(const Circle<T>& circle, const HalfLine<T>& line)
  {
    Vector2DArray<float> res;
    auto const& d  = line.dir;
    auto const& pt = line.pt;
    
    auto const  m = pt - circle.center;
    float b = m.dot(d);
    float c = m.dot(m) - circle.radius * circle.radius;
    // Exit if line's origin outside circle (c > 0) and line pointing away from circle (b > 0)
    if(c > 0.0f && b > 0.0f) return res;
    float discr = b*b - c;
    // A negative discriminant corresponds to a line missing circle
    if (discr < 0.0f) return res;
    // Line now found to intersect circle, compute intersection point(s)
    discr = sqrt(discr);
    float mag = -b - discr;
    if(mag>=0) {
      res.push_back(pt + line.dir * mag);
    }
    mag = -b + discr;
    if(mag>0){
      res.push_back(pt + line.dir * mag);
    }
    return res;    
  }

  template <class T>
  Vector2DArray<T> Intersection(const Circle<T>& circle, const LineSegment<T>& line)
  {
    Vector2DArray<float> res;
    auto const& d  = geo2d::dir(line);
    auto const& pt = line.pt1;
    
    auto const  m = pt - circle.center;
    float b = m.dot(d);
    float c = m.dot(m) - circle.radius * circle.radius;
    // Exit if line's origin outside circle (c > 0) and line pointing away from circle (b > 0)
    if(c > 0.0f && b > 0.0f) return res;
    float discr = b*b - c;
    // A negative discriminant corresponds to a line missing circle
    if (discr < 0.0f) return res;
    // Line now found to intersect circle, compute intersection point(s)
    discr = sqrt(discr);
    float mag = -b - discr;
    if(mag>=0 && mag < length(line)) {
      res.push_back(pt + line.dir * mag);
    }
    mag = -b + discr;
    if(mag>0 && mag < length(line)) {
      res.push_back(pt + line.dir * mag);
    }
    return res;    
  }

  template <class T>
  Vector2DArray<T> Intersection(const Circle<T>& circle, const Line<T>& line)
  {
    Vector2DArray<float> res;
    auto const& d = geo2d::dir(line);
    auto const pt = Vector2D<T>();
    pt.x = 0; pt.y = line.offset;
    
    auto const  m = pt - circle.center;
    float b = m.dot(d);
    float c = m.dot(m) - circle.radius * circle.radius;
    float discr = b*b - c;
    // A negative discriminant corresponds to a line missing circle
    if (discr < 0.0f) return res;
    // Line now found to intersect circle, compute intersection point(s)
    discr = sqrt(discr);
    if(discr==0.0f) {
      res.push_back(pt - b * line.dir );
    }else{
      res.resize(2);
      res[0] = pt + line.dir * (-b - discr);
      res[1] = pt + line.dir * (-b + discr);
    }
    return res;    
  }

}


#endif
