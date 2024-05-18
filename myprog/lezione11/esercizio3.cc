#include <iostream>
#include "TCanvas.h"
#include "TF1.h"
#include "TApplication.h"
#include "TH1F.h"
#include "TStyle.h"

int main(int argc, char **argv){
	TApplication app("App", &argc, argv);
	
	TCanvas *c = new TCanvas("c", "Esercizio3", 800,800);
	TH1F *h1 = new TH1F("h1", "gaus", 100, -4, 4);
	h1->FillRandom("gaus", 5000);
	h1->Draw();
	h1->GetXaxis()->SetTitle("x");
	h1->GetYaxis()->SetTitle("y");
	h1->SetFillColor(kGreen+2);
	h1->SetLineColor(kRed-1);
	
	TF1 *f = new TF1("f", "gaus", -4, 4);
	h1->Fit(f);
	h1->Draw("Same");
	
	gStyle->SetOptFit();
	c->SaveAs("esercizio3.png");
	
	app.Run();
	return 0;
}
