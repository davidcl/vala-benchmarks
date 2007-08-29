# vala-benchmarks
# mandelbrot plain-C bench makefile

include ../../Make.header
include ../info.txt

all: clean build test bench

test: build
	./mandelbrot $(NTEST) > $(FILE)
	$(if diff $(FILE) ../$(FILE), @echo ">> mandelbrot plain-C: OK",\
	 	@echo ">> mandelbrot plain-C: Failed")

bench: build
	$(TIME) --output=mandelbrot-plain-C.csv \
		./mandelbrot $(NBENCH) > /dev/null

build:
	$(GCC) $(GCCOPTS) mandelbrot.c -o mandelbrot

clean:
	rm -fr *~ mandelbrot $(FILE) *.csv

