matrices: main_matrix.o matrix.o vector.o
	g++ -Wall main_matrix.o matrix.o vector.o -o matrices

main.o: main_matrix.cpp matrix.h vector.h
	g++ -c main_matrix.cpp -o main_matrix.o

matrix.o: matrix.cpp matrix.h vector.h
	g++ -c matrix.cpp -o matrix.o

vector.o: vector.cpp vector.h
	g++ -c vector.cpp -o vector.o

vectors: main_vec.o vector.o
	g++ -Wall main_vec.o vector.o -o vectors

main_vec.o: main_vec.cpp vector.h
	g++ -c main_vec.cpp -o main_vec.o


clean:
	rm -f core text main_matrix.o main_vec.o matrix.o vector.o
