# vala-benchmarks
# nsieve vala bench makefile

include ../../Make.header
include ../info.txt

all: clean build test bench

test: build
	./nsieve $(NTEST) > $(FILE)
	$(if diff $(FILE) ../$(FILE), @echo ">> nsieve Vala: OK",\
	 	@echo ">> nsieve Vala: Failed")

bench: build
	$(TIME) --output=nsieve-vala-time.csv \
		./nsieve $(NBENCH) > /dev/null
	$(MEMORY) --output=nsieve-vala-mem.csv \
		./nsieve $(NBENCH) > /dev/null
	$(STRIP) ./nsieve
	gzip -c ./nsieve |wc -c > nsieve-vala-size.csv

build:
	$(VALAC) $(VALACOPTS) nsieve.vala
	$(GCC) $(GCCOPTS) nsieve.c -o nsieve

clean:
	rm -fr *~ nsieve.{c,h} nsieve $(FILE) *.csv
