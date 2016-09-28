/**
 * \file OBox.h
 *
 * \ingroup DataFormat
 * 
 * \brief Class def header for a class OBox
 *
 * @author kazuhiro
 */

/** \addtogroup DataFormat

    @{*/

#ifndef OBOX_H
#define OBOX_H

#include "Vector.h"

namespace geo2d {

  /**                                                                                                                              
     \class OBox                                                                                                                  
     @brief Representation of a 2D rectangular box which sides are aligned w/ coordinate axis.  
     A representation of an Axis-Aligned-Boundary-Box, a simple & popular representation of   \n
     3D boundary box for collision detection. The concept was taken from the reference,       \n
     Real-Time-Collision-Detection (RTCD), and in particular Ch. 4.2 (page 77):               \n
                                                                                                                                   
     Ref: http://realtimecollisiondetection.net                                                 
                                                                                                
     This class uses one of the simplest representation for OBox: "min-max" representation.  \n
     Though this method requires storing 6 floating vector values, class attributes (i.e.      \n
     "min" and "max" vectors) store intuitive values for most UB analyzers. Also it simplifies \n
     utility function implementations.                                                        \n
     
     This class is borrowed from LArLite: UserDev/BasicTool/GeoAlgo package and simplified into .\n
  */
  template <class T>
  class OBox {

  public:

    /// Default constructor
    OBox();

    /// Default destructor
    virtual ~OBox(){};

    /// Alternative ctor (0)
    OBox(const T x_min, const T y_min, 
	 const T x_dir, const T y_dir,
	 const T width, const T height);

    /// Altenartive ctor (1)
    OBox(const Vector<T>& min, const Vector<T>& dir, const Vector<T>& width);

    //
    // Attribute accessor
    //
    bool Contain(const Vector<T> &pt) const; ///< Test if a vector is contained within the box

  protected:

    Vector<T> _center; ///< center coordinate
    Vector<T> _axes;   ///< local axis unit vector
    Vector<T> _width;  ///< half width span along each axis

  };
}

#include "OBox.template.h"

#endif
