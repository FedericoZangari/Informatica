#include <iostream>

using namespace std;

template<typename t>

t sum(t a, t b){
	return a + b;
}

int main(){

	double x=5.1, y=6.6;
	
	cout << sum(x,y) << endl;

	int q = 10, p = 12;
	cout << sum(q,p) << endl;



	return 0;
}
