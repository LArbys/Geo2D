#ifndef ALGOCONVEXHULL_TEMPLATE_H
#define ALGOCONVEXHULL_TEMPLATE_H

#include "AlgoConvexHull.h"
#include <algorithm>

namespace geo2d {

  template <class T>
  T ccw(const Vector2D<T>& a, const Vector2D<T>& b, const Vector2D<T> c)
  { return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x); }

  template <class T>
  bool is_left(const Vector2D<T>& a, const Vector2D<T>& b)
  { return (a.x < b.x || (a.x == b.x && a.y < b.y)); }

  template <class T>
  Vector2DArray<T> AlgoConvexHull<T>::MonotoneChain(Vector2DArray<T> pts)
  {

    // Sort our points in lexicographic order.
    //std::sort(pts.begin(), pts.end(), &AlgoConvexHull<T>::is_left);
    std::sort(pts.begin(), pts.end(), is_left<T>);


    // Find the lower half of the convex hull.
    Vector2DArray<T> lower;
    for (auto const& pt : pts) {
      // Pop off any points that make a convex angle with *it
      while (lower.size() >= 2 && ccw(*(lower.rbegin() + 1), *(lower.rbegin()), pt) >= 0) {
	lower.pop_back();
      }
      lower.push_back(pt);
    }

    // Find the upper half of the convex hull.
    Vector2DArray<T> upper;
    for (auto const& pt : pts) {
      // Pop off any points that make a convex angle with *it
      while (upper.size() >= 2 && ccw(*(upper.rbegin() + 1), *(upper.rbegin()), pt) <= 0) {
	upper.pop_back();
      }
      upper.push_back(pt);
    }

    Vector2DArray<T> hull;
    hull.insert(hull.end(), lower.begin(), lower.end());
    // Both hulls include both endpoints, so leave them out when we
    // append the upper hull.
    hull.insert(hull.end(), upper.rbegin() + 1, upper.rend() - 1);
    return hull;

  }

}
#endif
