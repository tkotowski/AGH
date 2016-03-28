puzzle_main: puzzle_main.o
	g++ -o puzzle_main puzzle_main.o

puzzle_main.o: puzzle_main.cpp
	g++ -Wall -c puzzle_main.cpp

puzzle.h: puzzle.h
	g++ -Wall -c puzzle.h

lista.h: lista.h
	g++ -Wall -c lista.h
