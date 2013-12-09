{
    tree->Draw("tps_p4.pt()>>h_pt_barrel(100,0,10)", "fabs(tps_p4.eta())<1.1");
    h_pt_barrel->Draw();
    h_pt_barrel->SetLineColor(kBlue);
    h_pt_barrel->SetLineWidth(2);
    h_pt_barrel->SetTitle("Tracking Particle p_{T} (Barrel);p_{T} (GeV)");
    h_pt_barrel->Draw();

    tree->Draw("tps_p4.pt()>>h_pt_endcap(100,0,10)", "fabs(tps_p4.eta())>1.1");
    h_pt_endcap->SetLineColor(kRed);
    h_pt_endcap->SetLineWidth(2);
    h_pt_endcap->SetTitle("Tracking Particle p_{T} (Endcap);p_{T} (GeV)");

    h_pt_endcap->Draw();
    h_pt_barrel->Draw("sames");
    TLegend leg(0.3, 0.8, 0.6, 0.5);
    leg.AddEntry(h_pt_endcap, "Endcap");
    leg.AddEntry(h_pt_barrel, "Barrel");
    leg.SetFillStyle(0);
    leg.Draw();
}
