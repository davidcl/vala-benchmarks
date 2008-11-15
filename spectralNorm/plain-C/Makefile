# vala-benchmarks
# spectralNorm plain-C bench makefile

include ../../Make.header
include ../info.txt

all: clean build test bench

test: build
	./spectralnorm $(NTEST) > $(FILE)
	$(if $(diff $(FILE) ../$(FILE)), @echo ">> spectralNorm plain-C: OK",\
	 	@echo ">> spectralNorm plain-C: Failed")

bench: build
	$(TIME) --output=spectralnorm-plain-C-time.csv \
		./spectralnorm $(NBENCH) > /dev/null
	$(MEMORY) --output=spectralnorm-plain-C-mem.csv \
		./spectralnorm $(NBENCH) > /dev/null
	$(STRIP) ./spectralnorm
	gzip -c ./spectralnorm |wc -c > spectralnorm-plain-C-size.csv

build:
	$(GCC) $(GCCOPTS) spectralnorm.c -o spectralnorm

clean:
	rm -fr *~ spectralnorm $(FILE) *.csv

