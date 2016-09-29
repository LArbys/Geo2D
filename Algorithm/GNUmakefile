#
# This is an example GNUmakefile for my packages
#

# specific names for this package
DICT  = Geo2D_AlgorithmDict
SHLIB = libGeo2D_Algorithm.so
SOURCES = $(filter-out $(DICT).cxx, $(wildcard *.cxx))
FMWK_HEADERS = LinkDef.h $(DICT).h
HEADERS = $(filter-out $(FMWK_HEADERS), $(wildcard *.h))
OBJECTS = $(SOURCES:.cxx=.o)

# include options for this package
INCFLAGS  = -I.                       #Include itself
INCFLAGS += -I$(GEO2D_BASEDIR)

LDFLAGS += -L$(GEO2D_LIBDIR) -lGeo2D_Core -lGeo2D_Object

# platform-specific options
OSNAME          = $(shell uname -s)
HOST            = $(shell uname -n)
OSNAMEMODE      = $(OSNAME)

# call kernel specific compiler setup
include $(GEO2D_BASEDIR)/Makefile/Makefile.${OSNAME}

# call the common GNUmakefile
include $(GEO2D_BASEDIR)/Makefile/GNUmakefile.CORE
