/**
 * \file AABox.h
 *
 * \ingroup DataFormat
 * 
 * \brief Class def header for a class AABox
 *
 * @author kazuhiro
 */

/** \addtogroup DataFormat

    @{*/

#ifndef AABOX_H
#define AABOX_H

#include "Vector2D.h"
#include <vector>
namespace geo2d {

  /**                                                                                                                              
     \class AABox                                                                                                                  
     @brief Representation of a 2D rectangular box which sides are aligned w/ coordinate axis.  
     A representation of an Axis-Aligned-Boundary-Box, a simple & popular representation of   \n
     3D boundary box for collision detection. The concept was taken from the reference,       \n
     Real-Time-Collision-Detection (RTCD), and in particular Ch. 4.2 (page 77):               \n
                                                                                                                                   
     Ref: http://realtimecollisiondetection.net                                                 
                                                                                                
     This class uses one of the simplest representation for AABox: "min-max" representation.  \n
     Though this method requires storing 6 floating vector values, class attributes (i.e.      \n
     "min" and "max" vectors) store intuitive values for most UB analyzers. Also it simplifies \n
     utility function implementations.                                                        \n
     
     This class is borrowed from LArLite: UserDev/BasicTool/GeoAlgo package and simplified into .\n
  */
  template <class T>
  class AABox {

  public:

    /// Default constructor
    AABox();

    /// Default destructor
    virtual ~AABox(){};

    /// Alternative ctor (0)
    AABox(const T x_min, const T y_min,
	  const T x_width, const T y_width);

    /// Altenartive ctor (1)
    AABox(const Vector2D<T>& min, const Vector2D<T>& width);

    /// Alternative ctor (2)
    AABox(const std::vector<Vector2D<T> >& pts);

    //
    // Attribute accessor
    //
    bool contain(const Vector2D<T> &pt) const; ///< Test if a vector is contained within the box
    const Vector2D<T>& min() const; ///< Minimum vector getter
    T xwidth()  const; ///< Width along X
    T ywidth()  const; ///< Width along Y
    T xcenter() const; ///< Center X
    T ycenter() const; ///< Center Y
    T xmax()    const; ///< Max X
    T ymax()    const; ///< Max Y
    T xmin()    const; ///< Min X
    T ymin()    const; ///< Min Y

    //
    // Modifier
    //
    void min(const T x, const T y); ///< Minimum vector setter
    void width(const T x, const T y); ///< Width setter
    void shift(const T dx, const T dy); ///< Shifter

    //
    // Python support
    //
    std::vector<T> as_vector() const;
    
  protected:

    Vector2D<T> _min;   ///< Minimum vector
    Vector2D<T> _width; ///< Diameter

  };
}

#include "AABox.template.h"

#endif
