# vala-benchmarks
# mandelbrot plain-C bench makefile

include ../../Make.header
include ../info.txt

all: clean build test bench

test: build
	./mandelbrot $(NTEST) > $(FILE)
	$(if $($(diff $(FILE) ../$(FILE))), @echo ">> mandelbrot plain-C: OK",\
	 	@echo ">> mandelbrot plain-C: Failed")

bench: build
	$(TIME) --output=mandelbrot-plain-C-time.csv \
		./mandelbrot $(NBENCH) > /dev/null
	$(MEMORY) --output=mandelbrot-plain-C-mem.csv \
		./mandelbrot $(NBENCH) > /dev/null
	$(STRIP) ./mandelbrot
	gzip -c ./mandelbrot |wc -c > mandelbrot-plain-C-size.csv

build:
	$(GCC) $(GCCOPTS) mandelbrot.c -o mandelbrot

clean:
	rm -fr *~ mandelbrot $(FILE) *.csv

