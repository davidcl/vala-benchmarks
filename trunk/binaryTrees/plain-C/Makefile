# vala-benchmarks
# binaryTrees plain-C bench makefile

include ../../Make.header
include ../info.txt

all: clean build test bench

test: build
	./binarytrees $(NTEST) > $(FILE)
	$(if diff $(FILE) ../$(FILE), @echo ">> binaryTrees plain-C: OK",\
	 	@echo ">> binaryTrees plain-C: Failed")

bench: build
	$(TIME) --output=binarytrees-plain-C-time.csv \
		./binarytrees $(NBENCH) > /dev/null
	$(MEMORY) --output=binarytrees-plain-C-mem.csv \
		./binarytrees $(NBENCH) > /dev/null
	$(STRIP) ./binarytrees
	gzip -c ./binarytrees |wc -c > binarytrees-plain-C-size.csv

build:
	$(GCC) $(GCCOPTS) binarytrees.c -o binarytrees

clean:
	rm -fr *~ binarytrees $(FILE) *.csv

