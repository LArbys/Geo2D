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
    HalfLine(T islope, const Vector2D<T>& point)
      : slope(islope), pt(point)
    {}

    /// Default destructor
    ~HalfLine(){}
    
    T slope;
    Vector2D<T> pt;

  };
}

#endif
/** @} */ // end of doxygen group 

