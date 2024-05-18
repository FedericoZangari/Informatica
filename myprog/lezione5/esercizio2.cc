#include <iostream>

using namespace std;

int main(){
	int n;
	double sum=0, num;
	
	cout << "Scrivere quanti numeri si vuole inserire: ";
	cin >> n;
	
	for(int i=0; i<n; i++){
		cout << "Inserire il numero " << i+1 << " : ";
		cin >> num;
		sum += num;
		}
	
	double med;
	med = sum / n;
	
	cout << "La media e': " << med << endl;
	
	return 0;
}
