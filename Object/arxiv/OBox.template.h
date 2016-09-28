#ifndef OBOX_TEMPLATE_H
#define OBOX_TEMPLATE_H

namespace geo2d {

  template <class T>
  OBox<T>::OBox()
  {}

  template <class T>
  OBox<T>::~OBox()
  {}

  template <class T>
  OBox<T>::OBox(const T x_center, const T y_center, 
		const T x_dir, const T y_dir,
		const T width, const T height)
  {
    _center.x = x_center;
    _center.y = y_center;
    _dir.x = x_dir;
    _dir.y = y_dir;
    _width.x = width;
    _width.y = height;
    _dir /= _dir.length();
  }

  template <class T>
  OBox<T>::OBox(const Vector<T>& center, const Vector<T>& dir, const Vector<T>& width)
    : _center(center), _dir(dir), _width(width)
  { _width /= _width.length(); }

  template <class T>
  bool OBox<T>::Contain(const Vector<T> &pt) const
  {
    
  }
  
  
  
}
#endif
