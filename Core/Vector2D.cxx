#include "Vector2D.h"
#include "Vector2D.imp.h"

template class cv::Point_<double>;
template class cv::Point_<float>;
template class cv::Point_<int>;
template class cv::Point_<short>;

namespace geo2d {

  template double angle(const Vector2D<double>&);
  template double angle(const Vector2D<float >&);
  template double angle(const Vector2D<int   >&);
  template double angle(const Vector2D<short >&);

  template double angle(const Vector2D<double>&, const Vector2D<double>&);
  template double angle(const Vector2D<float >&, const Vector2D<float >&);
  template double angle(const Vector2D<int   >&, const Vector2D<int   >&);
  template double angle(const Vector2D<short >&, const Vector2D<short >&);

  template Vector2D<double> dir(const Vector2D<double>&, const Vector2D<double>&);
  template Vector2D<float > dir(const Vector2D<float >&, const Vector2D<float >&);
  template Vector2D<int   > dir(const Vector2D<int   >&, const Vector2D<int   >&);
  template Vector2D<short > dir(const Vector2D<short >&, const Vector2D<short >&);

  template Vector2D<double> dir(double angle);
  template Vector2D<float > dir(double angle);
  template Vector2D<int   > dir(double angle);
  template Vector2D<short > dir(double angle);

  template double length2(const Vector2D<double>&);
  template float  length2(const Vector2D<float >&);
  template int    length2(const Vector2D<int   >&);
  template short  length2(const Vector2D<short >&);

  template double dist2(const Vector2D<double>&, const Vector2D<double>&);
  template float  dist2(const Vector2D<float >&, const Vector2D<float >&);
  template int    dist2(const Vector2D<int   >&, const Vector2D<int   >&);
  template short  dist2(const Vector2D<short >&, const Vector2D<short >&);

  template double length(const Vector2D<double>&);
  template float  length(const Vector2D<float >&);
  template int    length(const Vector2D<int   >&);
  template short  length(const Vector2D<short >&);

  template double dist(const Vector2D<double>&, const Vector2D<double>&);
  template float  dist(const Vector2D<float >&, const Vector2D<float >&);
  template int    dist(const Vector2D<int   >&, const Vector2D<int   >&);
  template short  dist(const Vector2D<short >&, const Vector2D<short >&);

}

