/**
 * \file Circle.h
 *
 * \ingroup Core
 * 
 * \brief Class def header for a class Circle
 *
 * @author kazuhiro
 */

/** \addtogroup Core

    @{*/
#ifndef CIRCLE_H
#define CIRCLE_H

#include "Vector.h"
#include "VectorArray.h"

namespace geo2d {
  /**
     \class Circle
     User defined class Circle ... these comments are used to generate
     doxygen documentation!
  */
  template <class T>
  class Circle{
    
  public:
    
    /// Default constructor
    Circle() : center(), radius(1) {}
    
    Circle(const Vector<T>&, const T);

    Circle(const T, const T, const T);

    Circle(const VectorArray<T>& pts);
    
    Circle(const std::vector<Vector<T> >& pts);

    /// Default destructor
    ~Circle(){}

    ::cv::Point_<T> center;
    T radius;
    
  };

  template<class T>
  bool contains(const Circle<T>& circle, const Vector<T>& pt, double& measureDist);
  
}

#endif
/** @} */ // end of doxygen group 

