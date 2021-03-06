/*	-----------------------------------------------------------------------------
	main_matrix.cpp
	-----------------------------------------------------------------------------
	Tomasz Kotowski
	Automatyka i Robotyka '14
	Grupa 1, WEAIIB, AGH
	tomasz.kotowski95@gmail.com
	http://student.agh.edu.pl/~kotowski/
	-----------------------------------------------------------------------------
	Krótkie podsumowanie pliku	
	-----------------------------------------------------------------------------
	"THE BEER-WARE LICENSE":
	Tomasz Kotowski wrote this file. As long as you retain this notice you
	can do whatever you want with this stuff. If we meet some day, and you think
	this stuff is worth it, you can buy me a beer in return.
	
	Yours sincerely,
	Tomasz Kotowski
	-----------------------------------------------------------------------------

*/

#ifndef MATRIX_H
#define MATRIX_H

#include "vector.h"

class Matrix{
	private:
	Vector* vectors;
	int rows;
	int cols;
	public:
	Matrix(int arg_rows = 2, int arg_cols = 2);
	Matrix(const Matrix&);
	~Matrix();
	Vector& operator[] (size_t index);
	const Vector& operator[] (size_t index) const;
	Matrix& operator= (const Matrix& b);
	Matrix operator+ (const Matrix& b) const;
	Matrix operator- (const Matrix& b) const;
	Matrix operator* (const Matrix& b) const;
	Matrix operator* (const int& b) const;
	friend Matrix operator* (const int& a, const Matrix& b);
	friend std::ostream& operator<< (std::ostream& out, const Matrix& b);
	friend std::istream& operator>> (std::istream& in, Matrix& b);
	bool operator== (Matrix &b);
	bool operator!= (Matrix &b);
	Matrix& operator+= (const Matrix &b);
	Matrix& operator-= (const Matrix &b);
	Matrix& operator*= (const int& b);

};

#endif

