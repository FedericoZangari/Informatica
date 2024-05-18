#include <iostream>
#include "TCanvas.h"
#include "TF1.h"
#include "TApplication.h"
#include "TH1F.h"
#include "TStyle.h"
#include <fstream>

const int N = 10000;
using namespace std;

int main(int argc, char **argv){
	TApplication app("App", &argc, argv);
	
	fstream f;
	double *x = new double[N];
	
	f.open("data4.dat", ios::in);
	if(!f.good()){
		cout << "error" << endl;
		return -1;
	}
	
	
	TCanvas *c = new TCanvas("c", "Esercizio4", 800,800);
	TH1F *h1 = new TH1F("h1", "Esercizio4", 50, -20, 25);
	
	for(int i=0; i < N; i++){
		f >> x[i];
		h1->Fill(x[i]);
	}
	h1->Draw();
	h1->GetXaxis()->SetTitle("x");
	h1->GetYaxis()->SetTitle("y");
	h1->SetFillColor(kAzure+6);
	h1->SetLineColor(kRed-1);
	
	//TF1 *f = new TF1("f", "gaus", -4, 4);
	//h1->Fit(f);
	//h1->Draw("Same");
	
	//gStyle->SetOptFit();
	c->SaveAs("esercizio4.png");
	
	delete x;
	app.Run();
	return 0;
}
