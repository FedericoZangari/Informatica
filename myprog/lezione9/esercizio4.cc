#include<iostream>
#include "TF1.h"
#include "TCanvas.h"
#include "TApplication.h"
#include "TAxis.h"

using namespace std;

int main(int argc, char **argv){
	TApplication app("App", &argc, argv);
	
	TCanvas *c1 = new TCanvas("c1", "plot1", 800,500);
	TF1 *f1 = new TF1 ("f1", "1/x", -10,10);
	
	f1->SetTitle("Esercizio 4");
	f1->GetXaxis()->SetTitle("x");
	f1->GetYaxis()->SetTitle("y");
	f1->SetLineColor(kRed+3);
	
	f1->Draw();
	
	c1->SaveAs("esercizio4.png");
	
	//delete!!!!!!!
	
	
	
	
	
	
	
	app.Run();
	return 0;
}
