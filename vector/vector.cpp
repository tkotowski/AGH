/*	-----------------------------------------------------------------------------
	vector.cpp
	-----------------------------------------------------------------------------
	Tomasz Kotowski
	Automatyka i Robotyka '14
	WEAIIB, AGH
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

#include "vector.h"
using namespace std;

Vector :: Vector(int arg_size) { //Konstruktor
	}

	numbers = new int [arg_size];
	if(numbers == NULL){
		size = 0;
		throw Exception_NewFailed();
	}
	else{
		size = arg_size;
		for(int i = 0; i < size; i++) numbers[i] = 0;
	}
}

Vector :: Vector(const Vector& b) //Tutaj jest konstruktor kopiujący
{
	if(b.size < 1){
		size = 0;
		numbers = NULL;
	}
	else{
		numbers = new int[b.size];
		if(numbers == NULL){
			size = 0;
			throw Exception_NewFailed();
		}
		else{
			size = b.size;
			for(int i = 0; i < size; i++) numbers[i] = b.numbers[i];
		}
	}
}

Vector :: ~Vector() //destruktor
{
	delete [] numbers;
}

Vector& Vector :: operator= (const Vector& b) //a = b
{
	if(this == &b) return *this;
	if(b.size < 1 || b.numbers == NULL)
	{
		delete [] numbers;
		numbers = NULL;
		size = 0;
	}
	else	{
		if(size == b.size){
			for(int i = 0; i < size; i++) numbers[i] = b.numbers[i];
		}
		else{
			delete [] numbers;
			numbers = new int[b.size];

			if(numbers == NULL){
				size = 0;
				throw new Exception_NewFailed();
			}
			else{
				size = b.size;
				for(int i = 0; i < size; i++) numbers[i] = b.numbers[i];
			}
		}
	}

	return *this;
}

Vector Vector :: operator+ (const Vector& b) const //a+b
{
	if(b.size < 1 || b.numbers == NULL) return *this; //sprawdza czy macierz nie jest pusta
	if(size < 1 || numbers == NULL) return b;

	int max_size = size > b.size ? size : b.size;
	Vector c(max_size);
	for(int i = 0; i < max_size; i++)	{
		if(i < size) c.numbers[i] += numbers[i];
		if(i < b.size) c.numbers[i] += b.numbers[i];
	}
	return c;
}


Vector Vector :: operator- (const Vector& b) const //a-b
{
	if(b.size < 1 || b.numbers == NULL) return *this; //znowu sprawdzacz czy coś nie jest puste

	if(size < 1 || numbers == NULL)
	{
		Vector c(b.size);

		for(int i = 0; i < b.size; i++) c.numbers[i] = -c.numbers[i];
		return c;
	}

	int max_size = size > b.size ? size : b.size;

	Vector c(max_size);

	for(int i = 0; i < max_size; i++)
	{
		if(i < size) c.numbers[i] += numbers[i];
		if(i < b.size) c.numbers[i] -= b.numbers[i];
	}

	return c;
}


int Vector :: operator* (const Vector& b) //mnożę skalarnie
{
	if(b.size < 1 || b.numbers == NULL) return 0;
	if(size < 1 || numbers == NULL) return 0;

	int min_size = size > b.size ? b.size : size;

	int result = 0;

	for(int i = 0; i < min_size; i++)
	{
		result += numbers[i]*b.numbers[i];
	}

	return result;
}

Vector Vector :: operator* (const int& b) //mnożę liczbą
{
	if(size < 1 || numbers == NULL) return *this;
		
	Vector c(size);
	for(int i = 0; i < size; i++) c[i] = b*numbers[i];

	return c;
}


int& Vector :: operator[] (size_t index) //a[]
{
	if(index >= 0 && index < (size_t) size) return numbers[(size_t)index];
	else	throw Exception_InvalidArgument();
}

const int& Vector :: operator[] (size_t index) const
{
	if(index >= 0 && index < (size_t) size) return numbers[(size_t)index];
	else	throw Exception_InvalidArgument();
}

bool Vector :: operator== (Vector &b) //przyrównanie
{
	
	if(size < 1 || numbers == NULL)	{
		if(b.size < 1 || b.numbers == NULL) return true;
		else		{
			for(int i = 0; i < b.size; i++)
			{
				if(b.numbers[i] != 0) return false;
			}
			return true; //dogłębny sprawdzacz, czy nie są zerami
		}
	}
	
	if(b.size < 1 || b.numbers == NULL){
		for(int i = 0; i < size; i++){
			if(numbers[i] != 0) return false;
		}
		return true;
	} //ciąg dalszy sprawdzania
	
	int min = size < b.size ? size : b.size;
	for(int i = 0; i < min; i++)
	{
		if(numbers[i] != b.numbers[i]) return false;
	}
	if(size == b.size) return true;
	Vector* bigger = size > b.size ? this : &b; //sprawdza wielkości wektorów
	for(int i = min; i < bigger->size; i++)
	{
		if(bigger->numbers[i] != 0) return false;
	}

	return true;
}

bool Vector :: operator!= (Vector &b)
{
	return !(*this == b); //ze względu na specyfikę operatora ==
}


Vector& Vector :: operator+= (const Vector &b) //a+=b
{
	if(b.size < 1 || b.numbers == NULL)	return *this;  //a += 0
	if(size < 1 || numbers == NULL){//b jest prawidłowe
		if(numbers != NULL) delete [] numbers;
		numbers = new int[b.size];
			
		if(numbers == NULL){
			size = 0; throw Exception_NewFailed();
		}
			
		size = b.size;
		for(int i = 0; i < size; i++) numbers[i] = b.numbers[i];
			
		return *this;
	}

	int max = size > b.size ? size : b.size;

	int* new_numbers = new int [max];
	if(new_numbers == NULL)	throw Exception_NewFailed();

	for(int i = 0; i < max; i++)
	{
		new_numbers[i] = 0;
		if(i < size) new_numbers[i] += numbers[i];
		if(i < b.size) new_numbers[i] += b.numbers[i];
	}

	delete [] numbers;
	numbers = new_numbers;
	size = max;

	return *this;
}

Vector& Vector :: operator-= (const Vector &b) //a-=b
{
	if(b.size < 1 || b.numbers == NULL){
		return *this;
	}

	if(size < 1 || numbers == NULL)	{
		if(numbers != NULL) delete [] numbers;
		numbers = new int[b.size];
			
		if(numbers == NULL){
			size = 0;
			throw Exception_NewFailed();
		}
			
		size = b.size;		
		for(int i = 0; i < size; i++)	numbers[i] = -b.numbers[i];			
		return *this;
	}

	
	int max = size > b.size ? size : b.size;

	int* new_numbers = new int [max];
	if(new_numbers == NULL)	throw Exception_NewFailed();

	for(int i = 0; i < max; i++){
		new_numbers[i] = 0;
		if(i < size) new_numbers[i] += numbers[i];
		if(i < b.size) new_numbers[i] -= b.numbers[i];
	}

	delete [] numbers;
	numbers = new_numbers;
	size = max;

	return *this;
}

Vector& Vector :: operator*= (const int& b){
	if(size > 0 && numbers != NULL)
	{
		for(int i = 0; i < size; i++) numbers[i] *= b;
	}
	return *this;
}

std::ostream& operator<< (std::ostream& out, const Vector& b){
	if(b.size < 1 || b.numbers == NULL)	out << "[0,0,0,...,0]";
	else
	{
		out << "[";
		for(int i = 0; i < b.size-1; i++) out << b.numbers[i] << ",";
		out << b.numbers[b.size-1] << "]";
	}
	return out;
}

std::istream& operator>> (std::istream& in, Vector& b)
{
	if(b.size >= 1 && b.numbers != NULL)
	{
		for(int i = 0; i < b.size; i++) in >> b.numbers[i];
	}
	return in;
}

Vector operator* (const int& a, const Vector& b)
{
	if(b.size < 1 || b.numbers == NULL) return b;
		
	Vector c(b.size);
	for(int i = 0; i < b.size; i++) c[i] = a * b.numbers[i];
	return c;
}
