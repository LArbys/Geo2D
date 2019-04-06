#ifndef __GEO2D_PYUTILS_H__
#define __GEO2D_PYUTILS_H__

struct _object;
typedef _object PyObject;

#ifndef __CLING__
#ifndef __CINT__
#include <Python.h>
#endif
#endif
#include <vector>

namespace geo2d {
  /// Utility function: call one-time-only numpy module initialization (you don't have to call)
  int SetPyUtil();
  PyObject* as_ndarray32(const std::vector<float>& vec);
  PyObject* as_ndarray64(const std::vector<double>& vec);
}

//#include "PyUtils.template.h"

#endif
