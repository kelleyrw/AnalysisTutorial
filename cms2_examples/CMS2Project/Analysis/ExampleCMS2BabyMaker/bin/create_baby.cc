#include <iostream>
#include "TROOT.h" 
#include "TStyle.h" 
#include "TChain.h" 
#include "TSystem.h" 
#include "Analysis/ExampleCMS2BabyMaker/interface/CMS2BabyMaker.h"
#include "Packages/LooperTools/interface/LoadFWLite.h"

int main()
{
    const long num_events   = -1;
    const double lumi       = 0.082;

    // Load TChain for the sample
    LoadFWLite();
    TChain chain("Events");
    chain.Add("/nfs-7/userdata/rwkelley/cms2/DYJetsToLL_M-50_TuneZ2Star_8TeV-madgraph-tarball_Summer12_DR53X-PU_S10_START53_V7A-v1.root");

    // correction factor for using subset of CMS2 events
    const double nevts_corr = (27137253.0/static_cast<double>(chain.GetEntries()));

    // create baby maker object
    CMS2BabyMaker baby_maker
    (
        "dyll",
        "babies/dyll_baby.root",
        "json/Merged_190456-208686_8TeV_PromptReReco_Collisions12_goodruns.txt",
        lumi,
        nevts_corr, 
        false
    );

    // run it
    std::cout << "running cms2 baby maker..." << std::endl;
    baby_maker.ScanChain(chain, num_events);

    return 0;
}

