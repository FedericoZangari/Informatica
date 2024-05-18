void esercizio2(){
	
	
	TF1 *f1 = new TF1 ("f1", "sin(x*x)/x + 0.01", -3,3);
	
	f1->SetTitle("Esercizio 2");
	f1->GetXaxis()->SetTitle("x");
	f1->GetYaxis()->SetTitle("y");
	f1->SetLineColor(kRed+3);
	
	f1->Draw();
	
	TF1 *f2 = new TF1 ("f2", "0.1*sin(4*x)/x", -3,3);
	f2->Draw("same");
	
	TF1 *f3 = new TF1 ("f1", "0.5*x ", -3,3);
	f3->SetLineColor(kGreen);
	f3->Draw("same");
}
