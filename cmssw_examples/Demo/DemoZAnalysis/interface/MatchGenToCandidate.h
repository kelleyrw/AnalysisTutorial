#ifndef MATCHGENTOCANDDIATE_H
#define MATCHGENTOCANDDIATE_H

#include "DataFormats/MuonReco/interface/Muon.h"
#include "DataFormats/MuonReco/interface/MuonFwd.h"
#include "DataFormats/EgammaCandidates/interface/GsfElectron.h"
#include "DataFormats/EgammaCandidates/interface/GsfElectronFwd.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
#include "DataFormats/HepMCCandidate/interface/GenParticleFwd.h"

// match a reco::GenParticle to an object of the reco::MuonCollection by dr
// returns NULL if not found
const reco::Candidate* MatchGenToCandidate(const reco::GenParticle& gp, const reco::MuonCollection& muons, double dr_min = 0.2);

// match a reco::GenParticle to an object of the reco::GsfElectronCollection by dr
// returns NULL if not found
const reco::Candidate* MatchGenToCandidate(const reco::GenParticle& gp, const reco::GsfElectronCollection& electrons, double dr_min = 0.2);

#endif // MATCHGENTOCANDDIATE_H
