# vala-benchmarks Makefile

include Make.header

all: build test bench

build test:
	-@for directory in $(BENCHS); do ( cd $$directory; \
	for dir in $(LANGS); do ( cd $$dir; make $@ ); done  ); done
	
bench:
	-@for directory in $(BENCHS); do ( cd $$directory; \
	for dir in $(LANGS); do ( cd $$dir; make $@ ); done  ); done
	$(SH) ./bench.sh $(BENCHS)

clean:
	-@for directory in $(BENCHS); do ( cd $$directory; \
	for dir in $(LANGS); do ( cd $$dir; make $@ ); done  ); done
#	rm -fr *.csv
	rm -fr `find . -iname "*~"`
