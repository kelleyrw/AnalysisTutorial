import FWCore.ParameterSet.Config as cms

ZTreeAnalyzer = cms.EDAnalyzer('ZTreeAnalyzer',
    mll_min   = cms.untracked.double(60.0),
    mll_max   = cms.untracked.double(120.0),
    mll_nbins = cms.untracked.uint32(30),
	hist_filename = cms.untracked.string("test.root")
)
