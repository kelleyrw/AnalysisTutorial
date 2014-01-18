import FWCore.ParameterSet.Config as cms

ZTreeFilter = cms.EDFilter('ZTreeFilter',
    l1pdgid_label = cms.untracked.InputTag("ZTreeMaker", "l1pdgid"),
    l2pdgid_label = cms.untracked.InputTag("ZTreeMaker", "l2pdgid"),
)
