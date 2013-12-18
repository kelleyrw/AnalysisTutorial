void run_all()
{
    // build the code
    gROOT->LoadMacro("build.C++");
    if (!build())
    {
        std::cout << "[run_all] build failed..." << std::endl;
    }

    // create the chain
    TChain chain("tree");
    chain.Add("../data/tracking_ntuple.root");


    // input parameters
    const std::string output_file_name = "plots/eff.root";
    const std::string suffix = "png";
    const long long num_events = -1;
    const bool verbose = false;

    // create Analysis object and run it
    try
    {
        TrackingEfficiencyAnalysis analysis(output_file_name, suffix, verbose);
        analysis.ScanChain(chain, num_events);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}
