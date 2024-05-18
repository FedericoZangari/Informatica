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

buca *loadbuca(int &n){
	fstream f;
    
    f.open("buche.dat", ios::in);
    if (!f.good())
    	cout << "error" << endl;
	
	float x, y, r;
	char l;
	for(; ;){
		f >> x >> y >> r;
		f >> l;
		if(f.eof()) break;
		n++;		
		}
	f.close();
	
    f.open("buche.dat", ios::in);
    
    buca *read = new buca[n];
    for (int i = 0; i < n; i++){
    	f >> read[i].xc >> read[i].yc >> read[i].rad >> 			read[i].lab;
    }
    
    return read;
}

void printbuca(buca v[], int n, int type, stringstream &ss){
	for(int i = 0; i < n; i++){
		switch(type)
		{
			case 1:
				ss << v[i].lab << " " << v[i].n_part << endl;
				break;
				
			case 2:
				ss << v[i].xc << " " << v[i].yc << " " <<
					v[i].rad << " " << v[i].lab << endl;
				break;
		}
	}
	
}

part *loadpart(int &n){
	fstream f;
    
    f.open("particelle.dat", ios::in);
    if (!f.good())
    	cout << "error" << endl;
	
	float x;
	
	for(; ;){
		f >> x;
		if(f.eof()) break;
		n++;		
		}
	f.close();
	
    f.open("particelle.dat", ios::in);
    n= n / 4;
    part *read = new part[n];
    for (int i = 0; i < n; i++){
    	f >> read[i].x >> read[i].y >> read[i].c >> read[i].m;
    }
    
    return read;
}

void printpart(part v[], int i, int n, stringstream &ss){
	for(; i < n; i++){
		ss << v[i].x << " " << v[i].y << " " <<
				v[i].c << " " << v[i].m << endl;
	}
	
}

float dist(float x1, float y1, float x2, float y2){
	float d;
	d = sqrt(pow(x1 - x2,2) + pow(y1 - y2,2));
	return d;
}

int dentro(buca b, part p[], int n){
	int k = 0;
	for(int i = 0; i < n; i++){
		if(dist(b.xc, b.yc, p[i].x, p[i].y) < b.rad)
			k++;
	}
	
	return k;
}

void assignment(buca b, part p[], int n){
	int k = 0;
	for(int i = 0; i < n; i++){
		if(dist(b.xc, b.yc, p[i].x, p[i].y) < b.rad){
			b.v_part[k] = p[i];
			k++;
		}
	}
}

void sort(buca *v, int n){
	for(int i = 0; i< n-1; i++){
		for(int j = i+1; j < n; j++){
			if(v[i].n_part < v[j].n_part){
				buca tmp = v[i];
				v[i] = v[j];
				v[j] = tmp;
			}
		}
	}
}
