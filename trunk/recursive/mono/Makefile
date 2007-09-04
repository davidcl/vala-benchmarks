# vala-benchmarks
# recursive mono bench makefile

include ../../Make.header
include ../info.txt

all: clean build test bench

test: build
	$(MONORUN) recursive.exe $(NTEST) > $(FILE)
	$(if diff $(FILE) ../$(FILE), @echo ">> recursive mono: OK",\
	 	@echo ">> recursive mono: Failed")

bench: build
	$(TIME) --output=recursive-mono-time.csv \
		$(MONORUN) recursive.exe $(NBENCH) > /dev/null
	gzip -c recursive.exe |cat - /usr/bin/mono |wc -c > recursive-mono-size.csv
	
build:
	$(MONOC) $(MONOCOPTS) recursive.cs
#Ahead of time mode
	$(MONORUN) $(MONORUNOPTS) recursive.exe > /dev/null

clean:
	rm -fr *~ recursive.exe *.so $(FILE) *.csv

