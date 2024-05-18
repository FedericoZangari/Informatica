#include <iostream>
#include <fstream>
#include "TGraph.h"
#include "TApplication.h"
#include "TCanvas.h"

using namespace std;

const double r= 0.5, xc = 0.5, yc = 0.5;
const int N = 1000;

struct punto{
	double x;
	double y;
};

double dist(punto p, int j){
	double d;
	d = sqrt(pow(xc-p.x,2) + pow(yc-p.y,2));
	return d;
}

int main(int argc, char **argv){
	TApplication app("App", &argc, argv);
	punto *p = new punto[N];
	
	fstream f;
	f.open("data1.dat", ios::in);
	if(!f.good()){
		cout << "error" << endl;
		return -1;
	}
	
	for(int i=0; i < N; i++){
		f >> p[i].x;
		f >> p[i].y;
	}
	
	TCanvas *c = new TCanvas("c", "Esercizio1", 800, 800);
	
	TGraph *g1 = new TGraph(N);
	for(int i=0; i < N; i++){
		if(dist(p[i], i) <= r){
			g1->SetPoint(i, p[i].x, p[i].y);
		}
	}
	g1->Draw("A*");
	g1->SetMarkerColor(kBlue);
	
	
	TGraph *g2 = new TGraph(N);
	for(int i=0; i < N; i++){
		if(dist(p[i], i) > r){
			g2->SetPoint(i, p[i].x, p[i].y);
		}
	}
	g2->Draw("*Same");
	g2->SetMarkerColor(kRed);
	g2->SetMarkerStyle(21);
	
	c->SaveAs("esercizio1.png");
	
	delete []p;
	app.Run();
	return 0;
}
