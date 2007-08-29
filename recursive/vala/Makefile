# vala-benchmarks
# recursive vala bench makefile

include ../../Make.header
include ../info.txt

all: clean build test bench

test: build
	./recursive $(NTEST) > $(FILE)
	$(if diff $(FILE) ../$(FILE), @echo ">> recursive Vala: OK",\
	 	@echo ">> recursive Vala: Failed")

bench: build
	$(TIME) --output=recursive-vala.csv \
		./recursive $(NBENCH) > /dev/null

build:
	$(VALAC) $(VALACOPTS) recursive.vala
	$(GCC) $(GCCOPTS) recursive.c -o recursive

clean:
	rm -fr *~ recursive.{c,h} recursive $(FILE) *.csv
