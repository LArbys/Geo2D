#ifndef CIRCLE_IMP_H
#define CIRCLE_IMP_H

namespace geo2d {

  template<class T>
  bool contains(const Circle<T>& circle, const Vector<T>& pt,double& measureDist) {

    measureDist = dist(circle.center,pt);
    if (measureDist <= circle.radius) return true;

    return false;
  }
  
}

#endif
