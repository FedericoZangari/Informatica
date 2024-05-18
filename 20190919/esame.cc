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
	
	int I = 0;
	ione *io = loadione(I);
	
	sout << "n ioni letti: " << I << endl;
	sout << endl << "descrizione di tutti gli ioni: " << endl;
	printione(io, I, sout);
	
	int E = 0;
	elettrone *el = loadelet(E);
	
	sout << "n elettroni letti: " << E << endl;
	sout << endl << "descrizione dei primi 5 elettroni: " << endl;
	printelet(el, 5, sout);
	
	int cat = 0;
	for(int i = 0; i < E; i++){
		cat += gotcha(&el[i], io, I);
	}
	
	sout << endl << "elettroni catturati: " << cat << endl;
	sout << endl << "ioni" << endl;
	printione(io, I, sout);
	sout << endl << "elettroni " << endl;
	printelet(el, E, sout);
	
	
	
	
	
	print_and_clear_buffer(sout);
	app.Run();
	//delete h;
	//delete c;
	return 0;
}
