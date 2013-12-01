#include <iostream>
#include <string>
// #include <vector> 
// #include <cstdlib>
// #include <limits>
// #include <algorithm>
#include "TFile.h"
#include "TChain.h"
#include "TH1.h"
#include "TCanvas.h"
#include "TROOT.h"
/* #include "Math/LorentzVector.h" */
/* typedef ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<double> > LorentzVectorD; */

// automatically generated class type
#include "TRKEFF.h"

// histogram tools
#include "HistTools.h"

class TrackingEfficiencyAnalysis
{
    public:
        // construct: 
        TrackingEfficiencyAnalysis
        (
             const std::string& output_file_name = "plots/counts_vs_eta_looper.root",
             const std::string& suffix = "png",
             const bool verbose = true
        );

        // destroy:
        ~TrackingEfficiencyAnalysis();

        // analysis methods:
        void BeginJob();
        void EndJob();
        void Analyze();
        void ScanChain(TChain& chain, long long num_events = std::numeric_limits<long>::max());

    private:

        // members
        const std::string m_output_file_name;
        const std::string m_suffix;
        const bool m_verbose;

        // member functions
        TH1Map m_hist_map;
};

// construct:
TrackingEfficiencyAnalysis::TrackingEfficiencyAnalysis
(
    const std::string& output_file_name,
    const std::string& suffix,
    const bool verbose
)
    : m_output_file_name(output_file_name)
    , m_suffix(suffix)
    , m_verbose(verbose)
{
    // run begin job when object is constructed
    BeginJob();
   
    if (m_verbose)
    {
        std::cout << "[TrackingEfficiencyAnalysis] TrackingEfficiencyAnalysis has been initialized with the following parameters:" << std::endl;
        std::cout << "output_file_name = " << m_output_file_name << std::endl;
        std::cout << "suffix           = " << m_suffix           << std::endl;
        std::cout << "verbose          = " << m_verbose          << std::endl;
    }
}

// destroy:
TrackingEfficiencyAnalysis::~TrackingEfficiencyAnalysis()
{
    // run end job when object is destroyed 
    EndJob();

    if (m_verbose) {std::cout << "[TrackingEfficiencyAnalysis] TrackingEfficiencyAnalysis is complete." << std::endl;}
}


// operations performed at the beginning of the job
void TrackingEfficiencyAnalysis::BeginJob()
{
    // convenience alias
    TH1Map& hc = m_hist_map;

    // book all the histograms
    AddHist(hc, new TH1F("h_num_vs_eta", "Numerator Count vs |#eta|;|#eta|;Numerator Count"    , 50, -2.5, 2.5));
    AddHist(hc, new TH1F("h_den_vs_eta", "Denominator Count vs |#eta|;|#eta|;Denominator Count", 50, -2.5, 2.5));

    if (m_verbose) {std::cout << "[TrackingEfficiencyAnalysis] The following histgrams are booked: " << std::endl;}
}

// operations performed at the end of the job
void TrackingEfficiencyAnalysis::EndJob()
{
    // convenience alias
    TH1Map& hc = m_hist_map;

    if (m_verbose) {std::cout << "[TrackingEfficiencyAnalysis] TrackingEfficiencyAnalysis saving histograms." << std::endl;}

    // divide to make the efficiency hists
    AddHist(hc, MakeEfficiencyPlot(hc["h_num_vs_eta"], hc["h_den_vs_eta"], "h_eff_vs_eta", "Tracking Efficiency vs |#eta|;|#eta|;Efficiency"));

    // save the plots
    SaveHists(hc, m_output_file_name, "RECREATE");

    // print the plots
    if (not m_suffix.empty())
    {
        if (m_verbose) {std::cout << "[TrackingEfficiencyAnalysis] printing histograms:" << std::endl;}
        PrintHists(hc, "plots", m_suffix);
    }

    // delete the hists
    DeleteHists(hc);
}

// operations performed per event 
void TrackingEfficiencyAnalysis::Analyze()
{
}

// loop over the chain and call analyze per event
void TrackingEfficiencyAnalysis::ScanChain(TChain& chain, long long num_events)
{
}

#ifndef __CINT__
int main()
try
{
    TChain chain("tree");
    chain.Add("../data/tracking_ntuple.root");
    const std::string& output_file_name = "plots/counts_vs_eta_looper.root";
    const std::string& suffix = "png";
/*     const long long num_events = std::numeric_limits<long>::max(); */
    const long long num_events = 1;
    const bool verbose = true;
    TrackingEfficiencyAnalysis analysis(output_file_name, suffix, verbose);
    analysis.ScanChain(chain, num_events);
    return 0;
}
catch (std::exception& e)
{
    std::cout << e.what() << std::endl;
}
#endif
