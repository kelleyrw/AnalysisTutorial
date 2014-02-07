// Usage:

// > ./setup.sh
// > root -b run_sample.C

// C++
#include <iostream>
#include <vector>

// ROOT
#include "TBenchmark.h"
#include "TChain.h"
#include "TDirectory.h"
#include "TFile.h"
#include "TROOT.h"
#include "TTreeCache.h"
#include "Math/VectorUtil.h"
#include "TDatabasePDG.h"

// CMS2
#include "CMS2.h"
#include "goodrun.h"
#include "ScanChain.h"

// CORE
#include "mcSelections.h"

//stuff from looper tools
#include "eventFilter.h"


// construct:
CMS2Looper::CMS2Looper()
{
}

// destroy:
CMS2Looper::~CMS2Looper()
{
}

int CMS2Looper::ScanChain(TChain& chain, long num_events)
{

    // Benchmark
    TBenchmark bmark;
    bmark.Start("benchmark");

    //~-~-~-~-~-~-~-~-~-~-//
    //Book Histograms Here//
    //~-~-~-~-~-~-~-~-~-~-//

    TH1F* const h_sample = new TH1F("h_sample", "Example histogram;pdg ID", 5, 0, 25);

    //~-~-~-~-~-~-~-~-~-~-~-//
    //Set json here for data//
    //~-~-~-~-~-~-~-~-~-~-~-//

    //json for moriond
    set_goodrun_file("json/Merged_190456-208686_8TeV_PromptReReco_Collisions12_goodruns.txt");

    //~-~-~-~-~-~-~-~-~-~-~-~-~-~-//
    // Loop over events to Analyze//
    //~-~-~-~-~-~-~-~-~-~-~-~-~-~-//

    // initialize the chain
    cms2.Init(&chain);
    TTreeCache::SetLearnEntries(10);
    chain.SetCacheSize(128*1024*1024);

    // number of events to run on
    num_events = (num_events < 0 or num_events > chain.GetEntries() ? chain.GetEntries() : num_events);

    // count the total and duplicates events
    unsigned long num_events_total = 0;
    unsigned long num_duplicates   = 0;

    // loop over events
    for (long event = 0; event != num_events; ++event)
    {
        // Get Event Content
        chain.LoadTree(event);
        cms2.GetEntry(event);
        ++num_events_total;

        //parse events from json
        if (tas::evt_isRealData())
        {
            // for read data, check that the run is good
            if (!goodrun_json(tas::evt_run(), tas::evt_lumiBlock()))
            {
                continue;
            }

            // check for duplicates
            DorkyEventIdentifier id = {tas::evt_run(), tas::evt_event(), tas::evt_lumiBlock()};
            if (is_duplicate(id))
            {
                // cout << "\t! ERROR: found duplicate." << endl;
                num_duplicates++;
                continue;
            }
        }

        // Progress
        CMS2::progress(num_events_total, num_events);

        //~-~-~-~-~-~-~-//
        // Analysis Code//
        //~-~-~-~-~-~-~-//

        bool foundwz = false;
        unsigned int nwzpartons = 0;

        for (size_t idx = 0; idx < tas::genps_id().size(); idx++ )
        {
            const unsigned int pid = abs(tas::genps_id().at(idx));
            foundwz = (pid == 23);

            if (foundwz && (pid == 1 || pid == 2 || pid == 3 || pid == 4 || pid == 5 || pid == 6 || pid == 21))
            {  
                nwzpartons++;
                h_sample->Fill(pid);
            }
        }

        if (nwzpartons > 3)
        {
            dumpDocLines();
        }
    }

    // Example Histograms
    h_sample->Draw();

    // return
    bmark.Stop("benchmark");
    std::cout << std::endl;
    std::cout << num_events_total << " Events Processed" << std::endl;
    std::cout << num_duplicates   << " Duplicate Events" << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << "CPU  Time:	" << Form("%.01f", bmark.GetCpuTime("benchmark") ) << std::endl;
    std::cout << "Real Time:	" << Form("%.01f", bmark.GetRealTime("benchmark")) << std::endl;
    std::cout << std::endl;

    // done
    return 0;
}
