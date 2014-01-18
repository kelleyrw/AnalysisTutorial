#include "Demo/DemoZAnalysis/interface/MatchGenToCandidate.h"
#include "DataFormats/MuonReco/interface/Muon.h"
#include "DataFormats/MuonReco/interface/MuonFwd.h"
#include "DataFormats/EgammaCandidates/interface/GsfElectron.h"
#include "DataFormats/EgammaCandidates/interface/GsfElectronFwd.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
#include "DataFormats/HepMCCandidate/interface/GenParticleFwd.h"
#include "DataFormats/Math/interface/LorentzVector.h"
#include "Math/VectorUtil.h"

typedef ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<double> > LorentzVectorD;

const reco::Candidate* MatchGenToCandidate(const reco::GenParticle& gp, const reco::MuonCollection& muons, double dr_min)
{
    const reco::Candidate* result = NULL;
    for (reco::MuonCollection::const_iterator iter = muons.begin(); iter != muons.end(); ++iter)
    {
        const LorentzVectorD gen_p4(gp.px(), gp.py(), gp.pz(), gp.energy());
        const LorentzVectorD cand_p4(iter->px(), iter->py(), iter->pz(), iter->energy());
        const double dr = ROOT::Math::VectorUtil::DeltaR(gen_p4, cand_p4);
        if (dr < dr_min) 
        {
            dr_min = dr;
            result = &(*iter);
        }
    }

    return result;
}

const reco::Candidate* MatchGenToCandidate(const reco::GenParticle& gp, const reco::GsfElectronCollection& electrons, double dr_min)
{
    const reco::Candidate* result = NULL;
    for (reco::GsfElectronCollection::const_iterator iter = electrons.begin(); iter != electrons.end(); ++iter)
    {
        const LorentzVectorD gen_p4(gp.px(), gp.py(), gp.pz(), gp.energy());
        const LorentzVectorD cand_p4(iter->px(), iter->py(), iter->pz(), iter->energy());
        const double dr = ROOT::Math::VectorUtil::DeltaR(gen_p4, cand_p4);
        if (dr < dr_min) 
        {
            dr_min = dr;
            result = &(*iter);
        }
    }

    return result;
}

