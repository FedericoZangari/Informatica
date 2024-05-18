#include <iostream>
#include <cmath>

using namespace std;

struct complex{
	double real;
	double imag;
};

void print(complex c){
	cout << "(" << c.real << ") , (" << c.imag << ")" << endl;
}

double modulo(complex d){
	double mod;
	mod = sqrt( d.real * d.real + d.imag * d.imag);
	return mod;	
}

complex somma(complex m, complex n){
	complex q;
	q.real = m.real + n.real;
	q.imag = m.imag + n.imag;
	return q;
}
int main(){
	//declaring variables
	complex a, b;
	
	//assignments
	a.real = 7;
	a.imag = 2;
	
	b = a;
	
	//printing test
	print(a);
	print(b);
	
	cout << modulo(a) << endl;
	
	complex z;
	z = somma(a, b);
	print(z);
	
	
	
	return 0;
}
