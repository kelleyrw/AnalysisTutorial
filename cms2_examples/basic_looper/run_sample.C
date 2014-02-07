int run_sample(const long num_events = -1)
{
    // load the library for the class
    gSystem->Load("libcms2_looper.so");

    // simple style
    gROOT->SetStyle("Plain");
    gStyle->SetOptStat(111111);

    TChain chain("Events");
    chain.Add("/nfs-7/userdata/rwkelley/cms2/dyjets_ntuple_slim_10k_53X_v2.root");

    CMS2Looper looper("output/dy_plots.root");
    std::cout << "running cms2 looper..." << std::endl;
    looper.ScanChain(chain, num_events);

    return 0;
}
