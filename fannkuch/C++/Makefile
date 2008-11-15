# vala-benchmarks
# fannkuch C++ bench makefile

include ../../Make.header
include ../info.txt

all: clean build test bench

test: build
	./fannkuch $(NTEST) > $(FILE)
	$(if $($(diff $(FILE) ../$(FILE))), @echo ">> fannkuch C++: OK",\
	 	@echo ">> fannkuch C++: Failed")

bench: build
	$(TIME) --output=fannkuch-C++-time.csv \
		./fannkuch $(NBENCH) > /dev/null
	$(MEMORY) --output=fannkuch-C++-mem.csv \
		./fannkuch $(NBENCH) > /dev/null
	$(STRIP) ./fannkuch
	gzip -c ./fannkuch |wc -c > fannkuch-C++-size.csv

build:
	$(GPP) $(GPPOPTS) fannkuch.cpp -o fannkuch

clean:
	rm -fr *~ fannkuch $(FILE) *.csv

