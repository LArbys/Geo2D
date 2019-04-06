#ifndef PYDRAW_CXX
#define PYDRAW_CXX

#include "PyDraw.h"
#include "PyUtils.h"
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <numpy/ndarrayobject.h>
#include "Geo2D/Core/spoon.h"
namespace geo2d {

  PyDraw::PyDraw()
  {
    SetPyUtil();
  }

  cv::Mat PyDraw::mat(PyObject* pyarray) const
  {
    float **carray;
    //Create C arrays from numpy objects:
    const int dtype = NPY_FLOAT;
    PyArray_Descr *descr = PyArray_DescrFromType(dtype);
    npy_intp dims[3];
    if (PyArray_AsCArray(&pyarray, (void **)&carray, dims, 2, descr) < 0) {
      std::cerr << "cannot convert to 2D C-array" << std::endl;
      throw spoon();
    }

    auto img = cv::Mat(dims[0],dims[1],CV_8UC1,cvScalar(0));

    std::vector<float> res_data(dims[0]*dims[1],0.);
    for(int i=0; i<dims[0]; ++i) {
      for(int j=0; j<dims[1]; ++j) {
	img.at<unsigned char>(i,j) = (unsigned char)((float)carray[i][j]);
      }
    }
    PyArray_Free(pyarray,(void *)carray);

    return img;
  }

  PyObject* PyDraw::image(const cv::Mat m) const
  {

    //float carray[m.rows * m.cols];
    std::vector<float> carray(m.rows * m.cols,0.);
    size_t row,col;
    for(size_t i=0; i<m.rows; ++i) {
      //size_t row = (m.rows - i -1);
      row = i;
      for(size_t j=0; j<m.cols; ++j) {
	//col = m.cols - j - 1;
	col = j;
	carray[row*m.cols+col] = (float)(int(m.at<uchar>(i,j)));
      }
    }

    npy_intp dims[2];
    dims[0] = m.rows;
    dims[1] = m.cols;
    auto array = (PyArrayObject*)(PyArray_ZEROS(2,dims,NPY_FLOAT,0));

    float* data_ptr = (float*) PyArray_DATA(array);

    memcpy(data_ptr, &carray[0], sizeof(float)*(m.rows*m.cols));

    return PyArray_Return(array);
  }

  PyObject* PyDraw::points(const VectorArray<float>& input) const
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
