# vala-benchmarks
# partialSums mono bench makefile

include ../../Make.header
include ../info.txt

all: clean build test bench

test: build
	$(MONORUN) partialSums.exe $(NTEST) > $(FILE)
	$(if diff $(FILE) ../$(FILE), @echo ">> partialSums mono: OK",\
	 	@echo ">> partialSums mono: Failed")

bench: build
	
build:
	$(MONOC) $(MONOCOPTS) partialSums.cs
#Ahead of time mode
	$(MONORUN) $(MONORUNOPTS) partialSums.exe > /dev/null

clean:
	rm -fr *~ partialSums.exe *.so $(FILE)

