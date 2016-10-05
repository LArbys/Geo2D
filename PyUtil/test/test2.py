import ROOT
from ROOT import cv,geo2d
geo2d.load_pyutil
import numpy as np

data=ROOT.std.vector("float")()
data.push_back(1.)
data.push_back(2.)

print geo2d.as_ndarray32(data)
