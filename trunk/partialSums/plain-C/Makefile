# vala-benchmarks
# partialSums plain-C bench makefile

include ../../Make.header
include ../info.txt

all: clean build test bench

test: build
	./partialSums $(NTEST) > $(FILE)
	$(if diff $(FILE) ../$(FILE), @echo ">> partialSums plain-C: OK",\
	 	@echo ">> partialSums plain-C: Failed")

bench: build
		
build:
	$(GCC) $(GCCOPTS) partialSums.c -o partialSums

clean:
	rm -fr *~ partialSums $(FILE)

