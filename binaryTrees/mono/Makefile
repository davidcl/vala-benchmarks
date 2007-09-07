# vala-benchmarks
# binaryTrees mono bench makefile

include ../../Make.header
include ../info.txt

all: clean build test bench

test: build
	$(MONORUN) binarytrees.exe $(NTEST) > $(FILE)
	$(if diff $(FILE) ../$(FILE), @echo ">> binaryTrees mono: OK",\
	 	@echo ">> binaryTrees mono: Failed")

bench: build
	$(TIME) --output=binarytrees-mono-time.csv \
		$(MONORUN) binarytrees.exe $(NBENCH) > /dev/null
	gzip -c binarytrees.exe |wc -c > binarytrees-mono-size.csv
	
build:
	$(MONOC) $(MONOCOPTS) binarytrees.cs
#Ahead of time mode
	$(MONORUN) $(MONORUNOPTS) binarytrees.exe > /dev/null

clean:
	rm -fr *~ binarytrees.exe *.so $(FILE) *.csv

