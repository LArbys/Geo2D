#ifndef __GEO2D_PYFUNCS_H__
#define __GEO2D_PYFUNCS_H__

#include <Python.h>
#include <vector>

namespace geo2d {
  
  /// Utility function: call one-time-only numpy module initialization (you don't have to call)
  class PyFuncs {

  public:
    
    PyFuncs();
    ~PyFuncs();
    
    int load_ndarray();
    PyObject* as_ndarray_float(const std::vector<float>& vec);
    PyObject* as_ndarray_double(const std::vector<double>& vec);

  private:

    static bool _once;
  };
}

#endif
