import os,sys,commands

# check if GEO2D_BASEDIR is defined. If not, nothing to do.
if not 'GEO2D_BASEDIR' in os.environ:
    sys.exit(1)

# read in template GNUmakefile
makefile=open('%s/config/template/TopMakefile.tmp' % os.environ['GEO2D_BASEDIR'],'r').read()

fout=open('%s/GNUmakefile' % os.environ['GEO2D_BASEDIR'],'w')
fout.write(makefile)
fout.close()
