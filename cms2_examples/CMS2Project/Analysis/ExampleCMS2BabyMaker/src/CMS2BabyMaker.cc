#include "Analysis/ExampleCMS2BabyMaker/interface/CMS2BabyMaker.h"

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

// CMS2
#include "CMS2/NtupleMacrosHeader/interface/CMS2.h"

// stuff from packages 
#include "Packages/LooperTools/interface/GoodRun.h"
#include "Packages/LooperTools/interface/DorkyEventIdentifier.h"

// -------------------------------------------------//
// Class to hold the ntuple information 
// -------------------------------------------------//

TreeInfo::TreeInfo()
    : run                  ( -999999    ) 
    , ls                   ( -999999    ) 
    , evt                  ( -999999    ) 
    , sample               ( ""         ) 
    , dataset              ( ""         ) 
    , filename             ( ""         ) 
    , is_real_data         ( false      ) 
    , scale1fb             ( 1.0        ) 
    , scale1fb_cms2        ( 1.0        ) 
    , lumi                 ( 1.0        ) 
    , xsec                 ( -999999    ) 
    , kfactor              ( -999999    ) 
    , filt_eff             ( -999999    ) 
    , is_gen_z             ( false      ) 
    , is_gen_ee            ( false      ) 
    , is_gen_mm            ( false      ) 
    , gen_p4               ( 0, 0, 0, 0 ) 
    , gen_lep1_p4          ( 0, 0, 0, 0 ) 
    , gen_lep1_id          ( -999999    ) 
    , gen_lep1_charge      ( -999999    ) 
    , gen_lep2_p4          ( 0, 0, 0, 0 ) 
    , gen_lep2_id          ( -999999    ) 
    , gen_lep2_charge      ( -999999    ) 
{
}

void TreeInfo::Reset()
{
    run                  = -999999; 
    ls                   = -999999; 
    evt                  = -999999; 
    sample               = ""; 
    dataset              = ""; 
    filename             = ""; 
    is_real_data         = false; 
    scale1fb             = 1.0; 
    scale1fb_cms2        = 1.0; 
    lumi                 = 1.0; 
    xsec                 = -999999; 
    kfactor              = -999999; 
    filt_eff             = -999999; 
    is_gen_z             = false; 
    is_gen_ee            = false; 
    is_gen_mm            = false; 
    gen_p4               = LorentzVector(0, 0, 0, 0); 
    gen_lep1_p4          = LorentzVector(0, 0, 0, 0); 
    gen_lep1_id          = -999999; 
    gen_lep1_charge      = -999999; 
    gen_lep2_p4          = LorentzVector(0, 0, 0, 0); 
    gen_lep2_id          = -999999; 
    gen_lep2_charge      = -999999; 
}
    
void TreeInfo::SetBranches(TTree& tree)
{
    tree.Branch("run"                  , &run                  );
    tree.Branch("ls"                   , &ls                   );
    tree.Branch("evt"                  , &evt                  );
    tree.Branch("sample"               , &sample               );
    tree.Branch("dataset"              , &dataset              );
    tree.Branch("filename"             , &filename             );
    tree.Branch("is_real_data"         , &is_real_data         );
    tree.Branch("scale1fb"             , &scale1fb             );
    tree.Branch("scale1fb_cms2"        , &scale1fb_cms2        );
    tree.Branch("lumi"                 , &lumi                 );
    tree.Branch("xsec"                 , &xsec                 );
    tree.Branch("filt_eff"             , &filt_eff             );
    tree.Branch("is_gen_z"             , &is_gen_z             );
    tree.Branch("is_gen_ee"            , &is_gen_ee            );
    tree.Branch("is_gen_mm"            , &is_gen_mm            );
    tree.Branch("gen_lep1_id"          , &gen_lep1_id          );
    tree.Branch("gen_lep1_charge"      , &gen_lep1_charge      );
    tree.Branch("gen_lep2_id"          , &gen_lep2_id          );
    tree.Branch("gen_lep2_charge"      , &gen_lep2_charge      );

    tree.Branch("gen_p4"      , "LorentzVector" , &gen_p4     );
    tree.Branch("gen_lep1_p4" , "LorentzVector" , &gen_lep1_p4);
    tree.Branch("gen_lep2_p4" , "LorentzVector" , &gen_lep2_p4);
}

std::ostream& operator<< (std::ostream& out, const TreeInfo& info)
{
    out << "run                  = " << info.run                  << std::endl;
    out << "ls                   = " << info.ls                   << std::endl;
    out << "evt                  = " << info.evt                  << std::endl;
    out << "sample               = " << info.sample               << std::endl;
    out << "dataset              = " << info.dataset              << std::endl;
    out << "filename             = " << info.filename             << std::endl;
    out << "is_real_data         = " << info.is_real_data         << std::endl;
    out << "scale1fb             = " << info.scale1fb             << std::endl;
    out << "scale1fb_cms2        = " << info.scale1fb_cms2        << std::endl;
    out << "lumi                 = " << info.lumi                 << std::endl;
    out << "xsec                 = " << info.xsec                 << std::endl;
    out << "kfactor              = " << info.kfactor              << std::endl;
    out << "filt_eff             = " << info.filt_eff             << std::endl;
    out << "is_gen_z             = " << info.is_gen_z             << std::endl;
    out << "is_gen_ee            = " << info.is_gen_ee            << std::endl;
    out << "is_gen_mm            = " << info.is_gen_mm            << std::endl;
    out << "gen_p4.mass()        = " << info.gen_p4.mass()        << std::endl;
    out << "gen_lep1_p4.pt()     = " << info.gen_lep1_p4.pt()     << std::endl;
    out << "gen_lep1_id          = " << info.gen_lep1_id          << std::endl;
    out << "gen_lep1_charge      = " << info.gen_lep1_charge      << std::endl;
    out << "gen_lep2_p4.pt()     = " << info.gen_lep2_p4.pt()     << std::endl;
    out << "gen_lep2_id          = " << info.gen_lep2_id          << std::endl;
    out << "gen_lep2_charge      = " << info.gen_lep2_charge      << std::endl;
    return out;
}

// ------------------------------------ //
//  Looper class 
// ------------------------------------ //

// construct:
CMS2BabyMaker::CMS2BabyMaker
(
    const std::string& sample_name, 
    const std::string& output_filename,
    const std::string& runlist_filename,
    const double lumi,
    const double nevts_corr,
    const bool verbose
)
    : m_sample_name(sample_name)
    , m_output_filename(output_filename)
    , m_runlist_filename("")
    , m_nevts_corr(nevts_corr)
    , m_lumi(lumi)
    , m_verbose(verbose)
    , m_info()
    , m_file(*TFile::Open(output_filename.c_str(), "RECREATE"))
    , m_tree(*new TTree("tree", "CMS2 Example Baby TTree"))
{
}

// ------------------------------------ //
// Stuff to do before job starts
// ------------------------------------ //

void CMS2BabyMaker::BeginJob()
{
    // Set all the branches to the TTree
    m_info.SetBranches(m_tree);
}

// ------------------------------------ //
// simple gen information 
// ------------------------------------ //

struct GenInfo
{
    LorentzVector p4;
    int id;
    int charge;
    int mom_id;
};

// simple gen hypothesis 
struct GenHyp
{
    GenInfo lep1;
    GenInfo lep2;
};

// compare the hypothesis
bool CompareGenHyp(const GenHyp& hyp1, const GenHyp& hyp2)
{
    int hyp1_type = -1;
    switch (hyp1.lep1.id*hyp2.lep2.id)
    {
        case -11*11: hyp1_type = 1; break; // ee
        case -13*13: hyp1_type = 2; break; // mu mu
    }
    int hyp2_type = -1;
    switch (hyp2.lep1.id*hyp2.lep2.id)
    {
        case -11*11: hyp2_type = 1; break; // ee
        case -13*13: hyp2_type = 2; break; // mu mu
    }

    // choose mm over ee over tau tau
    if (hyp1_type != hyp2_type)
    {
        return (hyp1_type > hyp2_type);
    }
    else
    {
        // choose one closer to pdg value of mass of Z-boson
        static const double Mz = 91.1876;
        const double dm1 = fabs((hyp1.lep1.p4 + hyp1.lep2.p4).mass() - Mz);
        const double dm2 = fabs((hyp2.lep1.p4 + hyp2.lep2.p4).mass() - Mz);
        return (dm1 < dm2);
    }
    return true;
}

// ------------------------------------ //
// Stuff to do on each event 
// ------------------------------------ //

void CMS2BabyMaker::Analyze(const long event, const std::string& current_filename)
{
    if (m_verbose)
    {
        std::cout << "\n[DrellYanNtupleMaker] Running on run, ls, event: " 
            << tas::evt_run()       << ", "
            << tas::evt_lumiBlock() << ", "
            << tas::evt_event()     << std::endl;
    }

    // reset the TTree variables
    // ---------------------- // 
    m_info.Reset();

    // event information 
    // ---------------------- // 

    m_info.run          = tas::evt_run();
    m_info.ls           = tas::evt_lumiBlock();
    m_info.evt          = tas::evt_event();
    m_info.sample       = m_sample_name; 
    m_info.dataset      = tas::evt_dataset().front().Data();
    m_info.filename     = current_filename; 
    m_info.is_real_data = tas::evt_isRealData(); 
    if (!tas::evt_isRealData())
    {
        m_info.scale1fb_cms2 = tas::evt_scale1fb();
        m_info.scale1fb      = m_info.scale1fb_cms2 * m_nevts_corr; 
        m_info.lumi          = m_lumi; 
        m_info.xsec          = tas::evt_xsec_excl();
        m_info.kfactor       = tas::evt_kfactor();
        m_info.filt_eff      = tas::evt_filt_eff();
    }

    // gen information 
    // ---------------------- // 

    if (!tas::evt_isRealData())
    {
        // loop over gen particles and create a list of status 3 leptons 
        std::vector<GenInfo> gen_infos;
        for (size_t gen_idx = 0; gen_idx < tas::genps_id().size(); ++gen_idx)
        {
            // only keep status 3
            if (cms2.genps_status().at(gen_idx) != 3) {continue;}
        
            // only keep charged leptons
            const int id = tas::genps_id().at(gen_idx);
            if (abs(id) == 11 || abs(id) == 13)
            {
                // create the GenInfo object 
                const int charge        = -1*id/abs(id); // e.g. 11 == e^- and -11 == e+
                const LorentzVector& p4 = tas::genps_p4().at(gen_idx);
                const int mom_id        = tas::genps_id_mother().at(gen_idx);
                const GenInfo gen_info{p4, id, charge, mom_id}; 
                gen_infos.push_back(gen_info);
            }
            if (abs(id) == 15)
            {
                // only consider tau --> nu_tau + nu_lep + lep events
                // we count neutrino's because that guarantees that 
                // there is a corresponding lepton and that it comes from
                // a leptonic tau decay. You can get electrons from converted photons
                // which are radiated by charged pions from the tau decay but thats
                // hadronic and we don't care for those 
                int nu_count = 0;
                for (const int& d_id : tas::genps_lepdaughter_id().at(gen_idx))
                {
                    if (abs(d_id)==12 || abs(d_id)==14) ++nu_count;
                }
                if (nu_count < 1) {continue;}

                // now find the lepton
                for (size_t d_idx = 0; d_idx != tas::genps_lepdaughter_id().at(gen_idx).size(); ++d_idx)
                {
                    const int d_id = tas::genps_lepdaughter_id().at(gen_idx).at(d_idx);
                    if (abs(d_id)==11 || abs(d_id)==13)
                    {
                        const int d_charge        = -1*d_id/abs(d_id); // e.g. 11 == e^- and -11 == e+
                        const LorentzVector& d_p4 = tas::genps_lepdaughter_p4().at(gen_idx).at(d_idx);
                        const int d_mom_id        = id; 
                        const GenInfo gen_info{d_p4, d_id, d_charge, d_mom_id}; 
                        gen_infos.push_back(gen_info);
                        break;
                    }
                }
            }
        }

        // for the gyn hypothesis pairs from the GenInfos 
        std::vector<GenHyp> gen_hyps;
        for (size_t idx1 = 0; idx1 < gen_infos.size(); idx1++)
        {
            for (size_t idx2 = idx1 + 1; idx2 < gen_infos.size(); idx2++)
            {
                // sort by pt
                const GenInfo& gen_l1 = (gen_infos.at(idx1).p4.pt() > gen_infos.at(idx2).p4.pt() ? gen_infos.at(idx1) : gen_infos.at(idx2));
                const GenInfo& gen_l2 = (gen_infos.at(idx1).p4.pt() > gen_infos.at(idx2).p4.pt() ? gen_infos.at(idx2) : gen_infos.at(idx1));
                const GenHyp gen_hyp{gen_l1, gen_l2};

                // ensure opposite sign
                if (gen_hyp.lep1.charge == gen_hyp.lep2.charge) {continue;}

                // ensure same flavor
                if (abs(gen_hyp.lep1.id) != abs(gen_hyp.lep2.id)) {continue;}

                gen_hyps.push_back(gen_hyp);
            }
        }

        // sort the gen hyps in order of precedence
        std::sort(gen_hyps.begin(), gen_hyps.end(), CompareGenHyp);

        // fill the tree info with gen info

        if (m_verbose) {std::cout << "number of gen hyps = " << gen_hyps.size() << std::endl;}
        if (!gen_hyps.empty())
        {
            const GenHyp& gen_hyp = gen_hyps.front();

            // assign info 
            m_info.is_gen_z        = (gen_hyp.lep1.mom_id==23 && gen_hyp.lep2.mom_id==23);
            m_info.is_gen_ee       = (gen_hyp.lep1.id*gen_hyp.lep2.id == -11*11);
            m_info.is_gen_mm       = (gen_hyp.lep1.id*gen_hyp.lep2.id == -13*13);
            m_info.gen_p4          = (gen_hyp.lep1.p4 + gen_hyp.lep2.p4);
            m_info.gen_lep1_p4     = gen_hyp.lep1.p4;
            m_info.gen_lep1_id     = gen_hyp.lep1.id;
            m_info.gen_lep1_charge = gen_hyp.lep1.charge;
            m_info.gen_lep2_p4     = gen_hyp.lep2.p4;
            m_info.gen_lep2_id     = gen_hyp.lep2.id;
            m_info.gen_lep2_charge = gen_hyp.lep2.charge;
        }
    }

    // fill the tree
    // ---------------------- // 
    if (m_verbose) {std::cout << m_info << std::endl;}

    m_tree.Fill();

    // done
    return;
}

// ------------------------------------ //
// Stuff to do after job finishes
// ------------------------------------ //

void CMS2BabyMaker::EndJob()
{
    std::cout << "[CMS2BabyMaker] Saving hists to output file: " << m_output_filename << std::endl;
    m_file.cd(); 
    m_tree.Write();
    m_file.Close(); 
    return;
}

// ------------------------------------ //
// loop over event 
// ------------------------------------ //

void CMS2BabyMaker::ScanChain(TChain& chain, const long num_events)
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
    if (!m_runlist_filename.empty())
    {
        set_goodrun_file(m_runlist_filename.c_str());
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
                if (!m_runlist_filename.empty())
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
            Analyze(event, current_file->GetTitle());

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
