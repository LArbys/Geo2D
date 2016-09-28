#ifndef OBOX_TEMPLATE_H
#define OBOX_TEMPLATE_H

#include "OBox.h"
#include "Core/spoon.h"

namespace geo2d {

  template <class T>
  OBox<T>::OBox()
  {}

  template <class T>
  OBox<T>::OBox(const T x_center, const T y_center, 
		const T x_dir, const T y_dir,
		const T width, const T height)
  {
    if(width<=0) throw spoon("Width must be a positive value");
    if(height<=0) throw spoon("Height must be a positive value");
    _center.x = x_center;
    _center.y = y_center;
    _axes.x = x_dir;
    _axes.y = y_dir;
    _width.x = width;
    _width.y = height;
    _axes /= _axes.length();
  }

  template <class T>
  OBox<T>::OBox(const Vector2D<T>& center, const Vector2D<T>& dir, const Vector2D<T>& width)
    : _center(center), _axes(dir), _width(width)
  {
    //std::cout << _width.x << " : " << _width.y << std::endl;
    _axes /= _axes.length();
    //if(_axes.x<0) { _axes.x *= -1; _axes.y *= -1; }
  }

  template <class T>
  OBox<T>::OBox(const std::vector<Vector2D<T> >& pts)
  {
    T minArea = std::numeric_limits<T>::max();
    // Loop through all edges; j trails i by 1, modulo numPts
    for (int i = 0, j = pts.size() - 1; i < pts.size(); j = i, i++) {
      // Get current edge e0 (e0x,e0y), normalized
      Vector2D<T> e0(pts[i].x - pts[j].x, pts[i].y - pts[j].y);
      e0 /= e0.length();
      // Get an axis e1 orthogonal to edge e0
      Vector2D<T> e1(-e0.y, e0.x); // = Perp2D(e0)
      // Loop through all points to get maximum extents
      T min0 = 0.0, min1 = 0.0, max0 = 0.0, max1 = 0.0;
      for (int k = 0; k < pts.size(); k++) {
	// Project points onto axes e0 and e1 and keep track // of minimum and maximum values along both axes Vector2D<T> d = pt[k] - pt[j];
	Vector2D<T> d = pts[k] - pts[j];
	T dot = d * e0;
	if (dot < min0) min0 = dot;
	if (dot > max0) max0 = dot;
	dot = d * e1;
	if (dot < min1) min1 = dot;
	if (dot > max1) max1 = dot;
      }
      T area = (max0 - min0) * (max1 - min1);
      // If best so far, remember area, center, and axes
      if (area < minArea) {
	minArea = area;
	_center = pts[j] + 0.5 * ((min0 + max0) * e0 + (min1 + max1) * e1);
	_axes.x= e0; _axes.y = e1;
	_width.x = (max0 - min0);
	_width.y = (max1 - min1);
      }
    }
  }
  
  template <class T>
  void OBox<T>::shift(T xshift, T yshift)
  { _center.x += xshift; _center.y += yshift; }

  template <class T>
  const Vector2D<T>& OBox<T>::center() const
  { return _center; }

  template <class T>
  const Vector2D<T>& OBox<T>::width()  const
  { return _width; }

  template <class T>
  const Vector2D<T>& OBox<T>::axes()   const
  { return _axes; }

  template <class T>
  T OBox<T>::xcenter() const
  { return _center.x; }

  template <class T>
  T OBox<T>::ycenter() const
  { return _center.y; }

  template <class T>
  T OBox<T>::angle() const
  { return _axes.angle(); }

  template <class T>
  T OBox<T>::xmax_from_center()    const
  {
    T len = sqrt(pow(_width.x,2)+pow(_width.y,2));
    double a1 = fabs(atan(_width.y/_width.x));
    double a2 = fabs(_axes.angle());
    double angle = fabs(a2 - a1);
    return len * cos(angle);
  }

  template <class T>
  T OBox<T>::xmax()    const
  { return (_center.x + xmax_from_center()); }

  template <class T>
  T OBox<T>::xmin()    const
  { return (_center.x - xmax_from_center()); }

  template <class T>
  T OBox<T>::ymax_from_center()    const
  {
    T len = sqrt(pow(_width.x,2)+pow(_width.y,2));
    double a1 = fabs(atan(_width.y/_width.x));
    double a2 = fabs(_axes.angle());
    double angle = fabs(a2 + a1);
    return len * sin(angle);
  }

  template <class T>
  T OBox<T>::ymax() const
  { return (_center.y + ymax_from_center()); }


  template <class T>
  Vector2D<T> OBox<T>::pt1() const
  {
    T len = _width.length();
    double angle_d = _width.angle();
    double angle_r = _axes.angle();
    //std::cout<<"Angle R " << angle_r << std::endl;
    //std::cout<<"Angle D " << angle_d << std::endl;
    Vector2D<T> pt;
    pt.x = _center.x + len * cos(angle_d + angle_r);
    pt.y = _center.y + len * sin(angle_d + angle_r);
    
    return pt;
  }

  template <class T>
  Vector2D<T> OBox<T>::pt2() const
  {
    T len = _width.length();
    double angle_d = _width.angle();
    double angle_r = _axes.angle();
    
    Vector2D<T> pt;
    pt.x = _center.x - len * cos(angle_d - angle_r);
    pt.y = _center.y + len * sin(angle_d - angle_r);
    return pt;
  }

  template <class T>
  Vector2D<T> OBox<T>::pt3() const
  {
    T len = _width.length();
    double angle_d = _width.angle();
    double angle_r = _axes.angle();
    Vector2D<T> pt;
    pt.x = _center.x + len * cos(angle_d + angle_r + M_PI);
    pt.y = _center.y + len * sin(angle_d + angle_r + M_PI);
    return pt;
  }

  template <class T>
  Vector2D<T> OBox<T>::pt4() const
  {
    T len = _width.length();
    double angle_d = _width.angle();
    double angle_r = _axes.angle();
    Vector2D<T> pt;
    pt.x = _center.x - len * cos(angle_d - angle_r + M_PI);
    pt.y = _center.y + len * sin(angle_d - angle_r + M_PI);
    return pt;
  }
  
  template <class T>
  std::vector<T> OBox<T>::as_vector() const
  {
    std::vector<T> dat(8);
    auto const p1 = pt1();
    auto const p2 = pt2();
    auto const p3 = pt3();
    auto const p4 = pt4();

    dat[0] = p1.x; dat[1] = p1.y;
    dat[2] = p2.x; dat[3] = p2.y;
    dat[4] = p3.x; dat[5] = p3.y;
    dat[6] = p4.x; dat[7] = p4.y;
    return dat;
  }


  template <class T>
  bool OBox<T>::Contain(const Vector2D<T> &pt) const
  {
    //
    // Box is aligned
    //
    double theta = angle();
    std::cout << "theta: " << theta << std::endl;
    static const double min_angle = 1.e-5;
    if( (-min_angle < theta && theta < min_angle)
	||
	((M_PI - min_angle) < theta && theta < (M_PI + min_angle)) )
      {
	std::cout<<"alingned case 1" << std::endl;
	// no rotation => width and height tells us
	if(pt.y > (_center.y + _width.y)) return false;
	if(pt.y < (_center.y - _width.y)) return false;
	if(pt.x > (_center.x + _width.x)) return false;
	if(pt.x < (_center.x - _width.x)) return false;
	return true;
      }

    if( ((M_PI/2. - min_angle) < theta && theta < (M_PI/2. + min_angle))
	||
	((M_PI*1.5 - min_angle) < theta && theta < (M_PI*1.5 + min_angle)) )
      {
	std::cout<<"alingned case 2" << std::endl;
	// no rotation => width and height tells us
	if(pt.y > (_center.y + _width.x)) return false;
	if(pt.y < (_center.y - _width.x)) return false;
	if(pt.x > (_center.x + _width.y)) return false;
	if(pt.x < (_center.x - _width.y)) return false;
	return true;
      }
    
    //
    // Has some slope
    //
    auto const p1 = pt1();
    auto const p2 = pt2();
    auto const p3 = pt3();
    auto const p4 = pt4();

    T slope1 = (p2.y - p1.y) / (p2.x - p1.x);

    if(p1.y > p4.y) {
      std::cout<<"nonalingned case 1" << std::endl;
      if(pt.y > slope1 * pt.x + (p1.y - slope1 * p1.x)) return false;
      if(pt.y < slope1 * pt.x + (p4.y - slope1 * p4.x)) return false;
    }else{
      std::cout<<"nonalingned case 2" << std::endl;
      if(pt.y > slope1 * pt.x + (p4.y - slope1 * p4.x)) return false;
      if(pt.y < slope1 * pt.x + (p1.y - slope1 * p1.x)) return false;
    }

    T slope2 = (p1.y - p4.y) / (p1.x - p4.x);
    
    if(p2.y > p1.y) {
      std::cout<<"nonalingned case 3" << std::endl;
      std::cout<<slope2 * pt.x + (p1.y - slope2 * p1.x)<< " => " << slope2 * pt.x + (p2.y - slope2 * p2.x) << std::endl;
      if(pt.y > slope2 * pt.x + (p2.y - slope2 * p2.x)) return false;
      if(pt.y < slope2 * pt.x + (p1.y - slope2 * p1.x)) return false;
    }else{
      std::cout<<"nonalingned case 4" << std::endl;
      std::cout<<slope2 * pt.x + (p2.y - slope2 * p2.x)<< " => " << slope2 * pt.x + (p1.y - slope2 * p1.x) << std::endl;
      if(pt.y > slope2 * pt.x + (p1.y - slope2 * p1.x)) return false;
      if(pt.y < slope2 * pt.x + (p2.y - slope2 * p2.x)) return false;
    }
    return true;
  }
  
}
#endif
