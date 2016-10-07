#ifndef LINESEGMENT_CXX
#define LINESEGMENT_CXX

#include "LineSegment.h"
#include "LineSegment.imp.h"
namespace geo2d {

  template class LineSegment<double>;
  template class LineSegment<float >;
  template class LineSegment<int   >;
  template class LineSegment<short >;

  template double length(const LineSegment<double>&);
  template double length(const LineSegment<float >&);
  template double length(const LineSegment<int   >&);
  template double length(const LineSegment<short >&);

  template double length2(const LineSegment<double>&);
  template double length2(const LineSegment<float >&);
  template double length2(const LineSegment<int   >&);
  template double length2(const LineSegment<short >&);

  template double angle(const LineSegment<double>&);
  template double angle(const LineSegment<float >&);
  template double angle(const LineSegment<int   >&);
  template double angle(const LineSegment<short >&);

  template Vector2D<double> dir(const LineSegment<double>&);
  template Vector2D<float > dir(const LineSegment<float >&);
  template Vector2D<int   > dir(const LineSegment<int   >&);
  template Vector2D<short > dir(const LineSegment<short >&);

}
#endif
