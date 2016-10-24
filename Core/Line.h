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
    
    /// ROOT needs empty constructor probably
    Line() {}

    /// Default constructor    
    Line(const Vector<T>& point, const Vector<T>& direction)
      : pt(point), dir(direction)
    { if(dir.x<0) { dir.x *= -1; dir.y *= -1;} }
    
    Line(const Vector<T>& point, double angle)
      : pt(point), dir(geo2d::dir<T>(angle))
    { if(dir.x<0) { dir.x *= -1; dir.y *= -1;} }

    Line(T ix, T iy, T angle)
      : dir(geo2d::dir<T>(angle))
    { pt.x = ix; pt.y = iy; if(dir.x<0) { dir.x *= -1; dir.y *= -1; } }

    /// Default destructor
    ~Line(){}

    cv::Point_<T> pt;
    cv::Point_<float> dir;

    T x(T y) const;
    T y(T x) const;
  };

  template <class T>
  double angle(const Line<T>&);
}

#endif
/** @} */ // end of doxygen group 

