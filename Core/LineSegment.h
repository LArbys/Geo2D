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
    LineSegment(const Vector2D<T>& point1 = Vector2D<T>(),
		const Vector2D<T>& point2 = Vector2D<T>())
      : pt1(point1), pt2(point2)
    {}
    
    /// Default destructor
    ~LineSegment(){}
    
    double length  (){ return dist (pt1,pt2); }
    double length2 (){ return dist2(pt1,pt2); }
    double angle   (){ return angle(pt1,pt2); }
    
    ::cv::Point_<T> pt1;
    ::cv::Point_<T> pt2;
    
  };
}

#endif
/** @} */ // end of doxygen group 

