# vala-benchmarks
# partialSums mono bench makefile

include ../../Make.header
include ../info.txt

all: clean build test bench

test: build
	$(MONORUN) partialsums.exe $(NTEST) > $(FILE)
	$(if diff $(FILE) ../$(FILE), @echo ">> partialSums mono: OK",\
	 	@echo ">> partialSums mono: Failed")

bench: build
	$(TIME) --output=partialSums-mono.csv \
                $(MONORUN) partialsums.exe $(NBENCH) > /dev/null

build:
	$(MONOC) $(MONOCOPTS) partialsums.cs
#Ahead of time mode
	$(MONORUN) $(MONORUNOPTS) partialsums.exe > /dev/null

clean:
	rm -fr *~ partialsums.exe *.so $(FILE) partialSums-mono.csv

