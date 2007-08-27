# vala-benchmarks Makefile

include Make.header

all: build test bench

build test bench:
	-@for directory in $(BENCHS); do ( cd $$directory; $(MAKE) $@ ); done

clean:
	-@for t in $(BENCHS); do (cd $$t; $(MAKE) clean); done
	rm -fr `find . -iname *~`
