#ifndef GEO2DIMP_H
#define GEO2DIMP_H

#include <LineSegment.h>

namespace geo2d {
  
  template <class T>
  float Signed2DTriArea(const Vector2D<T>& a,const Vector2D<T>& b, const Vector2D<T>& c)
  { return (a.x - c.x) * (b.y - c.y) - (a.y - c.y) * (b.x - c.x); }
  
  template <class T>
  bool SegmentIntersection(const LineSegment<T>& line1,const LineSegment<T>& line2,Vector2D<T>& inter_pt) {
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
  bool SegmentIntersection(const Vector2D<T>& a,const Vector2D<T>& b,const Vector2D<T>& c,const Vector2D<T>& d) {
    float t;
    float a1 = Signed2DTriArea(a,b,d);
    float a2 = Signed2DTriArea(a,b,c);
    if (a1 * a2 < 0.0f) {
      float a3 = Signed2DTriArea(c,d,a);
      float a4 = a3 + a2 - a1;
      if (a3 * a4 < 0.0f) {
	t = a3 / (a3 - a4);
	return 1;
      }
    }
    return 0;
  }

  template <class T>
  bool SegmentIntersection(const Vector2D<T>& a,const Vector2D<T>& b,const Vector2D<T>& c,const Vector2D<T>& d,Vector2D<T>& inter_pt) {
    float t;
    float a1 = Signed2DTriArea(a,b,d);
    float a2 = Signed2DTriArea(a,b,c);
    if (a1 * a2 < 0.0f) {
      float a3 = Signed2DTriArea(c,d,a);
      float a4 = a3 + a2 - a1;
      if (a3 * a4 < 0.0f) {
	t = a3 / (a3 - a4);
	inter_pt = a + t * (b - a);
	return 1;
      }
    }
    return 0;
  }
  

  
  template <class T>
  Vector2DArray<float> Intersection(const Circle<T>& circle, const HalfLine<T>& line)
  {
    Vector2DArray<float> res;
    Vector2D<float> d, pt, center;
    d.x  = line.dir.x;  d.y = line.dir.y;
    pt.x = line.pt.x;  pt.y = line.pt.y;
    center.x = circle.center.x;
    center.y = circle.center.y;

    auto const  m = pt - center;
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
      res.push_back(pt + d * mag);
    }
    mag = -b + discr;
    if(mag>0){
      res.push_back(pt + d * mag);
    }
    return res;    
  }

  template <class T>
  Vector2DArray<float> Intersection(const Circle<T>& circle, const LineSegment<T>& line)
  {
    Vector2DArray<float> res;
    Vector2D<float> d, pt, center;
    d.x = line.pt2.x - line.pt1.x;
    d.y = line.pt2.y - line.pt1.y;
    d /= geo2d::length(d);
    pt.x = line.pt1.x;  pt.y = line.pt1.y;
    center.x = circle.center.x;
    center.y = circle.center.y;
    
    auto const  m = pt - center;
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
      res.push_back(pt + d * mag);
    }
    mag = -b + discr;
    if(mag>0 && mag < length(line)) {
      res.push_back(pt + d * mag);
    }
    return res;    
  }

  template <class T>
  Vector2DArray<float> Intersection(const Circle<T>& circle, const Line<T>& line)
  {
    Vector2DArray<float> res;
    Vector2D<float> d, pt, center;
    d.x  = line.dir.x;  d.y = line.dir.y;
    pt.x = line.pt.x;  pt.y = line.pt.y;
    center.x = circle.center.x;
    center.y = circle.center.y;
    
    auto const  m = pt - center;
    float b = m.dot(d);
    float c = m.dot(m) - circle.radius * circle.radius;
    float discr = b*b - c;
    // A negative discriminant corresponds to a line missing circle
    if (discr < 0.0f) return res;
    // Line now found to intersect circle, compute intersection point(s)
    discr = sqrt(discr);
    if(discr==0.0f) {
      res.push_back(pt - d * b);
    }else{
      res.resize(2);
      res[0] = pt + d * (-b - discr);
      res[1] = pt + d * (-b + discr);
    }
    return res;    
  }


  template <class T>
  Vector2D<float> LineIntersect(const Vector2D<T>& v1, const Vector2D<T>& v2, const Vector2D<T>& v3, const Vector2D<T>& v4){
    float d   = (v1.x-v2.x)*(v3.y-v4.y) - (v1.y-v2.y)*(v3.x-v4.x);
    float x = ( (v1.x*v2.y - v1.y*v2.x)*(v3.x-v4.x) - (v1.x-v2.x)*(v3.x*v4.y-v3.y*v4.x) ) / d;
    float y = ( (v1.x*v2.y - v1.y*v2.x)*(v3.y-v4.y) - (v1.y-v2.y)*(v3.x*v4.y-v3.y*v4.x) ) / d;
    return geo2d::Vector2D<float>(x,y);
  }

  template <class T>
  Vector2D<float> ClosestPtOnLine(const Vector2D<T>& l_pt1, const Vector2D<T>& l_pt2, const Vector2D<T>& pt) {
    float k  = ((l_pt2.y-l_pt1.y) * (pt.x-l_pt1.x) - (l_pt2.x-l_pt1.x) * (pt.y-l_pt1.y))
      / (std::pow(l_pt2.y-l_pt1.y,2) + std::pow(l_pt2.x-l_pt1.x,2));
    
    float x4 = pt.x - k * (l_pt2.y-l_pt1.y);
    float y4 = pt.y + k * (l_pt2.x-l_pt1.x);
    
    return geo2d::Vector2D<float>(x4,y4);
  }
  
}


#endif
