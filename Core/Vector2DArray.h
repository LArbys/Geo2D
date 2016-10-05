/**
 * \file Vector2DArray.h
 *
 * \ingroup Object
 * 
 * \brief Class def header for a class Vector2DArray
 *
 * @author kazuhiro
 */

/** \addtogroup Object

    @{*/
#ifndef VECTOR2DARRAY_H
#define VECTOR2DARRAY_H

#include "Vector2D.h"
#include <vector>

namespace geo2d {
  /**
     \class Vector2DArray
     User defined class Vector2DArray ... these comments are used to generate
     doxygen documentation!
  */
  template <class T>
  class Vector2DArray : public std::vector< geo2d::Vector2D<T> > {
    
  public:
    
    /// Default constructor
    Vector2DArray(){}

    /// Alternative ctor (1)
    Vector2DArray(const std::vector<T>& xs, const std::vector<T>& ys);
    
    /// Default destructor
    ~Vector2DArray(){}

    //
    // Modifiers
    //
    inline Vector2DArray<T>& operator+=(const Vector2D<T>& rhs)
    { this->push_back(rhs); return *this; }
    inline Vector2DArray<T>& operator+=(const Vector2DArray<T>& rhs)
    { this->reserve(this->size()+rhs.size()); for(auto const& pt : rhs) this->push_back(pt); return (*this); }

    //
    // Accessors
    //
    T length() const;
    bool is_longer(T length) const;
    Vector2D<T> dir(size_t idx) const;   
    const std::vector<Vector2D<T> >& as_vector() const { return (*this); }
  };

}

#endif
/** @} */ // end of doxygen group 

