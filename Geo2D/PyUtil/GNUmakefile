#
# This is an example GNUmakefile for my packages
#

# specific names for this package
DICT  = Geo2D_PyUtilDict
SHLIB = libGeo2D_PyUtil.so
SOURCES = $(filter-out $(DICT).cxx, $(wildcard *.cxx))
FMWK_HEADERS = LinkDef.h $(DICT).h
HEADERS = $(filter-out $(FMWK_HEADERS), $(wildcard *.h))
OBJECTS = $(SOURCES:.cxx=.o)

# include options for this package
INCFLAGS  = -I.                       #Include itself
INCFLAGS += -I$(GEO2D_BASEDIR)
ifeq ("${GEO2D_PYTHON_VERSION}","3")
INCFLAGS += $(shell python3-config --includes)
else
INCFLAGS += $(shell python-config --includes)
endif
INCFLAGS += -I$(shell ${GEO2D_PYTHON} -c "from __future__ import print_function; import numpy; print(numpy.get_include())")

INCFLAGS += -I$(OPENCV_INCDIR)

# platform-specific options
OSNAME          = $(shell uname -s)
HOST            = $(shell uname -n)
OSNAMEMODE      = $(OSNAME)

LDFLAGS += -L$(GEO2D_LIBDIR) -lGeo2D_Core 
LDFLAGS += -L$(OPENCV_LIBDIR) -lopencv_core -lopencv_imgcodecs -lopencv_imgproc
ifeq ("${GEO2D_PYTHON_VERSION}","3")
LDFLAGS += -L$(shell python3-config --prefix)/lib/
LDFLAGS += $(shell python3-config --ldflags)
else
LDFLAGS += -L$(shell python-config --prefix)/lib/
LDFLAGS += $(shell python-config --ldflags)
endif

# call kernel specific compiler setup
include $(GEO2D_BASEDIR)/Makefile/Makefile.${OSNAME}

# call the common GNUmakefile
include $(GEO2D_BASEDIR)/Makefile/GNUmakefile.CORE
