#include <iostream>
using namespace std;

int main(){
	
	double x=5.5, *p=NULL;
	
	cout << x << endl;
	cout << &x << endl;
	cout << p << endl;
	cout << &p << endl;
	
	p = &x;
	
	cout << p << endl;
	cout << *p << endl;
	
	cin >> *p;
	
	cout << x << endl;
	
	double *a= new double[10];
	
	for(int i=0; i< 10; i++){
		cout << &a[i] << endl;
		if(&a[i] - &a[i+1]>8 && i<=9) cout << "error" << endl;
		}
	
	delete[] a;
	
	return 0;
}
