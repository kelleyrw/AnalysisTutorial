// compile the code and load it
// usage: 
// root [5] .x compile.C+

#include "TString.h"
#include "TSystem.h"
#include "TROOT.h"
#include <string>

bool compile(const std::string& option = "")
{
    // setup the include path
    TString include_path = gSystem->GetIncludePath();
    if (!include_path.Contains("-Iinclude"))
    {
        gSystem->AddIncludePath("-Iinclude");
    }

    // compile and load the source 
    if (gSystem->CompileMacro("source/HistTools.cc"                 , (option + "k-").c_str(), "libHistTools"                 , "lib") == 0) {return false;}
    if (gSystem->CompileMacro("source/TRKEFF.cc"                    , (option + "k-").c_str(), "libTRKEFF"                    , "lib") == 0) {return false;}
    if (gSystem->CompileMacro("source/TrackingEfficiencyAnalysis.cc", (option + "k-").c_str(), "libTrackingEfficiencyAnalysis", "lib") == 0) {return false;}

    // if here, then succeeded
    return true;
}

// clean up the libs 
// usage: 
// root [5] .L compile.C+
// root [6] clean() 
void clean()
{
    gSystem->Exec("rm lib/*");
}
