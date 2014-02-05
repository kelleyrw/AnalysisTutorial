import FWCore.ParameterSet.Config as cms

process = cms.Process("DEMOZANALYSIS")

# message logger (logorithmic printout)
process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.limit = cms.untracked.int32(10)

# options
process.options = cms.untracked.PSet(wantSummary = cms.untracked.bool(True))

# source
process.maxEvents = cms.untracked.PSet(input = cms.untracked.int32(-1))
process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
        'file:/nfs-7/userdata/edm/53X/DYJetsToLL_M-50_TuneZ2Star_8TeV-madgraph-tarball_AODSIM_PU_S10_START53_V7A-v1.root'
    )
)

# load ZTreeAnalysis
process.load("Demo.DemoZAnalysis.ZTreeAnalysis_cff")

# output 
process.out = cms.OutputModule("PoolOutputModule",
    fileName = cms.untracked.string('ntuples/dy.root'),
    SelectEvents = cms.untracked.PSet(SelectEvents = cms.vstring('p')),
    outputCommands = cms.untracked.vstring(
        'drop *',
        "keep *_ZTreeMaker_*_*"
    )
)

# paths
process.p = cms.Path(process.ZTreeAnalysis)
process.e = cms.EndPath(process.out)


