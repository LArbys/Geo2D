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

#include "Vector2D.h"
#include <vector>

namespace geo2d {

  //template class Vector2DArray<double>;
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
    virtual ~OBox(){}

    /// Alternative ctor (0)
    OBox(const T x_min, const T y_min, 
	 const T x_dir, const T y_dir,
	 const T width, const T height);

    /// Altenartive ctor (1)
    OBox(const Vector2D<T>& center, const Vector2D<T>& dir, const Vector2D<T>& width);

    /// Alternative ctor (2)
    OBox(std::vector<Vector2D<T> > pts);

    //
    // Modifier
    //
    void shift(T xshift, T yshift);
    //void rotate(double angle)

    //
    // Attribute accessor
    //
    T angle()   const; ///< Angle of rotation
    T xcenter() const; ///< Center X
    T ycenter() const; ///< Center Y
    T xmax()    const; ///< Max X
    T ymax()    const; ///< Max Y
    T xmin()    const; ///< Min X
    T ymin()    const; ///< Min Y

    T xmax_from_center() const;
    T ymax_from_center() const;

    Vector2D<T> xmax_pt() const;
    Vector2D<T> ymax_pt() const;
    Vector2D<T> xmin_pt() const;
    Vector2D<T> ymin_pt() const;

    Vector2D<T> pt1() const;
    Vector2D<T> pt2() const;
    Vector2D<T> pt3() const;
    Vector2D<T> pt4() const;

    const Vector2D<T>& center() const;
    const Vector2D<T>& width()  const;
    const Vector2D<T>& axes()   const;
    
    bool Contain(const Vector2D<T> &pt) const; ///< Test if a vector is contained within the box

    std::vector<T> as_vector() const;

  protected:

    Vector2D<T> _center; ///< center coordinate
    Vector2D<T> _axes;   ///< local axis unit vector
    Vector2D<T> _width;  ///< half width span along each axis

  };
}

#include "OBox.template.h"

//template class geo2d::OBox<double>;
#endif
