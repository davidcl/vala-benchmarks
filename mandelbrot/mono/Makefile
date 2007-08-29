# vala-benchmarks
# mandelbrot mono bench makefile

include ../../Make.header
include ../info.txt

all: clean build test bench

test: build
	$(MONORUN) mandelbrot.exe $(NTEST) > $(FILE)
	$(if diff $(FILE) ../$(FILE), @echo ">> mandelbrot mono: OK",\
	 	@echo ">> mandelbrot mono: Failed")

bench: build
	$(TIME) --output=mandelbrot-mono.csv \
		$(MONORUN) mandelbrot.exe $(NBENCH) > /dev/null
	
build:
	$(MONOC) $(MONOCOPTS) mandelbrot.cs
#Ahead of time mode
	$(MONORUN) $(MONORUNOPTS) mandelbrot.exe > /dev/null

clean:
	rm -fr *~ mandelbrot.exe *.so $(FILE) *.csv

