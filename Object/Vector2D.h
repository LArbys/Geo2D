/**
 * \file Vector2D.h
 *
 * \ingroup DataFormat
 * 
 * \brief Class def header for a class Vector2D
 *
 * @author kazuhiro
 */

/** \addtogroup DataFormat

    @{*/
#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <iostream>
#include <cmath>

namespace geo2d {
  /**
     \class Vector2D
     User defined class Vector2D ... these comments are used to generate
     doxygen documentation!
  */
  template <class T>
  class Vector2D {

  public:

    T x; ///< X position
    T y; ///< Y position
    
  public:
    
    /// Default constructor
    Vector2D(T ix=0, T iy=0) : x(ix) , y(iy) {}
    /// Alternative constructor
    Vector2D(const Vector2D& rhs) : x(rhs.x) , y(rhs.y) {}
    /// Default destructor
    ~Vector2D(){}

    //
    // uniry operators
    //
    inline Vector2D<T>& operator += ( const Vector2D<T>& rhs )
    { x += rhs.x; y += rhs.y; return (*this); }
    inline Vector2D<T>& operator -= ( const Vector2D<T>& rhs )
    { x -= rhs.x; y -= rhs.y; return (*this); }
    inline Vector2D<T>& operator /= ( const T&   rhs )
    { x /= rhs; y /= rhs; return (*this); }
    inline Vector2D<T>& operator *= ( const T&   rhs )
    { x *= rhs; y *= rhs; return (*this); }
    inline Vector2D<T>& operator  = ( const Vector2D<T>& rhs )
    { x  = rhs.x; y  = rhs.y; return (*this); }

    //
    // binary operators
    //
    inline Vector2D<T>  operator +  ( const Vector2D<T>& rhs )
    { auto res = (*this); res += rhs; return res; }
    inline Vector2D<T>  operator -  ( const Vector2D<T>& rhs )
    { auto res = (*this); res -= rhs; return res; }
    inline Vector2D<T>  operator /  ( const T&   rhs )
    { auto res = (*this); res /= rhs; return res; }
    inline Vector2D<T>  operator *  ( const T&   rhs )
    { auto res = (*this); res *= rhs; return res; }
    inline T    operator*( const Vector2D<T>& rhs )
    { return x * rhs.x + y + rhs.y; }

    /// Magnitude
    T length() const
    { return sqrt(length2()); }
    /// Magnitude
    T length2() const
    { return pow(x,2) + pow(y,2); }
    /// Magnitude
    T distance(const Vector2D<T>& pt) const
    { return sqrt(distance2(pt)); }
    /// Magnitude
    T distance2(const Vector2D<T>& pt) const
    { return pow(x-pt.x,2) + pow(y-pt.y,2); }
    /// Direction
    Vector2D<T> dir() const
    { Vector2D<T> res(*this);
      res /= length();
      return res;
    }
    /// Direction
    Vector2D<T> dir(const Vector2D<T> pt) const
    { Vector2D<T> res(pt.x - this->x, pt.y - this->y);
      res /= res.length();
      return res;
    }
    /// Angle
    double angle() const
    { return atan2(y,x); }
    /// Angle
    double angle(const Vector2D<T> pt) const
    { return atan2((pt.y - y), (pt.x - x)); }
    
  };

}

#endif
/** @} */ // end of doxygen group 

