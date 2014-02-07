import FWCore.ParameterSet.Config as cms

demo = cms.EDAnalyzer('CMS2TestAnalyzer',
	minTracks=cms.untracked.uint32(0)
)

