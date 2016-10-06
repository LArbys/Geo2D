//
// cint script to generate libraries
// Declaire namespace & classes you defined
// #pragma statement: order matters! Google it ;)
//

#ifdef __CINT__
#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;

#pragma link C++ namespace cv+;
#pragma link C++ class cv::Point_<double>+;
#pragma link C++ class cv::Point_<float>+;
#pragma link C++ class cv::Point_<short>+;
#pragma link C++ class cv::Point_<int>+;

#pragma link C++ class cv::Size_<double>+;
#pragma link C++ class cv::Size_<float>+;
#pragma link C++ class cv::Size_<short>+;
#pragma link C++ class cv::Size_<int>+;

#pragma link C++ class cv::Rect_<double>+;
#pragma link C++ class cv::Rect_<float>+;
#pragma link C++ class cv::Rect_<int>+;
#pragma link C++ class cv::Rect_<short>+;
#pragma link C++ class cv::RotatedRect+;

#pragma link C++ namespace geo2d+;

#pragma link C++ class geo2d::Vector2DArray<double>+;
#pragma link C++ class geo2d::Vector2DArray<float>+;
#pragma link C++ class geo2d::Vector2DArray<short>+;
#pragma link C++ class geo2d::Vector2DArray<int>+;

//#pragma link C++ class geo2d::Contour+;
#pragma link C++ class geo2d::Rect+;
#pragma link C++ class geo2d::RotatedRect+;

#pragma link C++ class geo2d::Line<double>+;
#pragma link C++ class geo2d::Line<float >+;
#pragma link C++ class geo2d::Line<int   >+;
#pragma link C++ class geo2d::Line<short >+;

#pragma link C++ class geo2d::HalfLine<double>+;
#pragma link C++ class geo2d::HalfLine<float >+;
#pragma link C++ class geo2d::HalfLine<int   >+;
#pragma link C++ class geo2d::HalfLine<short >+;

#pragma link C++ class geo2d::LineSegment<double>+;
#pragma link C++ class geo2d::LineSegment<float >+;
#pragma link C++ class geo2d::LineSegment<int   >+;
#pragma link C++ class geo2d::LineSegment<short >+;

#pragma link C++ class geo2d::Circle<double>+;
#pragma link C++ class geo2d::Circle<float >+;
#pragma link C++ class geo2d::Circle<int   >+;
#pragma link C++ class geo2d::Circle<short >+;
//ADD_NEW_CLASS ... do not change this line
#endif





