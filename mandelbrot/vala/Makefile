# vala-benchmarks
# mandelbrot vala bench makefile

include ../../Make.header
include ../info.txt

all: clean build test bench

test: build
	./mandelbrot $(NTEST) > $(FILE)
	$(if diff $(FILE) ../$(FILE), @echo ">> Mandelbrot Vala: OK",\
	 	@echo ">> Mandelbrot Vala: Failed")

bench: build
	

build:
	$(VALAC) $(VALACOPTS) mandelbrot.vala
	$(GCC) $(GCCOPTS) mandelbrot.c -o mandelbrot

clean:
	rm -fr *~ mandelbrot.{c,h} mandelbrot $(FILE)
