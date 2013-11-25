{
/*     tree->Draw("tps_p4.pt()>>hden(125,0,250)", "fabs(tps_p4.pt()>0.05) && tps_charge!=0 && tps_nhits>=3 && fabs(tps_dz)<30.0 && fabs(tps_d0)<3.5"); */
/*     tree->Draw("tps_p4.pt()>>hnum(125,0,250)", "fabs(tps_p4.pt()>0.05) && tps_charge!=0 && tps_nhits>=3 && fabs(tps_dz)<30.0 && fabs(tps_d0)<3.5 && tps_matched"); */
/*     heff_vs_eta = (TH1*)hnum->Clone("heff_vs_eta"); */
/*     heff_vs_eta->Divide(hden); */
/*     heff_vs_eta->Draw(); */

    tree->Draw("tps_p4.eta()>>hden(50,-2.5,2.5)", "tps_charge!=0 && tps_p4.pt()>1.0 && fabs(tps_p4.eta())<2.5 && tps_nhits>=3 && fabs(tps_dz)<30.0 && fabs(tps_d0)<3.5");
    tree->Draw("tps_p4.eta()>>hnum(50,-2.5,2.5)", "tps_charge!=0 && tps_p4.pt()>1.0 && fabs(tps_p4.eta())<2.5 && tps_nhits>=3 && fabs(tps_dz)<30.0 && fabs(tps_d0)<3.5 && tps_matched");
    heff_vs_pt = (TH1*)hnum->Clone("heff_vs_pt");
    heff_vs_pt->Divide(hden);
    heff_vs_pt->Draw();
}
