#include <iostream>
using namespace std;

int main(){
	double tc, tk, tf;
	int scelta;
	
	cout << "Inserire la temperatura in gradi Celsius: ";
	cin >> tc;
	
	cout << "Premere 1 per conversione a Kelvin." << endl << "Premere 2 per conversione a Fahrenheit." <<
		endl<< "Opzione scelta: ";
	cin >> scelta;
	
	if(scelta == 1){
		tk = tc + 273.15;
		cout << "T Celsius= "<< tc << " --> " << "T Kelvin = " << tk << endl;
		}
		
	if(scelta == 2){
		tf = tc * 9.0 / 5.0 + 32.0;
		cout << "T Celsius= "<< tc << " --> " << "T Fahrenheit = " << tf << endl;
		}
		
	return 0;
}
	
