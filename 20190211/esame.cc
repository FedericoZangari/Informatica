#include <iostream>
#include <fstream>
#include <cmath>
#include "TApplication.h"
#include "TCanvas.h"
#include "TF1.h"
#include "TH1F.h"
#include "TAxis.h"
#include "TGraph.h"
#include "funzioni.h"
#include <string>
#include <sstream>


using namespace std;


int main(int argc, char **argv){

	TApplication app("App", &argc, argv);
	
	stringstream sout;
	
	int B = 0;
	
	buca *bc = loadbuca(B);
	cout << "numero di buche lette: " << B << endl;
	
	printbuca(bc, B, 2, sout);
	
	int N = 0;
    part *data = loadpart(N);
    sout << "printing prime 3 particelle: " << endl;
    printpart(data, 0, 3, sout);
    sout << "printing ultime 3 particelle: " << endl;
    printpart(data, N - 3, N, sout);
    
    sout << endl << endl;
    
    for(int i = 0; i < B; i++){
    	bc[i].n_part = dentro(bc[i], data, N);
    	bc[i].v_part = new part[bc[i].n_part];    	
    	assignment(bc[i], data, N);
    	
    }
	
	sout << "descrizione particelle dentro cerchio A:" << endl;
	printpart(bc[0].v_part, 0, bc[0].n_part, sout);
	
	sort(bc, B);
	sout << "print campi lab e n_part del vettore ordinato per"<< 				" n_part decrescente" << endl;
	printbuca(bc, B, 1, sout);
	
	
	
	for(int i = 0; i < B; i++)
		printpart(bc[i].v_part, 0, bc[i].n_part, sout);
	
	
	
	TCanvas *c = new TCanvas("c", "particelle", 800, 800);
	TGraph *g1 = new TGraph();
  	
  	g1->SetMarkerColor(kBlue);
  	
  	
  	for(int i=0; i < B; i++){
		for(int j = 0; j < bc[i].n_part; j++){	
			g1->SetPoint(j, bc[i].v_part[j].x, bc[i].v_part[j].y);
		}
	}
  	
	g1->SetTitle("Esame");
 	g1->GetXaxis()->SetTitle("x coordinate");
 	g1->GetYaxis()->SetTitle("y coordinate");
	g1->Draw("A*");
	
	print_and_clear_buffer(sout);
	app.Run();
	delete g1;
	delete c;
	delete []bc;
	delete []data;
	return 0;
}
