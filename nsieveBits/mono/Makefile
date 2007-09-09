# vala-benchmarks
# nsieveBits mono bench makefile

include ../../Make.header
include ../info.txt

all: clean build test bench

test: build
	$(MONORUN) nsievebits.exe $(NTEST) > $(FILE)
	$(if diff $(FILE) ../$(FILE), @echo ">> nsieveBits mono: OK",\
	 	@echo ">> nsieveBits mono: Failed")

bench: build
	$(TIME) --output=nsievebits-mono-time.csv \
		$(MONORUN) nsievebits.exe $(NBENCH) > /dev/null
	gzip -c nsievebits.exe |wc -c > nsievebits-mono-size.csv
	
build:
	$(MONOC) $(MONOCOPTS) nsievebits.cs
#Ahead of time mode
	$(MONORUN) $(MONORUNOPTS) nsievebits.exe > /dev/null

clean:
	rm -fr *~ nsievebits.exe *.so $(FILE) *.csv

