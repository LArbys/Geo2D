#include "BoundingBox.h"
#include "BoundingBox.imp.h"

template class cv::Size_<double>;
template class cv::Size_<float >;
template class cv::Size_<int   >;
template class cv::Size_<short >;

template class cv::Rect_<double>;
template class cv::Rect_<float >;
template class cv::Rect_<int   >;
template class cv::Rect_<short >;

namespace geo2d {

  Vector2DArray<float> edges(const cv::RotatedRect& box)
  {
    Vector2DArray<float> res;
    res.resize(4);
    box.points(&res[0]);
    return res;
  }



  template Vector2DArray<float> edges(const cv::Rect_<double>&);
  template Vector2DArray<float> edges(const cv::Rect_<float >&);
  template Vector2DArray<float> edges(const cv::Rect_<int   >&);
  template Vector2DArray<float> edges(const cv::Rect_<short >&);

}
