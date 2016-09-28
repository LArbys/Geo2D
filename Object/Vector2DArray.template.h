#ifndef VECTOR2DARRAY_TEMPLATE_H
#define VECTOR2DARRAY_TEMPLATE_H

#include "Vector2DArray.h"
#include "Core/spoon.h"

namespace geo2d {

  template <class T>
  Vector2DArray<T>::Vector2DArray(const std::vector<T>& xs, const std::vector<T>& ys)
  {
    if(xs.size() != ys.size()) throw spoon("Provided X and Y points length do not match!");
    for(size_t idx=0; idx<xs.size(); ++idx) {
      Vector2D<T> pt(xs[idx],ys[idx]);
      this->emplace_back(std::move(pt));
    }
  }

  template <class T>
  T Vector2DArray<T>::length() const
  {
    T res=0;
    for(size_t idx=0; idx+1<this->size(); ++idx) {
      res += (*this)[idx].distance((*this)[idx+1]);
    }
    return res;
  }

  template <class T>
  bool Vector2DArray<T>::is_longer(T length) const
  {
    T lsum=0;
    for(size_t idx=0; idx+1<this->size(); ++idx) {
      lsum += (*this)[idx].distance((*this)[idx+1]);
      if(lsum > length) break;
    }
    return (lsum > length);
  }

  template <class T>
  Vector2D<T> Vector2DArray<T>::dir(size_t idx) const
  {
    if(idx >= this->size()) throw spoon("Requested index out of range!");
    if(this->size() <2) throw spoon("Array length < 2 ... no direction can be defined!");
    if((idx+1) == this->size())
      return (*this)[idx-1].dir((*this)[idx]);
    else
      return (*this)[idx].dir((*this)[idx+1]);
  }

}
#endif
