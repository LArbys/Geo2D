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
#include "Vector.h"

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
    Line(const Vector<T>& point, const Vector<T>& direction)
      : pt(point), dir(direction)
    {}
    
    Line(const Vector<T>& point, double angle)
      : pt(point), dir(geo2d::dir<T>(angle))
    {}

    Line(T ix, T iy, T angle)
      : dir(geo2d::dir<T>(angle))
    { pt.x = ix; pt.y = iy; }

    /// Default destructor
    ~Line(){}

    Vector<T> pt;
    Vector<float> dir;

    T x(T y) const;
    T y(T x) const;
  };

  template <class T>
  double angle(const Line<T>&);
}

#endif
/** @} */ // end of doxygen group 

