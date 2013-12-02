#include <iostream>
#include <limits>
#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "TCut.h"
#include "TCanvas.h"

using namespace std;

void eff_compiled
(
    const std::string& input_file_name,
    const std::string& output_file_name = "eff.root",
    const std::string& suffix = "png",
    const long num_events = std::numeric_limits<long>::max(),
    const bool verbose = true
)
{
    // open the file and get the tree
    TFile input_file(input_file_name.c_str());
    if (input_file.IsZombie())
    {
        cout << "[eff_compiled] Error : " << input_file_name << " is not found or is zombie.  Exiting..." << endl;
        return;
    }
    TTree& tree = *dynamic_cast<TTree*>(input_file.Get("tree"));
    if (verbose) {cout << "[eff_compiled] tree is opened with " << tree.GetEntries() << " entries" << endl;}

    // book the historams
    TH1::SetDefaultSumw2(true);
    TH1* h_num_vs_eta = new TH1F("h_num_vs_eta", "Numerator Count vs |#eta|;|#eta|;Numerator Count"    , 50, -2.5, 2.5);
    TH1* h_den_vs_eta = new TH1F("h_den_vs_eta", "Denominator Count vs |#eta|;|#eta|;Denominator Count", 50, -2.5, 2.5);

    // define selection
    TCut tps_sel     = "tps_charge!=0 && tps_p4.pt()>0.9 && fabs(tps_p4.eta())<2.5 && fabs(tps_lip)<30.0 && fabs(tps_tip)<3.5";
    TCut tps_matched = "tps_matched";

    // fill the histograms with TTree::Draw
    tree.Draw("tps_p4.eta()>>h_den_vs_eta", tps_sel               , "goff", num_events);
    tree.Draw("tps_p4.eta()>>h_num_vs_eta", tps_sel && tps_matched, "goff", num_events);

    // make the efficiency plot
    TH1* h_eff_vs_eta = dynamic_cast<TH1*>(h_num_vs_eta->Clone("h_eff_vs_eta"));
    h_eff_vs_eta->SetTitle("Efficiency vs |#eta|;|#eta|;Efficiency");
    h_eff_vs_eta->Divide(h_num_vs_eta, h_den_vs_eta, 1.0, 1.0, "B");
    h_eff_vs_eta->GetYaxis()->SetRangeUser(0.1, 1.1);
    h_eff_vs_eta->SetMarkerSize(0.75);
    h_eff_vs_eta->SetMarkerStyle(20);
    h_eff_vs_eta->SetMarkerColor(kBlack);

    // write the output
    if (suffix == "png" or suffix == "pdf" or suffix == "eps")
    {
        if (verbose) {cout << "[eff_compiled] printing plots to plots directory." << endl;}
        TCanvas c1("c1", "c1", 600, 600);
        h_num_vs_eta->Draw(); c1.Print(Form("plots/%s_compiled.%s", h_num_vs_eta->GetName(), suffix.c_str()));
        h_den_vs_eta->Draw(); c1.Print(Form("plots/%s_compiled.%s", h_den_vs_eta->GetName(), suffix.c_str()));
        h_eff_vs_eta->Draw(); c1.Print(Form("plots/%s_compiled.%s", h_eff_vs_eta->GetName(), suffix.c_str()));
    }

    // output the file
    if (verbose) {cout << "[eff_compiled] writing plots to " << output_file_name << endl;}
    TFile output_file(output_file_name.c_str(), "RECREATE");
    h_num_vs_eta->Write();
    h_den_vs_eta->Write();
    h_eff_vs_eta->Write();
    output_file.Close();
}
