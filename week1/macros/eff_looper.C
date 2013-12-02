#include <iostream>
#include <string>
#include <vector> 
#include <cstdlib>
#include <limits>
#include <algorithm>
#include "TFile.h"
#include "TChain.h"
#include "TBranch.h"
#include "TH1.h"
#include "TCanvas.h"
#include "TROOT.h"
#include "Math/LorentzVector.h"
typedef ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<double> > LorentzVector;

// Loop over tree and create the plots
void CreatePlots
(
    const std::string& input_file_name,
    const std::string& output_file_name = "plots/counts_vs_eta_looper.root",
    const long long num_events = std::numeric_limits<long>::max(),
    const bool verbose = false
)
{
    using namespace std;

    // get the Tree from the file 
    TChain chain("tree");
    chain.Add(input_file_name.c_str());
    if (verbose)
    {
        cout << "[CreatePlots] Loading tree \"Events\"" << endl;
        cout << "[CreatePlots] Tree contains " << chain.GetEntries() << " entries" << endl;
    }

    // book histograms
    TH1::SetDefaultSumw2(true);
    TH1F h_num_vs_eta("h_num_vs_eta", "Numerator Count vs |#eta|;|#eta|;Numerator Count"    , 50, -2.5, 2.5);
    TH1F h_den_vs_eta("h_den_vs_eta", "Denominator Count vs |#eta|;|#eta|;Denominator Count", 50, -2.5, 2.5);

    // branch pointers
    std::vector<LorentzVector>* tps_p4_ptr      = new std::vector<LorentzVector>;
    std::vector<double>*        tps_lip_ptr     = new std::vector<double>;
    std::vector<double>*        tps_tip_ptr     = new std::vector<double>;
    std::vector<bool>*          tps_matched_ptr = new std::vector<bool>;
    std::vector<int>*           tps_nhits_ptr   = new std::vector<int>;
    std::vector<int>*           tps_charge_ptr  = new std::vector<int>;

    // toggle branches
    chain.SetBranchAddress("tps_p4"     , &tps_p4_ptr     );
    chain.SetBranchAddress("tps_lip"    , &tps_lip_ptr    );
    chain.SetBranchAddress("tps_tip"    , &tps_tip_ptr    );
    chain.SetBranchAddress("tps_matched", &tps_matched_ptr);
    chain.SetBranchAddress("tps_nhits"  , &tps_nhits_ptr  );
    chain.SetBranchAddress("tps_charge" , &tps_charge_ptr );

    // set the status
    chain.SetBranchStatus("*"    , /*toggle = */false);
    chain.SetBranchStatus("tps_*", /*toggle = */true );

    // convenience (so i dont' have to use pointer syntax)
    std::vector<LorentzVector>& tps_p4      = *tps_p4_ptr;
    std::vector<double>&        tps_lip     = *tps_lip_ptr;
    std::vector<double>&        tps_tip     = *tps_tip_ptr;
    std::vector<bool>&          tps_matched = *tps_matched_ptr;
    std::vector<int>&           tps_nhits   = *tps_nhits_ptr;
    std::vector<int>&           tps_charge  = *tps_charge_ptr;

    // how many events to run on?
    long long tree_num_entries = std::min(chain.GetEntries(), num_events);
    
    // Event Loop
    for (long long entry = 0; entry < tree_num_entries; entry++)
    {
        if (verbose)
        {
            cout << "[CreatePlots] Processing entry " << entry << endl;
            cout << "--------------------------\n\n";
        }

        // set the branches
        chain.GetEntry(entry);
        if (verbose) {cout << "number of tps = " << tps_p4.size() << endl;}

        // loop over gen particles 
        for (size_t tp_idx = 0; tp_idx < tps_p4.size(); tp_idx++)
        {
            const double tp_pt      = tps_p4.at(tp_idx).pt();
            const double tp_eta     = tps_p4.at(tp_idx).eta();
            const double tp_lip     = tps_lip.at(tp_idx);
            const double tp_tip     = tps_tip.at(tp_idx);
            const bool   tp_matched = tps_matched.at(tp_idx);
            const int    tp_nhits   = tps_nhits.at(tp_idx);
            const int    tp_charge  = tps_charge.at(tp_idx);

            if (verbose) {cout << "Looping on Tracking Particle: " << tp_idx << endl;}

            // apply slection //
            // -------------- // 
            // TCut tps_sel = "tps_charge!=0 && tps_p4.pt()>0.9 && fabs(tps_p4.eta())<2.5 && tps_nhits>=3 && fabs(tps_lip)<30.0 && fabs(tps_tip)<3.5"

            // only charged 
            if (tp_charge==0)
            {
                if (verbose) {cout << "\tfailing charge requirement" << endl;}
                continue;
            }

            // min pt
            if (tp_pt < 0.9/*GeV*/)
            {
                if (verbose) {cout << "\tfailing pt requirement" << endl;}
                continue;
            }

            // max eta 
            if (fabs(tp_eta) > 2.5)
            {
                if (verbose) {cout << "\tfailing eta requirement" << endl;}
                continue;
            }

            // max transverse impact parameter 
            if (fabs(tp_tip) > 3.5/*cm*/)
            {
                if (verbose) {cout << "\tfailing d0 requirement" << endl;}
                continue;
            }

            // max longitudinal impact parameter 
            if (fabs(tp_lip) > 30/*cm*/)
            {
                if (verbose) {cout << "\tfailing dz requirement" << endl;}
                continue;
            }

            // min # hits 
            if (fabs(tp_nhits) < 3)
            {
                if (verbose) {cout << "\tfailing nhits requirement" << endl;}
                continue;
            }

            // fill histograms 
            // -------------- // 

            // deonminator selection has passed
            h_den_vs_eta.Fill(tp_eta);
            if (verbose) {cout << "\tpasses denomiantor" << endl;}

            // numerator
            if (tp_matched)
            {
                h_num_vs_eta.Fill(tp_eta);
                if (verbose) {cout << "\tpasses numerator" << endl;}
            }
            else
            {
                if (verbose) {cout << "\tfails numerator" << endl;}
            }

            if (verbose) {cout << "End loop over Tracking Particle: " << tp_idx << endl;}
        }

        // end of event loop
        if (verbose)
        {
            cout << "[CreatePlots] End entry " << entry << endl;
            cout << endl;
        }
    }

    // save the histogram
    TFile output_file(output_file_name.c_str(), "RECREATE");
    h_num_vs_eta.Write();
    h_den_vs_eta.Write();
    output_file.Close();
};

// open the histograms file and create efficiency plot 
void FinalPlots
(
    const std::string& input_file_name = "plots/counts_vs_eta_looper.root",
    const std::string& output_file_name = "plots/eff_vs_eta_looper.root",
    const std::string& suffix = "png"
)
{
    // open ROOT file with num/den counts
    TFile input_file(input_file_name.c_str());
    TH1* h_num_vs_eta = dynamic_cast<TH1*>(input_file.Get("h_num_vs_eta"));
    TH1* h_den_vs_eta = dynamic_cast<TH1*>(input_file.Get("h_den_vs_eta"));

    // create efficiency histogram
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
        TCanvas c1("c1", "c1", 600, 600);
        h_num_vs_eta->Draw(); c1.Print(Form("plots/%s_looper.%s", h_num_vs_eta->GetName(), suffix.c_str()));
        h_den_vs_eta->Draw(); c1.Print(Form("plots/%s_looper.%s", h_den_vs_eta->GetName(), suffix.c_str()));
        h_eff_vs_eta->Draw(); c1.Print(Form("plots/%s_looper.%s", h_eff_vs_eta->GetName(), suffix.c_str()));
    }

    // save to root file
    TFile output_file(output_file_name.c_str(), "RECREATE");
    h_num_vs_eta->Write();
    h_den_vs_eta->Write();
    h_eff_vs_eta->Write();
    output_file.Close();
}

#ifndef __CINT__
int main()
try
{
    CreatePlots("trees/tracking_ntuple.root", "plots/eff_vs_eta_looper.root", 1000, false);
    return 0;
}
catch (std::exception& e)
{
    std::cout << e.what() << std::endl;
}
#endif
