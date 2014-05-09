// C++
#include <iostream>
#include <vector>
#include <string>

// ROOT
#include "TBenchmark.h"
#include "TChain.h"
#include "TDirectory.h"
#include "TFile.h"
#include "TROOT.h"
#include "TTreeCache.h"
#include "Math/LorentzVector.h"
#include "Math/VectorUtil.h"

// CMS2 and CORE
#include "CMS2/NtupleMacrosHeader/interface/CMS2.h"
#include "CMS2/NtupleMacrosCore/interface/eventSelections.h"
#include "CMS2/NtupleMacrosCore/interface/trackSelections.h"
#include "CMS2/NtupleMacrosCore/interface/mcSelections.h"

// from packages 
#include "Packages/LooperTools/interface/LoadFWLite.h"
#include "Packages/LooperTools/interface/GoodRun.h"
#include "Packages/LooperTools/interface/DorkyEventIdentifier.h"

// typedefs
typedef ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > LorentzVector;

// class that contains the branch variables
class TreeInfo
{
    public:

        // constructors and destructor
        TreeInfo();

        // methods:
        void Reset();
        void SetBranches(TTree& tree);

        // members:

        // event level info
        int run;
        int ls;
        int evt;
        std::string sample;
        std::string dataset;
        std::string filename;
        bool is_real_data;
        double scale1fb;
        double xsec;
        double kfactor;
        double filt_eff;
        double rho;

        // lepton reco info
        LorentzVector p4;
        bool passes_id;
        bool passes_iso;
        bool is_mu;
        bool is_el;
        int is_prompt;
        int charge;
        int pdgid;
        int type;
        double d0;
        double dz;
        double pfiso;
        double chiso;
        double emiso;
        double nhiso;

        // lepton gen info
        LorentzVector mc1_p4;
        LorentzVector mc3_p4;
        LorentzVector mc1_mom_p4;
        int mc1_id;
        int mc3_id;
        int mc1_mom_id;
        int mc3_mom_id;

        // electron specific info
        bool el_is_conv;
        bool el_is_fiducial;
        double el_effarea;
        double el_sc_eta;
        double el_exp_innerlayers;
        double el_sigma_ieie;
        double el_dphi_in;
        double el_deta_in;
        double el_ooemoop; // |1/E - 1/p|
        double el_h_over_e;

        // muon specific variables
        bool mu_is_global_mu;
        bool mu_is_pf_mu;
        bool mu_is_fiducial;
        double mu_gfit_chi2ndof;
        double mu_dbeta;
        int mu_nmatched_stations;
        int mu_nvalid_stahits;
        int mu_trk_nvalid_pixhits;
        int mu_trk_nlayers;
};

// construct:
TreeInfo::TreeInfo()
    : run                   ( -999999   )
    , ls                    ( -999999   )
    , evt                   ( -999999   )
    , sample                ( ""        )
    , dataset               ( ""        )
    , filename              ( ""        )
    , is_real_data          ( false     )
    , scale1fb              ( -999999.0 )
    , xsec                  ( -999999.0 )
    , kfactor               ( -999999.0 )
    , filt_eff              ( -999999.0 )
    , rho                   ( -999999.0 )
    , p4                    ( 0,0,0,0   )
    , passes_id             ( false     )
    , passes_iso            ( false     )
    , is_mu                 ( false     )
    , is_el                 ( false     )
    , is_prompt             ( -999999   )
    , charge                ( -999999   )
    , pdgid                 ( -999999   )
    , type                  ( -999999   )
    , d0                    ( -999999.0 )
    , dz                    ( -999999.0 )
    , pfiso                 ( -999999.0 )
    , chiso                 ( -999999.0 )
    , emiso                 ( -999999.0 )
    , nhiso                 ( -999999.0 )
    , mc1_p4                ( 0,0,0,0   )
    , mc3_p4                ( 0,0,0,0   )
    , mc1_mom_p4            ( 0,0,0,0   )
    , mc1_id                ( -999999   )
    , mc3_id                ( -999999   )
    , mc1_mom_id            ( -999999   )
    , mc3_mom_id            ( -999999   )
    , el_is_conv            ( false     )
    , el_is_fiducial        ( false     )
    , el_effarea            ( -999999.0 )
    , el_sc_eta             ( -999999.0 )
    , el_exp_innerlayers    ( -999999.0 )
    , el_sigma_ieie         ( -999999.0 )
    , el_dphi_in            ( -999999.0 )
    , el_deta_in            ( -999999.0 )
    , el_ooemoop            ( -999999.0 )
    , el_h_over_e           ( -999999.0 )
    , mu_is_global_mu       ( false     )
    , mu_is_pf_mu           ( false     )
    , mu_is_fiducial        ( false     )
    , mu_gfit_chi2ndof      ( -999999.0 )
    , mu_dbeta              ( -999999.0 )
    , mu_nmatched_stations  ( -999999   )
    , mu_nvalid_stahits     ( -999999   )
    , mu_trk_nvalid_pixhits ( -999999   )
    , mu_trk_nlayers        ( -999999   )
{
}

// methods:
void TreeInfo::Reset()
{
    run                   = -999999   ;
    ls                    = -999999   ;
    evt                   = -999999   ;
    sample                = ""        ;
    dataset               = ""        ;
    filename              = ""        ;
    is_real_data          = false     ;
    scale1fb              = -999999.0 ;
    xsec                  = -999999.0 ;
    kfactor               = -999999.0 ;
    filt_eff              = -999999.0 ;
    rho                   = -999999.0 ;
    passes_id             = false     ;
    passes_iso            = false     ;
    is_mu                 = false     ;
    is_el                 = false     ;
    is_prompt             = -999999   ;
    charge                = -999999   ;
    pdgid                 = -999999   ;
    type                  = -999999   ;
    d0                    = -999999.0 ;
    dz                    = -999999.0 ;
    pfiso                 = -999999.0 ;
    chiso                 = -999999.0 ;
    emiso                 = -999999.0 ;
    nhiso                 = -999999.0 ;
    mc1_id                = -999999   ;
    mc3_id                = -999999   ;
    mc1_mom_id            = -999999   ;
    mc3_mom_id            = -999999   ;
    el_is_conv            = false     ;
    el_is_fiducial        = false     ;
    el_effarea            = -999999.0 ;
    el_sc_eta             = -999999.0 ;
    el_exp_innerlayers    = -999999.0 ;
    el_sigma_ieie         = -999999.0 ;
    el_dphi_in            = -999999.0 ;
    el_deta_in            = -999999.0 ;
    el_ooemoop            = -999999.0 ;
    el_h_over_e           = -999999.0 ;
    mu_is_global_mu       = false     ;
    mu_is_pf_mu           = false     ;
    mu_is_fiducial        = false     ;
    mu_gfit_chi2ndof      = -999999.0 ;
    mu_dbeta              = -999999.0 ;
    mu_nmatched_stations  = -999999   ;
    mu_nvalid_stahits     = -999999   ;
    mu_trk_nvalid_pixhits = -999999   ;
    mu_trk_nlayers        = -999999   ;

    p4.SetXYZT(0,0,0,0);
    mc1_p4.SetXYZT(0,0,0,0);
    mc3_p4.SetXYZT(0,0,0,0);
    mc1_mom_p4.SetXYZT(0,0,0,0);
}

void TreeInfo::SetBranches(TTree& tree)
{
    tree.Branch("run"                  , &run                   );
    tree.Branch("ls"                   , &ls                    );
    tree.Branch("evt"                  , &evt                   );
    tree.Branch("sample"               , &sample                );
    tree.Branch("dataset"              , &dataset               );
    tree.Branch("filename"             , &filename              );
    tree.Branch("is_real_data"         , &is_real_data          );
    tree.Branch("scale1fb"             , &scale1fb              );
    tree.Branch("xsec"                 , &xsec                  );
    tree.Branch("kfactor"              , &kfactor               );
    tree.Branch("filt_eff"             , &filt_eff              );
    tree.Branch("rho"                  , &rho                   );
    tree.Branch("p4"                   , &p4                    );
    tree.Branch("passes_id"            , &passes_id             );
    tree.Branch("passes_iso"           , &passes_iso            );
    tree.Branch("is_mu"                , &is_mu                 );
    tree.Branch("is_el"                , &is_el                 );
    tree.Branch("is_prompt"            , &is_prompt             );
    tree.Branch("charge"               , &charge                );
    tree.Branch("pdgid"                , &pdgid                 );
    tree.Branch("type"                 , &type                  );
    tree.Branch("d0"                   , &d0                    );
    tree.Branch("dz"                   , &dz                    );
    tree.Branch("pfiso"                , &pfiso                 );
    tree.Branch("chiso"                , &chiso                 );
    tree.Branch("emiso"                , &emiso                 );
    tree.Branch("nhiso"                , &nhiso                 );
    tree.Branch("mc1_p4"               , &mc1_p4                );
    tree.Branch("mc3_p4"               , &mc3_p4                );
    tree.Branch("mc1_mom_p4"           , &mc1_mom_p4            );
    tree.Branch("mc1_id"               , &mc1_id                );
    tree.Branch("mc3_id"               , &mc3_id                );
    tree.Branch("mc1_mom_id"           , &mc1_mom_id            );
    tree.Branch("mc3_mom_id"           , &mc3_mom_id            );
    tree.Branch("el_is_conv"           , &el_is_conv            );
    tree.Branch("el_is_fiducial"       , &el_is_fiducial        );
    tree.Branch("el_effarea"           , &el_effarea            );
    tree.Branch("el_sc_eta"            , &el_sc_eta              );
    tree.Branch("el_exp_innerlayers"   , &el_exp_innerlayers    );
    tree.Branch("el_sigma_ieie"        , &el_sigma_ieie         );
    tree.Branch("el_dphi_in"           , &el_dphi_in            );
    tree.Branch("el_deta_in"           , &el_deta_in            );
    tree.Branch("el_ooemoop"           , &el_ooemoop            );
    tree.Branch("el_h_over_e"          , &el_h_over_e           );
    tree.Branch("mu_is_global_mu"      , &mu_is_global_mu       );
    tree.Branch("mu_is_pf_mu"          , &mu_is_pf_mu           );
    tree.Branch("mu_is_fiducial"       , &mu_is_fiducial        );
    tree.Branch("mu_gfit_chi2ndof"     , &mu_gfit_chi2ndof      );
    tree.Branch("mu_dbeta"             , &mu_dbeta              );
    tree.Branch("mu_nmatched_stations" , &mu_nmatched_stations  );
    tree.Branch("mu_nvalid_stahits"    , &mu_nvalid_stahits     );
    tree.Branch("mu_trk_nvalid_pixhits", &mu_trk_nvalid_pixhits );
    tree.Branch("mu_trk_nlayers"       , &mu_trk_nlayers        );
}

// non-members:
std::ostream& operator<< (std::ostream& out, const TreeInfo& info)
{
    out << "run                   = " << info.run                   << endl;
    out << "ls                    = " << info.ls                    << endl;
    out << "evt                   = " << info.evt                   << endl;
    out << "sample                = " << info.sample                << endl;
    out << "dataset               = " << info.dataset               << endl;
    out << "filename              = " << info.filename              << endl;
    out << "is_real_data          = " << info.is_real_data          << endl;
    out << "scale1fb              = " << info.scale1fb              << endl;
    out << "xsec                  = " << info.xsec                  << endl;
    out << "kfactor               = " << info.kfactor               << endl;
    out << "filt_eff              = " << info.filt_eff              << endl;
    out << "rho                   = " << info.rho                   << endl;
    out << "p4                    = " << info.p4.mass()             << endl;
    out << "passes_id             = " << info.passes_id             << endl;
    out << "passes_iso            = " << info.passes_iso            << endl;
    out << "is_mu                 = " << info.is_mu                 << endl;
    out << "is_el                 = " << info.is_el                 << endl;
    out << "is_prompt             = " << info.is_prompt             << endl;
    out << "charge                = " << info.charge                << endl;
    out << "pdgid                 = " << info.pdgid                 << endl;
    out << "type                  = " << info.type                  << endl;
    out << "d0                    = " << info.d0                    << endl;
    out << "dz                    = " << info.dz                    << endl;
    out << "pfiso                 = " << info.pfiso                 << endl;
    out << "chiso                 = " << info.chiso                 << endl;
    out << "emiso                 = " << info.emiso                 << endl;
    out << "nhiso                 = " << info.nhiso                 << endl;
    out << "mc1_p4.mass()         = " << info.mc1_p4.mass()         << endl;
    out << "mc3_p4.mass()         = " << info.mc3_p4.mass()         << endl;
    out << "mc1_mom_p4.mass()     = " << info.mc1_mom_p4.mass()     << endl;
    out << "mc1_id                = " << info.mc1_id                << endl;
    out << "mc3_id                = " << info.mc3_id                << endl;
    out << "mc1_mom_id            = " << info.mc1_mom_id            << endl;
    out << "mc3_mom_id            = " << info.mc3_mom_id            << endl;
    out << "el_is_conv            = " << info.el_is_conv            << endl;
    out << "el_is_fiducial        = " << info.el_is_fiducial        << endl;
    out << "el_effarea            = " << info.el_effarea            << endl;
    out << "el_sc_eta             = " << info.el_sc_eta             << endl;
    out << "el_exp_innerlayers    = " << info.el_exp_innerlayers    << endl;
    out << "el_sigma_ieie         = " << info.el_sigma_ieie         << endl;
    out << "el_dphi_in            = " << info.el_dphi_in            << endl;
    out << "el_deta_in            = " << info.el_deta_in            << endl;
    out << "el_ooemoop            = " << info.el_ooemoop            << endl;
    out << "el_h_over_e           = " << info.el_h_over_e           << endl;
    out << "mu_is_global_mu       = " << info.mu_is_global_mu       << endl;
    out << "mu_is_pf_mu           = " << info.mu_is_pf_mu           << endl;
    out << "mu_is_fiducial        = " << info.mu_is_fiducial        << endl;
    out << "mu_gfit_chi2ndof      = " << info.mu_gfit_chi2ndof      << endl;
    out << "mu_dbeta              = " << info.mu_dbeta              << endl;
    out << "mu_nmatched_stations  = " << info.mu_nmatched_stations  << endl;
    out << "mu_nvalid_stahits     = " << info.mu_nvalid_stahits     << endl;
    out << "mu_trk_nvalid_pixhits = " << info.mu_trk_nvalid_pixhits << endl;
    out << "mu_trk_nlayers        = " << info.mu_trk_nlayers        << endl;
    return out;
}

// -------------------------------------------------//
// Simple class to hold your analysis meta-data
// -------------------------------------------------//

class SingleLeptonNtupleMaker
{
    public:
        // construct:
        SingleLeptonNtupleMaker
        (
            const std::string& sample_name, 
            const std::string& output_filename,
            const std::string& runlist_filename = "",
            const bool verbose = false
        );

        // methods:
        void ScanChain(TChain& chain, const long num_events = -1);

    private:
        // private methods:
        void BeginJob();
        void Analyze(const long event, const std::string& current_filename);
        void EndJob();

        // members:
        std::string m_sample_name;
        std::string m_output_filename;
        std::string m_runlist_filename;
        bool m_verbose;
        TreeInfo m_info;
        TFile& m_file;
        TTree& m_tree;
};

// construct:
SingleLeptonNtupleMaker::SingleLeptonNtupleMaker
(
    const std::string& sample_name, 
    const std::string& output_filename, 
    const std::string& runlist_filename,
    const bool verbose
)
    : m_sample_name(sample_name)
    , m_output_filename(output_filename)
    , m_runlist_filename(runlist_filename)
    , m_verbose(verbose)
    , m_info()
    , m_file(*TFile::Open(output_filename.c_str(), "RECREATE"))
    , m_tree(*new TTree("tree", "Single Lepton Ntuple"))
{
}

// ------------------------------------ //
// Stuff to do before job starts
// ------------------------------------ //

void SingleLeptonNtupleMaker::BeginJob()
{
    m_info.SetBranches(m_tree);
}

// ------------------------------------ //
// helper functions 
// ------------------------------------ //

double LeptonD0(const int lep_id, const int lep_idx)
{
    const int vtxidx = firstGoodVertex();
    if (vtxidx < 0)
    {
        std::cout << "[LeptonD0] WARNING - first good vertex index < 0.  Returning bogus value 999999" << std::endl;
        return 999999.0;
    }
    if (abs(lep_id)==13)
    {
        const int trkidx = tas::mus_trkidx().at(lep_idx);
        if (trkidx >= 0)
        {
            return trks_d0_pv(trkidx, vtxidx).first;
        }
    }
    else if (abs(lep_id)==11)
    {
        const int gsfidx = tas::els_gsftrkidx().at(lep_idx);
        if (gsfidx >= 0) 
        {
            return gsftrks_d0_pv(gsfidx, vtxidx).first;
        }
        const int trkidx = tas::els_trkidx().at(lep_idx);
        if (trkidx >= 0)
        {
            return trks_d0_pv(trkidx, vtxidx).first;
        }
    }

    // return bogus for non electon/muon
    return -999999.0;
}

double LeptonDz(const int lep_id, const int lep_idx)
{
    const int vtxidx = firstGoodVertex();
    if (vtxidx < 0)
    {
        std::cout << "[LeptonDz] WARNING - first good vertex index < 0.  Returning bogus value 999999" << std::endl;
        return 999999.0;
    }
    if (abs(lep_id)==13)
    {
        const int trkidx = tas::mus_trkidx().at(lep_idx);
        if (trkidx >= 0)
        {
            return trks_dz_pv(trkidx, vtxidx).first;
        }
    }
    else if (abs(lep_id)==11)
    {
        const int gsfidx = tas::els_gsftrkidx().at(lep_idx);
        if (gsfidx >= 0)
        {
            return gsftrks_dz_pv(gsfidx, vtxidx).first;
        }
        const int trkidx = tas::els_trkidx().at(lep_idx);
        if (trkidx >= 0)
        {
            return trks_dz_pv(trkidx, vtxidx).first;
        }
    }

    // return bogus for non electon/muon
    return -999999.0;
}

// ------------------------------------ //
// Stuff to do on each event 
// ------------------------------------ //

void SingleLeptonNtupleMaker::Analyze(const long event, const std::string& current_filename)
{
    if (m_verbose)
    {
        std::cout << "\n[SingleLeptonNtupleMaker] Running on run, ls, event: " 
            << tas::evt_run()       << ", "
            << tas::evt_lumiBlock() << ", "
            << tas::evt_event()     << std::endl;
    }

    // electrons
    // ------------------------------------ //

    for (size_t el_idx = 0; el_idx < tas::els_p4().size(); ++el_idx)
    {
        // reset the TTree variables
        m_info.Reset();

        // event info:
        m_info.run          = tas::evt_run();
        m_info.ls           = tas::evt_lumiBlock();
        m_info.evt          = tas::evt_event();
        m_info.sample       = m_sample_name; 
        m_info.dataset      = tas::evt_dataset().front().Data();
        m_info.filename     = current_filename; 
        m_info.is_real_data = tas::evt_isRealData(); 
        m_info.rho          = -999999.0; 
        if (!tas::evt_isRealData())
        {
            m_info.scale1fb = tas::evt_scale1fb();
            m_info.xsec     = tas::evt_xsec_excl();
            m_info.kfactor  = tas::evt_kfactor();
            m_info.filt_eff = tas::evt_filt_eff();
        }

        // lepton info:
        m_info.p4         = tas::els_p4().at(el_idx); 
        m_info.passes_id  = false;
        m_info.passes_iso = false;
        m_info.is_mu      = false;
        m_info.is_el      = true;
        m_info.charge     = tas::els_charge().at(el_idx);
        m_info.pdgid      = m_info.charge * -11;
        m_info.type       = tas::els_type().at(el_idx);
        m_info.d0         = LeptonD0(m_info.pdgid, el_idx);
        m_info.dz         = LeptonDz(m_info.pdgid, el_idx);
        m_info.pfiso      = -999999.0;
        m_info.chiso      = -999999.0;
        m_info.emiso      = -999999.0;
        m_info.nhiso      = -999999.0;

        // gen info:
        if (!tas::evt_isRealData())
        {
            // status 1
            m_info.mc1_p4     = tas::els_mc_p4().at(el_idx);
            m_info.mc1_mom_p4 = tas::els_mc_motherp4().at(el_idx);
            m_info.mc1_id     = tas::els_mc_id().at(el_idx);
            m_info.mc1_mom_id = tas::els_mc3_id().at(el_idx);

            // status 3
            m_info.mc3_mom_id = tas::els_mc3_motherid().at(el_idx);
            const int mc3idx  = tas::els_mc3idx().at(el_idx);
            if (mc3idx >= 0)
            {
                m_info.mc3_p4 = tas::genps_p4().at(mc3idx);           
                m_info.mc3_id = tas::genps_id().at(mc3idx);           
            }

            // determine if from non-colored process (i.e. is prompt)
            // see: https://github.com/cmstas/CORE/blob/scram_compliant/mcSelections.h#L55 
            m_info.is_prompt = leptonIsFromW(el_idx, m_info.pdgid, /*include SUSY=*/false) >= 1;
        }

        // electron info:
        m_info.el_effarea         = -999999.0;
        m_info.el_sc_eta          = fabs(tas::els_etaSC().at(el_idx));
        m_info.el_exp_innerlayers = -999999.0;
        m_info.el_sigma_ieie      = -999999.0;
        m_info.el_dphi_in         = -999999.0;
        m_info.el_deta_in         = -999999.0;
        m_info.el_ooemoop         = -999999.0;
        m_info.el_h_over_e        = -999999.0;
        m_info.el_is_conv         = false;

        const double aeta_sc  = fabs(m_info.el_sc_eta);
        m_info.el_is_fiducial = (aeta_sc < 2.5) and not (1.4442 < aeta_sc and aeta_sc < 1.566);

        // fill the tree
        if (m_verbose) {std::cout << m_info << std::endl;}
        m_tree.Fill();

    } // end electrons

    // muons
    // ------------------------------------ //

    for (size_t mu_idx = 0; mu_idx < tas::mus_p4().size(); ++mu_idx)
    {
        // reset the TTree variables
        m_info.Reset();

        // event info:
        m_info.run          = tas::evt_run();
        m_info.ls           = tas::evt_lumiBlock();
        m_info.evt          = tas::evt_event();
        m_info.sample       = m_sample_name; 
        m_info.dataset      = tas::evt_dataset().front().Data();
        m_info.filename     = current_filename; 
        m_info.is_real_data = tas::evt_isRealData(); 
        m_info.rho          = -999999.0; 
        if (!tas::evt_isRealData())
        {
            m_info.scale1fb = tas::evt_scale1fb();
            m_info.xsec     = tas::evt_xsec_excl();
            m_info.kfactor  = tas::evt_kfactor();
            m_info.filt_eff = tas::evt_filt_eff();
        }

        // lepton info:
        m_info.p4         = tas::mus_p4().at(mu_idx); 
        m_info.passes_id  = false;
        m_info.passes_iso = false;
        m_info.is_mu      = true;
        m_info.is_el      = false;
        m_info.charge     = tas::mus_charge().at(mu_idx);
        m_info.pdgid      = m_info.charge * -13;
        m_info.type       = tas::mus_type().at(mu_idx);
        m_info.d0         = LeptonD0(m_info.pdgid, mu_idx);
        m_info.dz         = LeptonDz(m_info.pdgid, mu_idx);
        m_info.pfiso      = -999999.0;
        m_info.chiso      = -999999.0;
        m_info.emiso      = -999999.0;
        m_info.nhiso      = -999999.0;

        // gen info:
        if (!tas::evt_isRealData())
        {
            // status 1
            m_info.mc1_p4     = tas::mus_mc_p4().at(mu_idx);
            m_info.mc1_mom_p4 = tas::mus_mc_motherp4().at(mu_idx);
            m_info.mc1_id     = tas::mus_mc_id().at(mu_idx);
            m_info.mc1_mom_id = tas::mus_mc3_id().at(mu_idx);

            // status 3
            m_info.mc3_mom_id = tas::mus_mc3_motherid().at(mu_idx);
            const int mc3idx  = tas::mus_mc3idx().at(mu_idx);
            if (mc3idx >= 0)
            {
                m_info.mc3_p4 = tas::genps_p4().at(mc3idx);           
                m_info.mc3_id = tas::genps_id().at(mc3idx);           
            }

            // determine if from non-colored process (i.e. is prompt)
            // see: https://github.com/cmstas/CORE/blob/scram_compliant/mcSelections.h#L55 
            m_info.is_prompt = leptonIsFromW(mu_idx, m_info.pdgid, /*include SUSY=*/false) >= 1;
        }

        // muon info:
        m_info.mu_is_global_mu       = false;
        m_info.mu_is_pf_mu           = false;
        m_info.mu_is_fiducial        = false;
        m_info.mu_gfit_chi2ndof      = -999999.0;
        m_info.mu_dbeta              = -999999.0;
        m_info.mu_nmatched_stations  = -999999;
        m_info.mu_nvalid_stahits     = -999999;
        m_info.mu_trk_nvalid_pixhits = -999999;
        m_info.mu_trk_nlayers        = -999999;

        // fill the tree
        if (m_verbose) {std::cout << m_info << std::endl;}
        m_tree.Fill();

    } // end muons

    // done
    return;
}

// ------------------------------------ //
// Stuff to do after job finishes
// ------------------------------------ //

void SingleLeptonNtupleMaker::EndJob()
{
    std::cout << "[SingleLeptonNtupleMaker] Saving TTree to output file: " << m_output_filename << std::endl;
    m_file.cd(); 
    m_tree.Write();
    m_file.Close(); 
    return;
}

// ------------------------------------ //
// loop over event 
// ------------------------------------ //

void SingleLeptonNtupleMaker::ScanChain(TChain& chain, const long num_events)
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
            CMS2::progress(num_events_total, num_events_chain);

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

// ------------------------------------ //
// main program 
// ------------------------------------ //

#include "boost/program_options.hpp"

int main(int argc, char **argv)
try
{
    // parse the inputs
    // see: http://www.boost.org/doc/libs/1_55_0/doc/html/program_options.html
    // -------------------------------------------------------------------------------------------------//

    // defaults 
    long long number_of_events = -1;
    std::string sample_name    = "";
    std::string output_file    = "";
    bool verbose               = false;

    // parse arguments
    namespace po = boost::program_options;
    po::options_description desc("Allowed options");
    desc.add_options()
        ("help"       , "print this menu")
        ("sample"     , po::value<std::string>(&sample_name)->required(), "REQUIRED: Sample name to run on" )
        ("output"     , po::value<std::string>(&output_file)            , "output ROOT file"                )
        ("nevts"      , po::value<long long>(&number_of_events)         , "maximum number of events to skim")
        ("verbose"    , po::value<bool>(&verbose)                       , "verbosity toggle"                )
        ;
    try
    {
        // first parse command line options
        po::variables_map vm;
        po::store(po::parse_command_line(argc, argv, desc), vm);
        if (vm.count("help")) 
        {
            std::cout << desc << "\n";
            return 1;
        }
        po::notify(vm);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << "\nexiting" << std::endl;
        std::cout << desc << "\n";
        return 1;
    }
    catch (...)
    {
        std::cerr << "Unknown error!" << "\n";
        return 1;
    }

    // print the inputs  
    std::cout << "[create_singlep_baby] inputs:\n";
    std::cout << "sample           = " << sample_name      << "\n";
    std::cout << "output           = " << output_file      << "\n";
    std::cout << "nevts            = " << number_of_events << "\n";
    std::cout << "verbose          = " << verbose          << "\n";
    std::cout << std::endl;

    // check inputs 
    // -------------------------------------------------------------------------------------------------//

    // available samples
    const std::vector<std::string> samples
    {
        "dyll",
        "qcd"
    };

    // check that sample name is value
    if (std::find(samples.begin(), samples.end(), sample_name) == samples.end())
    {
        throw std::invalid_argument(Form("[create_singlelp_baby] sample %s is not valid.\n", sample_name.c_str()));
    }

    // get sample files
    std::string input_file = "";
    if (sample_name == "dyll") {input_file = "/nfs-7/userdata/rwkelley/cms2/DYJetsToLL_M-50_TuneZ2Star_8TeV-madgraph-tarball_Summer12_DR53X-PU_S10_START53_V7A-v1.root";}
    if (sample_name == "qcd" ) {input_file = "/nfs-7/userdata/rwkelley/cms2/QCD_Pt_20_MuEnrichedPt_15_TuneZ2star_8TeV_pythia6_Summer12_DR53X-PU_S10_START53_V7A-v3.root";}
    if (input_file.empty())
    {
        throw std::invalid_argument(Form("[create_singlelp_baby] sample input_file %s is not valid.\n", input_file.c_str()));
    }

    // set output file
    if (output_file.empty())
    {
        output_file = Form("babies/%s_baby.root", sample_name.c_str());
    }

    // do it 
    // -------------------------------------------------------------------------------------------------//

    // Load TChain for the sample
    LoadFWLite();
    TChain chain("Events");
    chain.Add(input_file.c_str());

    // create baby maker object
    SingleLeptonNtupleMaker baby_maker
    (
        sample_name,
        output_file,
        /*run_list=*/"",
        verbose
    );

    // run it
    std::cout << "running single lepton baby maker..." << std::endl;
    baby_maker.ScanChain(chain, number_of_events);

    return 0;
}
catch (std::exception& e)
{
    std::cerr << "[create_singlep_baby] Error: failed..." << std::endl;
    std::cerr << e.what() << std::endl;
    return 1;
}
