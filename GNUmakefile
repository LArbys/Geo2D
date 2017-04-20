SUBDIRS :=  Core PyUtil Algorithm

.phony: all clean

all:
	@mkdir -p $(GEO2D_LIBDIR)
	@for i in $(SUBDIRS); do ( echo "" && echo "Compiling $$i..." && cd Geo2D/$$i && $(MAKE) ) || exit $$?; done

clean:
	@for i in $(SUBDIRS); do ( echo "" && echo "Cleaning $$i..." && cd Geo2D/$$i && $(MAKE) clean && rm -f $(GEO2D_LIBDIR)/$$i.* ) || exit $$?; done

