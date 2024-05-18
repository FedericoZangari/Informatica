#include <iostream>
#include <cmath>
using namespace std;

const int l=5, d=3;

double scalar(double a[], double b[], int n){
	double scalare=0;
	for(int i=0; i<l; i++){
		scalare += a[i]*b[i];
		}
	return scalare;
}

double norm(double c[], int n){
	double norma;
	norma = sqrt(scalar(c,c,l));
	return norma;
}

void scambia(double &a, double &b){
	double tmp;
	tmp = a;
	a = b;
	b = tmp;
	}		
			
int main(){
	// variables
	double v[l]={1,2,3,4,5};
	double w[l]={10, 2, 4, 3, 2};
	double m[3][3]={1, 2, 3, 4, 5, 6, 7, 8, 9};
	
	// scalar product
	cout << "il prodotto scalare e': " << scalar(v, w, l) << endl;
	
	// norm
	cout << "la norma del vettore v e': " << norm(v, l) << endl;
	
	// matrix printing
	for(int i=0; i<d; i++){
		for(int j=0; j<d; j++){
			cout << m[i][j] << "\t";
			} cout << endl;
		}
	
	
	// computing transposed matrix
	cout << endl << "La matrice trasposta e': " << endl;
	for(int i = 0; i < d; i++){
		for (int j = i; j < d; j++){
			scambia(m[i][j], m[j][i]);
			}
		}
	
	// printing transposed matrix
	for(int i=0; i<d; i++){
		for(int j=0; j<d; j++){
			cout << m[i][j] << "\t";
			} cout << endl;
		}
	return 0;
}
