int run_sample_osx(const long num_events = -1)
{
    // load relevant libaries
    gSystem->Load("$CMSSW_BASE/lib/$SCRAM_ARCH/libPackagesLooperTools.dylib");
    gSystem->Load("$CMSSW_BASE/lib/$SCRAM_ARCH/libAnalysisExampleCMS2Looper.dylib");

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
