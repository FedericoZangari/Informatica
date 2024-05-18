#include <iostream>
#include <fstream>
#include <cmath>
#include "TApplication.h"
#include "TCanvas.h"
#include "TF1.h"
#include "TH1F.h"
#include "TAxis.h"
#include "TGraph.h"
#include "TStyle.h"
#include "funzioni.h"
#include <string>
#include <sstream>

using namespace std;


int main(int argc, char **argv){

	TApplication app("App", &argc, argv);
	
	stringstream sout;
	
	int N = 0;
    evento *data = load(N, signal, background);
    
	
	
	
	
	
	
	
	
	
	
	
	TCanvas *c = new TCanvas("c", "istogramma masse", 800, 800);
	
	
	TH1F *h = new TH1F("h", "masse", 30, minall - 0.00001, maxall + 				0.00001);
	for(int i = 0; i < N; i++)
		h->Fill(data[i].massainv);
	h1->FillRandom("gaus", 5000);
	h->SetFillColor(kAzure);
	h->SetLineColor(kBlue);
	h->GetXaxis()->SetTitle("mass");
	h->GetYaxis()->SetTitle("frequency");
	h->Draw();
	gStyle->SetOptFit();
 	h->Fit("gaus");
 	
 	
	TGraph *g1 = new TGraph();
  	g1->SetMarkerColor(kBlue);
  	g1->SetMarkerStyle(39);
  	for(int i=0; i < B; i++){
		for(int j = 0; j < bc[i].n_part; j++){	
			g1->SetPoint(j, bc[i].v_part[j].x, bc[i].v_part[j].y);
		}
	}
	g1->GetXaxis()->SetRangeUser(0,1);
	g1->GetYaxis()->SetRangeUser(0,1);
	g1->Draw("A*");
	
	
	TGraphErrors *data = new TGraphErrors(N);
  	for (int i = 0; i < N; i++){
    	f >> t >> y;
     	data->SetPoint(i, t, y);
      	data->SetPointError(i, 0, 0.1);
    }
    TF1 *fit = new TF1("fit", "0.5*[0]*x^2");
	data->Fit(fit);
    
	print_and_clear_buffer(sout);
	app.Run();
	delete h;
	delete c;
	delete []bc;
	delete []data;
	return 0;
}
