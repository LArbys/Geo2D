#
# This is an example GNUmakefile for my packages
#

# specific names for this package
DICT  = Geo2D_CoreDict
SHLIB = libGeo2D_Core.so
SOURCES = $(filter-out $(DICT).cxx, $(wildcard *.cxx))
FMWK_HEADERS = LinkDef.h $(DICT).h
HEADERS = $(filter-out $(FMWK_HEADERS), $(wildcard *.h))
OBJECTS = $(SOURCES:.cxx=.o)

# include options for this package
INCFLAGS  = -I.                       #Include itself
INCFLAGS += -I$(OPENCV_INCDIR)

# platform-specific options
OSNAME          = $(shell uname -s)
HOST            = $(shell uname -n)
OSNAMEMODE      = $(OSNAME)

LDFLAGS += -L$(OPENCV_LIBDIR) -lopencv_core -lopencv_imgproc

# call kernel specific compiler setup
include $(GEO2D_BASEDIR)/Makefile/Makefile.${OSNAME}

# call the common GNUmakefile
include $(GEO2D_BASEDIR)/Makefile/GNUmakefile.CORE
