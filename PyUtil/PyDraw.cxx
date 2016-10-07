#ifndef PYDRAW_CXX
#define PYDRAW_CXX

#include "PyDraw.h"
//#include <numpy/arrayobject.h>
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <numpy/ndarrayobject.h>
#include "Core/spoon.h"
namespace geo2d {

  PyDraw::PyDraw()
  {
    static bool once=false;
    if(!once) { import_array(); once=true; }
    //SetPyUtil();
  }

  PyObject* PyDraw::image(const cv::Mat m) const
  {
    float carray[m.rows * m.cols];
    for(size_t i=0; i<m.rows; ++i) {
      for(size_t j=0; j<m.cols; ++j) {
	carray[i*m.cols+j] = (float)(int(m.at<uchar>(i,j)));
      }
    }

    npy_intp dims[2];
    dims[0] = m.rows;
    dims[1] = m.cols;
    auto array = (PyArrayObject*)(PyArray_ZEROS(2,dims,NPY_FLOAT,0));

    float* data_ptr = (float*) PyArray_DATA(array);

    memcpy(data_ptr, carray, sizeof(float)*(m.rows*m.cols));

    return PyArray_Return(array);
  }

  PyObject* PyDraw::points(const Vector2DArray<float>& input) const
  {
    float carray[input.size()*2];
    for(size_t i=0; i<input.size(); ++i) {
      auto const& pt(input[i]);
      carray[i] = pt.x;
      carray[i+input.size()] = pt.y;
    }
    
    npy_intp dims[2];
    dims[0] = 2;
    dims[1] = (npy_int)(input.size());
    auto array = (PyArrayObject*)(PyArray_ZEROS(2,dims,NPY_FLOAT,0));

    float* data_ptr = (float*) PyArray_DATA(array);
    
    memcpy(data_ptr, carray, sizeof(float)*input.size()*2);

    return PyArray_Return(array);
  }

  PyObject* PyDraw::rect(const geo2d::Rect& input) const
  {
    auto const pts = geo2d::edges(input);
    return this->points(pts);
  }

  PyObject* PyDraw::rrect(const geo2d::RotatedRect& input) const
  {
    auto const pts = geo2d::edges(input);
    return this->points(pts);
  }

}
#endif
