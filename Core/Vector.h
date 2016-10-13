/**
 * \file Vector.h
 *
 * \ingroup DataFormat
 * 
 * \brief Class def header for a class Vector
 *
 * @author kazuhiro
 */

/** \addtogroup DataFormat

    @{*/
#ifndef GEO2D_VECTOR_H
#define GEO2D_VECTOR_H

#include "opencv2/core/mat.hpp"

namespace geo2d {

  template <class T>
  using Vector = ::cv::Point_<T>;

  template <class T>
  double angle(const Vector<T>& obj);

  template <class T>
  double angle(const Vector<T>& obj1, const Vector<T>& obj2);

  template <class T>
  Vector<T> dir(const Vector<T>& obj1, const Vector<T>& obj2);

  template <class T>
  Vector<T> dir(double angle);

  template <class T>
  T length2(const Vector<T>& obj);

  template <class T>
  T dist2(const Vector<T>& obj1, const Vector<T>& obj2);

  template <class T>
  T length(const Vector<T>& obj);

  template <class T>
  T dist(const Vector<T>& obj1, const Vector<T>& obj2);

}

#endif
/** @} */ // end of doxygen group 

