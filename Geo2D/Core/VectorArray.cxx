#ifndef VECTORARRAY_TEMPLATE_H
#define VECTORARRAY_TEMPLATE_H

#include "VectorArray.h"
#include "spoon.h"

namespace geo2d {

  template <class T>
  VectorArray<T>::VectorArray(const std::vector<T>& xs, const std::vector<T>& ys)
  {
    if(xs.size() != ys.size()) throw spoon("Provided X and Y points length do not match!");
    for(size_t idx=0; idx<xs.size(); ++idx) {
      Vector<T> pt(xs[idx],ys[idx]);
      this->emplace_back(std::move(pt));
    }
  }

  template <class T>
  T VectorArray<T>::length() const
  {
    T res=0;
    for(size_t idx=0; idx+1<this->size(); ++idx) {
      res += geo2d::dist((*this)[idx],(*this)[idx+1]);
    }
    return res;
  }

  template <class T>
  bool VectorArray<T>::is_longer(T length) const
  {
    T lsum=0;
    for(size_t idx=0; idx+1<this->size(); ++idx) {
      lsum += geo2d::dist((*this)[idx],(*this)[idx+1]);
      if(lsum > length) break;
    }
    return (lsum > length);
  }

  template <class T>
  Vector<T> VectorArray<T>::dir(size_t idx) const
  {
    if(idx >= this->size()) throw spoon("Requested index out of range!");
    if(this->size() <2) throw spoon("Array length < 2 ... no direction can be defined!");
    if((idx+1) == this->size())
      return geo2d::dir((*this)[idx-1],(*this)[idx]);
    else
      return geo2d::dir((*this)[idx],(*this)[idx+1]);
  }

  template <class T>
  Vector<T> VectorArray<T>::mean() const
  {
    Vector<T> res(0,0);
    for(size_t idx=0; idx<this->size(); ++idx) {
      res.x += (*this)[idx].x;
      res.y += (*this)[idx].y;
    }
    res.x /= (T)this->size();
    res.y /= (T)this->size();
    return res;
  }

}

template class geo2d::VectorArray<double>;
template class geo2d::VectorArray<float >;
template class geo2d::VectorArray<int   >;
template class geo2d::VectorArray<short >;

#endif
