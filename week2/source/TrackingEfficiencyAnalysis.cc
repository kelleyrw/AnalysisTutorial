#include <iostream>
#include <string>
#include "TFile.h"
#include "TChain.h"
#include "TH1.h"
#include "TCanvas.h"
#include "TROOT.h"
#include "TStyle.h"
#include "TBenchmark.h"
#include "TTreeCache.h"
#include "Math/LorentzVector.h"
typedef ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<double> > LorentzVectorD;

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
        void ScanChain(TChain& chain, long long num_events = std::numeric_limits<long long>::max());

    private:
        // members:
        const std::string m_output_file_name;
        const std::string m_suffix;
        const bool m_verbose;
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
    , m_hist_map()
{
    // run begin job when object is constructed
    BeginJob();
   
    if (m_verbose)
    {
        std::cout << "[TrackingEfficiencyAnalysis::TrackingEfficiencyAnalysis] "
                     "TrackingEfficiencyAnalysis has been initialized with the following parameters:\n";
        std::cout << "output_file_name = " << m_output_file_name << "\n";
        std::cout << "suffix           = " << m_suffix           << "\n";
        std::cout << "verbose          = " << m_verbose          << "\n\n";
    }
}

// destroy:
TrackingEfficiencyAnalysis::~TrackingEfficiencyAnalysis()
{
    // run end job when object is destroyed 
    EndJob();

    if (m_verbose) {std::cout << "[TrackingEfficiencyAnalysis::~TrackingEfficiencyAnalysis] "
                                 "TrackingEfficiencyAnalysis is complete." << std::endl;}
}

// variable pt bins
const float pt_bins[] = {0.1 , 0.126   , 0.158   , 0.200   , 0.251   , 0.316   , 0.398   , 0.501   , 0.631   , 0.794   , 
                         1.0 , 1.259   , 1.585   , 1.995   , 2.512   , 3.162   , 3.981   , 5.012   , 6.310   , 7.943   , 
                         10  , 12.589  , 15.849  , 19.953  , 25.119  , 31.623  , 39.811  , 50.119  , 63.096  , 79.433  , 
                         100 , 125.893 , 158.489 , 199.526 , 251.189 , 316.228 , 398.107 , 501.187 , 630.957 , 794.328 , 1000};
const unsigned int npt_bins = sizeof(pt_bins)/sizeof(float)-1;

// operations performed at the beginning of the job
void TrackingEfficiencyAnalysis::BeginJob()
{
    // set the style
    SetStyle();

    // convenience alias
    TH1Map& hc = m_hist_map;

    // book all the histograms
    TH1::SetDefaultSumw2(true);
    AddHist(hc, new TH1F("h_num_vs_eta", "Numerator Count vs |#eta|;|#eta|;Numerator Count"        , 50, -2.5, 2.5));
    AddHist(hc, new TH1F("h_den_vs_eta", "Denominator Count vs |#eta|;|#eta|;Denominator Count"    , 50, -2.5, 2.5));
    AddHist(hc, new TH1F("h_num_vs_pt" , "Numerator Count vs p_{T};p_{T} (GeV);Numerator Count"    , npt_bins, pt_bins));
    AddHist(hc, new TH1F("h_den_vs_pt" , "Denominator Count vs p_{T};p_{T} (GeV);Denominator Count", npt_bins, pt_bins));
    TH1::SetDefaultSumw2(false);

    if (m_verbose) {std::cout << "[TrackingEfficiencyAnalysis::BeginJob] The following histgrams are booked: " << std::endl;}

    // set histogram styles
    for (TH1Map::const_iterator hm_iter = m_hist_map.begin(); hm_iter != m_hist_map.end(); hm_iter++)
    {
        TH1& h = *hm_iter->second; 
        h.SetMarkerSize(0.75);
        h.SetMarkerStyle(20);
        h.SetMarkerColor(kBlack);
    }
}

// operations performed at the end of the job
void TrackingEfficiencyAnalysis::EndJob()
{
    // convenience alias
    TH1Map& hc = m_hist_map;

    if (m_verbose) {std::cout << "[TrackingEfficiencyAnalysis::EndJob] TrackingEfficiencyAnalysis saving histograms." << std::endl;}

    // divide to make the efficiency hists
    AddHist(hc, MakeEfficiencyPlot(hc["h_num_vs_eta"], hc["h_den_vs_eta"], "h_eff_vs_eta", "Tracking Efficiency vs |#eta|;|#eta|;Efficiency"   ));
    AddHist(hc, MakeEfficiencyPlot(hc["h_num_vs_pt" ], hc["h_den_vs_pt" ], "h_eff_vs_pt" , "Tracking Efficiency vs p_{T};p_{T}(GeV);Efficiency"));

    hc["h_eff_vs_eta"]->GetYaxis()->SetRangeUser(0.1, 1.1);
    hc["h_eff_vs_pt" ]->GetYaxis()->SetRangeUser(0.1, 1.1);

    // save the plots
    SaveHists(hc, m_output_file_name, "RECREATE");

    // print the plots
    if (not m_suffix.empty())
    {
        if (m_verbose) {std::cout << "[TrackingEfficiencyAnalysis::EndJob] printing histograms:" << std::endl;}
        PrintHists(hc, "plots", m_suffix);
    }

    // delete the hists
    DeleteHists(hc);
}

// operations performed per event 
void TrackingEfficiencyAnalysis::Analyze()
{
    using namespace std;
    using namespace trkeff;

    // convenience alias
    TH1Map& hc = m_hist_map;
        
    if (m_verbose) {cout << Form("TrackingEfficiencyAnalysis::Analyze] Running on run %d, ls %d, event %d: ", run(), ls(), event()) << endl;}

    // loop over tracking particles 
    if (m_verbose) {cout << "number of tps = " << tps_p4().size() << "\n\n";}

    for (size_t tp_idx = 0; tp_idx < tps_p4().size(); tp_idx++)
    {
        const double tp_pt      = tps_p4().at(tp_idx).pt();
        const double tp_eta     = tps_p4().at(tp_idx).eta();
        const double tp_lip     = tps_lip().at(tp_idx);
        const double tp_tip     = tps_tip().at(tp_idx);
        const bool   tp_matched = tps_matched().at(tp_idx);
        const int    tp_nhits   = tps_nhits().at(tp_idx);
        const int    tp_charge  = tps_charge().at(tp_idx);

        if (m_verbose) {cout << "Looping on Tracking Particle: " << tp_idx << endl;}

        // apply slection //
        // -------------- // 

        // only charged 
        if (tp_charge==0)
        {
            if (m_verbose) {cout << "\tfailing charge requirement" << endl;}
            continue;
        }

        // min pt
        if (tp_pt < 0.1/*GeV*/)
        {
            if (m_verbose) {cout << "\tfailing pt requirement" << endl;}
            continue;
        }

        // max eta 
        if (fabs(tp_eta) > 2.5)
        {
            if (m_verbose) {cout << "\tfailing eta requirement" << endl;}
            continue;
        }

        // max transverse impact parameter 
        if (fabs(tp_tip) > 3.5/*cm*/)
        {
            if (m_verbose) {cout << "\tfailing tip requirement" << endl;}
            continue;
        }

        // max longitudinal impact parameter 
        if (fabs(tp_lip) > 30/*cm*/)
        {
            if (m_verbose) {cout << "\tfailing lip requirement" << endl;}
            continue;
        }

        // min # hits 
        if (fabs(tp_nhits) < 3)
        {
            if (m_verbose) {cout << "\tfailing nhits requirement" << endl;}
            continue;
        }

        // fill histograms 
        // -------------- // 

        const float min_tp_for_eta_eff = 0.9;
        const float min_tp_for_pt_eff  = 0.1;

        // deonminator selection has passed
        if (tp_pt > min_tp_for_eta_eff) {hc["h_den_vs_eta"]->Fill(tp_eta);}
        if (tp_pt > min_tp_for_pt_eff ) {hc["h_den_vs_pt" ]->Fill(tp_pt );}
        if (m_verbose) {cout << "\tpasses denomiantor" << endl;}

        // numerator
        if (tp_matched)
        {
            if (tp_pt > min_tp_for_eta_eff) {hc["h_num_vs_eta"]->Fill(tp_eta);}
            if (tp_pt > min_tp_for_pt_eff ) {hc["h_num_vs_pt" ]->Fill(tp_pt );}
            if (m_verbose) {cout << "\tpasses numerator" << endl;}
        }
        else
        {
            if (m_verbose) {cout << "\tfails numerator" << endl;}
        }

        if (m_verbose) {cout << "End loop over Tracking Particle: " << tp_idx << endl;}
    }
}

// loop over the chain and call analyze per event
void TrackingEfficiencyAnalysis::ScanChain(TChain& chain, long long num_events)
{
    using namespace std;

    // benchmark
    TBenchmark bmark;
    bmark.Start("benchmark");

    // optimize
    TTreeCache::SetLearnEntries(10);
    chain.SetCacheSize(128*1024*1024);

    // events counts and max events
    int per_mille_old = 0;
    long long num_events_processed = 0;
    num_events = (num_events > 0 ? std::min(chain.GetEntries(), num_events) : chain.GetEntries());
    trkeff_obj.Init(chain);

    // Event Loop
    for (long long entry = 0; entry < num_events; entry++)
    {
        if (m_verbose)
        {
            cout << "[TrackingEfficiencyAnalysis::ScanChain] Processing entry " << entry << "\n";
            cout << "--------------------------\n" << endl;
        }

        // pogress
        int per_mille = static_cast<int>(floor(1000.0 * static_cast<float>(num_events_processed)/static_cast<float>(num_events)));
        cout << per_mille << "\t" << per_mille_old;
        if (per_mille != per_mille_old)
        {
            printf("  \015\033[32m ---> \033[1m\033[31m%4.1f%%" "\033[0m\033[32m <---\033[0m\015", per_mille/10.0);
            fflush(stdout);
            per_mille_old = per_mille;
        }

        // load the current event 
        trkeff_obj.GetEntry(entry);

        // analyze the event
        Analyze();

        // increment counter
        num_events_processed++;
    }

    // the benchmark results 
    // -------------------------------------------------------------------------------------------------//

    // done
    bmark.Stop("benchmark");
    fflush(stdout);
    cout << "[TrackingEfficiencyAnalysis::ScanChain] finished processing " << num_events << " events" << endl;
    cout << "------------------------------" << endl;
    cout << "CPU  Time: " << Form("%.01f", bmark.GetCpuTime("benchmark" )) << endl;
    cout << "Real Time: " << Form("%.01f", bmark.GetRealTime("benchmark")) << endl;
    cout << endl;
}

#ifndef __CINT__
int main()
try
{
    TChain chain("tree");
    chain.Add("../data/tracking_ntuple.root");
    const std::string& output_file_name = "plots/counts_vs_eta_looper.root";
    const std::string& suffix = "png";
    const long long num_events = -1;
    const bool verbose = false;
    TrackingEfficiencyAnalysis analysis(output_file_name, suffix, verbose);
    analysis.ScanChain(chain, num_events);
    return 0;
}
catch (std::exception& e)
{
    std::cout << e.what() << std::endl;
}
#endif
