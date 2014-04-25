std::vector<std::string> string_split(const std::string &str, char delim)
{
    std::vector<std::string> result;
    std::stringstream ss(str);
    std::string item;
    while (std::getline(ss, item, delim))
    {
        result.push_back(item);
    }
    return result;
}

int create_baby
(
    const std::string& sample_name,
    const std::string& input_filename,
    const std::string& output_filename,
    const std::string& runlist_filename,
    const long num_events = -1,
    const double lumi = 1.0, 
    const bool verbose = false
)
{
    // load relevant libaries
    gSystem->Load("$CMSSW_BASE/lib/$SCRAM_ARCH/libPackagesLooperTools.so");
    gSystem->Load("$CMSSW_BASE/lib/$SCRAM_ARCH/libAnalysisExampleCMS2BabyMaker.so");

    // Load TChain for the sample
    LoadFWLite();
    TChain chain("Events");
    std::vector<std::string> input_files = string_split(input_filename, ',');
    for (size_t i = 0; i < input_files.size(); ++i)
    {
        std::cout << "adding to TChain: " << input_files[i] << std::endl;
        chain.Add(input_files[i].c_str());
    }

    // correction factor for using subset of CMS2 events
    double nevts_corr = 1.0;
    if (sample_name == "dyll"   ) nevts_corr = (27137253.0/static_cast<double>(chain.GetEntries()));
    if (sample_name == "wjets"  ) nevts_corr = (14890630.0/static_cast<double>(chain.GetEntries()));
    if (sample_name == "ttdil"  ) nevts_corr = (11902045.0/static_cast<double>(chain.GetEntries()));
    if (sample_name == "ttslq"  ) nevts_corr = (23453443.0/static_cast<double>(chain.GetEntries()));
    if (sample_name == "tthad"  ) nevts_corr = (21211839.0/static_cast<double>(chain.GetEntries()));
    if (sample_name == "qcd"    ) nevts_corr = (19770457.0/static_cast<double>(chain.GetEntries()));
    if (sample_name == "ww2l2q" ) nevts_corr = (1933235.0 /static_cast<double>(chain.GetEntries()));
    if (sample_name == "wz2l2q" ) nevts_corr = (2937874.0 /static_cast<double>(chain.GetEntries()));
    if (sample_name == "wz3l"   ) nevts_corr = (2017979.0 /static_cast<double>(chain.GetEntries()));
    if (sample_name == "zz2l2q" ) nevts_corr = (1777571.0 /static_cast<double>(chain.GetEntries()));
    if (sample_name == "zz2l2nu") nevts_corr = (857982.0  /static_cast<double>(chain.GetEntries()));
    if (sample_name == "zz4"    ) nevts_corr = (4807893.0 /static_cast<double>(chain.GetEntries()));

    // create baby maker object
    CMS2BabyMaker baby_maker
    (
        sample_name,
        output_filename,
        runlist_filename,
        lumi,
        nevts_corr,
        verbose
    );

    // run it
    std::cout << "running cms2 baby maker..." << std::endl;
    baby_maker.ScanChain(chain, num_events);

    return 0;
}
