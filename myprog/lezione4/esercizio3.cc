#include <iostream>
#include <string>
using namespace std;

int main(){
	double age, h, w;
	string taglia;
	
	cout << "Inserire eta': ";
	cin >> age;
	cout << "Inserire altezza (in metri): ";
	cin >> h;
	cout << "Inserire peso: ";
	cin >> w;
	
	if(age <= 10)	taglia = "XS";
	
	if(age > 10 && age <= 18){
		if(h <= 1.10)  taglia = "XS";
		if(h > 1.10 && h <= 1.30 && w <= 40)  taglia = "S";
		if(h > 1.10 && h <= 1.30 && w > 40)  taglia = "M";
		if(h > 1.30 && h <= 1.60 )  taglia = "M";
		if(h > 1.70 )  taglia = "L";
		}
		
	if(age > 18 ){
		if(h <= 1.40 || w <= 40)  taglia = "XS";
		if(h > 1.40 && h <= 1.60 )  taglia = "S";
		if(h > 1.60 && h <= 1.70)  taglia = "M";
		if(h > 1.70 && h <= 1.90 )  taglia = "L";
		if(h > 1.90 )  taglia = "XL";
		}
		
	cout << "Taglia: " << taglia<< endl;
	return 0;
}
