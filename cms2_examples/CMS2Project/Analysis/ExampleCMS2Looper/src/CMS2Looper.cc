#include "Analysis/ExampleCMS2Looper/interface/CMS2Looper.h"

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
#include "CMS2/NtupleMacrosHeader/interface/CMS2.h"

// CORE
#include "CMS2/NtupleMacrosCore/interface/mcSelections.h"

// stuff from packages 
#include "Packages/LooperTools/interface/GoodRun.h"
#include "Packages/HistTools/interface/HistTools.h"
#include "Packages/LooperTools/interface/DorkyEventIdentifier.h"

// construct:
CMS2Looper::CMS2Looper()
    : output_filename("hists.root")
    , runlist_filename("")
{
}

CMS2Looper::CMS2Looper(const std::string& filename)
    : output_filename(filename)
    , runlist_filename("")
{
}

// destroy:
CMS2Looper::~CMS2Looper()
{
}

// ------------------------------------ //
// Stuff to do before job starts
// ------------------------------------ //
void CMS2Looper::BeginJob()
{
    AddHist(hists, new TH1F("h_sample", "Example histogram;pdg ID", 25, 0, 25));
    return;
}

// ------------------------------------ //
// Stuff to do on each event 
// ------------------------------------ //
void CMS2Looper::Analyze(const long event)
{
    bool foundz = false;                                                      
    unsigned int nwzpartons = 0;                                               
                                                                               
    for (size_t idx = 0; idx < tas::genps_id().size(); idx++)                  
    {                                                                          
        const unsigned int pid = abs(tas::genps_id().at(idx));                 
        foundz = (pid == 23);                                                 
                                                                               
        // h_sample->Fill(pid);                                                
        hists.at("h_sample")->Fill(pid);                                       
                                                                               
        if (foundz && (pid == 1 || pid == 2 || pid == 3 || pid == 4 || pid == 5 || pid == 6 || pid == 21))
        {                                                                      
            nwzpartons++;                                                      
        }                                                                      
    }                                                                          
                                                                               
    if (nwzpartons > 3)                                                        
    {                                                                          
        dumpDocLines();                                                        
    }                                                                          
}

// ------------------------------------ //
// Stuff to do after job finishes
// ------------------------------------ //
void CMS2Looper::EndJob()
{
    std::cout << "[CMS2Looper] Saving hists to output file: " << output_filename << std::endl;
    SaveHists(hists, output_filename, "RECREATE");
    return;
}

// ------------------------------------ //
// loop over event 
// ------------------------------------ //
void CMS2Looper::ScanChain(TChain& chain, const long num_events)
{
    // Benchmark
    TBenchmark bmark;
    bmark.Start("benchmark");

    // Stuff to do before job starts
	BeginJob();

    //~-~-~-~-~-~-~-~-~-~-~-//
    //Set json here for data//
    //~-~-~-~-~-~-~-~-~-~-~-//

    // set the "good run" list 
    if (!runlist_filename.empty())
    {
        set_goodrun_file(runlist_filename.c_str());
        //set_goodrun_file_json(goodrun_file_name.c_str());
    }

    //~-~-~-~-~-~-~-~-~-~-~-~-~-~-//
    // Loop over events to Analyze//
    //~-~-~-~-~-~-~-~-~-~-~-~-~-~-//

    // number of events to run on
    const unsigned long num_events_chain = (num_events < 0 or num_events > chain.GetEntries() ? chain.GetEntries() : num_events);

    // count the total and duplicates events
    int i_permille_old             = 0;
    unsigned long num_events_total = 0;
    unsigned long num_duplicates   = 0;
    unsigned long num_bad_events   = 0;

    // files list --> TChain doesn't propoerly with CMS2.h so 
    // we have to looper manually over the files :(
    TObjArray* const list_of_files = chain.GetListOfFiles();
    TIter file_iter(list_of_files);
    TFile* current_file = NULL;

    // loop over files in the chain
    while ((current_file = (TFile*)file_iter.Next()))
    {
        // get the trees in each file
        TFile* const file = TFile::Open(current_file->GetTitle());
        TTree* const tree = dynamic_cast<TTree*>(file->Get("Events"));

        // initialize the chain
        cms2.Init(tree);
        TTreeCache::SetLearnEntries(10);
        chain.SetCacheSize(128*1024*1024);

        // Loop over Events in current file
        if (num_events_total >= num_events_chain) {break;}
        const long num_events_tree = tree->GetEntriesFast();

        // loop over events
        for (long event = 0; event != num_events_tree; ++event)
        {
            // quit if the total is > the number in the chain
            if (num_events_total >= num_events_chain) {continue;}

            // Get Event Content
            tree->LoadTree(event);
            cms2.GetEntry(event);
            ++num_events_total;

            //parse events from json
            if (tas::evt_isRealData())
            {
                // for read data, check that the run is good
                if (!runlist_filename.empty())
                {
                    if (!goodrun_json(tas::evt_run(), tas::evt_lumiBlock()))
                    {
                        num_bad_events++;
                        continue;
                    }
                }

                // check for duplicates
                const DorkyEventIdentifier id = {tas::evt_run(), tas::evt_event(), tas::evt_lumiBlock()};
                if (is_duplicate(id))
                {
                    // cout << "\t! ERROR: found duplicate." << endl;
                    num_duplicates++;
                    continue;
                }
            }

            // Progress
            const int i_permille = floor(1000 * num_events_total/ static_cast<float>(num_events_chain));
            if (i_permille != i_permille_old)
            {
                printf("  \015\033[32m ---> \033[1m\033[31m%4.1f%%" "\033[0m\033[32m <---\033[0m\015", i_permille/10.);
                fflush(stdout);
                i_permille_old = i_permille;
            }

            //~-~-~-~-~-~-~-//
            // Analysis Code//
            //~-~-~-~-~-~-~-//
            Analyze(event);

        } //end event loop

        // cleanup
        file->Close();

    } // end file loop

    // Stuff to do after job finishes
	EndJob();

    // return
    bmark.Stop("benchmark");
    std::cout << std::endl;
    std::cout << num_events_total << " Events Processed" << std::endl;
    std::cout << num_duplicates   << " Duplicate Events" << std::endl;
    std::cout << num_bad_events   << " Bad Events"       << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << "CPU  Time:	" << Form("%.01f", bmark.GetCpuTime("benchmark") ) << std::endl;
    std::cout << "Real Time:	" << Form("%.01f", bmark.GetRealTime("benchmark")) << std::endl;
    std::cout << std::endl;

    // done
    return;
}
        
void CMS2Looper::SetRunList(const std::string& runlist)
{
    runlist_filename = runlist;
}
