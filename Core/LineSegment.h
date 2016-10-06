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
#ifndef LINESEGMENT_H
#define LINESEGMENT_H

#include <iostream>
#include <Vector2D.h>

namespace geo2d {
  /**
     \class LineSegment
     User defined class LineSegment ... these comments are used to generate
     doxygen documentation!
  */
  template <class T>
  class LineSegment {
    
  public:
    
    /// Default constructor
    LineSegment(const Vector2D<T>& point1, const Vector2D<T>& point2)
      : p1(point1), p2(point2)
    {}
    
    /// Default destructor
    ~LineSegment(){}
    
    double length  (){ return dist(p1,p2);  }
    double length2 (){ return dist2(p1,p2); }
    double angle   (){ return angle(p1,p2); }
    
    Vector2D<T> p1;
    Vector2D<T> p2;
    
  };
}

#endif
/** @} */ // end of doxygen group 

