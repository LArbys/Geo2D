//
// cint script to generate libraries
// Declaire namespace & classes you defined
// #pragma statement: order matters! Google it ;)
//

#ifdef __CINT__
#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;

#pragma link C++ class geo2d::AlgoConvexHull<short>+;
#pragma link C++ class geo2d::AlgoConvexHull<int>+;
#pragma link C++ class geo2d::AlgoConvexHull<float>+;
#pragma link C++ class geo2d::AlgoConvexHull<double>+;
//ADD_NEW_CLASS ... do not change this line

#endif


