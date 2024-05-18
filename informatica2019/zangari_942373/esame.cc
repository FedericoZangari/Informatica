#include <iostream>
#include <fstream>
#include <cmath>
#include "TApplication.h"
#include "TCanvas.h"
#include "TF1.h"
#include "TH1F.h"
#include "TAxis.h"
#include "funzioni.h"
#include <string>
#include <sstream>

using namespace std;
/*
struct evento{
	double p1[4];
	double p2[4];
	bool segnale;
	double massainv;
};*/

int main(int argc, char **argv){

	TApplication app("App", &argc, argv);
	
	stringstream sout;
	
	int N = 0, signal = 0, background = 0;
    evento *data = load(N, signal, background);
    
	sout << "numero eventi: " << N << endl;
	sout << "# eventi segnale: " << signal << endl;
	sout << "percentuale di segnale: " << (signal * 100.0)/N << " %" << endl;
	sout << "# eventi background: " << background << endl;
	sout << "percentuale di background: " << (background * 100.0)/N << " %" 				<< endl;
	
	sout << "prime 10 masse invarianti: " << endl;
	for(int i = 0; i< N; i++){
		data[i].massainv = calcmass(data[i]);
		if(i< 10){
			sout << data[i].massainv << endl;
		}
	}
	
	//sorting
	sort(data, N);
	
	sout << endl;
	sout << "printing descrizione completa primi 4 eventi: " << endl;
	for(int i=0; i < 4; i++){
		for(int k = 0; k < 4; k++){
			sout << data[i].p1[k] << endl;
		}
		
		for(int j = 0; j < 4; j++){
			sout << data[i].p1[j] << endl;
		}
			
		sout << data[i].segnale << endl;
		sout << data[i].massainv << endl << endl;
	}
	
	sout << "printing descrizione completa ultimi 4 eventi: " << endl;
	for(int i=N-4; i < N; i++){
		for(int k = 0; k < 4; k++){
			sout << data[i].p1[k] << endl;
		}
		
		for(int j = 0; j < 4; j++){
			sout << data[i].p1[j] << endl;
		}
			
		sout << data[i].segnale << endl;
		sout << data[i].massainv << endl << endl;
	}
	
	int s = signal, b = background;
	evento *sig = new evento[s];
	evento *back = new evento[b];
	
	//popolamento array con solo segnale e background
	int k = 0, j = 0;
	for(int i=0; i < N; i++){		
		if(data[i].segnale == true){
			sig[k] = data[i];
			k++;
		}
		else{
			back[j] = data[i];
			j++;
		}
	}
	
	//calcolo medie
	double medall, medsig, medback;
	medall = media(data, N);
	medsig = media(sig, s);
	medback = media(back, b);
	
	
	sout << endl << "medie" << endl << medall << endl;
	sout << medsig << endl;
	sout << medback << endl;
	
	double devall, devsig, devback;
	devall = devstd(data, N, medall);
	devsig = devstd(sig, s, medsig);
	devback = devstd(back, b, medback);
	
	sout << endl << "Deviazioni standard" << endl;
	sout << devall << endl;
	sout << devsig << endl;
	sout << devback << endl;
	
	double maxall, maxsig, maxback;
	maxall = max(data, N);
	maxsig = max(sig, s);
	maxback = max(back, b);
	
	sout << endl << "massimi" << endl;
	sout << maxall << endl;
	sout << maxsig << endl;
	sout << maxback << endl;
	
	double minall, minsig, minback;
	minall = min(data, N);
	minsig = min(sig, s);
	minback = min(back, b);
	
	sout << endl << "minimi" << endl;
	sout << minall << endl;
	sout << minsig << endl;
	sout << minback << endl;
	
	TCanvas *c = new TCanvas("c", "istogramma masse", 800, 800);
	TH1F *h = new TH1F("h", "masse", 30, minall - 0.00001, maxall + 				0.00001);
	for(int i = 0; i < N; i++)
		h->Fill(data[i].massainv);
	h->SetFillColor(kAzure);
	h->GetXaxis()->SetTitle("mass");
	h->GetYaxis()->SetTitle("frequency");
	h->Draw();
	
	print_and_clear_buffer(sout);
	app.Run();
	delete h;
	delete c;
	return 0;
}
