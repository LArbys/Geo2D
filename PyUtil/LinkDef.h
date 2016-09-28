//
// cint script to generate libraries
// Declaire namespace & classes you defined
// #pragma statement: order matters! Google it ;)
//

#ifdef __CINT__
#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;

//
// Functions
//
#pragma link C++ class geo2d::load_pyutil+;
#pragma link C++ function geo2d::as_ndarray32(const std::vector<float>&)+;
#pragma link C++ function geo2d::as_ndarray64(const std::vector<double>&)+;
//ADD_NEW_CLASS ... do not change this line

#endif




















