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

ione *loadione(int &n){

    ifstream f;
    
    f.open("ioni.dat", ios::in);
    
    if (!f.good())
    	cout << "error" << endl;
	
	float a, b, r;
	int c;
	
	for(;;){
		f >> a >> b >> r >> c;
		if(f.eof()) break;
		n++;		
		}
	f.close();
	
    f.open("ioni.dat", ios::in);
    
    
    ione *read = new ione[n];
    for (int j = 0; j < n; j++)
    {
        f >> read[j].x;
        f >> read[j].y;
        f >> read[j].r;
        f >> read[j].carica;
    }

    return read;
}

void printione(ione v[], int n, stringstream &ss){
	for(int i = 0; i < n; i++){
		ss << v[i].x << " " << v[i].y << " " <<
				v[i].r << " " << v[i].carica << endl;		
	}
	
}

elettrone *loadelet(int &n){

    ifstream h;
    
    h.open("elettroni.dat", ios::in);
    
    if (!h.good())
    	cout << "error" << endl;
	
	float a;
	
	for(;;){
		h >> a;
		if(h.eof()) break;
		n++;		
		}
	h.close();
	
    h.open("elettroni.dat", ios::in);
    
    n = n /2;
    elettrone *read = new elettrone[n];
    for (int j = 0; j < n; j++)
    {
        h >> read[j].x;
        h >> read[j].y;
        read[j].vx = 0;
        read[j].vy = 0;
        read[j].fx = 0;
        read[j].fy = 0;
        read[j].free = 1;
    }

    return read;
}

void printelet(elettrone v[], int n, stringstream &ss){
	for(int i = 0; i < n; i++){
		ss << v[i].x << " " << v[i].y << " " <<
				v[i].vx << " " << v[i].vy << " " << v[i].free << 					endl;		
	}
	
}

float dist(float x1, float y1, float x2, float y2){
	float d;
	d = sqrt(pow(x1 - x2,2) + pow(y1 - y2,2));
	return d;
}

int gotcha(elettrone *el, ione ions[], int nions){
	for(int i = 0; i < nions; i++){
		if(dist(ions[i].x, ions[i].y, el->x, el->y) < ions[i].r){
			el->free = 0;
			ions[i].carica --;
			return 1;
		}
	}
	return 0;
}

/*
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
