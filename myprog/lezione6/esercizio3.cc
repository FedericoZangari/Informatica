#include <iostream>
#include <cmath>
using namespace std;

int main(){
	
	double x[3] = {1,1,2};
	double a[3][3];
	double b[3][3];
	double m[3][3]= {0,0,0,0,0,0,0,0,0};
	double v[3];
	
	a[0][0] =2;
	a[0][1] =4;
	a[0][2] =1;
	a[1][0] =4;
	a[1][1] =1;
	a[1][2] =3;
	a[2][0] =1;
	a[2][1] =3;
	a[2][2] =-2;
	
	b[0][0] =1;
	b[0][1] =1;
	b[0][2] =1;
	b[1][0] =0;
	b[1][1] =1;
	b[1][2] =2;
	b[2][0] =1;
	b[2][1] =5;
	b[2][2] =0;
	
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			for(int k=0; k<3; k++){
				m[i][j]+=a[i][k]*b[k][j];
				}cout << m[i][j] << "\t";
			}cout << endl;
		}
	
	for(int i=0; i<3;i++){
		for(int j=0; j<3; j++){
		v[i]+=m[i][j]*x[j];
		}
		cout << v[i] << "\t";
	}
	cout << endl;
	return 0;
}
