/**
 * \file Line2D.h
 *
 * \ingroup Object
 * 
 * \brief Class def header for a class Line2D
 *
 * @author kazuhiro
 */

/** \addtogroup Object

    @{*/
#ifndef HALFLINE_H
#define HALFLINE_H

#include <iostream>
#include "Vector.h"

namespace geo2d {
  /**
     \class HalfLine
     User defined class HalfLine ... these comments are used to generate
     doxygen documentation!
  */
  template <class T>
  class HalfLine {
    
  public:

    HalfLine() : pt(0,0), dir(0) {}
    
    /// Default constructor
    HalfLine(const Vector<T>& point, const Vector<T>& direction)
      : pt(point), dir(direction)
    {}

    /// Alternative ctor (1)
    HalfLine(const Vector<T>& point, double angle)
      : pt(point), dir(geo2d::dir<T>(angle))
    {}

    /// Alternative ctor (2)
    HalfLine(T ix, T iy, double angle)
      : dir(geo2d::dir<T>(angle))
    { pt.x = ix; pt.y = iy; }

    /// Default destructor
    ~HalfLine(){}

    ::cv::Point_<T> pt;
    Vector<T> dir;

    T x(T y) const;
    T y(T x) const;

  };

  template <class T>
  double angle(const HalfLine<T>&);

}

#endif
/** @} */ // end of doxygen group 

