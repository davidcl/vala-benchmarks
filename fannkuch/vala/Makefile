# vala-benchmarks
# fannkuch vala bench makefile

include ../../Make.header
include ../info.txt

all: clean build test bench

test: build
	./fannkuch $(NTEST) > $(FILE)
	$(if diff $(FILE) ../$(FILE), @echo ">> fannkuch Vala: OK",\
	 	@echo ">> fannkuch Vala: Failed")

bench: build
	$(TIME) --output=fannkuch-vala-time.csv \
		./fannkuch $(NBENCH) > /dev/null
	$(STRIP) ./fannkuch
	gzip -c ./fannkuch |wc -c > fannkuch-vala-size.csv

build:
	$(VALAC) $(VALACOPTS) fannkuch.vala
	$(GCC) $(GCCOPTS) fannkuch.c -o fannkuch

clean:
	rm -fr *~ fannkuch.{c,h} fannkuch $(FILE) *.csv
