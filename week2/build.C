// compile the code and load it

void build(const std::string& option = "")
{
    // setup the include path
    TString include_path = gSystem->GetIncludePath();
    if (!include_path.Contains("-Iinclude"))
    {
        gSystem->AddIncludePath("-Iinclude");
    }

    // compile and load the source 
    if (gSystem->CompileMacro("source/TRKEFF.cc"                    , (option + "k-").c_str(), "libTRKEFF"                    , "lib") == 0) {return;}
    if (gSystem->CompileMacro("source/HistTools.cc"                 , (option + "k-").c_str(), "libHistTools"                 , "lib") == 0) {return;}
    if (gSystem->CompileMacro("source/TrackingEfficiencyAnalysis.cc", (option + "k-").c_str(), "libTrackingEfficiencyAnalysis", "lib") == 0) {return;}
}
