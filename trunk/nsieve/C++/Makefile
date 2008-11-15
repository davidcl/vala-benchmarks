# vala-benchmarks
# nsieve C++ bench makefile

include ../../Make.header
include ../info.txt

all: clean build test bench

test: build
	./nsieve $(NTEST) > $(FILE)
	$(if $($(diff $(FILE) ../$(FILE))), @echo ">> nsieve C++: OK",\
	 	@echo ">> nsieve C++: Failed")

bench: build
	$(TIME) --output=nsieve-C++-time.csv \
		./nsieve $(NBENCH) > /dev/null
	$(MEMORY) --output=nsieve-C++-mem.csv \
		./nsieve $(NBENCH) > /dev/null
	$(STRIP) ./nsieve
	gzip -c ./nsieve |wc -c > nsieve-C++-size.csv

build:
	$(GPP) $(GPPOPTS) nsieve.cpp -o nsieve

clean:
	rm -fr *~ nsieve $(FILE) *.csv

