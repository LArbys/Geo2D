#ifndef GEO2DIMP_H
#define GEO2DIMP_H

#include <LineSegment.h>

namespace geo2d {
  
  template <class T>
  float Signed2DTriArea(const Vector<T>& a,const Vector<T>& b, const Vector<T>& c)
  { return (a.x - c.x) * (b.y - c.y) - (a.y - c.y) * (b.x - c.x); }
  
  template <class T>
  bool Intersection(const LineSegment<T>& line1,const LineSegment<T>& line2,Vector<T>& inter_pt) {
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
  bool Intersection(const LineSegment<T>& line1,const LineSegment<T>& line2) {
    float t;
    float a1 = Signed2DTriArea(line1.pt1, line1.pt2, line2.pt2);
    float a2 = Signed2DTriArea(line1.pt1, line1.pt2, line2.pt1);
    if (a1 * a2 < 0.0f) {
      float a3 = Signed2DTriArea(line2.pt1, line2.pt2, line1.pt1); 
      float a4 = a3 + a2 - a1;
      if (a3 * a4 < 0.0f) {
	t = a3 / (a3 - a4);
	return true;
      }
    }
    return false;
  }
  
  
  template <class T>
  VectorArray<float> Intersection(const Circle<T>& circle, const HalfLine<T>& line)
  {
    VectorArray<float> res;
    Vector<float> d, pt, center;
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
  VectorArray<float> Intersection(const Circle<T>& circle, const LineSegment<T>& line)
  {
    VectorArray<float> res;
    Vector<float> d, pt, center;
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
  VectorArray<float> Intersection(const Circle<T>& circle, const Line<T>& line)
  {
    VectorArray<float> res;
    Vector<float> d, pt, center;
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
  Vector<float> Intersection(const Line<T>& line1, const Line<T>& line2) {

    float t = (line1.dir.x - line2.dir.x) / (line2.pt.x - line1.pt.x);
    float px = line1.pt.x + line1.dir.x*t;
    float py = line1.pt.y + line1.dir.y*t;
    
    return Vector<float>(px,py);
  }

  template <class T>
  Vector<float> ClosestPtOnLine(const Vector<T>& l_pt1, const Vector<T>& l_pt2, const Vector<T>& pt) {
    float k  = ((l_pt2.y-l_pt1.y) * (pt.x-l_pt1.x) - (l_pt2.x-l_pt1.x) * (pt.y-l_pt1.y))
      / (std::pow(l_pt2.y-l_pt1.y,2) + std::pow(l_pt2.x-l_pt1.x,2));
    
    float x4 = pt.x - k * (l_pt2.y-l_pt1.y);
    float y4 = pt.y + k * (l_pt2.x-l_pt1.x);
    
    return geo2d::Vector<float>(x4,y4);
  }
  
}


#endif
