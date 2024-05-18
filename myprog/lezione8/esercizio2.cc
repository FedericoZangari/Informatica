#include <iostream>
#include "funzioni.h"

using namespace std;

void print(double m, double n){
	cout << m << "\t" << n << endl;
}

int main(){
	double x = 5;
	double y = 10;
	
	print(x, y);
	
	scambia1(x, y);
	print(x, y);
	
	scambia2(&x, &y);
	print(x, y);
	
	return 0;
}
