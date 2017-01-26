/**
 * \file PyDraw.h
 *
 * \ingroup Object
 * 
 * \brief Class def header for a class PyDraw
 *
 * @author kazuhiro
 */

/** \addtogroup Object

    @{*/

#ifndef GEO2DPYDRAW_H
#define GEO2DPYDRAW_H

struct _object;
typedef _object PyObject;

#ifndef __CLING__
#ifndef __CINT__
#include <Python.h>
#endif
#endif
#include <vector>

#include <iostream>
#include "Geo2D/Core/BoundingBox.h"
#include "Geo2D/Core/VectorArray.h"
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
namespace geo2d {
  /**
     \class PyDraw
     @brief A set of functions to convert geo2d objects into a draw-friendly shaped numpy array
  */
  class PyDraw{
    
  public:
    
    /// Default constructor
    PyDraw();
    
    /// Default destructor
    ~PyDraw(){}
    PyObject* image  (const cv::Mat                ) const;
    PyObject* points (const VectorArray<float >&   ) const;
    PyObject* rect   (const geo2d::Rect&           ) const;
    PyObject* rrect  (const geo2d::RotatedRect&    ) const;
    cv::Mat   mat    (PyObject*                    ) const;
  };
}

#endif
/** @} */ // end of doxygen group 

