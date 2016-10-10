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

#include "Core/VectorArray.h"
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

    VectorArray<T> MonotoneChain(VectorArray<T> pts);

    cv::Rect_<T> test(VectorArray<T> pts);

    RotatedRect test2(VectorArray<T> pts);
    
  protected:


  };
}

#endif
/** @} */ // end of doxygen group 

