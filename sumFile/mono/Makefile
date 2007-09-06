# vala-benchmarks
# sumFile mono bench makefile

include ../../Make.header
include ../info.txt

all: clean build test bench

test: build
	$(MONORUN) sumcol.exe <../$(INTESTFILE) > $(OUTFILE)
	$(if diff $(FILE) ../$(FILE), @echo ">> sumFile mono: OK",\
	 	@echo ">> sumFile mono: Failed")

bench: build
	$(GZIP) -d ../$(GZIPINFILE) -c > ../$(INFILE)
	$(TIME) --output=sumFile-mono-time.csv \
		$(MONORUN) sumcol.exe <../$(INFILE) > /dev/null
	$(GZIP) -c sumcol.exe |wc -c > mandelbrot-mono-size.csv
	
build:
	$(MONOC) $(MONOCOPTS) sumcol.cs
#Ahead of time mode
	$(MONORUN) $(MONORUNOPTS) sumcol.exe > /dev/null

clean:
	rm -fr *~ sumcol.exe *.so $(OUTFILE) *.csv ../$(INFILE)

