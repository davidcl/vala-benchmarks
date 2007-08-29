# vala-benchmarks Makefile

include Make.header

all: build test bench

build test:
	-@for directory in $(BENCHS); do ( cd $$directory; $(MAKE) $@ ); done
	
bench:
	rm -f bench.csv
	-@for directory in $(BENCHS); do ( cd $$directory; $(MAKE) $@ ); done
	$(SH) ./bench.sh $(BENCHS)

clean:
	-@for t in $(BENCHS); do (cd $$t; $(MAKE) clean); done
	rm -fr bench.csv
	rm -fr `find . -iname *~`
