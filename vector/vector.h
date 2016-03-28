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

#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

class Exception {};
class Exception_InvalidArgument: public Exception {};
class Exception_NewFailed : public Exception {};

class Vector
{
	private:
	int* numbers;
	int size;

	public:
	Vector(int arg_size = 2);
	Vector(const Vector& b);
	~Vector();

	Vector& operator= (const Vector& b);
	Vector operator+ (const Vector& b) const;
	Vector operator- (const Vector& b) const;
	int operator* (const Vector& b);
	Vector operator* (const int& b);
	friend Vector operator* (const int& a, const Vector& b);
	int& operator[] (size_t index); 
	const int& operator[] (size_t index) const;
	friend std::ostream& operator<< (std::ostream& out, const Vector& b);
	friend std::istream& operator>> (std::istream& in, Vector& b);
	bool operator== (Vector &b);
	bool operator!= (Vector &b);
	Vector& operator+= (const Vector &b);
	Vector& operator-= (const Vector &b);
	Vector& operator*= (const int& b);
};

#endif
