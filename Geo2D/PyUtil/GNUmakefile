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
INCFLAGS += $(shell python-config --includes)
INCFLAGS += -I$(shell python -c "import numpy; print numpy.get_include()")
INCFLAGS += -I$(OPENCV_INCDIR)

# platform-specific options
OSNAME          = $(shell uname -s)
HOST            = $(shell uname -n)
OSNAMEMODE      = $(OSNAME)

LDFLAGS += -L$(GEO2D_LIBDIR) -lGeo2D_Core 
LDFLAGS += -L$(OPENCV_LIBDIR) -lopencv_core -lopencv_highgui -lopencv_imgcodecs -lopencv_imgproc
LDFLAGS += -L$(shell python-config --prefix)/lib/
LDFLAGS += $(shell python-config --ldflags)

# call kernel specific compiler setup
include $(GEO2D_BASEDIR)/Makefile/Makefile.${OSNAME}

# call the common GNUmakefile
include $(GEO2D_BASEDIR)/Makefile/GNUmakefile.CORE
