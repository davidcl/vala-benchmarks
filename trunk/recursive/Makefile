# vala-benchmarks 
# recursive bench makefile

include ../Make.header

all test build clean: 
	-(cd mono; $(MAKE) $@)
	-(cd plain-C; $(MAKE) $@)
	-(cd vala; $(MAKE) $@)

bench:
	-(cd mono; $(MAKE) $@)
	-(cd plain-C; $(MAKE) $@)
	-(cd vala; $(MAKE) $@)

