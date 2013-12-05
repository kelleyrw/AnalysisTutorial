#include "HistTools.h"
#include "TH1.h"
#include "TCanvas.h"

void FormattedPlots()
{
    TH1Map hc;
    LoadHists(hc, "plots/tracking_eff_analysis.root");

    TCanvas* c1 = new TCanvas("c1", "c1", 800, 1200);
    c1->Divide(2,3);

    hc["h_phires_vs_eta_sigma"     ]->GetYaxis()->SetRangeUser(1e-5 , 1e-2);
    hc["h_cotthetares_vs_eta_sigma"]->GetYaxis()->SetRangeUser(1e-4 , 1e-1);
    hc["h_d0res_vs_eta_sigma"      ]->GetYaxis()->SetRangeUser(1e-4 , 1e-1);
    hc["h_dzres_vs_eta_sigma"      ]->GetYaxis()->SetRangeUser(1e-3 , 1e-1);
    hc["h_ptres_vs_eta_sigma"      ]->GetYaxis()->SetRangeUser(1e-3 , 1e-1);

    c1->cd(1)->SetLogy(); hc["h_phires_vs_eta_sigma"     ]->Draw();
    c1->cd(2)->SetLogy(); hc["h_cotthetares_vs_eta_sigma"]->Draw();
    c1->cd(3)->SetLogy(); hc["h_d0res_vs_eta_sigma"      ]->Draw();
    c1->cd(4)->SetLogy(); hc["h_dzres_vs_eta_sigma"      ]->Draw();
    c1->cd(5)->SetLogy(); hc["h_ptres_vs_eta_sigma"      ]->Draw();

    c1->Print("plots/sigma_res.pdf");
} 





