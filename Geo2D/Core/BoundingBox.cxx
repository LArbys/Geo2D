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

  VectorArray<float> edges(const cv::RotatedRect& box)
  {
    VectorArray<float> res;
    res.resize(4);
    box.points(&res[0]);
    return res;
  }
  
  template VectorArray<float> edges(const cv::Rect_<double>&);
  template VectorArray<float> edges(const cv::Rect_<float >&);
  template VectorArray<float> edges(const cv::Rect_<int   >&);
  template VectorArray<float> edges(const cv::Rect_<short >&);
  
  template cv::Rect_<double> Union(const cv::Rect_<double>&, const cv::Rect_<double>&);
  template cv::Rect_<float>  Union(const cv::Rect_<float>&, const cv::Rect_<float>&);
  template cv::Rect_<int>  Union(const cv::Rect_<int>&, const cv::Rect_<int>&);
  template cv::Rect_<short>  Union(const cv::Rect_<short>&, const cv::Rect_<short>&);
  template cv::Rect_<double> Intersection(const cv::Rect_<double>&, const cv::Rect_<double>&);
  template cv::Rect_<float>  Intersection(const cv::Rect_<float>&, const cv::Rect_<float>&);
  template cv::Rect_<int>  Intersection(const cv::Rect_<int>&, const cv::Rect_<int>&);
  template cv::Rect_<short>  Intersection(const cv::Rect_<short>&, const cv::Rect_<short>&);
    

}
