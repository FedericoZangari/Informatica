#include <iostream>
#include <cmath>
using namespace std;

int main(){
	
	double *v = new double[5];
	double *w = new double[5];
	double prod=0;
	
	v[0] =2;
	v[1] =5;
	v[2] =10;
	v[3] =20;
	v[4] =50;
	
	w[0] =10;
	w[1] =-5;
	w[2] =3;
	w[3] =1;
	w[4] =100;
	
	for(int i=0; i<5; i++)
		prod += w[i] * v[i];
	
	cout << "Il prodotto scalare tra v e w e': " << prod << endl;
	
	double *z = new double[5];
	
	for(int i=0; i<5; i++)
		z[i]= v[i];
	
	z[2]=0;
	
	double norm=0;
	for(int i=0; i<5; i++)
		norm += z[i]*z[i];
		
	norm = sqrt(norm);
	cout << "La norma di z e': " << norm << endl;
	
	for(int i=0; i<5; i++){
		z[i]= z[i]/norm;
		cout << "z[" << i<< "] = " << z[i] << endl;
		}
	
	
	delete[] v;
	delete[] w;
	delete[] z;
	return 0;
}
