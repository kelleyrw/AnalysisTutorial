import FWCore.ParameterSet.Config as cms

demo = cms.EDAnalyzer('SimpleNtuple'
    ,tracks = cms.untracked.InputTag('ctfWithMaterialTracks')
)
