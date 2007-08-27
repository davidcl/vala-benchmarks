# vala-benchmarks
# mandelbrot plain-C bench makefile

include ../../Make.header
include ../info.txt

all: clean build test bench

test: build
	./mandelbrot $(NTEST) > $(FILE)
	$(if diff $(FILE) ../$(FILE), @echo ">> Mandelbrot plain-C: OK",\
	 	@echo ">> Mandelbrot plain-C: Failed")

bench: build
		
build:
	$(GCC) $(GCCOPTS) mandelbrot.c -o mandelbrot

clean:
	rm -fr *~ mandelbrot $(FILE)

