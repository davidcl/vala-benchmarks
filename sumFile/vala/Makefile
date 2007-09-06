# vala-benchmarks
# sumFile vala bench makefile

include ../../Make.header
include ../info.txt

all: clean build test bench

test: build
	./sumcol <../$(INTESTFILE) > $(OUTFILE)
	$(if diff $(OUTFILE) ../$(OUTFILE), @echo ">> sumFile Vala: OK",\
	 	@echo ">> sumFile Vala: Failed")

bench: build
	gunzip ../$(GZIPINFILE) -c > ../$(INFILE)
	$(TIME) --output=sumFile-vala-time.csv \
		./sumcol <../$(INFILE) > /dev/null
	$(STRIP) ./sumcol
	$(GZIP) -c ./sumcol |wc -c > sumFile-vala-size.csv

build:
	$(VALAC) $(VALACOPTS) sumcol.vala
	$(GCC) $(GCCOPTS) sumcol.c -o sumcol

clean:
	rm -fr *~ sumcol sumcol.{c,h} $(OUTFILE) *.csv ../$(INFILE)

