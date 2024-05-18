#include <iostream>
#include <ctime>
using namespace std;

const int n=10;

int main(){
	double v[n];
	double sum = 0;
	
	srand(time(NULL));
	for(int i = 0; i < n; i++){
		v[i]= rand() % 100;
		sum += v[i];
		cout << v[i] << endl;
		}
	
	cout << "Il valor medio dell'array e': " << (sum/n) << endl;
	
	return 0;
}
