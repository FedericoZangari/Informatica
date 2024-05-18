{
	TCanvas *c = new TCanvas("c", "Esercizio2", 800,800);
	TH1F *h1 = new TH1F("h1", "gaus", 100, -4, 4);
	h1->FillRandom("gaus", 5000);
	h1->Draw();
	h1->GetXaxis()->SetTitle("x");
	h1->GetYaxis()->SetTitle("y");
	h1->SetFillColor(kYellow);
	h1->SetLineColor(kBlue);
	c->SaveAs("esercizio2.png");
}
