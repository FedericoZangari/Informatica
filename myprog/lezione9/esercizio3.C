void esercizio3(){
	
	TCanvas *c1 = new TCanvas("c1", "plot1", 600,400);
	TF1 *f1 = new TF1 ("f1", "x^2", -5,5);
	
	f1->SetTitle("Esercizio 3");
	f1->GetXaxis()->SetTitle("x");
	f1->GetYaxis()->SetTitle("y");
	f1->SetLineColor(kRed+3);
	
	f1->Draw();
	
	c1->SaveAs("c1.png");
	
	TCanvas *c2 = new TCanvas("c2", "plot2", 600,400);
	TF1 *f2 = new TF1 ("f2", "sin(x)/x", -5,5);
	
	f2->SetTitle("Esercizio 3");
	f2->GetXaxis()->SetTitle("x");
	f2->GetYaxis()->SetTitle("y");
	f2->SetLineColor(kBlue+3);
	
	f2->Draw();
	
	c2->SaveAs("c2.png");
}
