#ifndef __GEO2D_PYUTILS_CXX__
#define __GEO2D_PYUTILS_CXX__

#include "Geo2D/Core/spoon.h"
#include "PyUtils.h"
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <numpy/ndarrayobject.h>
#include <vector>

namespace geo2d {

  void SetPyUtil()
  {
    static bool once=false;
    if(!once) { import_array(); once=true; }
  }

  PyObject* as_ndarray32(const std::vector<float>& vec)
  {
    SetPyUtil();

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

  PyObject* as_ndarray64(const std::vector<double>& vec)
  {
    SetPyUtil();

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
