# vala-benchmarks
# binaryTrees vala bench makefile

include ../../Make.header
include ../info.txt

all: clean build test bench

test: build
	./binarytrees $(NTEST) > $(FILE)
	$(if diff $(FILE) ../$(FILE), @echo ">> binaryTrees Vala: OK",\
		@echo ">> binaryTrees Vala: Failed")

bench: build
	$(TIME) --output=binarytrees-vala-time.csv \
		./binarytrees $(NBENCH) > /dev/null
	$(MEMORY) --output=binarytrees-vala-mem.csv \
		./binarytrees $(NBENCH) > /dev/null
	$(STRIP) ./binarytrees
	gzip -c ./binarytrees |wc -c > binarytrees-vala-size.csv

build:
	$(VALAC) $(VALACOPTS) binarytrees.vala
	$(GCC) $(GCCOPTS) binarytrees.c -o binarytrees

clean:
	rm -fr *~ binarytrees.{c,h} binarytrees $(FILE) *.csv
