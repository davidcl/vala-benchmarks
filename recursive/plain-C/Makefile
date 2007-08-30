# vala-benchmarks
# recursive plain-C bench makefile

include ../../Make.header
include ../info.txt

all: clean build test bench

test: build
	./recursive $(NTEST) > $(FILE)
	$(if diff $(FILE) ../$(FILE), @echo ">> recursive plain-C: OK",\
	 	@echo ">> recursive plain-C: Failed")

bench: build
	$(TIME) --output=recursive-plain-C-time.csv \
		./recursive $(NBENCH) > /dev/null
	gzip -c ./recursive |wc -c > recursive-plain-C-size.csv

build:
	$(GCC) $(GCCOPTS) recursive.c -o recursive

clean:
	rm -fr *~ recursive $(FILE) *.csv

