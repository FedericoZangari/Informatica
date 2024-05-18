#include <iostream>

using namespace std;

int main(){
	int matr;
	cout << "Inserire numero di matricola: ";
	cin >> matr;
	
	switch(matr){
		case 942373:
			cout << "Nome matricola\t: Federico Zangari" << endl;
			break;
		case 950606:
			cout << "Nome matricola\t: Alessandro Reverberi" << endl;
			break;
		default:
			cout << "Matricola non trovata" << endl;
			break;
		}
	
	return 0;
}
