import FWCore.ParameterSet.Config as cms

process = cms.Process("ZFILTER")

# message logger (logorithmic printout)
process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.limit = cms.untracked.int32(10)

# options
process.options = cms.untracked.PSet(wantSummary = cms.untracked.bool(True))

# source
process.maxEvents = cms.untracked.PSet(input = cms.untracked.int32(-1))
process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
        'file:ntuples/dy_nofilter.root'
    )
)

# load ZTreeFilter
process.load("Demo.DemoZAnalysis.ZTreeFilter_cfi")

# output 
process.out = cms.OutputModule("PoolOutputModule",
    fileName = cms.untracked.string('ntuples/dy_filter.root'),
	SelectEvents = cms.untracked.PSet(SelectEvents = cms.vstring('p')),
	outputCommands = cms.untracked.vstring(
		'drop *',
		"keep *_ZTreeMaker_*_*"
	)
)

# paths
process.p = cms.Path(process.ZTreeFilter)
process.e = cms.EndPath(process.out)
