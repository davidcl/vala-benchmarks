# vala-benchmarks
# fasta vala bench makefile

include ../../Make.header
include ../info.txt

all: clean build test bench

test: build
	./fasta $(NTEST) > $(FILE)
	$(if diff $(FILE) ../$(FILE), @echo ">> fasta Vala: OK",\
	 	@echo ">> fasta Vala: Failed")

bench: build
	$(TIME) --output=fasta-vala-time.csv \
		./fasta $(NBENCH) > /dev/null
	$(STRIP) ./fasta
	gzip -c ./fasta |wc -c > fasta-vala-size.csv

build:
	$(VALAC) $(VALACOPTS) fasta.vala
	$(GCC) $(GCCOPTS) fasta.c -o fasta

clean:
	rm -fr *~ fasta.{c,h} fasta $(FILE) *.csv
