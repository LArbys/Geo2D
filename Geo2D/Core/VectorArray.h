/**
 * \file VectorArray.h
 *
 * \ingroup Object
 * 
 * \brief Class def header for a class VectorArray
 *
 * @author kazuhiro
 */

/** \addtogroup Object

    @{*/
#ifndef VECTORARRAY_H
#define VECTORARRAY_H

#include "Vector.h"
#include <vector>

namespace geo2d {

  /**
     \class VectorArray
     User defined class VectorArray ... these comments are used to generate
     doxygen documentation!
  */
  template <class T>
  class VectorArray : public std::vector< geo2d::Vector<T> > {
    
  public:
    
    /// Default constructor
    VectorArray(){}

    /// Alternative ctor (1)
    VectorArray(const std::vector<T>& xs, const std::vector<T>& ys);
    
    /// Default destructor
    ~VectorArray(){}

    //
    // Modifiers
    //
    inline VectorArray<T>& operator+=(const Vector<T>& rhs)
    { this->push_back(rhs); return *this; }
    inline VectorArray<T>& operator+=(const VectorArray<T>& rhs)
    { this->reserve(this->size()+rhs.size()); for(auto const& pt : rhs) this->push_back(pt); return (*this); }

    //
    // Accessors
    //
    T length() const;
    bool is_longer(T length) const;
    Vector<T> dir(size_t idx) const;   
    const std::vector<Vector<T> >& as_vector() const { return (*this); }
  };

}

#endif
/** @} */ // end of doxygen group 

