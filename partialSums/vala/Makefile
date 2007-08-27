# vala-benchmarks
# partialSums vala bench makefile

include ../../Make.header
include ../info.txt

all: clean build test bench

test: build
	./partialSums $(NTEST) > $(FILE)
	$(if diff $(FILE) ../$(FILE), @echo ">> partialSums Vala: OK",\
	 	@echo ">> partialSums Vala: Failed")

bench: build
	

build:
	$(VALAC) $(VALACOPTS) partialSums.vala
	$(GCC) $(GCCOPTS) partialSums.c -o partialSums

clean:
	rm -fr *~ partialSums.{c,h} partialSums $(FILE)
