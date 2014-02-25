#include <iostream>
#include "TROOT.h" 
#include "TStyle.h" 
#include "TChain.h" 
#include "TSystem.h" 
#include "Analysis/ExampleCMS2Looper/interface/CMS2Looper.h"
#include "Packages/LooperTools/interface/LoadFWLite.h"

int main()
{
    const long num_events = -1;

    // simple style
    gROOT->SetStyle("Plain");
    gStyle->SetOptStat(111111);

    LoadFWLite();
    TChain chain("Events");
    chain.Add("/nfs-7/userdata/rwkelley/cms2/dyjets_ntuple_slim_10k_53X_v2.root");

    CMS2Looper looper("output/dy_plots.root");
    looper.SetRunList("json/Merged_190456-208686_8TeV_PromptReReco_Collisions12_goodruns.txt");
    std::cout << "running cms2 looper..." << std::endl;
    looper.ScanChain(chain, num_events);

    return 0;
}

