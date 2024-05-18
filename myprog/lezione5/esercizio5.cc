#include <iostream>
using namespace std;

int main(){
	int n;
	int uno=0, due=1, tre=0;
	cout << "Quanti numeri si vuole introdurre?" ;
	cin >> n;
	
	for(int i=0; i<n; i++){
		tre= due + uno;
		uno= due;
		due= tre;
		cout << tre << endl;
	}
	return 0;
}
	
