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
#include <Vector2D.h>

namespace geo2d {
  /**
     \class HalfLine
     User defined class HalfLine ... these comments are used to generate
     doxygen documentation!
  */
  template <class T>
  class HalfLine {
    
  public:
    
    /// Default constructor
    HalfLine(const Vector2D<T>& point, const Vector2D<T>& direction)
      : pt(point), dir(direction)
    {}

    /// Default constructor
    HalfLine(const Vector2D<T>& point, double angle)
      : pt(point), dir(geo2d::dir<T>(angle))
    {}

    /// Default destructor
    ~HalfLine(){}

    ::cv::Point_<T> pt;
    Vector2D<T> dir;

  };

  template <class T>
  double angle(const HalfLine<T>&);

}

#endif
/** @} */ // end of doxygen group 

