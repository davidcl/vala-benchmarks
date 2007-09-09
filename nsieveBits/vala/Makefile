# vala-benchmarks
# nsievebits vala bench makefile

include ../../Make.header
include ../info.txt

all: clean build test bench

test: build
	./nsievebits $(NTEST) > $(FILE)
	$(if diff $(FILE) ../$(FILE), @echo ">> nsieveBits Vala: OK",\
	 	@echo ">> nsieveBits Vala: Failed")

bench: build
	$(TIME) --output=nsievebits-vala-time.csv \
		./nsievebits $(NBENCH) > /dev/null
	$(STRIP) ./nsievebits
	gzip -c ./nsievebits |wc -c > nsievebits-vala-size.csv

build:
	$(VALAC) $(VALACOPTS) nsievebits.vala
	$(GCC) $(GCCOPTS) nsievebits.c -o nsievebits

clean:
	rm -fr *~ nsievebits.{c,h} nsievebits $(FILE) *.csv
