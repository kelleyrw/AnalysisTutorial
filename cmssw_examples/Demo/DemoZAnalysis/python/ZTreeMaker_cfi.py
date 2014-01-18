import FWCore.ParameterSet.Config as cms

ZTreeMaker = cms.EDProducer('ZTreeMaker',
    genparticle_label = cms.untracked.InputTag("genParticles"),
    electron_label = cms.untracked.InputTag("gsfElectrons"),
    muon_label = cms.untracked.InputTag("muons"),
	dr = cms.untracked.double(0.2)
)
