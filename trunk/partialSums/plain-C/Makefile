# vala-benchmarks
# partialSums plain-C bench makefile

include ../../Make.header
include ../info.txt

all: clean build test bench

test: build
	./partialsums $(NTEST) > $(FILE)
	$(if diff $(FILE) ../$(FILE), @echo ">> partialSums plain-C: OK",\
	 	@echo ">> partialSums plain-C: Failed")

bench: build
	$(TIME) --output=partialSums-plain-C-time.csv \
                ./partialsums $(NBENCH) > /dev/null
	gzip -c ./partialsums |wc -c > partialsums-plain-C-size.csv


build:
	$(GCC) $(GCCOPTS) partialsums.c -o partialsums

clean:
	rm -fr *~ partialsums $(FILE) *.csv

