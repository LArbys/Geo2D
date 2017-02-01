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
#include "Vector.h"

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
    LineSegment(const Vector<T>& point1 = Vector<T>(),
		const Vector<T>& point2 = Vector<T>())
      : pt1(point1), pt2(point2)
    {}

    /// Alternative ctor (1)
    LineSegment(T x1, T y1, T x2, T y2)
    { pt1.x = x1; pt1.y = y1; pt2.x = x2; pt2.y = y2; }
    
    /// Default destructor
    ~LineSegment(){}
    
    cv::Point_<T> pt1;
    cv::Point_<T> pt2;
    
    T x(T y) const;
    T y(T x) const;
    
  };

  template <class T>
  double length  (const LineSegment<T>&);
  template <class T>
  double length2 (const LineSegment<T>&);
  template <class T>
  double angle   (const LineSegment<T>&);
  template <class T>
  Vector<T> dir(const LineSegment<T>&);
}

#endif
/** @} */ // end of doxygen group 

