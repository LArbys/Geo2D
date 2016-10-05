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
#ifndef LINE2D_H
#define LINE2D_H

#include <iostream>
#include <Vector2D.h>
namespace geo2d {
  /**
     \class Line2D
     User defined class Line2D ... these comments are used to generate
     doxygen documentation!
  */
  template <class T>
  class Line2D {
    
  public:
    
    /// Default constructor
    Line2D(T islope=0, T ioffset=0)
      : slope(islope), offset(ioffset)
    {}
    
    /// Default destructor
    ~Line2D(){}

    T slope;
    T offset;
  };
}

#endif
/** @} */ // end of doxygen group 

