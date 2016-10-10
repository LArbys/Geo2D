#ifndef BOUNDINGBOX_IMP_H
#define BOUNDINGBOX_IMP_H
#include "opencv2/imgproc/imgproc.hpp"

namespace geo2d {

  template <class T>
  VectorArray<float> edges(const cv::Rect_<T>& box)
  {
    VectorArray<float> res;
    res.resize(4);
    res[0].x = box.x;             res[0].y = box.y;
    res[1].x = box.x + box.width; res[1].y = box.y;
    res[2].x = box.x + box.width; res[2].y = box.y + box.height;
    res[3].x = box.x;             res[3].y = box.y + box.height;
    return res;
  }

  template <class T>
  bool contains(const cv::Rect_<T>& box, const Vector<T>& pt)
  { return box.contains(pt); }

  template <class T>
  bool contains(const cv::RotatedRect& box, const Vector<T>& pt)
  {
    //
    // Box is aligned
    //
    static const double min_angle = 0.001;
    if( (-min_angle < box.angle && box.angle < min_angle)
	||
	((180. - min_angle) < box.angle && box.angle < (180. + min_angle)) )
      {
	// no rotation => width and height tells us
	if(pt.y > (box.center.y + box.size.height)) return false;
	if(pt.y < (box.center.y - box.size.height)) return false;
	if(pt.x > (box.center.x + box.size.width )) return false;
	if(pt.x < (box.center.x - box.size.width )) return false;
	return true;
      }

    if( ((90. - min_angle) < box.angle && box.angle < (90. + min_angle))
	||
	((270. - min_angle) < box.angle && box.angle < (270. + min_angle)) )
      {
	// no rotation => width and height tells us
	if(pt.y > (box.center.y + box.size.width )) return false;
	if(pt.y < (box.center.y - box.size.width )) return false;
	if(pt.x > (box.center.x + box.size.height)) return false;
	if(pt.x < (box.center.x - box.size.height)) return false;
	return true;
      }
    
    //
    // Has some slope
    //
    auto const& pts = geo2d::edges(box);
    auto const& p1 = pts[0];
    auto const& p2 = pts[1];
    //auto const& p3 = pts[2];
    auto const& p4 = pts[3];

    T slope1 = (p2.y - p1.y) / (p2.x - p1.x);

    if(p1.y > p4.y) {
      //std::cout<<"nonalingned case 1" << std::endl;
      if(pt.y > slope1 * pt.x + (p1.y - slope1 * p1.x)) return false;
      if(pt.y < slope1 * pt.x + (p4.y - slope1 * p4.x)) return false;
    }else{
      //std::cout<<"nonalingned case 2" << std::endl;
      if(pt.y > slope1 * pt.x + (p4.y - slope1 * p4.x)) return false;
      if(pt.y < slope1 * pt.x + (p1.y - slope1 * p1.x)) return false;
    }

    T slope2 = (p1.y - p4.y) / (p1.x - p4.x);
    
    if(p2.y > p1.y) {
      //std::cout<<"nonalingned case 3" << std::endl;
      //std::cout<<slope2 * pt.x + (p1.y - slope2 * p1.x)<< " => " << slope2 * pt.x + (p2.y - slope2 * p2.x) << std::endl;
      if(pt.y > slope2 * pt.x + (p2.y - slope2 * p2.x)) return false;
      if(pt.y < slope2 * pt.x + (p1.y - slope2 * p1.x)) return false;
    }else{
      //std::cout<<"nonalingned case 4" << std::endl;
      //std::cout<<slope2 * pt.x + (p2.y - slope2 * p2.x)<< " => " << slope2 * pt.x + (p1.y - slope2 * p1.x) << std::endl;
      if(pt.y > slope2 * pt.x + (p1.y - slope2 * p1.x)) return false;
      if(pt.y < slope2 * pt.x + (p2.y - slope2 * p2.x)) return false;
    }
    return true;
  }
}
#endif
