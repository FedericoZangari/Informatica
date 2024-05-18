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
    //f.open(filename.c_str());
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
	//f.open(filename.c_str());
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
				double tmp = v[i].massainv;
				v[i].massainv = v[j].massainv;
				v[j].massainv = tmp;
			}
		}
	}
}
	
