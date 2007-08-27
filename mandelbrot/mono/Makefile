# vala-benchmarks
# mandelbrot mono bench makefile

include ../../Make.header
include ../info.txt

all: clean build test bench

test: build
	$(MONORUN) mandelbrot.exe $(NTEST) > $(FILE)
	$(if diff $(FILE) ../$(FILE), @echo ">> Mandelbrot mono: OK",\
	 	@echo ">> Mandelbrot mono: Failed")

bench: build
	
	
build:
	$(MONOC) $(MONOCOPTS) mandelbrot.cs
#Ahead of time mode
	$(MONORUN) $(MONORUNOPTS) mandelbrot.exe > /dev/null

clean:
	rm -fr *~ mandelbrot.exe *.so $(FILE)

