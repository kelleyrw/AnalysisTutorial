#include "Demo/DemoZAnalysis/interface/MatchGenToCandidate.h"
#include "DataFormats/MuonReco/interface/Muon.h"
#include "DataFormats/MuonReco/interface/MuonFwd.h"
#include "DataFormats/EgammaCandidates/interface/GsfElectron.h"
#include "DataFormats/EgammaCandidates/interface/GsfElectronFwd.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
#include "DataFormats/HepMCCandidate/interface/GenParticleFwd.h"
#include "Math/VectorUtil.h"

const reco::Candidate* MatchGenToCandidate(const reco::GenParticle& gp, const reco::MuonCollection& muons, double dr_min)
{
    const reco::Candidate* result = NULL;
    for (reco::MuonCollection::const_iterator iter = muons.begin(); iter != muons.end(); ++iter)
    {
        const double dr = ROOT::Math::VectorUtil::DeltaR(gp.momentum(), iter->momentum());
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
        const double dr = ROOT::Math::VectorUtil::DeltaR(gp.momentum(), iter->momentum());
        if (dr < dr_min) 
        {
            dr_min = dr;
            result = &(*iter);
        }
    }
    return result;
}

