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

int main(){
	try{
		Matrix a(2,2);
		Matrix b(2,2);
		int m;
		cin >> a;
		cin >> b;
		cin >> m;
		cout << a << "+\n" << b << "=\n" << a+b << endl;
		cout << a << "-\n" << b << "=\n" << a-b << endl;
		cout << a << "*\n" << b << "=\n" << a*b << endl;
		cout << a << "*\n" << m << "=\n" << a*m << endl;
		cout << m << "*\n" << a << "=\n" << m*a << endl;
		cout << a << "==\n" << b << ": " << ((a == b) ? "prawda" : "fałsz") << endl << endl;
		cout << a << "!=\n" << b << ": " << ((a != b) ? "prawda" : "fałsz") << endl << endl;
		cout << a << "+=\n" << b << "\na = \n";
		a += b;
		cout << a << endl;
		cout << a << "-=\n" << b << "\na = \n";
		a -= b;
		cout << a << endl;
		cout << a << "*=" << m << "\na = \n";
		a *= m;
		cout << a << endl;
	}
	catch(Exception_NewFailed &e) { cout << "Brak pamięci" << endl; }
	catch(Exception_InvalidArgument& e) {cout << "Zły argument" << endl; }
}
