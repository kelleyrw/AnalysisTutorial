void run_all()
{
    // compile the code
    gROOT->LoadMacro("compile.C++");
    if (!compile())
    {
        std::cout << "[run_all] compile failed..." << std::endl;
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
