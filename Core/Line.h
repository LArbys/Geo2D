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
#include <Vector2D.h>

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
    Line(const Vector2D<T>& direction, T ioffset = 0)
      : dir(direction), offset(ioffset)
    {}
    
    Line(T angle = 0, T ioffset = 0)
      : dir(geo2d::dir<T>(angle)), offset(ioffset)
    {}
    
    /// Default destructor
    ~Line(){}
    
    Vector2D<float> dir;
    T offset;
  };

  template <class T>
  double angle(const Line<T>&);
}

#endif
/** @} */ // end of doxygen group 

