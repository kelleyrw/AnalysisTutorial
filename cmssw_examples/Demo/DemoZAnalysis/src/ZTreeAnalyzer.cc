/* ------------------------------------------------------------------ * 

Package:         DemoZAnalysis
Class:           ZTreeAnalyzer
Description:     Simple EDProducer to make a simple ntuple for z analysis 
Original Author: Ryan W. Kelley 
Created:         Tue Jan 14 11:30:45 PST 2014

* ------------------------------------------------------------------ */

// system include files
#include <memory>
#include <array>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

// ROOT include files
#include "Math/LorentzVector.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TFile.h"
#include "TDirectory.h"

// class declaration
// ------------------------------------------------------------------ //

class ZTreeAnalyzer : public edm::EDAnalyzer
{
    public:
        // construct:
        explicit ZTreeAnalyzer(const edm::ParameterSet&);

        // destroy:
        ~ZTreeAnalyzer();

        // methods:
        static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);

    private:

        // private methods:
        virtual void beginJob() ;
        virtual void analyze(const edm::Event&, const edm::EventSetup&);
        virtual void endJob() ;

        virtual void beginRun(edm::Run const&, edm::EventSetup const&);
        virtual void endRun(edm::Run const&, edm::EventSetup const&);
        virtual void beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&);
        virtual void endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&);

        // ----------member data ---------------------------

        // parameters
        const unsigned int m_mll_nbins;
        const double m_mll_min;
        const double m_mll_max;
        const std::string m_hist_filename;

        // histograms 
        TH1D h_gen_mz;
        TH1D h_gen_mll;
        TH1D h_reco_mll;
        TH1D h_gen_mee;
        TH1D h_reco_mee;
        TH1D h_gen_mmm;
        TH1D h_reco_mmm;

        TH1D h_gen_e1_pt;
        TH1D h_gen_e1_eta;
        TH1D h_gen_e1_charge;
        TH1D h_gen_e1_matched;
        TH1D h_num_e1_pt;
        TH1D h_den_e1_pt;
        TH1D h_reco_e1_pt;
        TH1D h_reco_e1_eta;
        TH1D h_reco_e1_charge;
        TH1D h_reco_e1_dr;
        TH2D h_reco_e1_res_vs_pt;

        TH1D h_gen_e2_pt;
        TH1D h_gen_e2_eta;
        TH1D h_gen_e2_charge;
        TH1D h_gen_e2_matched;
        TH1D h_num_e2_pt;
        TH1D h_den_e2_pt;
        TH1D h_reco_e2_pt;
        TH1D h_reco_e2_eta;
        TH1D h_reco_e2_charge;
        TH1D h_reco_e2_dr;
        TH2D h_reco_e2_res_vs_pt;

        TH1D h_gen_mu1_pt;
        TH1D h_gen_mu1_eta;
        TH1D h_gen_mu1_charge;
        TH1D h_gen_mu1_matched;
        TH1D h_num_mu1_pt;
        TH1D h_den_mu1_pt;
        TH1D h_reco_mu1_pt;
        TH1D h_reco_mu1_eta;
        TH1D h_reco_mu1_charge;
        TH1D h_reco_mu1_dr;
        TH2D h_reco_mu1_res_vs_pt;

        TH1D h_gen_mu2_pt;
        TH1D h_gen_mu2_eta;
        TH1D h_gen_mu2_charge;
        TH1D h_gen_mu2_matched;
        TH1D h_num_mu2_pt;
        TH1D h_den_mu2_pt;
        TH1D h_reco_mu2_pt;
        TH1D h_reco_mu2_eta;
        TH1D h_reco_mu2_charge;
        TH1D h_reco_mu2_dr;
        TH2D h_reco_mu2_res_vs_pt;

        TH2D h_res_mll;
        TH2D h_res_mee;
        TH2D h_res_mmm;
};

// constants, enums and typedefs
// ------------------------------------------------------------------ //

typedef ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<double> > LorentzVectorD;

const std::array<double, 7> pt_bins = {{0, 10, 20, 30, 40, 50, 100}};

void SetHistStyle(TH1& hist)
{
    if (not hist.GetSumw2N())
    {
        hist.Sumw2();
    }
    hist.SetMarkerSize(0.85);
    hist.SetMarkerStyle(20);
    hist.SetMarkerColor(kBlue);
    hist.SetLineColor(kBlack);
}

// construct:
ZTreeAnalyzer::ZTreeAnalyzer(const edm::ParameterSet& iConfig)
    : m_mll_nbins(iConfig.getUntrackedParameter<unsigned int>("mll_nbins", 30))
    , m_mll_min(iConfig.getUntrackedParameter<double>("mll_min", 60.0))
    , m_mll_max(iConfig.getUntrackedParameter<double>("mll_max", 120.0))
    , m_hist_filename(iConfig.getUntrackedParameter<std::string>("hist_filename", "test.root"))
    , h_gen_mz               ("h_gen_mz"              , "Z-boson Invariant Mass;m_{Z} (GeV);a.u."                  , m_mll_nbins , m_mll_min , m_mll_max )
    , h_gen_mll              ("h_gen_mll"             , "Dilepton Invariant Mass (Generator);m_{ll} (GeV);a.u."    , m_mll_nbins , m_mll_min , m_mll_max )
    , h_reco_mll             ("h_reco_mll"            , "Dilepton Invariant Mass (Reco);m_{ll} (GeV);a.u."         , m_mll_nbins , m_mll_min , m_mll_max )
    , h_gen_mee              ("h_gen_mee"             , "Dielectron Invariant Mass (Generator);m_{ee} (GeV);a.u."  , m_mll_nbins , m_mll_min , m_mll_max )
    , h_reco_mee             ("h_reco_mee"            , "Dielectron Invariant Mass (Reco);m_{ee} (GeV);a.u."       , m_mll_nbins , m_mll_min , m_mll_max )
    , h_gen_mmm              ("h_gen_mmm"             , "Dimuon Invariant Mass (Generator);m_{#mu#mu} (GeV);a.u."  , m_mll_nbins , m_mll_min , m_mll_max )
    , h_reco_mmm             ("h_reco_mmm"            , "Dimuon Invariant Mass (Reco);m_{#mu#mu} (GeV);a.u."       , m_mll_nbins , m_mll_min , m_mll_max )
    , h_gen_e1_pt            ("h_gen_e1_pt"           , "e_{1} p_{T} (Generator);p_{T} (GeV);a.u."                 , 50          , 0         , 100       )
    , h_gen_e1_eta           ("h_gen_e1_eta"          , "e_{1} |#eta| (Generator);|#eta|;a.u."                     , 50          , -5        , 5         )
    , h_gen_e1_charge        ("h_gen_e1_charge"       , "e_{1} charge (Generator);charge;a.u."                     , 5           , -2.5      , 2.5       )
    , h_gen_e1_matched       ("h_gen_e1_matched"      , "e_{1} is matched to reco (Generator);;a.u."               , 6           , -0.5      , 2.5       )
    , h_num_e1_pt            ("h_num_e1_pt"           , "e_{1} p_{T} (Numerator);p_{T} (GeV);a.u."                 , pt_bins.size()-1, pt_bins.data()    )
    , h_den_e1_pt            ("h_den_e1_pt"           , "e_{1} p_{T} (Denominator);p_{T} (GeV);a.u."               , pt_bins.size()-1, pt_bins.data()    )
    , h_reco_e1_pt           ("h_reco_e1_pt"          , "e_{1} p_{T} (Reco);p_{T} (GeV);a.u."                      , 50          , 0         , 100       )
    , h_reco_e1_eta          ("h_reco_e1_eta"         , "e_{1} |#eta| (Reco);|#eta|;a.u."                          , 50          , -5        , 5         )
    , h_reco_e1_charge       ("h_reco_e1_charge"      , "e_{1} charge (Reco);charge;a.u."                          , 5           , -2.5      , 2.5       )
    , h_reco_e1_dr           ("h_reco_e1_dr"          , "e_{1} #deltaR(gen, reco);#deltaR;a.u."                    , 10          , 0.0       , 0.2       )
    , h_reco_e1_res_vs_pt    ("h_reco_e1_res_vs_pt"   , "e_{1} Residual vs p_{T};p_{T} (GeV);Residual"             , pt_bins.size()-1, pt_bins.data()    , 100, -10.0, 10.0)
    , h_gen_e2_pt            ("h_gen_e2_pt"           , "e_{2} p_{T} (Generator);p_{T} (GeV);a.u."                 , 50          , 0         , 100       )
    , h_gen_e2_eta           ("h_gen_e2_eta"          , "e_{2} |#eta| (Generator);|#eta|;a.u."                     , 50          , -5        , 5         )
    , h_gen_e2_charge        ("h_gen_e2_charge"       , "e_{2} charge (Generator);charge;a.u."                     , 5           , -2.5      , 2.5       )
    , h_gen_e2_matched       ("h_gen_e2_matched"      , "e_{2} is matched to reco (Generator);;a.u."               , 6           , -0.5      , 2.5       )
    , h_num_e2_pt            ("h_num_e2_pt"           , "e_{2} p_{T} (Numerator);p_{T} (GeV);a.u."                 , pt_bins.size()-1, pt_bins.data()    )
    , h_den_e2_pt            ("h_den_e2_pt"           , "e_{2} p_{T} (Denominator);p_{T} (GeV);a.u."               , pt_bins.size()-1, pt_bins.data()    )
    , h_reco_e2_pt           ("h_reco_e2_pt"          , "e_{2} p_{T} (Reco);p_{T} (GeV);a.u."                      , 50          , 0         , 100       )
    , h_reco_e2_eta          ("h_reco_e2_eta"         , "e_{2} |#eta| (Reco);|#eta|;a.u."                          , 50          , -5        , 5         )
    , h_reco_e2_charge       ("h_reco_e2_charge"      , "e_{2} charge (Reco);charge;a.u."                          , 5           , -2.5      , 2.5       )
    , h_reco_e2_dr           ("h_reco_e2_dr"          , "e_{2} #deltaR(gen, reco);#deltaR;a.u."                    , 10          , 0.0       , 0.2       )
    , h_reco_e2_res_vs_pt    ("h_reco_e2_res_vs_pt"   , "e_{2} Residual vs p_{T};p_{T} (GeV);Residual"             , pt_bins.size()-1, pt_bins.data()    , 100, -10.0, 10.0)
    , h_gen_mu1_pt           ("h_gen_mu1_pt"          , "#mu_{1} p_{T} (Generator);p_{T} (GeV);a.u."               , 50          , 0         , 100       )
    , h_gen_mu1_eta          ("h_gen_mu1_eta"         , "#mu_{1} |#eta| (Generator);|#eta|;a.u."                   , 50          , -5        , 5         )
    , h_gen_mu1_charge       ("h_gen_mu1_charge"      , "#mu_{1} charge (Generator);charge;a.u."                   , 5           , -2.5      , 2.5       )
    , h_gen_mu1_matched      ("h_gen_mu1_matched"     , "#mu_{1} is matched to reco (Generator);;a.u."             , 6           , -0.5      , 2.5       )
    , h_num_mu1_pt           ("h_num_mu1_pt"          , "#mu_{1} p_{T} (Numerator);p_{T} (GeV);a.u."               , pt_bins.size()-1, pt_bins.data()    )
    , h_den_mu1_pt           ("h_den_mu1_pt"          , "#mu_{1} p_{T} (Denominator);p_{T} (GeV);a.u."             , pt_bins.size()-1, pt_bins.data()    )
    , h_reco_mu1_pt          ("h_reco_mu1_pt"         , "#mu_{1} p_{T} (Reco);p_{T} (GeV);a.u."                    , 50          , 0         , 100       )
    , h_reco_mu1_eta         ("h_reco_mu1_eta"        , "#mu_{1} |#eta| (Reco);|#eta|;a.u."                        , 50          , -5        , 5         )
    , h_reco_mu1_charge      ("h_reco_mu1_charge"     , "#mu_{1} charge (Reco);charge;a.u."                        , 5           , -2.5      , 2.5       )
    , h_reco_mu1_dr          ("h_reco_mu1_dr"         , "#mu_{1} #deltaR(gen, reco);#deltaR;a.u."                  , 10          , 0.0       , 0.2       )
    , h_reco_mu1_res_vs_pt   ("h_reco_mu1_res_vs_pt"  , "#mu_{1} Residual vs p_{T};p_{T} (GeV);Residual"           , pt_bins.size()-1, pt_bins.data()    , 100, -10.0, 10.0)
    , h_gen_mu2_pt           ("h_gen_mu2_pt"          , "#mu_{2} p_{T} (Generator);p_{T} (GeV);a.u."               , 50          , 0         , 100       )
    , h_gen_mu2_eta          ("h_gen_mu2_eta"         , "#mu_{2} |#eta| (Generator);|#eta|;a.u."                   , 50          , -5        , 5         )
    , h_gen_mu2_charge       ("h_gen_mu2_charge"      , "#mu_{2} charge (Generator);charge;a.u."                   , 5           , -2.5      , 2.5       )
    , h_gen_mu2_matched      ("h_gen_mu2_matched"     , "#mu_{2} is matched to reco (Generator);;a.u."             , 6           , -0.5      , 2.5       )
    , h_num_mu2_pt           ("h_num_mu2_pt"          , "#mu_{2} p_{T} (Numerator);p_{T} (GeV);a.u."               , pt_bins.size()-1, pt_bins.data()    )
    , h_den_mu2_pt           ("h_den_mu2_pt"          , "#mu_{2} p_{T} (Denominator);p_{T} (GeV);a.u."             , pt_bins.size()-1, pt_bins.data()    )
    , h_reco_mu2_pt          ("h_reco_mu2_pt"         , "#mu_{2} p_{T} (Reco);p_{T} (GeV);a.u."                    , 50          , 0         , 100       )
    , h_reco_mu2_eta         ("h_reco_mu2_eta"        , "#mu_{2} |#eta| (Reco);|#eta|;a.u."                        , 50          , -5        , 5         )
    , h_reco_mu2_charge      ("h_reco_mu2_charge"     , "#mu_{2} charge (Reco);charge;a.u."                        , 5           , -2.5      , 2.5       )
    , h_reco_mu2_dr          ("h_reco_mu2_dr"         , "#mu_{2} #deltaR(gen, reco);#deltaR;a.u."                  , 10          , 0.0       , 0.2       )
    , h_reco_mu2_res_vs_pt   ("h_reco_mu2_res_vs_pt"  , "#mu_{2} Residual vs p_{T};p_{T} (GeV);Residual"           , pt_bins.size()-1, pt_bins.data()    , 100, -10.0, 10.0)
    , h_res_mll              ("h_res_mll"             , "Dilepton Invariant Mass Residual;m_{ll} (GeV);Residual"   , m_mll_nbins , m_mll_min , m_mll_max , 100, -10.0, 10.0)
    , h_res_mee              ("h_res_mee"             , "Dilelectron Invariant Mass Residual;m_{ee} (GeV);Residual", m_mll_nbins , m_mll_min , m_mll_max , 100, -10.0, 10.0)
    , h_res_mmm              ("h_res_mmm"             , "Dimuon Invariant Mass Resisdual;m_{#mu#mu} (GeV);Residual", m_mll_nbins , m_mll_min , m_mll_max , 100, -10.0, 10.0)
{
    // histogram cosmetics
    h_gen_e1_matched.GetXaxis()->SetBinLabel(2, "not matched");
    h_gen_e1_matched.GetXaxis()->SetBinLabel(4, "matched"    );
    h_gen_e2_matched.GetXaxis()->SetBinLabel(2, "not matched");
    h_gen_e2_matched.GetXaxis()->SetBinLabel(4, "matched"    );
    h_gen_mu1_matched.GetXaxis()->SetBinLabel(2, "not matched");
    h_gen_mu1_matched.GetXaxis()->SetBinLabel(4, "matched"    );
    h_gen_mu2_matched.GetXaxis()->SetBinLabel(2, "not matched");
    h_gen_mu2_matched.GetXaxis()->SetBinLabel(4, "matched"    );
    h_gen_e1_charge.GetXaxis()->SetBinLabel(2, "negative");
    h_gen_e1_charge.GetXaxis()->SetBinLabel(4, "positive");
    h_gen_e2_charge.GetXaxis()->SetBinLabel(2, "negative");
    h_gen_e2_charge.GetXaxis()->SetBinLabel(4, "positive");
    h_gen_mu1_charge.GetXaxis()->SetBinLabel(2, "negative");
    h_gen_mu1_charge.GetXaxis()->SetBinLabel(4, "positive");
    h_gen_mu2_charge.GetXaxis()->SetBinLabel(2, "negative");
    h_gen_mu2_charge.GetXaxis()->SetBinLabel(4, "positive");
    h_reco_e1_charge.GetXaxis()->SetBinLabel(2, "negative");
    h_reco_e1_charge.GetXaxis()->SetBinLabel(4, "positive");
    h_reco_e2_charge.GetXaxis()->SetBinLabel(2, "negative");
    h_reco_e2_charge.GetXaxis()->SetBinLabel(4, "positive");
    h_reco_mu1_charge.GetXaxis()->SetBinLabel(2, "negative");
    h_reco_mu1_charge.GetXaxis()->SetBinLabel(4, "positive");
    h_reco_mu2_charge.GetXaxis()->SetBinLabel(2, "negative");
    h_reco_mu2_charge.GetXaxis()->SetBinLabel(4, "positive");

    SetHistStyle(h_gen_mz               );
    SetHistStyle(h_gen_mll              );
    SetHistStyle(h_reco_mll             );
    SetHistStyle(h_gen_mee              );
    SetHistStyle(h_reco_mee             );
    SetHistStyle(h_gen_mmm              );
    SetHistStyle(h_reco_mmm             );
    SetHistStyle(h_gen_e1_pt            );
    SetHistStyle(h_gen_e1_eta           );
    SetHistStyle(h_gen_e1_charge        );
    SetHistStyle(h_gen_e1_matched       );
    SetHistStyle(h_num_e1_pt            );
    SetHistStyle(h_den_e1_pt            );
    SetHistStyle(h_reco_e1_pt           );
    SetHistStyle(h_reco_e1_eta          );
    SetHistStyle(h_reco_e1_charge       );
    SetHistStyle(h_reco_e1_dr           );
    SetHistStyle(h_reco_e1_res_vs_pt    );
    SetHistStyle(h_gen_e2_pt            );
    SetHistStyle(h_gen_e2_eta           );
    SetHistStyle(h_gen_e2_charge        );
    SetHistStyle(h_gen_e2_matched       );
    SetHistStyle(h_num_e2_pt            );
    SetHistStyle(h_den_e2_pt            );
    SetHistStyle(h_reco_e2_pt           );
    SetHistStyle(h_reco_e2_eta          );
    SetHistStyle(h_reco_e2_charge       );
    SetHistStyle(h_reco_e2_dr           );
    SetHistStyle(h_reco_e2_res_vs_pt    );
    SetHistStyle(h_gen_mu1_pt           );
    SetHistStyle(h_gen_mu1_eta          );
    SetHistStyle(h_gen_mu1_charge       );
    SetHistStyle(h_gen_mu1_matched      );
    SetHistStyle(h_num_mu1_pt           );
    SetHistStyle(h_den_mu1_pt           );
    SetHistStyle(h_reco_mu1_pt          );
    SetHistStyle(h_reco_mu1_eta         );
    SetHistStyle(h_reco_mu1_charge      );
    SetHistStyle(h_reco_mu1_dr          );
    SetHistStyle(h_reco_mu1_res_vs_pt   );
    SetHistStyle(h_gen_mu2_pt           );
    SetHistStyle(h_gen_mu2_eta          );
    SetHistStyle(h_gen_mu2_charge       );
    SetHistStyle(h_gen_mu2_matched      );
    SetHistStyle(h_num_mu2_pt           );
    SetHistStyle(h_den_mu2_pt           );
    SetHistStyle(h_reco_mu2_pt          );
    SetHistStyle(h_reco_mu2_eta         );
    SetHistStyle(h_reco_mu2_charge      );
    SetHistStyle(h_reco_mu2_dr          );
    SetHistStyle(h_reco_mu2_res_vs_pt   );
    SetHistStyle(h_res_mll              );
    SetHistStyle(h_res_mee              );
    SetHistStyle(h_res_mmm              );
}

ZTreeAnalyzer::~ZTreeAnalyzer()
{
}

// ------------ method called once each job just before starting event loop  ------------
void ZTreeAnalyzer::beginJob()
{
}

// ------------ method called for each event  ------------
void ZTreeAnalyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
    using namespace edm;

    // Load the braches -- (This is very tedious and potentially slow!!)
    // --------------------------------------------- //

    edm::Handle<LorentzVectorD> l12_p4_handle;         iEvent.getByLabel(edm::InputTag("ZTreeMaker", "l12p4"       ), l12_p4_handle         ); const LorentzVectorD& l12_p4         = *l12_p4_handle;        
    edm::Handle<LorentzVectorD> l12_reco_p4_handle;    iEvent.getByLabel(edm::InputTag("ZTreeMaker", "l12recop4"   ), l12_reco_p4_handle    ); const LorentzVectorD& l12_reco_p4    = *l12_reco_p4_handle;   
    edm::Handle<LorentzVectorD> l1_p4_handle;          iEvent.getByLabel(edm::InputTag("ZTreeMaker", "l1p4"        ), l1_p4_handle          ); const LorentzVectorD& l1_p4          = *l1_p4_handle;         
    edm::Handle<LorentzVectorD> l1_reco_p4_handle;     iEvent.getByLabel(edm::InputTag("ZTreeMaker", "l1recop4"    ), l1_reco_p4_handle     ); const LorentzVectorD& l1_reco_p4     = *l1_reco_p4_handle;    
    edm::Handle<LorentzVectorD> l2_p4_handle;          iEvent.getByLabel(edm::InputTag("ZTreeMaker", "l2p4"        ), l2_p4_handle          ); const LorentzVectorD& l2_p4          = *l2_p4_handle;         
    edm::Handle<LorentzVectorD> l2_reco_p4_handle;     iEvent.getByLabel(edm::InputTag("ZTreeMaker", "l2recop4"    ), l2_reco_p4_handle     ); const LorentzVectorD& l2_reco_p4     = *l2_reco_p4_handle;    
    edm::Handle<LorentzVectorD> z_p4_handle;           iEvent.getByLabel(edm::InputTag("ZTreeMaker", "zp4"         ), z_p4_handle           ); const LorentzVectorD& z_p4           = *z_p4_handle;          
    edm::Handle<bool          > l12_matched_handle;    iEvent.getByLabel(edm::InputTag("ZTreeMaker", "l12matched"  ), l12_matched_handle    ); const bool            l12_matched    = *l12_matched_handle;   
    edm::Handle<bool          > l1_matched_handle;     iEvent.getByLabel(edm::InputTag("ZTreeMaker", "l1matched"   ), l1_matched_handle     ); const bool            l1_matched     = *l1_matched_handle;    
    edm::Handle<bool          > l2_matched_handle;     iEvent.getByLabel(edm::InputTag("ZTreeMaker", "l2matched"   ), l2_matched_handle     ); const bool            l2_matched     = *l2_matched_handle;    
    edm::Handle<double        > l1_reco_dr_handle;     iEvent.getByLabel(edm::InputTag("ZTreeMaker", "l1recodr"    ), l1_reco_dr_handle     ); const double          l1_reco_dr     = *l1_reco_dr_handle;    
    edm::Handle<double        > l2_reco_dr_handle;     iEvent.getByLabel(edm::InputTag("ZTreeMaker", "l2recodr"    ), l2_reco_dr_handle     ); const double          l2_reco_dr     = *l2_reco_dr_handle;    
    edm::Handle<int           > l1_charge_handle;      iEvent.getByLabel(edm::InputTag("ZTreeMaker", "l1charge"    ), l1_charge_handle      ); const int             l1_charge      = *l1_charge_handle;     
    edm::Handle<int           > l1_pdgid_handle;       iEvent.getByLabel(edm::InputTag("ZTreeMaker", "l1pdgid"     ), l1_pdgid_handle       ); const int             l1_pdgid       = *l1_pdgid_handle;      
    edm::Handle<int           > l1_reco_charge_handle; iEvent.getByLabel(edm::InputTag("ZTreeMaker", "l1recocharge"), l1_reco_charge_handle ); const int             l1_reco_charge = *l1_reco_charge_handle;
    edm::Handle<int           > l2_charge_handle;      iEvent.getByLabel(edm::InputTag("ZTreeMaker", "l2charge"    ), l2_charge_handle      ); const int             l2_charge      = *l2_charge_handle;     
    edm::Handle<int           > l2_pdgid_handle;       iEvent.getByLabel(edm::InputTag("ZTreeMaker", "l2pdgid"     ), l2_pdgid_handle       ); const int             l2_pdgid       = *l2_pdgid_handle;      
    edm::Handle<int           > l2_reco_charge_handle; iEvent.getByLabel(edm::InputTag("ZTreeMaker", "l2recocharge"), l2_reco_charge_handle ); const int             l2_reco_charge = *l2_reco_charge_handle;

    // Fill gen level info
    // --------------------------------------------- //

    const bool is_mumu    = (l1_pdgid*l2_pdgid == -11*11);
    const bool is_ee      = (l1_pdgid*l2_pdgid == -13*13);
 
    h_gen_mz.Fill(z_p4.mass());
    h_gen_mll.Fill(l12_p4.mass());
    if (is_mumu)
    {
        h_gen_mee.Fill(l12_p4.mass());
        h_gen_mmm.Fill(l12_p4.mass());
        h_gen_mu1_pt.Fill(l1_p4.pt());
        h_gen_mu1_eta.Fill(l1_p4.eta());
        h_gen_mu1_charge.Fill(l1_charge);
        h_gen_mu1_matched.Fill(l1_matched);
        h_den_mu1_pt.Fill(l1_p4.pt());
        h_gen_mu2_pt.Fill(l2_p4.pt());
        h_gen_mu2_eta.Fill(l2_p4.eta());
        h_gen_mu2_charge.Fill(l2_charge);
        h_gen_mu2_matched.Fill(l2_matched);
        h_den_mu2_pt.Fill(l2_p4.pt());
    }
    if (is_ee)
    {
        h_gen_mmm.Fill(l12_p4.mass());
        h_gen_e1_pt.Fill(l1_p4.pt());
        h_gen_e1_eta.Fill(l1_p4.eta());
        h_gen_e1_charge.Fill(l1_charge);
        h_gen_e1_matched.Fill(l1_matched);
        h_den_e1_pt.Fill(l1_p4.pt());
        h_gen_e2_pt.Fill(l2_p4.pt());
        h_gen_e2_eta.Fill(l2_p4.eta());
        h_gen_e2_charge.Fill(l2_charge);
        h_gen_e2_matched.Fill(l2_matched);
        h_den_e2_pt.Fill(l2_p4.pt());
    }

    // Fill reco level info
    // --------------------------------------------- //

    // assume everything is matched after here
    if (not l12_matched) {return;}

    h_reco_mll.Fill(l12_reco_p4.mass());
    if (is_mumu)
    {
        h_reco_mmm.Fill(l12_reco_p4.mass());
        h_res_mmm.Fill(l12_p4.mass(), l12_p4.mass()-l12_reco_p4.mass());
        h_reco_mu1_pt.Fill(l1_reco_p4.pt());
        h_reco_mu1_eta.Fill(l1_reco_p4.eta());
        h_reco_mu1_charge.Fill(l1_reco_charge);
        h_reco_mu1_dr.Fill(l1_reco_dr);
        h_num_mu1_pt.Fill(l1_p4.pt());
        h_reco_mu2_pt.Fill(l2_reco_p4.pt());
        h_reco_mu2_eta.Fill(l2_reco_p4.eta());
        h_num_mu2_pt.Fill(l2_p4.pt());
        h_reco_mu2_charge.Fill(l2_reco_charge);
        h_reco_mu2_dr.Fill(l2_reco_dr);
        h_res_mll.Fill(l12_p4.mass(), l12_p4.mass()-l12_reco_p4.mass());
        h_reco_mu1_res_vs_pt.Fill(l1_p4.pt(), l1_p4.pt()-l1_reco_p4.pt());
        h_reco_mu2_res_vs_pt.Fill(l2_p4.pt(), l2_p4.pt()-l2_reco_p4.pt());
    }
    if (is_ee)
    {
        h_reco_mee.Fill(l12_reco_p4.mass());
        h_res_mee.Fill(l12_p4.mass(), l12_p4.mass()-l12_reco_p4.mass());
        h_reco_e1_pt.Fill(l1_reco_p4.pt());
        h_reco_e1_eta.Fill(l1_reco_p4.eta());
        h_num_e1_pt.Fill(l1_p4.pt());
        h_reco_e1_charge.Fill(l1_reco_charge);
        h_reco_e1_dr.Fill(l1_reco_dr);
        h_reco_e2_pt.Fill(l2_reco_p4.pt());
        h_reco_e2_eta.Fill(l2_reco_p4.eta());
        h_num_e2_pt.Fill(l2_p4.pt());
        h_reco_e2_charge.Fill(l2_reco_charge);
        h_reco_e2_dr.Fill(l2_reco_dr);
        h_res_mll.Fill(l12_p4.mass(), l12_p4.mass()-l12_reco_p4.mass());
        h_reco_e1_res_vs_pt.Fill(l1_p4.pt(), l1_p4.pt()-l1_reco_p4.pt());
        h_reco_e2_res_vs_pt.Fill(l2_p4.pt(), l2_p4.pt()-l2_reco_p4.pt());
    }
}

// ------------ method called once each job just after ending the event loop  ------------

TH1& MakeEfficiencyPlot(const TH1& num_hist, const TH1& den_hist, const std::string& name, const std::string& title = "")
{
    // verify that all histograms have same binning
    if (den_hist.GetNbinsX() != num_hist.GetNbinsX()) 
    {
        throw std::runtime_error("[ZTreeAnalyzer::MakeEfficiencyPlot] Error: Histograms must have same number of bins");
    }

    // get the new histogram
    TH1* eff_hist = dynamic_cast<TH1*>(num_hist.Clone(name.c_str()));
    eff_hist->SetTitle(title.empty() ? name.c_str() : title.c_str());
    eff_hist->Reset();
    if (!eff_hist->GetSumw2N())
    {
        eff_hist->Sumw2();
    }

    // Do the calculation
    eff_hist->Divide(&num_hist, &den_hist, 1.0, 1.0, "B");

    // Done
    return *eff_hist;
}

// run FitSlicesY and return resolution hist
TH1& MakeResolutionHist(TH2& res_hist, const std::string& name, const std::string& title)
{
    // fit the vertical slices
    // (need to ensure directory exists) 
    const bool old_add_dir = TH1::AddDirectoryStatus();
    TH1::AddDirectory(true);
    res_hist.FitSlicesY();
    TH1* h_sigma = dynamic_cast<TH1*>(gDirectory->Get(Form("%s_2", res_hist.GetName())));
    if (not h_sigma) 
    {
        throw std::runtime_error("[ZTreeAnalyzer::MakeResolutionPlot] Error: Sigma Histograms not found!");
    }
    TH1::AddDirectory(old_add_dir);
    h_sigma->SetName(Form("%s_sigma", name.c_str()));
    h_sigma->SetTitle(title.c_str());
    SetHistStyle(*h_sigma);
    return *h_sigma;
}

void ZTreeAnalyzer::endJob() 
{
    try
    {
        // efficiency plots
        TH1& h_e1_eff_vs_pt  = MakeEfficiencyPlot(h_num_e1_pt , h_den_e1_pt , "h_e1_eff_vs_pt" , "e_{1} Efficiency vs p_{T};p_{T} (GeV);#espsilon"  );
        TH1& h_e2_eff_vs_pt  = MakeEfficiencyPlot(h_num_e2_pt , h_den_e2_pt , "h_e2_eff_vs_pt" , "e_{2} Efficiency vs p_{T};p_{T} (GeV);#espsilon"  );
        TH1& h_mu1_eff_vs_pt = MakeEfficiencyPlot(h_num_mu1_pt, h_den_mu1_pt, "h_mu1_eff_vs_pt", "#mu_{1} Efficiency vs p_{T};p_{T} (GeV);#espsilon");
        TH1& h_mu2_eff_vs_pt = MakeEfficiencyPlot(h_num_mu2_pt, h_den_mu2_pt, "h_mu2_eff_vs_pt", "#mu_{2} Efficiency vs p_{T};p_{T} (GeV);#espsilon");

        // resolution sigma plots
        TH1& h_sigma_mll       = MakeResolutionHist(h_res_mll           , "h_sigma_mll"       , "Dilepton Invariant Mass Residual;m_{ll} (GeV);#sigma(m_{ll}^{gen}-m_{ll}^{reco}) (GeV)"          );
        TH1& h_sigma_mee       = MakeResolutionHist(h_res_mee           , "h_sigma_mee"       , "Dielectron Invariant Mass Residual;m_{ee} (GeV);#sigma(m_{ee}^{gen}-m_{ee}^{reco}) (GeV)"        );
        TH1& h_sigma_mmm       = MakeResolutionHist(h_res_mmm           , "h_sigma_mmm"       , "Dimuon Invariant Mass Residual;m_{#mu#mu} (GeV);#sigma(m_{#mu#mu}^{gen}-m_{#mu#mu}^{reco}) (GeV)");
        TH1& h_sigma_e1_vs_pt  = MakeResolutionHist(h_reco_e1_res_vs_pt , "h_sigma_e1_vs_pt"  , "e_{1} p_{T} Resolution;p_{T} (GeV);#sigma(p_{T}^{gen}-p_{T}^{reco}) (GeV)"                       );
        TH1& h_sigma_e2_vs_pt  = MakeResolutionHist(h_reco_e2_res_vs_pt , "h_sigma_e2_vs_pt"  , "e_{2} p_{T} Resolution;p_{T} (GeV);#sigma(p_{T}^{gen}-p_{T}^{reco}) (GeV)"                       );
        TH1& h_sigma_mu1_vs_pt = MakeResolutionHist(h_reco_mu1_res_vs_pt, "h_sigma_mu1_vs_pt" , "#mu_{1} p_{T} Resolution;p_{T} (GeV);#sigma(p_{T}^{gen}-p_{T}^{reco}) (GeV)"                     );
        TH1& h_sigma_mu2_vs_pt = MakeResolutionHist(h_reco_mu2_res_vs_pt, "h_sigma_mu2_vs_pt" , "#mu_{2} p_{T} Resolution;p_{T} (GeV);#sigma(p_{T}^{gen}-p_{T}^{reco}) (GeV)"                     );

        // save the hisotgrams
        // (This is very tedious as well -- screaming abstraction!!)
        TFile hist_file(m_hist_filename.c_str(), "RECREATE");
        h_gen_mz.Write();
        h_gen_mll.Write();
        h_reco_mll.Write();
        h_gen_mee.Write();
        h_reco_mee.Write();
        h_gen_mmm.Write();
        h_reco_mmm.Write();
        h_gen_e1_pt.Write();
        h_gen_e1_eta.Write();
        h_gen_e1_charge.Write();
        h_gen_e1_matched.Write();
        h_reco_e1_pt.Write();
        h_reco_e1_eta.Write();
        h_reco_e1_charge.Write();
        h_reco_e1_dr.Write();
        h_gen_e2_pt.Write();
        h_gen_e2_eta.Write();
        h_gen_e2_charge.Write();
        h_gen_e2_matched.Write();
        h_reco_e2_pt.Write();
        h_reco_e2_eta.Write();
        h_reco_e2_charge.Write();
        h_reco_e2_dr.Write();
        h_reco_e1_res_vs_pt.Write();
        h_reco_e2_res_vs_pt.Write();
        h_e1_eff_vs_pt.Write();
        h_e2_eff_vs_pt.Write();
        h_num_e1_pt.Write();
        h_den_e1_pt.Write();
        h_num_e2_pt.Write();
        h_den_e2_pt.Write();
        h_sigma_e1_vs_pt.Write();
        h_sigma_e2_vs_pt.Write();
        h_gen_mu1_pt.Write();
        h_gen_mu1_eta.Write();
        h_gen_mu1_charge.Write();
        h_gen_mu1_matched.Write();
        h_reco_mu1_pt.Write();
        h_reco_mu1_eta.Write();
        h_reco_mu1_charge.Write();
        h_reco_mu1_dr.Write();
        h_gen_mu2_pt.Write();
        h_gen_mu2_eta.Write();
        h_gen_mu2_charge.Write();
        h_gen_mu2_matched.Write();
        h_reco_mu2_pt.Write();
        h_reco_mu2_eta.Write();
        h_reco_mu2_charge.Write();
        h_reco_mu2_dr.Write();
        h_reco_mu1_res_vs_pt.Write();
        h_reco_mu2_res_vs_pt.Write();
        h_mu1_eff_vs_pt.Write();
        h_mu2_eff_vs_pt.Write();
        h_num_mu1_pt.Write();
        h_den_mu1_pt.Write();
        h_num_mu2_pt.Write();
        h_den_mu2_pt.Write();
        h_sigma_mu1_vs_pt.Write();
        h_sigma_mu2_vs_pt.Write();
        h_res_mll.Write();
        h_res_mee.Write();
        h_res_mmm.Write();
        h_sigma_mll.Write();
        h_sigma_mee.Write();
        h_sigma_mmm.Write();
        hist_file.Close();
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

// ------------ method called when starting to processes a run  ------------
void ZTreeAnalyzer::beginRun(edm::Run const&, edm::EventSetup const&)
{
}

// ------------ method called when ending the processing of a run  ------------
void ZTreeAnalyzer::endRun(edm::Run const&, edm::EventSetup const&)
{
}

// ------------ method called when starting to processes a luminosity block  ------------
void ZTreeAnalyzer::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}

// ------------ method called when ending the processing of a luminosity block  ------------
void ZTreeAnalyzer::endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void ZTreeAnalyzer::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(ZTreeAnalyzer);
