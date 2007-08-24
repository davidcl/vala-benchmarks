# vala-benchmarks 
# mandelbrot bench makefile

include ../Make.header

test bench: build
	-(cd mono; make $@)
        -(cd plain-C; make $@)
        -(cd vala; make $@)

build clean:
	-(cd mono; make $@)
	-(cd plain-C; make $@)
	-(cd vala; make $@)


