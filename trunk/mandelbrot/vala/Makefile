# vala-benchmarks
# mandelbrot vala bench makefile

include ../../Make.header
include ../info.txt

all: clean build test bench

test: build
	./mandelbrot $(NTEST) > $(FILE)
	$(if diff $(FILE) ../$(FILE), @echo ">> mandelbrot Vala: OK",\
	 	@echo ">> mandelbrot Vala: Failed")

bench: build
	$(TIME) --output=mandelbrot-vala-time.csv \
		./mandelbrot $(NBENCH) > /dev/null
	$(STRIP) ./mandelbrot
	gzip -c ./mandelbrot |wc -c > mandelbrot-vala-size.csv

build:
	$(VALAC) $(VALACOPTS) mandelbrot.vala
	$(GCC) $(GCCOPTS) mandelbrot.c -o mandelbrot

clean:
	rm -fr *~ mandelbrot.{c,h} mandelbrot $(FILE) *.csv
