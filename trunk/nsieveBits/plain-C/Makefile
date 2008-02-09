# vala-benchmarks
# nsievebits plain-C bench makefile

include ../../Make.header
include ../info.txt

all: clean build test bench

test: build
	./nsievebits $(NTEST) > $(FILE)
	$(if diff $(FILE) ../$(FILE), @echo ">> nsieveBits plain-C: OK",\
	 	@echo ">> nsieveBits plain-C: Failed")

bench: build
	$(TIME) --output=nsievebits-plain-C-time.csv \
		./nsievebits $(NBENCH) > /dev/null
	$(MEMORY) --output=nsievebits-plain-C-mem.csv \
		./nsievebits $(NBENCH) > /dev/null
	$(STRIP) ./nsievebits
	gzip -c ./nsievebits |wc -c > nsievebits-plain-C-size.csv

build:
	$(GCC) $(GCCOPTS) nsievebits.c -o nsievebits

clean:
	rm -fr *~ nsievebits $(FILE) *.csv

