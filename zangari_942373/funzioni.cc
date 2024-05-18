#include "funzioni.h"
#include <iostream>
#include "cmath"
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

evento *load(int &n, int &s, int &b)
{
    fstream f;
    
    f.open("eventi.dat", ios::in);
    if (!f.good())
    	cout << "error" << endl;
	
	double t;
	for(; ;){
		f >> t;
		if(f.eof()) break;
		n++;		
		}
	f.close();
	
    f.open("eventi.dat", ios::in);
    n = n / 9;
    
    evento *read = new evento[n];
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < 4; i++)
            f >> read[j].p1[i];
        for (int i = 0; i < 4; i++)
            f >> read[j].p2[i];
        f >> read[j].segnale;

        if (read[j].segnale == true)
            s++;
        else
            b++;
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

double media(evento v[], int n){
	double sum = 0, mean;
	for(int i = 0; i < n; i++){
		sum += v[i].massainv;
	}
	mean = sum / n;
	return mean;
}

float dist(float x1, float y1, float x2, float y2){
	float d;
	d = sqrt(pow(x1 - x2,2) + pow(y1 - y2,2));
	return d;
}

double devstd(evento w[], int n, double med){
	double scarto;
	for(int i = 0; i < n; i++)
		scarto += pow(w[i].massainv - med,2);
	return sqrt(scarto/n);
}

double max(evento v[], int n){
	double m=v[0].massainv;
	for(int i = 0; i < n; i++){
		if(v[i].massainv > m)
			m = v[i].massainv;
	}
	return m;
}


double min(evento v[], int n){
	double m=v[0].massainv;
	for(int i = 0; i < n; i++){
		if(v[i].massainv < m)
			m = v[i].massainv;
	}
	return m;
}


double calcmass(evento a){
	double mass;
	mass = sqrt(pow(a.p1[0] + a.p2[0], 2) - (pow(a.p1[1] + a.p2[1], 2) + 				pow(a.p1[2] + a.p2[2], 2) + pow(a.p1[3] + a.p2[3], 2)));
	return mass;
}

void sort(evento *v, int n){
	for(int i = 0; i< n-1; i++){
		for(int j = i+1; j < n; j++){
			if(v[i].massainv > v[j].massainv){
				evento tmp = v[i];
				v[i] = v[j];
				v[j] = tmp;
			}
		}
	}
}

/* prodotto tra 2 matrici

for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			for(int k=0; k<3; k++){
				m[i][j]+=a[i][k]*b[k][j];
				}cout << m[i][j] << "\t";
			}cout << endl;
		}
*/
