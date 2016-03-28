all: main.o bib.o alg.o
	gcc main.o alg.o bib.o -o LIFEGAME
main.o: main.c
	gcc -Wall -c main.c

bib.o: bib.c bib.h
	gcc -Wall -c bib.c
alg.o: alg.c alg.h
	gcc -Wall -c alg.c
