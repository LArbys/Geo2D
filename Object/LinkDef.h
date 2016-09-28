//
// cint script to generate libraries
// Declaire namespace & classes you defined
// #pragma statement: order matters! Google it ;)
//

#ifdef __CINT__
#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;

#pragma link C++ namespace geo2d+;
#pragma link C++ class geo2d::Vector2D<double>+;
#pragma link C++ class geo2d::Vector2D<float>+;
#pragma link C++ class geo2d::Vector2D<short>+;
#pragma link C++ class geo2d::Vector2D<int>+;

#pragma link C++ class geo2d::Vector2DArray<double>+;
#pragma link C++ class geo2d::Vector2DArray<float>+;
#pragma link C++ class geo2d::Vector2DArray<short>+;
#pragma link C++ class geo2d::Vector2DArray<int>+;

#pragma link C++ class geo2d::AABox<double>+;
#pragma link C++ class geo2d::AABox<float>+;
#pragma link C++ class geo2d::AABox<short>+;
#pragma link C++ class geo2d::AABox<int>+;

#pragma link C++ class geo2d::OBox<double>+;
#pragma link C++ class geo2d::OBox<float>+;
#pragma link C++ class geo2d::OBox<short>+;
#pragma link C++ class geo2d::OBox<int>+;

//ADD_NEW_CLASS ... do not change this line

#endif

