#include <iostream>
#include <fstream>
#include <cmath>
#include "TApplication.h"
#include "TCanvas.h"
#include "TF1.h"
#include "TH1F.h"
#include "TAxis.h"
#include <string>
#include <sstream>
#include "funzioni.h"
using namespace std;


int main(int argc, char **argv){

	TApplication app("App", &argc, argv);
	
	stringstream sout;
	
	int N = 0, bl = 0, gr = 0, rd = 0;
    sfera *data = load(N, bl, gr, rd);
    
    sout << "Il numero totale di sfere e': " << N << endl;
    sout << "Il numero di sfere blu e': " << bl << endl;
    sout << "Il numero di sfere verdi e': " << gr << endl;
    sout << "Il numero di sfere rosse e': " << rd << endl;
    
    sout << endl <<  "printing completo" << endl;
    print(data, N, 2, sout);
    
    sort(data, N, bl);
    sout << endl << "printing ordinato" << endl;
    print(data, N, 2, sout);
    
    int bb = 0;
    sfera *blu = justblu(data, bl, bb);
    
    sout << "sfere rimaste: " << bb << endl;    
    sout << "sfere eliminate: " << bl - bb << endl << endl;
    
    print(blu, bb, 2, sout);
    
	float mx = max(blu, bb);
	float mn = min(blu, bb);
	
	
	TCanvas *c = new TCanvas("c", "istogramma diametri", 800, 800);
	TH1F *h = new TH1F("h", "diam", 5, mn - 0.001, mx + 				0.001);
	for(int i = 0; i < bb; i++)
		h->Fill(blu[i].diam);
	h->SetFillColor(kAzure);
	h->GetXaxis()->SetTitle("diam");
	h->GetYaxis()->SetTitle("frequency");
	h->Draw();
	
	print_and_clear_buffer(sout);
	app.Run();
	delete h;
	delete c;
	return 0;
}
