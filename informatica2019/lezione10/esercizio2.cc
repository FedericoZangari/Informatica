#include <iostream>
#include <fstream>
#include "TGraph.h"
#include "TApplication.h"
#include "TCanvas.h"
#include "TF1.h"
#include "TGraphErrors.h"
#include "TStyle.h"
#include "TStyle.h"

using namespace std;

const int N = 100;



int main(int argc, char **argv){
	TApplication app("App", &argc, argv);
	double t[N], y[N];
	double yerr[N] , xerr[N];
	
	fstream f;
	f.open("data2.dat", ios::in);
	if(!f.good()){
		cout << "error" << endl;
		return -1;
	}
	
	for(int i=0; i < N; i++){
		f >> t[i];
		f >> y[i];
		yerr[i] = 0.1;
		xerr[i] = 0;
	}
	f.close();
	
	TCanvas *c = new TCanvas("c", "Esercizio2", 800, 800);
	
	TGraphErrors *g = new TGraphErrors(N, t, y, xerr, yerr);
	
		
	g->Draw("AL*");
	g->SetMarkerColor(kBlue);
	
	TF1 *f1 = new TF1("f1", "0.5 * [0] * x^2", 0,1);

	g->Fit(f1);
	g->Draw("same");
	//cout << f1->GetChisquare() << endl << f1->GetParameter(0) << endl;
	gStyle->SetOptFit();
	f1->SetTitle("Esercizio2");
	c->SaveAs("esercizio2.png");
	
	
	app.Run();
	return 0;
}
