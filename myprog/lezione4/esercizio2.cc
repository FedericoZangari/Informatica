#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	double a, b, c, d;
	double x1, x2;
	double r, imm;
	
	cout << "a x^2 + b x + c = 0" << endl;
	cout << "Inserisci a: ";
	cin >> a;
	cout << "Inserisci b: ";
	cin >> b;
	cout << "Inserisci c: ";
	cin >> c;
	
	d = b*b - 4*a*c;
	
	if(d==0){
		x1= -b / (2*a);
		x2 = x1;
		cout << "x1: " << x1 << endl << "x2: " << x2 <<endl;
		}
	if(d > 0){
		x1= (-b - sqrt(d))/(2 * a);
		x2= (-b + sqrt(d))/(2 * a);
		cout << "x1: " << x1 << endl << "x2: " << x2 <<endl;
		}
	if(d < 0){
		r = (- b) / (2* a);
		imm = ( sqrt(-d) ) / (2 * a);
		cout << "x1: " << r << " + " << imm << "i" << endl 
			 << "x2: " << r << " - " << imm << "i" << endl;
		}
	return 0;
}
