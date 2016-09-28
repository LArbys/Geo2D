#ifndef AABOX_TEMPLATE_H
#define AABOX_TEMPLATE_H

#include "AABox.h"
#include "Core/spoon.h"

namespace geo2d {

  template <class T>
  AABox<T>::AABox()
    : _min()
    , _width()
  {}

  template <class T>
  AABox<T>::AABox(const T x_min,   const T y_min,
		  const T x_width, const T y_width)
    : _min   ( x_min,   y_min   )
    , _width ( x_width, y_width )
  {
    if(x_width<=0) throw spoon("AABox x width <= 0");
    if(y_width<=0) throw spoon("AABox y width <= 0");
  }

  template <class T>
  AABox<T>::AABox(const Vector2D<T>& min, const Vector2D<T>& width)
    : _min   ( min   )
    , _width ( width )
  {
    if(_width.x < 0) throw spoon("AABox x width <= 0");
    if(_width.y < 0) throw spoon("AABox y width <= 0");
  }

  template <class T>
  AABox<T>::AABox(const std::vector<Vector2D<T> >& pts)
  {
    if(pts.size() < 2) throw spoon("AABox cannot be created from 1 point");
    T xmin, xmax, ymin, ymax;
    xmin = xmax = pts[0].x;
    ymin = ymax = pts[0].y;

    for(auto const& pt : pts) {
      if(pt.x < xmin) xmin = pt.x;
      if(pt.x > xmax) xmax = pt.x;
      if(pt.y < ymin) ymin = pt.y;
      if(pt.y > ymax) ymax = pt.y;
    }
    if(xmin == xmax) throw spoon("Min/Max X value is same: cannot create AABox!");
    if(ymin == ymax) throw spoon("Min/Max Y value is same: cannot create AABox!");
    _min.x = xmin;
    _min.y = ymin;
    _width.x = xmax - xmin;
    _width.y = ymax - ymin;
  }
  
  template <class T>
  void AABox<T>::min(const T x, const T y)
  { _min.x = x; _min.y = y; }

  template <class T>
  void AABox<T>::width(const T x, const T y)
  {
    if(x <= 0) throw spoon("AABox x width <= 0!");
    if(y <= 0) throw spoon("AABox y width <= 0!");
    _width.x = x; _width.y = y;
  }

  template <class T>
  void AABox<T>::shift(const T dx, const T dy)
  { _min.x += dx; _min.y += dy; }

  template <class T>
  const Vector2D<T>& AABox<T>::min() const { return _min; }

  template <class T>
  T AABox<T>::xwidth() const { return _width.x; }

  template <class T>
  T AABox<T>::ywidth() const { return _width.y; }

  template <class T>
  T AABox<T>::xcenter() const { return (_min.x + _width.x / 2.); }

  template <class T>
  T AABox<T>::ycenter() const { return (_min.y + _width.y / 2.); }

  template <class T>
  T AABox<T>::xmin() const { return _min.x; }

  template <class T>
  T AABox<T>::ymin() const { return _min.y; }

  template <class T>
  T AABox<T>::xmax() const { return (_min.x + _width.x); }

  template <class T>
  T AABox<T>::ymax() const { return (_min.y + _width.y); }

  template <class T>
  bool AABox<T>::contain(const Vector2D<T> &pt) const {
    return !( (pt.x < _min.x || (_min.x + _width.x) < pt.x) // vector is outside X boundaries OR
	      || 
	      (pt.y < _min.y || (_min.y + _width.y) < pt.y) // vector is outside Y boundaries 
	      );
  }

  template <class T>
  std::vector<T> AABox<T>::as_vector() const
  {
    std::vector<T> dat(8);
    dat[0] = this->xmin(); dat[1] = this->ymin();
    dat[2] = this->xmin(); dat[3] = this->ymax();
    dat[4] = this->xmax(); dat[5] = this->ymax();
    dat[6] = this->xmax(); dat[7] = this->ymin();
    return dat;
  }
}
#endif
