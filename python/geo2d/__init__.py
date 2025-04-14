from __future__ import print_function
import numpy as np
import os

if not 'GEO2D_BASEDIR' in os.environ:
    print('$GEO2D_BASEDIR shell env. var. not found (run configure.sh)')
    raise ImportError

import ROOT
from ROOT import geo2d
geo2d.PyDraw
