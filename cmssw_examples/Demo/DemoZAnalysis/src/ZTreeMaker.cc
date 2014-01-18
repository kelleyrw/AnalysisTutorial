/* ------------------------------------------------------------------ * 

Package:         DemoZAnalysis
Class:           ZTreeMaker
Description:     Simple EDProducer to make a simple ntuple for z analysis 
Original Author: Ryan W. Kelley 
Created:         Tue Jan 14 11:30:45 PST 2014

* ------------------------------------------------------------------ */

// system include files
#include <memory>
#include <cmath>
#include <iostream>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDProducer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
#include "DataFormats/HepMCCandidate/interface/GenParticleFwd.h"
#include "DataFormats/MuonReco/interface/Muon.h"
#include "DataFormats/MuonReco/interface/MuonFwd.h"
#include "DataFormats/EgammaCandidates/interface/GsfElectron.h"
#include "DataFormats/EgammaCandidates/interface/GsfElectronFwd.h"
#include "Demo/DemoZAnalysis/interface/MatchGenToCandidate.h"

// ROOT include files
#include "Math/LorentzVector.h"
#include "Math/VectorUtil.h"

// constants, enums and typedefs
// ------------------------------------------------------------------ //

typedef ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<double> > LorentzVectorD;

// class declaration
// ------------------------------------------------------------------ //

class ZTreeMaker : public edm::EDProducer
{
    public:
        // construct:
        explicit ZTreeMaker(const edm::ParameterSet&);

        // destroy:
        ~ZTreeMaker();

        // public methods:
        static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);

    private:
        // private methods:
        virtual void beginJob() ;
        virtual void produce(edm::Event&, const edm::EventSetup&);
        virtual void endJob() ;

        virtual void beginRun(edm::Run&, edm::EventSetup const&);
        virtual void endRun(edm::Run&, edm::EventSetup const&);
        virtual void beginLuminosityBlock(edm::LuminosityBlock&, edm::EventSetup const&);
        virtual void endLuminosityBlock(edm::LuminosityBlock&, edm::EventSetup const&);

        // member data:
        edm::InputTag m_genparticle_label;
        edm::InputTag m_electron_label;
        edm::InputTag m_muon_label;
        const double m_dr;
};


// constructors and destructor
ZTreeMaker::ZTreeMaker(const edm::ParameterSet& iConfig)
    : m_genparticle_label(iConfig.getUntrackedParameter<edm::InputTag>("genparticle_label", edm::InputTag("genParticles")))
    , m_electron_label(iConfig.getUntrackedParameter<edm::InputTag>("electron_label", edm::InputTag("gsfElectrons")))
    , m_muon_label(iConfig.getUntrackedParameter<edm::InputTag>("muon_label", edm::InputTag("muons")))
    , m_dr(iConfig.getUntrackedParameter<double>("dr", 0.2))
{
    // register products
    produces<LorentzVectorD>("zp4"         ).setBranchAlias("z_p4"           ); 
    produces<LorentzVectorD>("l1p4"        ).setBranchAlias("l1_p4"          ); 
    produces<int>           ("l1pdgid"     ).setBranchAlias("l1_pdgid"       ); 
    produces<int>           ("l1charge"    ).setBranchAlias("l1_charge"      ); 
    produces<bool>          ("l1matched"   ).setBranchAlias("l1_matched"     ); 
    produces<LorentzVectorD>("l1recop4"    ).setBranchAlias("l1_reco_p4"     ); 
    produces<int>           ("l1recocharge").setBranchAlias("l1_reco_charge" ); 
    produces<double>        ("l1recodr"    ).setBranchAlias("l1_reco_dr"     ); 
    produces<LorentzVectorD>("l2p4"        ).setBranchAlias("l2_p4"          ); 
    produces<int>           ("l2pdgid"     ).setBranchAlias("l2_pdgid"       ); 
    produces<int>           ("l2charge"    ).setBranchAlias("l2_charge"      ); 
    produces<bool>          ("l2matched"   ).setBranchAlias("l2_matched"     ); 
    produces<LorentzVectorD>("l2recop4"    ).setBranchAlias("l2_reco_p4"     ); 
    produces<int>           ("l2recocharge").setBranchAlias("l2_reco_charge" ); 
    produces<double>        ("l2recodr"    ).setBranchAlias("l2_reco_dr"     ); 
    produces<LorentzVectorD>("l12p4"       ).setBranchAlias("l12_p4"         ); 
    produces<LorentzVectorD>("l12recop4"   ).setBranchAlias("l12_reco_p4"    ); 
    produces<bool>          ("l12matched"  ).setBranchAlias("l12_matched"    ); 
}

// destory:
ZTreeMaker::~ZTreeMaker()
{
}

// member functions:
void ZTreeMaker::produce(edm::Event& iEvent, const edm::EventSetup& iSetup)
{
    using namespace edm;

    // ntuple members 
    std::auto_ptr<LorentzVectorD> z_p4           (new LorentzVectorD(0, 0, 0, 0)); 
    std::auto_ptr<LorentzVectorD> l1_p4          (new LorentzVectorD(0, 0, 0, 0)); 
    std::auto_ptr<int>            l1_pdgid       (new int           (-999      )); 
    std::auto_ptr<int>            l1_charge      (new int           (-999      )); 
    std::auto_ptr<bool>           l1_matched     (new bool          (false     )); 
    std::auto_ptr<LorentzVectorD> l1_reco_p4     (new LorentzVectorD(0, 0, 0, 0)); 
    std::auto_ptr<int>            l1_reco_charge (new int           (-999      )); 
    std::auto_ptr<double>         l1_reco_dr     (new double        (-999      )); 
    std::auto_ptr<LorentzVectorD> l2_p4          (new LorentzVectorD(0, 0, 0, 0)); 
    std::auto_ptr<int>            l2_pdgid       (new int           (-999      )); 
    std::auto_ptr<int>            l2_charge      (new int           (-999      )); 
    std::auto_ptr<bool>           l2_matched     (new bool          (false     )); 
    std::auto_ptr<LorentzVectorD> l2_reco_p4     (new LorentzVectorD(0, 0, 0, 0)); 
    std::auto_ptr<int>            l2_reco_charge (new int           (-999      )); 
    std::auto_ptr<double>         l2_reco_dr     (new double        (-999      )); 
    std::auto_ptr<LorentzVectorD> l12_p4         (new LorentzVectorD(0, 0, 0, 0)); 
    std::auto_ptr<LorentzVectorD> l12_reco_p4    (new LorentzVectorD(0, 0, 0, 0)); 
    std::auto_ptr<bool>           l12_matched    (new bool          (false     )); 

    // Fill gen values
    edm::Handle<reco::GenParticleCollection> genps_handle;
    iEvent.getByLabel(m_genparticle_label, genps_handle); 
    const reco::GenParticleCollection& gen_particles = *genps_handle;

    const reco::GenParticle* d1 = NULL; 
    const reco::GenParticle* d2 = NULL; 
    for (size_t i = 0; i != gen_particles.size(); i++)
    {
        const reco::GenParticle& gp = gen_particles.at(i);

        // keep only status 3 Z's
        if (abs(gp.status()) != 3) {continue;}

        // keep only Z particles
        if (abs(gp.pdgId()) != 23) {continue;}

        // z boson
        z_p4->SetPxPyPzE(gp.px(), gp.py(), gp.pz(), gp.energy());

        // daughters
        d1 = dynamic_cast<const reco::GenParticle*>(gp.daughter(0));
        l1_p4->SetPxPyPzE(d1->px(), d1->py(), d1->pz(), d1->energy());
        *l1_pdgid = d1->pdgId();
        *l1_charge = d1->charge();

        d2 = dynamic_cast<const reco::GenParticle*>(gp.daughter(1));
        l2_p4->SetPxPyPzE(d2->px(), d2->py(), d2->pz(), d2->energy());
        *l2_pdgid = d2->pdgId();
        *l2_charge = d2->charge();

        *l12_p4 = (*l1_p4 + *l2_p4);
    }

    // look for matched reco object
    edm::Handle<reco::MuonCollection> muons_handle;
    iEvent.getByLabel(m_muon_label, muons_handle); 
    const reco::MuonCollection& muons = *muons_handle;

    edm::Handle<reco::GsfElectronCollection> els_handle;
    iEvent.getByLabel(m_electron_label, els_handle);    
    const reco::GsfElectronCollection& electrons = *els_handle;

    const reco::Candidate* const d1_match_cand = (abs(d1->pdgId())==13 ? MatchGenToCandidate(*d1, muons, m_dr) : MatchGenToCandidate(*d1, electrons, m_dr));
    if (d1_match_cand != NULL)
    {
        l1_reco_p4->SetPxPyPzE(d1_match_cand->px(), d1_match_cand->py(), d1_match_cand->pz(), d1_match_cand->energy());
        *l1_matched = true;
        *l1_reco_charge = d1_match_cand->charge();
        *l1_reco_dr = ROOT::Math::VectorUtil::DeltaR(d1->momentum(), *l1_reco_p4);
    }
    const reco::Candidate* const d2_match_cand = (abs(d2->pdgId())==13 ? MatchGenToCandidate(*d2, muons, m_dr) : MatchGenToCandidate(*d2, electrons, m_dr));
    if (d2_match_cand != NULL)
    {
        l2_reco_p4->SetPxPyPzE(d2_match_cand->px(), d2_match_cand->py(), d2_match_cand->pz(), d2_match_cand->energy());
        *l2_matched = true;
        *l2_reco_charge = d2_match_cand->charge();
        *l2_reco_dr = ROOT::Math::VectorUtil::DeltaR(d2->momentum(), *l2_reco_p4);
    }
    if (d1_match_cand != NULL && d2_match_cand != NULL)
    {
        *l12_reco_p4 = (*l1_reco_p4 + *l2_reco_p4);
        *l12_matched = (*l1_matched && *l2_matched);
    }

    // sort by gen lepton pt
    if (l2_p4->pt() > l1_p4->pt())
    {
        std::swap(*l1_p4         , *l2_p4         );
        std::swap(*l1_pdgid      , *l2_pdgid      );
        std::swap(*l1_charge     , *l2_charge     );
        std::swap(*l1_matched    , *l2_matched    );
        std::swap(*l1_reco_p4    , *l2_reco_p4    );
        std::swap(*l1_reco_charge, *l2_reco_charge);
        std::swap(*l1_reco_dr    , *l2_reco_dr    );
    }

    // set branch variables
    iEvent.put(z_p4           , "zp4"         );
    iEvent.put(l1_p4          , "l1p4"        );
    iEvent.put(l1_pdgid       , "l1pdgid"     );
    iEvent.put(l1_charge      , "l1charge"    );
    iEvent.put(l1_matched     , "l1matched"   );
    iEvent.put(l1_reco_p4     , "l1recop4"    );
    iEvent.put(l1_reco_charge , "l1recocharge");
    iEvent.put(l1_reco_dr     , "l1recodr"    );
    iEvent.put(l2_p4          , "l2p4"        );
    iEvent.put(l2_pdgid       , "l2pdgid"     );
    iEvent.put(l2_charge      , "l2charge"    );
    iEvent.put(l2_matched     , "l2matched"   );
    iEvent.put(l2_reco_p4     , "l2recop4"    );
    iEvent.put(l2_reco_charge , "l2recocharge");
    iEvent.put(l2_reco_dr     , "l2recodr"    );
    iEvent.put(l12_p4         , "l12p4"       );
    iEvent.put(l12_reco_p4    , "l12recop4"   );
    iEvent.put(l12_matched    , "l12matched"  );
}

// ------------ method called once each job just before starting event loop  ------------
void ZTreeMaker::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void ZTreeMaker::endJob()
{
}

// ------------ method called when starting to processes a run  ------------
void ZTreeMaker::beginRun(edm::Run&, edm::EventSetup const&)
{
}

// ------------ method called when ending the processing of a run  ------------
void ZTreeMaker::endRun(edm::Run&, edm::EventSetup const&)
{
}

// ------------ method called when starting to processes a luminosity block  ------------
void ZTreeMaker::beginLuminosityBlock(edm::LuminosityBlock&, edm::EventSetup const&)
{
}

// ------------ method called when ending the processing of a luminosity block  ------------
void ZTreeMaker::endLuminosityBlock(edm::LuminosityBlock&, edm::EventSetup const&)
{
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void ZTreeMaker::fillDescriptions(edm::ConfigurationDescriptions& descriptions)
{
    //The following says we do not know what parameters are allowed so do no validation
    // Please change this to state exactly what you do use, even if it is no parameters
    edm::ParameterSetDescription desc;
    desc.setUnknown();
    descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(ZTreeMaker);
