/**
 * \file Contour.h
 *
 * \ingroup Core
 * 
 * \brief Class def header for a class Contour
 *
 * @author kazuhiro
 */

/** \addtogroup Core

    @{*/
#ifndef CONTOUR_H
#define CONTOUR_H

#include "VectorArray.h"
namespace geo2d {
  /**
     \class Contour
     User defined class Contour ... these comments are used to generate
     doxygen documentation!
  */
  template <class T>
  using Contour = VectorArray<T>;

  template<class T>
  double contains(const VectorArray<T>& contour, Vector<T>& pt, bool measureDist);
}

#endif
/** @} */ // end of doxygen group 

