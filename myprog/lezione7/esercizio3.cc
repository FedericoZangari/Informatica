#include <iostream>
#include <math.h>
using namespace std;

double gauss(double x){
	return ( 1/sqrt(2*M_PI) )* exp(-(x*x) /2);
	}

double integrate_gauss(double a, double b, double n){
	double d=(b-a)/n;
	double sum;
	for(int i=0; i<n; i++){
		sum += d*(gauss(a+i*d)+ gauss(a+ (i+1)*d))/2;
		}
	return sum;
	}
int main(){
	double x1, x2, step;
	cout << "insert a: " ;
	cin >> x1;
	cout << "insert b: " ;
	cin >> x2;
	cout << "insert number of steps: " ;
	cin >> step;
	cout << "the integral is: " << integrate_gauss(x1, x2, step) << endl;
	
	return 0;
}
