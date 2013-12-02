{
    TH1::SetDefaultSumw2(true);
    tree->Draw("tps_p4.eta()>>h_den(50, -2.5, 2.5)", "tps_charge!=0 && tps_p4.pt()>0.9 && fabs(tps_p4.eta())<2.5 && tps_nhits>=3 && fabs(tps_lip)<30.0 && fabs(tps_tip)<3.5");
    tree->Draw("tps_p4.eta()>>h_num(50, -2.5, 2.5)", "tps_charge!=0 && tps_p4.pt()>0.9 && fabs(tps_p4.eta())<2.5 && tps_nhits>=3 && fabs(tps_lip)<30.0 && fabs(tps_tip)<3.5 && tps_matched");
    h_eff_vs_eta = (TH1*)h_num->Clone("h_eff_vs_eta");
    h_eff_vs_eta->Divide(h_num, h_den, 1.0, 1.0, "B");
    h_eff_vs_eta->GetYaxis()->SetRangeUser(0.1, 1.1);
    h_eff_vs_eta->SetMarkerSize(0.75);
    h_eff_vs_eta->SetMarkerStyle(20);
    h_eff_vs_eta->SetMarkerColor(kBlack);
    h_eff_vs_eta->Draw();
}
