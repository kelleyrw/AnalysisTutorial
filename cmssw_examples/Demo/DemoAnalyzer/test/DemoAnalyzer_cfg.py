import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")

# message logger (logorithmic printout)
process.MessageLogger = cms.Service("MessageLogger",
     default = cms.untracked.PSet(limit = cms.untracked.int32(10))
)

# initialize MessageLogger and output report
# process.load("FWCore.MessageLogger.MessageLogger_cfi")
# process.MessageLogger.cerr.threshold = 'INFO'
# process.MessageLogger.categories.append('Demo')
# process.MessageLogger.cerr.INFO = cms.untracked.PSet(
#     limit = cms.untracked.int32(-1)
# )
# process.options = cms.untracked.PSet(wantSummary = cms.untracked.bool(True))

# input source
process.maxEvents = cms.untracked.PSet(input = cms.untracked.int32(-1))
process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
    fileNames = cms.untracked.vstring(
        'file:/nfs-7/userdata/edm/53X/DYJetsToLL_M-50_TuneZ2Star_8TeV-madgraph-tarball_AODSIM_PU_S10_START53_V7A-v1.root'
    )
)

# output file name
process.TFileService = cms.Service("TFileService",
	fileName = cms.string('histodemo.root')
)

# my demo analyzer
process.load("Demo.DemoAnalyzer.DemoAnalyzer_cfi")
process.demo.minTracks=1000

# dump all events
process.dump = cms.EDAnalyzer('EventContentAnalyzer')

# path
# process.Tracer = cms.Service("Tracer")
# process.p = cms.Path(process.demo*process.dump)
process.p = cms.Path(process.demo)
