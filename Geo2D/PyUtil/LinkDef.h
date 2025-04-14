//
// cint script to generate libraries
// Declaire namespace & classes you defined
// #pragma statement: order matters! Google it ;)
//

#ifdef __CINT__

#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;
#pragma link off all namespaces;

// Enable the geo2d namespace
#pragma link C++ namespace geo2d;
#pragma link C++ namespace std;

// If you need the vector typedefs that are used by PyUtils methods
#pragma link C++ class std::vector<float>+;
#pragma link C++ class std::vector<double>+;

// If you need the PyObject to be properly handled
#pragma link C++ class PyObject+;

// Enable the PyUtils class and its methods
#pragma link C++ class geo2d::PyFuncs+;
#pragma link C++ class geo2d::PyDraw+;


#endif




















