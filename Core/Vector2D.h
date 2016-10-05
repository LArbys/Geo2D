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

#include "opencv2/core/mat.hpp"

namespace geo2d {

  template <class T>
  using Vector2D = ::cv::Point_<T>;

  template <class T>
  double angle(const Vector2D<T>& obj);

  template <class T>
  double angle(const Vector2D<T>& obj1, const Vector2D<T>& obj2);

  template <class T>
  Vector2D<T> dir(const Vector2D<T>& obj1, const Vector2D<T>& obj2);

  template <class T>
  T length2(const Vector2D<T>& obj);

  template <class T>
  T dist2(const Vector2D<T>& obj1, const Vector2D<T>& obj2);

  template <class T>
  T length(const Vector2D<T>& obj);

  template <class T>
  T dist(const Vector2D<T>& obj1, const Vector2D<T>& obj2);

}

#endif
/** @} */ // end of doxygen group 

