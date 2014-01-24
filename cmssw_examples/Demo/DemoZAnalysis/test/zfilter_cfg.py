import FWCore.ParameterSet.Config as cms

process = cms.Process("ZFILTER")

# source
process.maxEvents = cms.untracked.PSet(input = cms.untracked.int32(-1))
process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
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

# message logger (logorithmic printout)
# process.load("FWCore.MessageService.MessageLogger_cfi")
process.MessageLogger = cms.Service("MessageLogger",
     default = cms.untracked.PSet(limit = cms.untracked.int32(10))
)
