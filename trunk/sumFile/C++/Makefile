# vala-benchmarks
# sumFile C++ bench makefile

include ../../Make.header
include ../info.txt

all: clean build test bench

test: build
	./sumcol <../$(INTESTFILE) > $(OUTFILE)
	$(if $(diff $(OUTFILE) ../$(OUTFILE)), @echo ">> sumFile C++: OK",\
	 	@echo ">> sumFile C++: Failed")

bench: build
	gzip -dc ../$(GZINFILE) > ../$(INFILE)
	$(TIME) --output=sumFile-C++-time.csv \
		./sumcol <../$(INFILE) > /dev/null
	$(MEMORY) --output=sumFile-C++-mem.csv \
		./sumcol <../$(INFILE) > /dev/null
	$(STRIP) ./sumcol
	gzip -c ./sumcol |wc -c > sumFile-C++-size.csv

build:
	$(GPP) $(GPPOPTS) sumcol.cpp -o sumcol

clean:
	rm -fr *~ sumcol $(OUTFILE) *.csv ../$(INFILE)

