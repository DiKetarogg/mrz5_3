all: a.out

d: deb.out

a.out: main.cpp Teaching.hpp
	g++ -std=c++17 main.cpp

deb.out: main.cpp Teaching.hpp
	g++ -g3 -std=c++17 main.cpp -o deb.out

run: a.out
	./a.out
drun: deb.out
	gdb -tui deb.out
.PHONY: all d drun run
