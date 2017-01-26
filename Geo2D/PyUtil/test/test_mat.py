import numpy as np
import ROOT
from ROOT import geo2d
pdraw = geo2d.PyDraw()

ar=np.array([[0,0],[1,1]]).astype(np.float32)
print ar.shape

pdraw.mat(ar)


