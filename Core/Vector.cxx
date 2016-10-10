#include "Vector.h"
#include "Vector.imp.h"

template class cv::Point_<double>;
template class cv::Point_<float>;
template class cv::Point_<int>;
template class cv::Point_<short>;

namespace geo2d {

  template double angle(const Vector<double>&);
  template double angle(const Vector<float >&);
  template double angle(const Vector<int   >&);
  template double angle(const Vector<short >&);

  template double angle(const Vector<double>&, const Vector<double>&);
  template double angle(const Vector<float >&, const Vector<float >&);
  template double angle(const Vector<int   >&, const Vector<int   >&);
  template double angle(const Vector<short >&, const Vector<short >&);

  template Vector<double> dir(const Vector<double>&, const Vector<double>&);
  template Vector<float > dir(const Vector<float >&, const Vector<float >&);
  template Vector<int   > dir(const Vector<int   >&, const Vector<int   >&);
  template Vector<short > dir(const Vector<short >&, const Vector<short >&);

  template Vector<double> dir(double angle);
  template Vector<float > dir(double angle);
  template Vector<int   > dir(double angle);
  template Vector<short > dir(double angle);

  template double length2(const Vector<double>&);
  template float  length2(const Vector<float >&);
  template int    length2(const Vector<int   >&);
  template short  length2(const Vector<short >&);

  template double dist2(const Vector<double>&, const Vector<double>&);
  template float  dist2(const Vector<float >&, const Vector<float >&);
  template int    dist2(const Vector<int   >&, const Vector<int   >&);
  template short  dist2(const Vector<short >&, const Vector<short >&);

  template double length(const Vector<double>&);
  template float  length(const Vector<float >&);
  template int    length(const Vector<int   >&);
  template short  length(const Vector<short >&);

  template double dist(const Vector<double>&, const Vector<double>&);
  template float  dist(const Vector<float >&, const Vector<float >&);
  template int    dist(const Vector<int   >&, const Vector<int   >&);
  template short  dist(const Vector<short >&, const Vector<short >&);

}

