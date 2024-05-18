#include <iostream>
#include <fstream>
#include <cmath>
#define N 1000
using namespace std;

int main(){
	double x[N];
	double y[N];
	double v[N]={0};
	double vmed;
	
	fstream f;
	
	f.open("data_moto.dat",ios::in);
	for(int i=0; i<N; i++){
		f >> x[i];
		f >> y[i];
		v[i] = x[i]/y[i];
		vmed += v[i];
		}
	vmed= vmed/N;
	cout << "La velocità media e': " << vmed << endl;
	double dev=0;
	for(int i=0; i<N; i++){
		dev+=pow(v[i]-vmed,2);
		}
	dev= sqrt(dev/(N-1));
	cout << "La deviazione standard e': " << dev << endl;
	cout << vmed+dev << "\t" << vmed-dev<< endl;
	
	double min=v[0];
	double max=v[0];
	for(int i=0; i<N; i++){
		if(v[i]<min) min=v[i];
		if(v[i]>max) max=v[i];
		}
	cout << "Il valore minimo e': " << min << endl;
	cout << "Il valore massimo e': " << max << endl;
	return 0;
	}
		
