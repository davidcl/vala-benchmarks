# vala-benchmarks Makefile

include Make.header

all: build test bench

build test bench:
	-@for dir in $(BENCHS); do ( cd $$dir; make $@ ); done

clean:
	-@for t in $(BENCHS); do (cd $$t; make clean); done
	rm `find . -iname *~`
