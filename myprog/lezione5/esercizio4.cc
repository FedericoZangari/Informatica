#include <iostream>
#include <fstream>
using namespace std;

int main(){
	
	// Declaring variables
	fstream f;
	double g, sum=0.0;
	int i=0;
	
	// Open file input
	f.open("data.dat", ios::in);
	
	
	// Compute mean
	for(; ;){
		
		f >> g;
		if(f.eof()) break;
		sum+= g;
		i++;		
		}
	g = sum / i;
	cout << "Il valore di g e': " << g << endl;
	return 0;
}
