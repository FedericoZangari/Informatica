#include "funzioni.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

void print_and_clear_buffer(stringstream &ss)
{
    cout << ss.str();
    ofstream outfile("risultati.dat", ios::out);
    outfile << ss.str();
    ss.clear();
}

sfera *load(int &n, int &b, int &g, int &r)
{
    ifstream f, h;
    
    f.open("sfere.dat", ios::in);
    h.open("tolleranze.dat", ios::in);
    
    if (!f.good() || !h.good())
    	cout << "error" << endl;
	
	float t;
	char c;
	
	for(;;){
		f >> t;
		f >> c;
		if(f.eof()) break;
		n++;		
		}
	f.close();
	
    f.open("sfere.dat", ios::in);
    
    float toll[3][2];
    for(int i = 0; i < 3; i++){
    	h >> c;
    	for(int j = 0; j < 2; j ++)
    		h >> toll[i][j];
    }
    
    h.close();
    sfera *read = new sfera[n];
    for (int j = 0; j < n; j++)
    {
        f >> read[j].diam;
        f >> read[j].col;
        if(read[j].col == 'b'){
        	b++;
        	read[j].exact = toll[0][0];
        	read[j].atoll = toll[0][1];
        }
        if(read[j].col == 'g'){
        	g++;
        	read[j].exact = toll[1][0];
        	read[j].atoll = toll[1][1];
        }
        if(read[j].col == 'r'){
        	r++;
        	read[j].exact = toll[2][0];
        	read[j].atoll = toll[2][1];
        }
        read[j].discr = read[j].diam - read[j].exact;
    }

    return read;
}

void print(sfera v[], int n, int type, stringstream &ss){
	for(int i = 0; i < n; i++){
		switch(type)
		{
			case 1:
				ss << v[i].diam << endl;
				break;
			case 2:
				ss << v[i].diam << " " << v[i].col << " " <<
					v[i].exact << " " << v[i].atoll <<  " " <<
					v[i].discr << endl;
				break;
		}
	}
	
}

void sort(sfera *v, int n, int b){
	for(int i = 0; i< n-1; i++){
		for(int j = i+1; j < n; j++){
			if(v[j].col == 'b'){
				sfera tmp = v[i];
				v[i] = v[j];
				v[j] = tmp;
			}
		}
	}
	
	for(int i = b; i< n-1; i++){
		for(int j = i+1; j < n; j++){
			if(v[j].col == 'g'){
				sfera tmp = v[i];
				v[i] = v[j];
				v[j] = tmp;
			}
		}
	}
	for(int i = 0; i< b-1; i++){
		for(int j = i+1; j < b; j++){
			if(v[i].discr > v[j].discr){
				sfera tmp = v[i];
				v[i] = v[j];
				v[j] = tmp;
			}
		}
	}
}

sfera *justblu(sfera v[], int n, int &b){
	for(int i = 0; i < n; i++){
		if(v[i].discr > v[i].atoll || v[i].discr < -v[i].atoll)
			b++;
	}
	b = n - b;
	sfera *left = new sfera[b];
	int i = 0;
	for(int j = 0; j < n; j++){
		if(v[j].discr < v[j].atoll && v[j].discr> -v[j].atoll){
			left[i] = v[j];
			i++;
		}
	}
	
	return left;
}

float max(sfera v[], int n){
	float m=v[0].diam;
	for(int i = 0; i < n; i++){
		if(v[i].diam > m)
			m = v[i].diam;
	}
	return m;
}


float min(sfera v[], int n){
	double m=v[0].diam;
	for(int i = 0; i < n; i++){
		if(v[i].diam < m)
			m = v[i].diam;
	}
	return m;
}

/*
double media(evento v[], int n){
	double sum = 0, mean;
	for(int i = 0; i < n; i++){
		sum += v[i].massainv;
	}
	mean = sum / n;
	return mean;
}


double devstd(evento w[], int n, double med){
	double scarto;
	for(int i = 0; i < n; i++)
		scarto += pow(w[i].massainv - med,2);
	return sqrt(scarto/n);
}




double calcmass(evento a){
	double mass;
	mass = sqrt(pow(a.p1[0] + a.p2[0], 2) - (pow(a.p1[1] + a.p2[1], 2) + 				pow(a.p1[2] + a.p2[2], 2) + pow(a.p1[3] + a.p2[3], 2)));
	return mass;
}*/



/* prodotto tra 2 matrici

for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			for(int k=0; k<3; k++){
				m[i][j]+=a[i][k]*b[k][j];
				}cout << m[i][j] << "\t";
			}cout << endl;
		}
*/
