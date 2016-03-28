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

#include "matrix.h"
using namespace std;

Matrix :: Matrix(int arg_rows, int arg_cols){ //Konstruktor z dwoma argumentami
	if(arg_rows < 1 || arg_cols < 1){
		rows = cols = 0;
		vectors = NULL;
		return;
	}

	vectors = new Vector[arg_rows];
	if(vectors == NULL){
		rows = cols = 0;
		return;
	}
		
	for(int i = 0; i < arg_rows; i++){
		vectors[i] = Vector(arg_cols);
	}

	rows = arg_rows;
	cols = arg_cols;
}

Matrix :: Matrix(const Matrix& b){
	if(b.rows < 1 || b.cols < 1 || b.vectors == NULL){
		rows = cols = 0;
		vectors = NULL;
		return;
	}

	vectors = new Vector[b.rows];
	if(vectors == NULL){
		rows = cols = 0;
		std::cout << "blad";
		throw Exception_NewFailed();
	}

	for(int i = 0; i < b.rows; i++){
	vectors[i] = b.vectors[i];}

	rows = b.rows;
	cols = b.cols;
}

Matrix :: ~Matrix(){
	delete [] vectors;
}

Vector& Matrix :: operator[] (size_t index){
	if(index >= 0 && index < (size_t)rows && vectors != NULL) return vectors[index];
	throw Exception_InvalidArgument();
}

const Vector& Matrix :: operator[] (size_t index) const{
	if(index >= 0 && index < (size_t)rows && vectors != NULL) return vectors[index];
	throw Exception_InvalidArgument();
}

Matrix& Matrix :: operator= (const Matrix& b){
	if(this == &b) return *this;
	
	if(b.rows < 1 || b.cols < 1 || b.vectors == NULL){
		delete [] vectors;
		vectors = NULL;
		rows = cols = 0;
		return *this;
	}

	if(rows == b.rows){
		for(int i = 0; i < rows; i++) vectors[i] = b.vectors[i];
		return *this;
	}

	delete [] vectors;
	vectors = new Vector[b.rows];

	if(vectors == NULL){
		rows = cols = 0;
		throw Exception_NewFailed();
	}

	rows = b.rows;
	cols = b.cols;

	for(int i = 0; i < rows; i++) vectors[i] = b.vectors[i];

	return *this;
}

std::ostream& operator<< (std::ostream& out, const Matrix& b){
	if (b.rows < 1 || b.cols < 1 || b.vectors == NULL)	{
		out << "[0,0,0,...,0]" << std::endl << "..." << std::endl << "[0,0,0,...,0]" << std::endl;
	}
	else{
		for(int i = 0; i < b.rows; i++) out << b.vectors[i] << std::endl;
	}

	return out;
}

std::istream& operator>> (std::istream& in, Matrix& b)
{
	if(b.rows > 0 && b.cols > 0 && b.vectors != NULL){
		for(int i = 0; i < b.rows; i++) in >> b.vectors[i];
	}

	return in;
}

Matrix Matrix :: operator+ (const Matrix& b) const{
	if(b.rows < 1 || b.cols < 1 || b.vectors == NULL) return *this; 
	if(rows < 1 || cols < 1 || vectors == NULL) return b;

	int max_rows = rows > b.rows ? rows : b.rows;
	int max_cols = cols > b.cols ? cols : b.cols;
	Matrix c(max_rows, max_cols);

	for(int i = 0; i < max_rows; i++){
		if(i < rows) c.vectors[i] += vectors[i];
		if(i < b.rows) c.vectors[i] += b.vectors[i];
	}

	return c;
}

Matrix Matrix :: operator- (const Matrix& b) const{
	if(b.rows < 1 || b.cols < 1 || b.vectors == NULL) return *this; 
	if(rows < 1 || cols < 1 || vectors == NULL)
	{
		Matrix c(b.rows, b.cols);
		for(int i = 0; i < b.rows; i++)
		{
			c.vectors[i] -= b.vectors[i];
		}
		return c;
	}

	int max_rows = rows > b.rows ? rows : b.rows;
	int max_cols = cols > b.cols ? cols : b.cols;
	Matrix c(max_rows, max_cols);

	for(int i = 0; i < max_rows; i++){
		if(i < rows) c.vectors[i] += vectors[i];
		if(i < b.rows) c.vectors[i] -= b.vectors[i];
	}

	return c;
}

Matrix Matrix :: operator* (const int& b) const{
	if(rows < 1 || cols < 1 || vectors == NULL) return *this;
	
	Matrix c(rows, cols);
	for(int i = 0; i < rows; i++) c.vectors[i] = b*vectors[i];

	return c;
}

Matrix operator* (const int& a, const Matrix& b){
	if(b.rows < 1 || b.cols < 1 || b.vectors == NULL) return b;

	Matrix c(b.rows, b.cols);
	for(int i = 0; i < b.rows; i++) c.vectors[i] = a*b.vectors[i];

	return c;	
}

Matrix& Matrix :: operator+= (const Matrix &b){
	if(b.rows < 1 || b.cols < 1 || b.vectors == NULL) return *this;
	if(rows < 1 || cols < 1 || vectors == NULL){
		if(vectors != NULL) delete [] vectors;
		vectors = new Vector[b.rows];
		
		if(vectors == NULL){
			rows = cols = 0;
			throw Exception_NewFailed();
		}

		rows = b.rows;
		cols = b.cols;
		
		for(int i = 0; i < rows; i++) vectors[i] = b.vectors[i];

		return *this;
	}
	

	int max_rows = rows > b.rows ? rows : b.rows;

	Vector* new_vectors = new Vector[max_rows];
	if(new_vectors == NULL) throw Exception_NewFailed();

	for(int i = 0; i < max_rows; i++)	{
		if(i < rows) new_vectors[i] += vectors[i];
		if(i < b.rows) new_vectors[i] += b.vectors[i]; 
	}

	delete [] vectors;
	vectors = new_vectors;
	rows = max_rows;
	if(cols < b.cols) cols = b.cols;

	return* this;
}

Matrix& Matrix :: operator-= (const Matrix &b){	
	if(b.rows < 1 || b.cols < 1 || b.vectors == NULL) return *this;
	if(rows < 1 || cols < 1 || vectors == NULL){
		if(vectors != NULL) delete [] vectors;
		vectors = new Vector[b.rows];
		
		if(vectors == NULL){
			rows = cols = 0;
			throw Exception_NewFailed();
		}

		rows = b.rows;
		cols = b.cols;
		
		for(int i = 0; i < rows; i++) vectors[i] -= b.vectors[i];

		return *this;
	}
	
	
	int max_rows = rows > b.rows ? rows : b.rows;

	Vector* new_vectors = new Vector[max_rows];
	if(new_vectors == NULL) throw Exception_NewFailed();

	for(int i = 0; i < max_rows; i++){
		if(i < rows) new_vectors[i] += vectors[i];
		if(i < b.rows) new_vectors[i] -= b.vectors[i]; 
	}

	delete [] vectors;
	vectors = new_vectors;
	rows = max_rows;
	if(cols < b.cols) cols = b.cols;

	return* this;
}

Matrix& Matrix :: operator*= (const int& b){
	if(rows > 0 && cols > 0 && vectors != NULL){	
		for(int i = 0; i < rows; i++) vectors[i] *= b;
	}
	return *this;
}

bool Matrix :: operator== (Matrix &b){
	if(rows < 1 || cols < 1 || vectors == NULL)	{
		if(b.rows < 1 || b.cols < 1 || b.vectors == NULL) return true;
		else{
			Vector c(1);
			for(int i = 0; i < b.rows; i++){
				if(b.vectors[i] != c) return false;}
			return true;
		}
	}
	if(b.rows < 1 || b.cols < 1 || b.vectors == NULL){
		Vector c(1);
		for(int i = 0; i < rows; i++){
			if(vectors[i] != c) return false;
		}
		return true;
	}
	int min_rows = rows < b.rows ? rows : b.rows;
	for(int i = 0; i < min_rows; i++){
		if(vectors[i] != b.vectors[i]) return false;
	}
	if(rows == b.rows) return true;
	Matrix* bigger = rows > b.rows ? this : &b;
	
	Vector c(1);	

	for(int i = min_rows; i < bigger->rows; i++){
		if((*bigger).vectors[i] != c) return false;
	}
	return true;
}

bool Matrix :: operator!= (Matrix &b){
	return !(*this == b);
}

Matrix Matrix :: operator* (const Matrix& b) const{
	Matrix error(1,1);
	if(b.rows < 1 || b.cols < 1 || b.vectors == NULL || rows < 1 || cols < 1 || vectors == NULL || cols != b.rows) return error;

	Matrix c (b.rows, cols);
	
	for(int i = 0; i < cols; i++){
		for(int j = 0; j < b.rows; j++){
			for(int k = 0; k < cols; k++){
				c[i][j] += vectors[i][k] * b[k][j];
			}
		}
	}

	return c;
}
