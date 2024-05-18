#include <iostream>

using namespace std;

int main(){
	int n, pari=0, dis=0;
	
	for(;;){
		cin >> n;
		if(cin.eof()) break;
		if(n%2==0) pari++;
			else dis++;
		}
	
	cout << "I numeri pari sono: " << pari << endl;
	cout << "I numeri dispari sono: " << dis << endl;
	
	return 0;
}
