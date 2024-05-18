void esercizio1(){
	TF1 *f = new TF1 ("f", "sin(x*x)/x + 0.01", -3,3);
	
	f->SetTitle("Esercizio 1");
	f->GetXaxis()->SetTitle("x");
	f->GetYaxis()->SetTitle("y");
	f->SetLineColor(kRed+3);
	
	f->Draw();
}
