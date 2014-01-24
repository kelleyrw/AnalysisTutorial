import FWCore.ParameterSet.Config as cms

process = cms.Process("ZNTUPLE")

# source
process.maxEvents = cms.untracked.PSet(input = cms.untracked.int32(-1))
process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
    fileNames = cms.untracked.vstring(
        'file:/nfs-7/userdata/edm/53X/DYJetsToLL_M-50_TuneZ2Star_8TeV-madgraph-tarball_AODSIM_PU_S10_START53_V7A-v1.root'
    )
)

# load ZTreeMaker
process.load("Demo.DemoZAnalysis.ZTreeMaker_cfi")

# output 
process.out = cms.OutputModule("PoolOutputModule",
    fileName = cms.untracked.string('ntuples/dy_nofilter.root'),
	outputCommands = cms.untracked.vstring(
		'drop *',
		"keep *_ZTreeMaker_*_*"
	)
)

# paths
process.p = cms.Path(process.ZTreeMaker)
process.e = cms.EndPath(process.out)

# message logger (logorithmic printout)
# process.load("FWCore.MessageService.MessageLogger_cfi")
process.MessageLogger = cms.Service("MessageLogger",
     default = cms.untracked.PSet(limit = cms.untracked.int32(10))
)
