# vala-benchmarks
# sumFile plain-C bench makefile

include ../../Make.header
include ../info.txt

all: clean build test bench

test: build
	./sumcol <../$(INTESTFILE) > $(OUTFILE)
	$(if diff $(OUTFILE) ../$(OUTFILE), @echo ">> sumFile plain-C: OK",\
	 	@echo ">> sumFile plain-C: Failed")

bench: build
	gunzip ../$(GZIPINFILE) -c > ../$(INFILE)
	$(TIME) --output=sumFile-plain-C-time.csv \
		./sumcol <../$(INFILE) > /dev/null
	$(STRIP) ./sumcol
	$(GZIP) -c ./sumcol |wc -c > sumFile-plain-C-size.csv

build:
	$(GCC) $(GCCOPTS) sumcol.c -o sumcol

clean:
	rm -fr *~ sumcol $(OUTFILE) *.csv ../$(INFILE)

