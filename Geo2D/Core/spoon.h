/**
 * \file spoon.h
 *
 * \ingroup Geo2D
 * 
 * \brief Class def header for exception classes in Geo2D package
 *
 * @author kazuhiro
 */

/** \addtogroup Object

    @{*/
#ifndef __GEO2D_SPOON_H__
#define __GEO2D_SPOON_H__

#include <iostream>
#include <exception>

namespace geo2d {

  /**
     \class spoon
     Throw insignificant spoon when you find nonesense 
  */
  class spoon : public std::exception {
    
  public:
    
    spoon(std::string msg="") : std::exception()
    {
      _msg = "\033[93m";
      _msg += msg;
      _msg += "\033[00m";
    }

    virtual ~spoon() throw() {}
    virtual const char* what() const throw()
    { return _msg.c_str(); }

  private:
    
    std::string _msg;
  };
}

#endif
/** @} */ // end of doxygen group 

