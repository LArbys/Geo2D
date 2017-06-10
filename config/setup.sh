#!/bin/bash

# clean up previously set env
me="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd)"
`python $me/python/clean_env.py LD_LIBRARY_PATH`
`python $me/python/clean_env.py DYLD_LIBRARY_PATH`
`python $me/python/clean_env.py PYTHONPATH`
`python $me/python/clean_env.py PATH`
if [[ -z $FORCE_GEO2D_BASEDIR ]]; then
    # If GEO2D_BASEDIR not set, try to guess
    # Find the location of this script:
    me="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
    # Find the directory one above.
    export GEO2D_BASEDIR="$( cd "$( dirname "$me" )" && pwd )"
else
    export GEO2D_BASEDIR=$FORCE_GEO2D_BASEDIR
fi
unset me;

if [[ -z $ENABLE_GEO2D_ALIAS ]]; then
    export ENABLE_GEO2D_ALIAS=1
fi

echo "GEO2D_BASEDIR = $GEO2D_BASEDIR"
if [[ -z $GEO2D_BASEDIR ]]; then
    echo \$GEO2D_BASEDIR not set! 
    echo You have to set this first.
    return;
fi
# Abort if ROOT not installed. Let's check rootcint for this.
if [ `command -v rootcling` ]; then
    export GEO2D_ROOT6=1
else 
    if [[ -z `command -v rootcint` ]]; then
	echo
	echo Looks like you do not have ROOT installed.
	echo You cannot use LArLite w/o ROOT!
	echo Aborting.
	echo
	return;
    fi
fi
GEO2D_OS=`uname -s`

# Set path to sub directories
export GEO2D_INCDIR=$GEO2D_BASEDIR
export GEO2D_LIBDIR=$GEO2D_BASEDIR/lib
export GEO2D_BINDIR=$GEO2D_BASEDIR/bin
export GEO2D_COREDIR=$GEO2D_BASEDIR/Geo2D/core

export PATH=$GEO2D_BINDIR:$PATH

if [[ -z $USER_MODULE ]]; then
    export USER_MODULE=""
fi

# Check compiler availability for clang++ and g++
GEO2D_CXX=clang++
if [ `command -v $GEO2D_CXX` ]; then
    export GEO2D_CXX="$GEO2D_CXX -std=c++11";
else
    GEO2D_CXX=g++
    if [[ -z `command -v $GEO2D_CXX` ]]; then
	echo
	echo Looks like you do not have neither clang or g++!
	echo You need one of those to compile LArLite... Abort config...
	echo
	return;
    fi
    export GEO2D_CXX;
    if [ $GEO2D_OS = 'Darwin' ]; then
	echo $GEO2D_OS
	echo
	echo "***************** COMPILER WARNING *******************"
	echo "*                                                    *"
	echo "* You are using g++ on Darwin to compile LArLite.    *"
	echo "* Currently LArLite assumes you do not have C++11    *"
	echo "* in this combination. Contact the author if this is *"
	echo "* not the case. At this rate you have no ability to  *"
	echo "* compile packages using C++11 in LArLite.           *"
	echo "*                                                    *"
	echo "* Help to install clang? See manual/contact author!  *"
	echo "*                                                    *"
	echo "******************************************************"
	echo 
    fi
fi
if [[ -z $ROOTSYS ]]; then
    case `uname -n` in
	(houston.nevis.columbia.edu)
	    if [[ -z ${ROOTSYS} ]]; then
		source /usr/nevis/adm/nevis-init.sh
		setup root
		export PYTHONPATH=$ROOTSYS/lib:$PYTHONPATH;
	    fi
	    ;;
	(*)
	    echo
	    echo "****************** PyROOT WARNING ********************"
	    echo "*                                                    *"
	    echo "* Did not find your \$ROOTSYS. To use PyROOT feature, *"
	    echo "* Make sure ROOT.py is installed (comes with ROOT).  *"
	    echo "* You need to export \$PYTHONPATH to include the dir  *"
	    echo "* where ROOT.py exists.                              *"
	    echo "*                                                    *"
	    echo "* Help to install PyROOT? See manual/contact author! *"
	    echo "*                                                    *"
	    echo "******************************************************"
	    echo
	    ;;
	esac
else
    export PYTHONPATH=$ROOTSYS/lib:$PYTHONPATH;
fi

export LD_LIBRARY_PATH=$GEO2D_LIBDIR:$LD_LIBRARY_PATH
export PYTHONPATH=$GEO2D_BASEDIR/python:$PYTHONPATH
if [ $GEO2D_OS = 'Darwin' ]; then
    export DYLD_LIBRARY_PATH=$GEO2D_LIBDIR:$DYLD_LIBRARY_PATH
fi
export PATH=$GEO2D_BASEDIR/bin:$PATH
echo
echo "Finish configuration. To build, type:"
echo "> cd \$GEO2D_BASEDIR"
echo "> make"
echo
