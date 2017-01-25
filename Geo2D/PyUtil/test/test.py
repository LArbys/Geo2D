from ROOT import cv,geo2d
geo2d.load_pyutil
import numpy as np

d=geo2d.PyDraw()
dat=geo2d.VectorArray("float")()
for x in xrange(4):
    pt=cv.Point_("float")()
    pt.x = x
    pt.y = 2*x
    dat.push_back(pt)

print d.points2(dat)
