# vala-benchmarks
# nBody plain-C bench makefile

include ../../Make.header
include ../info.txt

all: clean build test bench

test: build
	./nbody $(NTEST) > $(FILE)
	$(if $($(diff $(FILE) ../$(FILE))), @echo ">> nBody plain-C: OK",\
	 	@echo ">> nBody plain-C: Failed")

bench: build
	$(TIME) --output=nbody-plain-C-time.csv \
		./nbody $(NBENCH) > /dev/null
	$(MEMORY) --output=nbody-plain-C-mem.csv \
		./nbody $(NBENCH) > /dev/null
	$(STRIP) ./nbody
	gzip -c ./nbody |wc -c > nbody-plain-C-size.csv

build:
	$(GCC) $(GCCOPTS) nbody.c -o nbody

clean:
	rm -fr *~ nbody $(FILE) *.csv

