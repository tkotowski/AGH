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

#include "vector.h"
using namespace std;

int main()
{
	try{
		Vector a(5); 
		Vector b(4);
		int m;		
		cin >> a;
		cin >> b;
		cin >> m;
		cout << a << " + " << b << " = " << a+b << endl;
		cout << a << " - " << b << " = " << a-b << endl;
		cout << a << " * " << b << " = " << a*b << endl;
		cout << a << " * " << m << " = " << a*m << endl;
		cout << m << " * " << a << " = " << m*a << endl;
		cout << a << " == " << b << " : " << ((a == b) ? "true" : "false") << endl;
		cout << a << " != " << b << " : " << ((a != b) ? "true" : "false") << endl;
		cout << a << " += " << b << " ; a = ";
		a += b;
		cout << a << endl;
		cout << a << " -= " << b << "; a = ";
		a -= b;
		cout << a << endl;
		cout << a << " *= " << m << "; a = ";
		a *= m;
		cout << a << endl;			
	}
	catch(Exception_NewFailed &e) { cout << "Brak pamięci" << endl; }
	catch(Exception_InvalidArgument& e) {cout << "Zły argument" << endl; }
}
