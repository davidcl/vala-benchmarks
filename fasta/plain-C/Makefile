# vala-benchmarks
# fasta plain-C bench makefile

include ../../Make.header
include ../info.txt

all: clean build test bench

test: build
	./fasta $(NTEST) > $(FILE)
	$(if diff $(FILE) ../$(FILE), @echo ">> fasta plain-C: OK",\
	 	@echo ">> fasta plain-C: Failed")

bench: build
	$(TIME) --output=fasta-plain-C-time.csv \
		./fasta $(NBENCH) > /dev/null
	$(MEMORY) --output=fasta-plain-C-mem.csv \
		./fasta $(NBENCH) > /dev/null
	$(STRIP) ./fasta
	gzip -c ./fasta |wc -c > fasta-plain-C-size.csv

build:
	$(GCC) $(GCCOPTS) fasta.c -o fasta

clean:
	rm -fr *~ fasta $(FILE) *.csv

