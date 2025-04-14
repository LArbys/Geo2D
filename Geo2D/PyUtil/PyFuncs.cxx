#ifndef __GEO2D_PYFUNCS_CXX__
#define __GEO2D_PYFUNCS_CXX__

#include "Geo2D/PyUtil/PyFuncs.h"

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <numpy/ndarrayobject.h>

#include "Geo2D/Core/spoon.h"
#include <vector>

namespace geo2d {

  bool PyFuncs::_once = false;

  PyFuncs::PyFuncs()
  {
    load_ndarray();
  }

  PyFuncs::~PyFuncs()
  {
  }
  
  int PyFuncs::load_ndarray()
  {
    if(!_once) {
      _once = true;
      import_array1(0);
    }
    return 0;
  }

  PyObject* PyFuncs::as_ndarray_float(const std::vector<float>& vec)
  {
    //SetPyUtil();

    if (vec.size()>=INT_MAX) {
      std::cerr << "Length of data vector too long to specify ndarray. Use by batch call." << std::endl;
      throw spoon();
    }
    int nd = 1;
    npy_intp dims[1];
    dims[0] = (int)vec.size();

    PyArrayObject *array = (PyArrayObject *) PyArray_SimpleNewFromData(nd, dims, NPY_FLOAT, (char*)&(vec[0]) );

    return PyArray_Return(array);
  }

  PyObject* PyFuncs::as_ndarray_double(const std::vector<double>& vec)
  {
    //SetPyUtil();

    if (vec.size()>=INT_MAX) {
      std::cerr << "Length of data vector too long to specify ndarray. Use by batch call." << std::endl;
      throw spoon();
    }
    int nd = 1;
    npy_intp dims[1];
    dims[0] = (int)vec.size();

    PyArrayObject *array = (PyArrayObject *) PyArray_SimpleNewFromData(nd, dims, NPY_DOUBLE, (char*)&(vec[0]) );

    return PyArray_Return(array);
  }

}

#endif
