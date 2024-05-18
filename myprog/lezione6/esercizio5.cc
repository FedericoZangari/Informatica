#include <iostream>
#include <fstream>
#include <cmath>
#define N 10000
using namespace std;

int main(){
	double mass[N];
	double y[N];
	double v[N]={0};
	double vmed;
	
	fstream f;
	
	f.open("data_higgs.dat",ios::in);
	for(int i=0; i<N; i++){
		f >> mass[i];
		}
	for(int i=0; i< N-1; i++){
		for(int j=i+1; j< N; j++){
			if(mass[i]>mass[j]){
				double tmp=mass[i];
				mass[i]=mass[j];
				mass[j]=tmp;
				}
			}
		}
	for(int i=0; i<N; i++){
		//cout << mass[i] << endl;
		}
	cout << "Il valore minimo e': " << mass[0] << endl;
	cout << "Il valore massimo e': " << mass[N-1] << endl;
	
	double bin[30];
	bin[0]=mass[0];
	for(int i=1; i<30; i++){
		bin[i] = bin[i-1] + 5;
		}
		
	double freq[30]= {0};
	freq[0]=1;
	for(int i=1; i<N; i++){
		for(int j=0; j<30; j++){
			if(mass[i]>bin[j] && mass[i]<=bin[j+1]) freq[j]++;
		}
	}
	int fmax=freq[0];
	int loc=0;
	for(int i=0; i<30; i++){
		cout << bin[i] << ": " << freq[i] << endl;
		if(freq[i]>fmax){
			fmax=freq[i];
			loc = i;
		}
	}
	cout << "La massa del bosone con frequenza maggiore e': " << bin[loc] << 				" GeV con frequenza: " << fmax << endl;
	return 0;
	}
		
