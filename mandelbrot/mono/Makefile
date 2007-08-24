# vala-benchmarks
# mandelbrot mono bench makefile

include ../../Make.header
include ../info.txt

test: build
	$(MONORUN) $(MONORUNOPTS) mandelbrot.exe $(NTEST) > $(MANDELFILE)
	-@if diff $(MANDELFILE) ../$(MANDELFILE); then echo '>> Mandelbrot: OK'; else echo '>> Mandelbrot: Failed'; fi

bench: build
	

build:
	$(MONOC) $(MONOCOPTS) mandelbrot.cs 

clean:
	rm -fr *~ mandelbrot.exe $(MANDELFILE)
