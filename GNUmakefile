SUBDIRS :=  Core Object PyUtil Algorithm

.phony: all clean

all:
	@for i in $(SUBDIRS); do ( echo "" && echo "Compiling $$i..." && cd $$i && $(MAKE) ) || exit $$?; done

clean:
	@for i in $(SUBDIRS); do ( echo "" && echo "Cleaning $$i..." && cd $$i && $(MAKE) clean && rm -f $(GEO2D_LIBDIR)/$$i.* ) || exit $$?; done

