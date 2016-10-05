#ifndef __BOUNDINGBOX_H__
#define __BOUNDINGBOX_H__

#include "opencv2/core/mat.hpp"
#include "Vector2DArray.h"

namespace geo2d {

  typedef cv::Rect_<float> Rect;
  
  typedef cv::RotatedRect  RotatedRect;

  template <class T>
  Vector2DArray<float> edges(const cv::Rect_<T>&);

  Vector2DArray<float> edges(const cv::RotatedRect&);

  template <class T>
  bool contains(const cv::Rect_<T>&, const geo2d::Vector2D<T>&);

  template <class T>
  bool contains(const cv::RotatedRect&, const geo2d::Vector2D<T>&);

}

#endif
