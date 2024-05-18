#include<fstream>

void esercizio5(){
	
	fstream f;
	f.open("data.dat",ios::in);
	/*int i=0;
	for(;;){
		i++;
		if(f.eof()) break;
	}*/
	
	double x[100], y[100], y2[100];
	
	for(int j=0; j<100; j++){
		f >> x[j];
		f >> y[j];
		f >> y2[j];
		
	}
	
	
	TCanvas *c1 = new TCanvas("c1", "plot1", 600,400);
	TGraph *g = new TGraph(100, x, y);
	g->Draw("A*L");
	
	TF1 *f1= new TF1("f1", "pol1", -5,5);
	g->Fit(f1);
	g->Draw("same");
	c1->SaveAs("ese5_1.png");
	
	
	
	TCanvas *c2 = new TCanvas("c2", "plot2", 600,400);
	TGraph *p = new TGraph(100, x, y2);
	p->Draw("A*L");
	
	TF1 *f2= new TF1("f2", "[0]*x^2 + [1]*x + [2]", -5,5);
	p->Fit(f2);
	p->Draw("same");
	c2->SaveAs("ese5_2.png");
	
	f.close();
}
