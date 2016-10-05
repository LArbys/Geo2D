import ROOT
from ROOT import cv,geo2d
geo2d.load_pyutil
import numpy as np

d=geo2d.PyDraw()
dat=ROOT.std.vector("double")()
for x in xrange(4):
    dat.push_back(float(x))

print d.conv(dat)
