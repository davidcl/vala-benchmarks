# vala-benchmarks
# fasta mono bench makefile

include ../../Make.header
include ../info.txt

all: clean build test bench

test: build
	$(MONORUN) fasta.exe $(NTEST) > $(FILE)
	$(if $($(diff $(FILE) ../$(FILE))), @echo ">> fasta mono: OK",\
	 	@echo ">> fasta mono: Failed")

bench: build
	$(TIME) --output=fasta-mono-time.csv \
		$(MONORUN) fasta.exe $(NBENCH) > /dev/null
	$(MEMORY) --output=fasta-mono-mem.csv \
		$(MONORUN) fasta.exe $(NBENCH) > /dev/null
	gzip -c fasta.exe |wc -c > fasta-mono-size.csv
	
build:
	$(MONOC) $(MONOCOPTS) fasta.cs
#Ahead of time mode
	$(MONORUN) $(MONORUNOPTS) fasta.exe > /dev/null

clean:
	rm -fr *~ fasta.exe *.so $(FILE) *.csv

