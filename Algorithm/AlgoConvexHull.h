/**
 * \file AlgoConvexHull.h
 *
 * \ingroup Algorithm
 * 
 * \brief Class def header for a class AlgoConvexHull
 *
 * @author kazuhiro
 */

/** \addtogroup Algorithm

    @{*/
#ifndef ALGOCONVEXHULL_H
#define ALGOCONVEXHULL_H

#include "Core/Vector2DArray.h"
#include "Core/BoundingBox.h"
namespace geo2d {
  /**
     \class ConvexHull
     User defined class ConvexHull ... these comments are used to generate
     doxygen documentation!
  */
  template <class T>
  class AlgoConvexHull{
    
  public:
    
    /// Default constructor
    AlgoConvexHull(){}
    
    /// Default destructor
    ~AlgoConvexHull(){}

    Vector2DArray<T> MonotoneChain(Vector2DArray<T> pts);

    cv::Rect_<T> test(Vector2DArray<T> pts);

    RotatedRect test2(Vector2DArray<T> pts);
    
  protected:


  };
}

#endif
/** @} */ // end of doxygen group 

