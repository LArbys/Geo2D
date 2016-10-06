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
    Line(T islope=0, T ioffset=0)
      : slope(islope), offset(ioffset)
    {}
    
    /// Default destructor
    ~Line(){}

    T slope;
    T offset;
  };
}

#endif
/** @} */ // end of doxygen group 

