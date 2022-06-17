all: a.out

a.out:
	g++ -std=c++17 ./Routines/task4/routine.cpp ./Routines/catch/catch.hpp  ./Routines/catch/testlib.cpp Array.cpp   -I./

test: a.out
	./a.out

clean:
	rm a.out
