/**
 * \file PyRep.h
 *
 * \ingroup Object
 * 
 * \brief Class def header for a class PyRep
 *
 * @author kazuhiro
 */

/** \addtogroup Object

    @{*/

#ifndef GEO2DPYREP_H
#define GEO2DPYREP_H

struct _object;
typedef _object PyObject;

#ifndef __CLING__
#ifndef __CINT__
#include <Python.h>
#endif
#endif
#include <vector>

#include <iostream>
#include "Core/BoundingBox.h"
#include "Core/Vector2DArray.h"

namespace geo2d {
  /**
     \class PyRep
     @brief A set of functions to convert geo2d objects into cv2-friendly native ndarray object 
  */
  class PyRep{
    
  public:
    
    /// Default constructor
    PyRep();
    
    /// Default destructor
    ~PyRep(){}
    PyObject* points (const Vector2DArray<float >& ) const;
    PyObject* rect   (const geo2d::Rect&           ) const;
    PyObject* rrect  (const geo2d::RotatedRect&    ) const;

  };
}

#endif
/** @} */ // end of doxygen group 

