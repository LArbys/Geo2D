/**
 * \file Line.h
 *
 * \ingroup Object
 * 
 * \brief Class def header for a class Line
 *
 * @author kazuhiro
 */

/** \addtogroup Object

    @{*/
#ifndef LINE_H
#define LINE_H

#include <iostream>
#include "Vector2D.h"

namespace geo2d {
  /**
     \class Line
     User defined class Line ... these comments are used to generate
     doxygen documentation!
  */
  template <class T>
  class Line {
    
  public:
    
    /// Default constructor
    Line(const Vector2D<T>& point, const Vector2D<T>& direction)
      : pt(point), dir(direction)
    {}
    
    Line(const Vector2D<T>& point, double angle)
      : pt(point), dir(geo2d::dir<T>(angle))
    {}

    Line(T ix, T iy, T angle)
      : dir(geo2d::dir<T>(angle))
    { pt.x = ix; pt.y = iy; }

    /// Default destructor
    ~Line(){}

    Vector2D<T> pt;
    Vector2D<float> dir;

    T x(T y) const;
    T y(T x) const;
  };

  template <class T>
  double angle(const Line<T>&);
}

#endif
/** @} */ // end of doxygen group 

