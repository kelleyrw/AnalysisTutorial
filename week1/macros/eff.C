{
/*     tree->Draw("tps_p4.pt()>>hden(125,0,250)", "fabs(tps_p4.pt()>0.05) && tps_charge!=0 && tps_nhits>=3 && fabs(tps_dz)<30.0 && fabs(tps_d0)<3.5"); */
/*     tree->Draw("tps_p4.pt()>>hnum(125,0,250)", "fabs(tps_p4.pt()>0.05) && tps_charge!=0 && tps_nhits>=3 && fabs(tps_dz)<30.0 && fabs(tps_d0)<3.5 && tps_matched"); */
/*     heff_vs_eta = (TH1*)hnum->Clone("heff_vs_eta"); */
/*     heff_vs_eta->Divide(hden); */
/*     heff_vs_eta->Draw(); */

/*         TpSelectorForEfficiencyVsEta = cms.PSet( */
/*             chargedOnly = cms.bool(True), */
/*             pdgId = cms.vint32(), */
/*             tip = cms.double(2.0), */
/*             signalOnly = cms.bool(True), */
/*             minRapidity = cms.double(-2.5), */
/*             lip = cms.double(30.0), */
/*             ptMin = cms.double(0.9), */
/*             maxRapidity = cms.double(2.5), */
/*             minHit = cms.int32(0), */
/*             stableOnly = cms.bool(False) */
/*         ), */

    TH1::SetDefaultSumw2(true);
    tree->Draw("tps_p4.eta()>>h_den(50, -2.5, 2.5)", "tps_charge!=0 && tps_p4.pt()>0.9 && fabs(tps_p4.eta())<2.5 && fabs(tps_lip)<30.0 && fabs(tps_tip)<3.5");
    tree->Draw("tps_p4.eta()>>h_num(50, -2.5, 2.5)", "tps_charge!=0 && tps_p4.pt()>0.9 && fabs(tps_p4.eta())<2.5 && fabs(tps_lip)<30.0 && fabs(tps_tip)<3.5 && tps_matched");
    h_eff_vs_eta = (TH1*)h_num->Clone("h_eff_vs_eta");
    h_eff_vs_eta->Divide(h_num, h_den, 1.0, 1.0, "B");
    h_eff_vs_eta->GetYaxis()->SetRangeUser(0.1, 1.1);
    h_eff_vs_eta->SetMarkerSize(0.75);
    h_eff_vs_eta->SetMarkerStyle(20);
    h_eff_vs_eta->SetMarkerColor(kBlack);
    h_eff_vs_eta->Draw();
}
